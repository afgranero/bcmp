# bcmp

## What it does

*bcmp* is a simple CLI program to compare binary files and output their differences in a simple and practical way.

If you wonder why *cmp* was not enough for me, the [Motivations](#motivations) section explains this.

## Quick start

   ```
   make
   ./bcmp file1.bin file2.bin
   ```

More details:

* [Compile and install](#compile-and-install).
* [Usage](#usage).


## Compile and install

To compile, you do:

```
make
```

To remove the compiled executable:

```
make clean
```

To install it on your system (requires *sudo*):

```
make install
```

To uninstall (requires *sudo*):

```
make uninstall
```


## Testing

The rationale for the way I made the tests is above in [Design decisions](#design-decisions).

Before tests, go to */tests* directory.

To run all tests, do:

```
make
```

To run a specific test, do:

```
make test_01
```

## Usage

All examples assume you installed *bcmp*, so you don't need to use *./bcmp*.

### Help

```
$ bcmp -h
```

```
Usage: bcmp [options] file1 file2

Options:
  -q, --quiet    quiet mode: no messages, only error messages
  -S, --silent   silent mode: no messages at all, even errors
  -n, --limit N  max differences shown (default 100, 0 to show all)
  -s, --skip N   skip first N bytes
  -h, --help     display this help and exit
  -v, --version  output version information and exit

Options with numeric parameters support decimal, hex with 0x prefix, and octal with 0 prefix.
If file1 or file2 is '-' (but not both), read standard input for that file.
Exit status is 0 if inputs are the same, 1 if different, 2 if error.
```

#### Version

```
$ bcmp -v
```

```
bcmp 1.0 (64-bit).
A reimagined cmp (GNU diffutils).
Copyright (C) Airton da Fonseca Granero.
License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

Max file size 9.22 EB.
```

### Simple file comparison:

```
bcmp file_01.bin file_02.bin
```

Output for equal files:

```
Files are equal.
```

Output example showing differences:

```
0109: a4 08
08c6: 62 02
0b75: 07 a2
0d5e: df bc
```

The address column pads positions with 0s so it can represent the larger position in the file. This way all positions in the file are the same width, so on a big file we can have this output:

```
0001 4000 0000: 0c 0a
0001 4000 0002: 0a 0c
```

If there are many differences, it shows the first 100 by default:

```
0000: 03 fa
0001: 76 1b
0002: dd 2d

...

0061: 70 a2
0062: 64 8b
0064: ad 26
Limit of 100 differences reached. Stopping.
```

This can be overridden by options *-n* or *--limit* followed by a numeric parameter:

```
bcmp -n 3 file_01.bin file_04.bin
```

```
0000: 03 fa
0001: 76 1b
0002: dd 2d
Limit of 3 differences reached. Stopping.
```

This can also be disabled completely passing 0 as parameter to *-n* or *--limit*:

```
bcmp -n 3 file_01.bin file_04.bin
```

```
0000: 03 fa
0001: 76 1b
0002: dd 2d

...

0ffd: 27 31
0ffe: 4b 2f
0fff: 27 b9
```

Files of different sizes will show differences until the smaller ends:

```
05ec: ea d9
1000: EOF on file_01.bin
```

### Skipping the beginning of file

To skip the first n bytes using an offset you can use *-s* or *--skip* followed by the offset:

```
bcmp -s 0x0900 file_01.bin file_03.bin
```

```
0b75: 07 a2
0d5e: df bc
```

Notice this skips the first bytes to be compared, not the first differences.

Notice also that in any numerical parameter of an option you can pass hexadecimal or octal values using the prefixes *0x* and *0* respectively.

### Using files streamed from *stdin*

You can use *-* for reading one of the files from *stdin*:

```
cat file_01.bin | bcmp - file_03.bin
```

or

```
cat file_03.bin | bcmp file_01.bin
```

This is useful for preprocessing the file, for instance with *head*, *tail*, or others.


### Exit codes

0: equal  
1: different  
2: error  

### Suppressing messages:

If you want to suppress showing the differences and informative messages, you can use the options *-q* or *--quiet*. This does not suppress error messages.

To suppress all messages including errors, you use the options *-S* or *--silent*.

All those options do not suppress help and version messages if they are asked explicitly with *-h* or *--help* and *-S* or *--silent* respectively.


## Motivations

While developing this program:

* https://github.com/afgranero/ExtractAsmFromPages;
* https://bitbucket.org/afgranero/extractasmfrompages;
* https://codeberg.org/agranero/ExtractAsmFromPages;

(those repos are not public at the moment, but they will once they are mature)

I had to compare the ROM file created from it with another. I used *GNU diffutils cmp*. I found it deficient in several ways:

* it does not show the differences by default, only when requested by an option;

* it counts difference positions from 1, not 0, which makes sense if we are talking of chars, not bytes where using positions like addresses makes more sense;

* it shows positions in decimal and byte differences values in octal, without even bothering to make it explicit. I see no point of using octal to anything other than things that use 3 bits, like *chmod* permissions.

#### Alternatives to *cmp*

I tested a few alternatives:

* *vbindiff* (https://github.com/madsen/vbindiff)

  It only shows both files like a *hexdump* with a split screen and navigates from difference to difference. 

* *hexcompare* (https://sourceforge.net/p/hexcompare/)

   It only shows a blue background with red squares where differences are on a split screen where bytes of the two files are shown side by side.

* *radiff2* (https://github.com/radareorg/radare2/tree/master/binr/radiff2)

   Similar to *vbindiff*, with a better interface.

* *dhex* (https://github.com/cxd4/dhex)

   A hexadecimal editor with a compare mode.

### Conclusion

I just wanted a simple CLI tool that showed me only the differences in a practical way. I was so surprised and annoyed that no such thing existed that I decided to make one.

## Decisions

I made some decisions about the program and pondered a lot about them. This section explains my thought process to show that those things were not chosen at random and are non-negotiable features, meaning they won't be changed unless a very good reason convinces me otherwise.

Those are:

### Design decisions

* not to use any dependency outside the C Standard Library, this way it is easy to compile and install;

* the program is too simple and monolithic, and without reusable parts; there are no unit tests, only black box tests, without using any test framework. This way the tests are completely oblivious of the details of the program. For example, if in the future I rewrite *bcmp* in Rust those tests will still work;

* each test in the *makefile* runs on a subshell so it does not leave any remnants in variables to interfere in the other tests;

* the tests for big files use sparse files created with *truncate* in the */tmp* directory (or, if another is defined in *TEMPDIR* variable this is used) and the file is deleted as soon as it is used; this avoids problems with cloud replication systems like Dropbox;

* the tests removing permissions are done in the */tmp* directory as some cloud replication systems like Dropbox restore immediately removed permissions;

* the files are always compared, even in quiet and silent modes. Files of different sizes are not considered different just because they are reported with different sizes. In files with problems the metadata of the file can be reporting wrong sizes while the files themselves are not corrupted. If you are suspicious of a file and use *bcmp* to confirm and if I did that it would not help;

* the program is intended to work on these POSIX-like environments:

    * Linux 64-bit systems;
    * Linux 32-bit systems;
    * macOS;
    * Windows 64-bit systems using Windows Subsystem for Linux;
    * Windows 64-bit systems using MSYS2;
    * Windows 64-bit systems using Cygwin;

   but for the moment I only tested it on 64-bit Linux.

### Interface decisions

* short options use single letters as required by POSIX;

* the long option names follow *kebab-case* (lowercase letters separated by hyphens), this is not a POSIX requirement, but it is commonly used by apps;

* options that require a numeric parameter can receive a decimal, hexadecimal or octal parameter with the proper prefix, this is not exactly a decision, but a consequence of using *strtoull* function to parse them;

* the *-q*, *--quiet* options suppress showing the differences and informative messages but not error messages sent to *stderr*;

* the *-S*, *--silent* options suppress all messages, even error ones, except help and version ones when explicitly asked for with *-h* and *--help* or *-v* and *--version* respectively.

* the help screen is shown when an improper option or parameter is used, and the program will return error code 2, if help is called explicitly, error code 0 is returned;

* *bcmp* accepts *-* as one of the mandatory file name parameters to accept redirected input from *stdin*;

* *bcmp* shows the differences by default, contrary to *cmp*, which does not show differences except when asked, probably because it is mainly intended for use in scripts for its return value;

### Output formatting decisions

* to show positions and values in hexadecimal without *0x* prefix for better readability and using lower case letters because this is the standard used by *hexedit* and *hexdump*. Example:

   ```
   0109: a4 08
   08c6: 62 02
   0b75: 07 a2
   0d5e: df bc
   ```

* to show addresses in groups of four digits separated by spaces for better readability, and to pad addresses until they are left with as much zeros as the smallest multiple of 4 needed to address all positions on the biggest file, this way all lines are always aligned in columns, making it easy to read and process by other commands, like *cut*, *sed*, *awk*, etc. Example:

   ```
   0002 01ac: 14 d4
   0002 01ad: 52 1c
   0002 01ae: 58 73
   0002 01b6: 71 8b
   ```

## Portability

This has not yet been tested in platforms other than Linux, so it may possibly have problems on those platforms, especially in the tests.

In Cygwin the compiled program may be generated as *bcmp.exe*. This must be adjusted in the two makefiles.

In BSD or other platforms with different versions of *glibc* some error messages generated by *getopt_long* can change slightly, breaking some tests.

All that will be adjusted in time.

## Possible future changes

Not all things were decided; some features still can be added:

* different offsets to skip for each file, like in *cmp*;

* outputs in decimal and octal.
