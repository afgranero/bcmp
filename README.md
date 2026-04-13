# bcmp

## What it does

I put this first as I think projects declare their purpose right away.

*bcmp* is a simple CLI program to compare binary files and output its differences in a simple, practical and logical way.

If you wonder why not to use cmp the next section explains that.

## Motivations

While developing the program:

* https://github.com/afgranero/ExtractAsmFromPages;
* https://bitbucket.org/afgranero/extractasmfrompages;
* DOIT Codeberg link

I had to compare the ROM file created from it with another. I used *GNU diffutils cmp*. I found it deficient in several things:

* it does not show the differences by default, only when requested by an option;

* it counts difference positions from 1, not 0 what makes sense if we are talking of chars, not bytes where using positions like addresses makes more sense;

* it shows positions in decimal and byte differences values in octal, without even bothering to explicit it. I see no point of using octal to anything other than things that use 3 bits, like chmod permissions.

#### Alternatives to *cmp*

I tested a few alternatives:

##### *vbindiff* (https://github.com/madsen/vbindiff)

It only shows both files like a *hexdump* with a split screen and navigates from difference to difference. 

##### *hexcompare* (https://sourceforge.net/p/hexcompare/)

It only shows a blue background with red squares where differences are on a split screen where bytes of the two files are shown side by side.

#### *radiff2* (https://github.com/radareorg/radare2/tree/master/binr/radiff2)

Similar to *vbindiff*, with a better interface.

#### *dhex* (https://github.com/cxd4/dhex)

An hexadecimal editor with a compare mode.

### Conclusion

I just wanted a simple CLI tool that showed me only the differences in an objective and practical way.
I was so surprised and annoyed that no such a thing existed that I decided to make one.

## Decisions

I made some decisions about the program and pondered a lot about them. This section explains my thought process to show that those things were not chosen at random and are non negotiable features, meaning they won't be changed unless a very good reason convinces me otherwise.

### Design

* not to use any dependency outside the C Standard Library, this way it is easy to compile and install;

* the program is too simple and monolithic without reusable parts; there are no unit tests, only black box tests, without using any test framework.  This way the tests are completely oblivious of the details of the program. If in the future I rewrite *bcmp* in Rust for instance those tests will still work;

* each test in the *makefile* runs on a sub shell so it does not leave any  remains in variables to interfere in the other tests;

* the tests for big files use sparse files created with *truncate* in the */tmp* directory (or, if another is defined in *TEMPDIR* variable this is used) and the file is deleted as soon as the file is used; this avoids problems with cloud duplication systems like Dropbox;

* the tests removing permissions are done in */tmp* directory as some cloud replication systems like Dropbox restore immediately removed permissions;

* the program is intended to work on any POSIX like environments:

    * Linux 64-bit systems;
    * Linux 32-bit systems;
    * MacOS;
    * Windows 64-bit systems using Windows Linux Subsystem;
    * Windows 64-bit systems using MSYS2;
    * Windows 64-bit systems using Cygwin;

### Interface

* short options use single letters as required by POSIX;

* the long options names follow *kebab-case* (lowercase letters separated by hyphens), this it is not a POSIX requirement, but it is commonly used by apps;

* options that require a numeric parameter can receive a decimal, hexadecimal or octal parameter with the proper prefix, this is not exactly a decision, but a consequence of using *strtoull* function to parse them;

* the *-q*, *--quiet* parameter suppress informative messages but not error messages sent to *stderr*;

* the help screen shown when an improper option or parameter is used will return error code 2, if help is called explicitly, error code 0 is returned;

* *bcmp* accepts *-* as one of the mandatory file name parameters to accept redirected input from *stdin*;

* *bcmp* shows the differences by default, contrary to *cmp* that does not show differences except when asked, probably because it is mainly intended for use in scripts for its return value;

### Output formatting

* to show positions and values in hexadecimal without *0x* prefix for better readability using lower case letters because this is the standard used by *hexedit* and *hexdump*. Example:

   ```
   0109: a4 08
   08c6: 62 02
   0b75: 07 a2
   0d5e: df bc
   ```

* to show addresses in groups of four digits separated by spaces for  better readability; and to to pad address left with as much zeros the smallest multiple of 4 needed to address all positions on the biggest file, this way all lines are always aligned in columns, making easy to be processed but other commands, like *cut*, *sed*, *awk*, etc. Example:

   ```
   0002 01ac: 14 d4
   0002 01ad: 52 1c
   0002 01ae: 58 73
   0002 01b6: 71 8b
   ```

## Compile and install

To compile you do:

```
make
```

To clean remove compiled executable:

```
make clean
```

To install:

```
make install
```

To uninstall:

```
make uninstall
```

## Testing

Before tests, go to */tests* directory.

To run all tests, do:

```
make
```

To run an specific test, do:

```
make test_01
```

## Possible future changes

Not all things were decided, some features still can be added:

* different offsets to skip for each file, like in *cmp*;

* an option to silence all messages including error messages;





