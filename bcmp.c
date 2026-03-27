#if !defined(_WIN32) && !defined(_MSDOS)
    #define _POSIX_C_SOURCE 200112L
#endif

#include <stdio.h>
#include <sys/types.h>

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

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <getopt.h>

#define BUFFER_SIZE 65536

void print_help(FILE *out, char *prog) {
    fprintf(out, "Usage: %s [options] file1 file2\n", prog);
    fprintf(out, "Options:\n"
                    "  -q, --quiet    quiet mode (exit 1 if different, 0 if equal)\n"
                    "  -n, --limit N  max differences shown (default 100, 0 to show all)\n"
                    "  -s, --skip N   skip first N bytes (supports hex 0x...)\n"
                    "  -h, --help     display this help and exit\n"
                    "  -v, --version  output version information and exit\n"
            );
}

void print_version() {
    fprintf(stdout, "bcmp, a reimagined cmp (GNU diffutils) 1.0\n"
                    "Copyright (C) Airton da Fonseca Granero.\n"
                    "License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n"
                    "This is free software: you are free to change and redistribute it.\n"
                    "There is NO WARRANTY, to the extent permitted by law.\n"
            );
}   

unsigned long parse_num(const char *str) {
    char *endptr;
    
    // Skip leading whitespace manually
    while (*str == ' ' || *str == '\t') str++;


    // strtoul returns unsigned int but receiving a negative number returns a two's complement negation ...
    // .. so check if the first character is a minus sign.
    if (*str == '-') {
        fprintf(stderr, "Error: Negative numbers are not allowed: '%s'\n", str);
        exit(2);
    }

    unsigned long val = strtoul(str, &endptr, 0);
    if (str == endptr || *endptr != '\0') {
        fprintf(stderr, "Error: '%s' is not a valid number.\n", str);
        exit(2);
    }
    return val;
}

FILE* safe_fopen(char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Error opening file: '%s': %s.\n", filename, strerror(errno));
        exit(2);
    }
    return f;
}

void safe_fseek(char *filename, FILE *f, off_t skip) {
    if (fseeko(f, 0, SEEK_END) != 0) {
        fprintf(stderr, "Error: could not skip to end of file '%s': %s.\n", filename, strerror(errno));
    }

    off_t size = ftello(f);
    if (size == -1) {
        fprintf(stderr, "Error: could not read size of file '%s': %s", filename, strerror(errno));
        exit(2);
    }

    if (skip > size) {
        fprintf(stderr, "Error: Skip '%llu' is larger than size '%lld' of file '%s'.\n", (long long)skip, (long long)size, filename);
        exit(2);
    }

    if (fseeko(f, skip, SEEK_SET) != 0) {
        fprintf(stderr, "Error: could not skip to offset 0x%llx in file '%s': %s.\n", (long long)skip, filename, strerror(errno));
        fclose(f);
        exit(2);
    }    
}

// not used yet
// int get_blocks(unsigned long size) {
//     int blocks = 0;
//     long temp = (size - 1);
//     do {
//         temp >>= 16;
//         blocks++;
//     } while (temp > 0);
//     blocks = (blocks + 1) & ~1;
// }

int main(int argc, char *argv[]) {
    int opt;
    int quiet = 0;
    off_t limit = 100;
    off_t skip = 0;
    off_t diff_count = 0;
    off_t offset;
    int result = 0;

    // long options mapping
    static struct option long_options[] = {
        {"quiet",   no_argument,       NULL, 'q'},
        {"limit",   required_argument, NULL, 'n'},
        {"skip",    required_argument, NULL, 's'},
        {"version", no_argument,       NULL, 'v'},
        {"help",    no_argument,       NULL, 'h'},
        {0, 0, 0, 0} // Array must be null-terminated
    };

    // getopt_long instead of getopt
    // the last argument (&option_index) can be NULL if you don't need the index
    while ((opt = getopt_long(argc, argv, "qn:s:vh", long_options, NULL)) != -1) {
        switch (opt) {
            case 'q': quiet = 1; break;
            case 'n': limit = parse_num(optarg); break;
            case 's': skip = parse_num(optarg); break;
            case 'v': print_version(); return 0;
            case 'h': print_help(stdout, argv[0]); return 0;
            default:  print_help(stderr, argv[0]); return 2;
        }
    }

    if (argc - optind != 2) {
        print_help(stderr, argv[0]);
        return 2;
    }

    FILE *f1 = safe_fopen(argv[optind]);
    FILE *f2 = safe_fopen(argv[optind + 1]);

    if (skip > 0) {
        safe_fseek(argv[optind], f1, skip);
        safe_fseek(argv[optind + 1], f2, skip);
    }
    offset = skip;

    // Buffers for file reading
    unsigned char buf1[BUFFER_SIZE];
    unsigned char buf2[BUFFER_SIZE];

    while (1) {
        size_t n1 = fread(buf1, 1, BUFFER_SIZE, f1);
        size_t n2 = fread(buf2, 1, BUFFER_SIZE, f2);
        size_t min_n = (n1 < n2) ? n1 : n2;

        if (min_n > 0) {
            if (memcmp(buf1, buf2, min_n) != 0) {
                result = 1;
                if (quiet) break;

                for (size_t i = 0; i < min_n; i++) {
                    if (buf1[i] != buf2[i]) {
                        printf("0x%08lx: 0x%02x != 0x%02x\n", offset + i, buf1[i], buf2[i]);
                        diff_count++;
                        if (limit > 0 && diff_count >= limit) {
                            if (!quiet) {
                                fprintf(stdout, "Limit of %lu differences reached. Stopping.\n", limit);                               
                            }
                            goto cleanup;
                        }

                    }
                }
            }
        }

        if (n1 != n2) {
            if (!quiet) {
                printf("0x%08lx: EOF on %s\n", offset + min_n, (n1 < n2) ? argv[optind] : argv[optind + 1]);
            }
            result = 1;
            break;
        }

        // If both files ended at the exact same time
        if (diff_count == 0) {
            if (!quiet) {
                fprintf(stdout, "Files are equal.\n");                               
            }
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
