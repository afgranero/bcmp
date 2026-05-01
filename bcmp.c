#if !defined(_WIN32) && !defined(_MSDOS)
    #define _POSIX_C_SOURCE 200112L
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#if defined(_WIN32) || defined(_MSDOS)
    #if defined(_MSC_VER) || defined(__MINGW32__)
        #define fseeko _fseeki64
        #define ftello _ftelli64
        typedef __int64 off_t;
    #else
        #define fseeko fseek
        #define ftello ftell
        #ifndef _OFF_T_DEFINED
            typedef long off_t;
            #define _OFF_T_DEFINED
        #endif
    #endif
#endif

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <getopt.h>

#define EQUAL 0
#define SUCCESS 0
#define DIFFERENT 1
#define ERROR 2
#define BUFFER_SIZE 65536

int quiet = 0;
int quiet_errors = 0;

// On legacy 32-bit Intel architectures (i386 through early Pentium 4), ...
// ... 'off_t' is typically 32-bit (4 bytes), limiting file offsets to 2GB, ...
// ... however, the compiler (GCC) may still support 64-bit 'long long' (8 bytes), ...
// ... on newer systems is 64-bit (8 bytes), allowing offsets of 16EB, ...
// ... MAX_OFF_T is dynamically calculated to handle this gap.
#define BITS sizeof(off_t) * 8
#define OFF_T_MAX ((1ULL << (BITS - 1)) - 1)

char* file_size_limit(void) {
    // it is overkill, as it will have 16 or 32 bytes, but it is funny
    static char buffer[32];
    const char *units[] = {"B", "kB", "MB", "GB", "TB", "PB", "EB"};
    double valor = (double)OFF_T_MAX;

    int i = 0;
    while (valor >= 1000 && i < 6) {
        valor /= 1000;
        i++;
    }

    sprintf(buffer, "%.2f %s", valor, units[i]);
    return buffer;
}

int fprintf_error(FILE *stream, const char *format, ...) {
    int result = 0;

    if (!quiet_errors) {
        va_list args;

        va_start(args, format);
        result = vfprintf(stream, format, args);
        va_end(args);
    }

    return result;
}

int fprintf_message(FILE *stream, const char *format, ...) {
    int result = 0;

    if (!quiet) {
        va_list args;

        va_start(args, format);
        result = vfprintf(stream, format, args);
        va_end(args);
    }

    return result;
}

void print_help(FILE *out, char *prog) {

    // do not show help in case of error if it is in silent mode
    if (out == stderr && quiet_errors) {
        return;
    }

    fprintf(out, "Usage: %s [options] file1 file2\n", prog);
    fprintf(out, "\n");
    fprintf(out, "Options:\n"
                    "  -q, --quiet    quiet mode: no messages, only error messages\n"
                    "  -S, --silent   silent mode: no messages at all, even errors\n"
                    "  -n, --limit N  max differences shown (default 100, 0 to show all)\n"
                    "  -s, --skip N   skip first N bytes\n"
                    "  -h, --help     display this help and exit\n"
                    "  -v, --version  output version information and exit\n"
                    "\n"
                    "Options with numeric parameters support decimal, hex with Ox prefix, and octal with 0 prefix.\n"
                    "If file1 or file2 is '-' (but not both), read standard input for that file.\n"
                    "Exit status is 0 if inputs are the same, 1 if different, 2 if error.\n"
            );
}

void print_version() {
    fprintf(stdout, "bcmp 1.0 (%ld-bit).\n" 
                    "A reimagined cmp (GNU diffutils).\n"
                    "Copyright (C) Airton da Fonseca Granero.\n"
                    "License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n"
                    "This is free software: you are free to change and redistribute it.\n"
                    "There is NO WARRANTY, to the extent permitted by law.\n"
                    "\n"
                    "Max file size %s.\n"
            , BITS, file_size_limit());
}   

off_t parse_num(const char *str) {
    char *endptr;
    
    // Skip leading whitespace manually
    while (*str == ' ' || *str == '\t') str++;

    // strtoull returns unsigned long long but receiving a negative number returns a two's complement negation ...
    // .. so check if the first character is a minus sign.
    if (*str == '-') {
        fprintf_error(stderr,"Error: Negative numbers are not allowed: '%s'\n", str);
        exit(ERROR);
    }

    unsigned long long val = strtoull(str, &endptr, 0);
    if (str == endptr || *endptr != '\0') {
        fprintf_error(stderr,"Error: '%s' is not a valid number.\n", str);
        exit(ERROR);
    }

    if (errno == ERANGE) {
        fprintf_error(stderr,"Error: '%s' overflows internal representation for parameters.\n", str);
        exit(ERROR);
    }

    // On 64-bit systems, off_t is typically a signed long long (64-bit).
    // On legacy 32-bit systems (without _FILE_OFFSET_BITS=64), off_t may only be 32-bit.
    // Since we use strtoull (always 64-bit unsigned long long ), the converted value might be ...
    // ... valid for strtoull (not triggering ERANGE), but still exceed the local off_t capacity, ...
    // ... either on 64 or 32 bit systems, so we added this check.
    // We chose to maintain each system's native typing to ensure consistent behavior.
    if (val > OFF_T_MAX) {
        fprintf_error(stderr,"Error: '%s' overflows internal representation for counters.\n", str);
        exit(ERROR);
    }

    // the compiler has not how to know that I treated the overflow already so the pragmas
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wconversion"
    off_t result = (off_t)val;
    #pragma GCC diagnostic pop
    return result;
}

FILE* safe_fopen(char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        fprintf_error(stderr,"Error opening file: '%s': %s.\n", filename, strerror(errno));
        exit(ERROR);
    }
    return f;
}

off_t get_size(char *filename, FILE *f) {
    if (fseeko(f, 0, SEEK_END) != 0) {
        fprintf_error(stderr,"Error: could not skip to end of file '%s': %s.\n", filename, strerror(errno));
        exit(ERROR);
    }

    off_t size = ftello(f);
    if (size == -1) {
        fprintf_error(stderr,"Error: could not read size of file '%s': %s\n", filename, strerror(errno));
        exit(ERROR);
    }

    // reposition the pointer
    if (fseeko(f, 0, SEEK_SET) != 0) {
        fprintf_error(stderr,"Error: could not skip to beginning of the file '%s': %s.\n", filename, strerror(errno));
        fclose(f);
        exit(ERROR);
    }

    return size;
}

void safe_fseek(char *filename, FILE *f, off_t skip, off_t* size) {
    *size = get_size(filename, f);

    if (skip > *size) {
        fprintf_error(stderr,"Error: Skip '%llu' is larger than size '%lld' of file '%s'.\n", (long long)skip, (long long)*size, filename);
        fclose(f);
        exit(ERROR);
    }

    if (fseeko(f, skip, SEEK_SET) != 0) {
        fprintf_error(stderr,"Error: could not skip to offset 0x%llx in file '%s': %s.\n", (long long)skip, filename, strerror(errno));
        fclose(f);
        exit(ERROR);
    }    
}

int is_stream(char *filename, FILE* stream) {
    struct stat st;
    
    if (fstat(fileno(stream), &st) != 0) {
        fprintf_error(stderr,"Error: could not fstat: '%s': %s.", filename, strerror(errno));
        exit(ERROR);
    }
    return !(S_ISREG(st.st_mode));
}

size_t safe_fread(unsigned char *buf, size_t size_element, size_t to_read, FILE *stream) {
    size_t read_count = fread(buf, size_element, to_read, stream);
    if (read_count < to_read) {
        if (ferror(stream)) {
            exit(ERROR);
        }
    }

    return read_count;
}

void synthetic_fseek(char *filename, FILE *f, off_t skip) {
    unsigned char junk[8192];
    off_t remaining = skip;
    off_t read = 0;
    while (remaining > 0) {
        size_t to_read = (remaining > (off_t)sizeof(junk)) ? sizeof(junk) : (size_t)remaining;
        size_t read_count = safe_fread(junk, 1, to_read, f);
        remaining -= read_count;
        read += read_count;
        if (read_count == 0) {
            if (feof(f)) {
                // in this case the stream ended: so the skip value is bigger than the stream
                // is to an error as safe_ferror treats those
                fprintf_error(stderr,"Error: could not skip '0x%llx' bytes from stdin. EOF found after 0x%llx bytes read.\n", (long long)skip, (long long)read);
                exit(ERROR);
            } else {
                // neither error of end of file
                fprintf_error(stderr,"Unexpected error: could not skip '0x%llx' bytes from stdin. Stream stopped after 0x%llx bytes read without reaching EOF.\n", (long long)skip, (long long)read);
                exit(ERROR);
            }
        }
    }
}

void generic_fseek(char *filename, FILE *f, off_t skip, off_t* size) {
    if (is_stream(filename, f)) {
        synthetic_fseek(filename, f, skip);
        size = 0;
    }
    else {
        safe_fseek(filename, f, skip, size);
    }
}

off_t generic_get_size(char *filename, FILE *f) {
    off_t size ;
    if (is_stream(filename, f)) {
        size = 0;
    }
    else {
        size = get_size(filename, f);
    }
}

int get_blocks(off_t size) {
    // returns the number blocks of 4 bytes needed for the address
    int blocks = 0;
    off_t temp = (size - 1);
    do {
        temp >>= 16;
        blocks += 1;
    } while (temp > 0);
    return blocks;
}

int get_address_chars(off_t size1, off_t size2) {
    off_t min_size = (size1 < size2) ? size1 : size2;
    int chars = 4 * get_blocks(min_size);
    return chars;
}

void get_address_formatted(char* out, off_t address_dec, off_t size1,  off_t size2) {
    int address_chars = get_address_chars(size1, size2);

    char address[17];
    int i = sprintf(address, "%0*llx", address_chars, (long long)address_dec);
    address[i] = '\0';

    // receives 0x0FFFFFFFFFFFFFFFF
    // returns 0x0FFF FFFF FFFFF FFFF

    int ia = 0;
    int io = 0;

    while (address[ia] != '\0') {
        io += sprintf(out + io, "%.4s", address + ia);
        ia += 4;
        //add space if there are chars remaining
        if (address[ia] != '\0') {
            out[io++] = ' ';
        }
    }
    out[io] = '\0';
}

int main(int argc, char *argv[]) {
    int opt;
    off_t limit = 100;
    off_t skip = 0;
    off_t diff_count = 0;
    off_t offset;
    int result = SUCCESS;

    // long options mapping
    static struct option long_options[] = {
        {"quiet",   no_argument,       NULL, 'q'},
        {"silent",   no_argument,      NULL, 'S'},
        {"limit",   required_argument, NULL, 'n'},
        {"skip",    required_argument, NULL, 's'},
        {"version", no_argument,       NULL, 'v'},
        {"help",    no_argument,       NULL, 'h'},
        {0, 0, 0, 0} // Array must be null-terminated
    };

    // pre-scanning argv to avoid getopt_long printing error messages during processing if silent mode is asked
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-S") == 0 || strcmp(argv[i], "--silent") == 0) {
            //opterr is a global included by getopt.h to control error output made by getopt_long
            quiet = 1; quiet_errors = 1; opterr = 0; break;
            break;
        }
    }

    // the last argument (&option_index) can be NULL if you don't need the index
    while ((opt = getopt_long(argc, argv, "qSn:s:vh", long_options, NULL)) != -1) {
        switch (opt) {
            case 'q': quiet = 1; break;
            case 'S': break; // already processed above
            case 'n': limit = parse_num(optarg); break;
            case 's': skip = parse_num(optarg); break;
            case 'v': print_version(); return 0;
            case 'h': print_help(stdout, argv[0]); return SUCCESS;
            default:  print_help(stderr, argv[0]); return ERROR;
        }
    }

    if (argc - optind != 2) {
        print_help(stderr, argv[0]);
        return ERROR;
    }

    char* filename1 = argv[optind];
    char* filename2 = argv[optind + 1];
    
    if (strcmp(filename1, "-") == 0 && strcmp(filename2, "-") == 0 )  {
         fprintf_error(stderr,"Only one file can be read from standard input.\n");
         exit(ERROR);
    }

    FILE *f1 = (strcmp(filename1, "-") == 0) ? stdin : safe_fopen(filename1);
    FILE *f2 = (strcmp(filename2, "-") == 0) ? stdin : safe_fopen(filename2);
    
    off_t size1;
    off_t size2;

    if (skip > 0) {
        generic_fseek(filename1, f1, skip, &size1);
        generic_fseek(filename2, f2, skip, &size2);
    } else {
        size1 = generic_get_size(filename1, f1);
        size2 = generic_get_size(filename2, f2);
    }

    char address[22];
    offset = skip;
    
    // Buffers for file reading
    unsigned char buf1[BUFFER_SIZE];
    unsigned char buf2[BUFFER_SIZE];

    while (1) {
        size_t n1 = safe_fread(buf1, 1, BUFFER_SIZE, f1);
        size_t n2 = safe_fread(buf2, 1, BUFFER_SIZE, f2);
        size_t min_n = (n1 < n2) ? n1 : n2;

        if (min_n > 0) {
            if (memcmp(buf1, buf2, min_n) != 0) {
                result = DIFFERENT;
                if (quiet) break;

                for (size_t i = 0; i < min_n; i++) {
                    if (buf1[i] != buf2[i]) {
                        get_address_formatted(address, offset + i, size1, size2);
                        fprintf(stdout, "%s: %02x %02x\n", address, buf1[i], buf2[i]);
                        diff_count++;
                        if (limit > 0 && diff_count >= limit) {
                            fprintf(stdout, "Limit of %lu differences reached. Stopping.\n", limit);
                            goto cleanup;
                        }

                    }
                }
            }
        }

        if (n1 != n2) {
            if (!quiet) {
                get_address_formatted(address, offset + min_n, size1, size2);
                fprintf(stdout, "%s: EOF on %s\n", address, (n1 < n2) ? filename1 : filename2);
            }
            result = DIFFERENT;
            break;
        }

        // If both files ended at the exact same time
        if (n1 < BUFFER_SIZE && diff_count == 0) {
            fprintf_message(stdout, "Files are equal.\n");
            break;
        }

        if (n1 < BUFFER_SIZE) break;

        offset += min_n;
    }

    cleanup:
        fclose(f1);
        fclose(f2);
        return result;
}
