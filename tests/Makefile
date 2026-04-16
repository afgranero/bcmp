# it will only work in Windows with MingGW32 and MSYS2
ifeq ($(OS),Windows_NT)
  ifndef MSYSTEM
    $(error Use MSYS2 to build/test on Windows)
  endif
endif

SHELL=/bin/bash

# := sets immediately avoiding to reexpand it every time it is referred
TMPDIR := $(or $(TMPDIR),/tmp)

TARGET = ../bcmp

LOG=result.txt

ALL_TESTS = test_01 \
			test_02 \
			test_03 \
			test_04 \
			test_05 \
			test_06 \
			test_07 \
			test_08 \
			test_09 \
			test_10 \
			test_11 \
			test_12 \
			test_13 \
			test_14 \
			test_15 \
			test_16 \
			test_17 \
			test_18 \
			test_19 \
			test_20 \
			test_21 \
			test_22 \
			test_23 \
			test_24 \
			test_25 \
			test_26 \
			test_27 \
			test_28 \
			test_29 \
			test_30 \
			test_31 \
			test_32 \
			test_33 \
			test_34 \
			test_35 \
			test_36 \
			test_37 \
			test_38 \
			test_39 \
			test_40 \
			test_41 \
			test_42 \
			test_43 \
			test_44 \
			test_45 \
			test_46 \
			test_47 \
			test_48 \
			test_49 \
			test_50 \
			test_51 \
			test_52 \
			test_53 \
			test_54 \
			test_55 \
			test_56 \
			test_57 \
			test_58 \
			test_59 \
			test_60 \
			test_61 \
			test_62 \
			test_63 \
			test_64 \
			test_65 \
			test_66 \
			test_67 \
			test_68 \
			test_69 \
			test_70 \
			test_71 \
			test_72 \
			test_73 \
			test_74 \
			test_75 \
			test_76 \
			test_77 \
			test_78 \
			test_79 \
			test_80 \
			test_81 \
			test_82 \
			test_83 \
			test_84 \
			test_85 \
			test_86 \
			test_87 \
			test_88 \
			test_89 \
			test_90 \
			test_91 \
			test_92 \
			test_93 \
			test_94 \
			test_95 \
			test_96 \
			test_97 \
			test_98 \
			test_99 \
			test_100 \
			test_101 \
			test_102 \
			test_103 \
			test_104 \
			test_105 \
			test_106 \
			test_107 \
			test_108 \
			test_109 \
			test_110 \
			test_111 \
			test_112 \
			test_113 \
			test_114 \
			test_115 \
			test_116 \
			test_117 \
			test_118 \
			test_119 \
			test_120 \
			test_121 \
			summary

RED   = \033[31m
YELLOW = \033[33m
GREEN = \033[32m
RESET = \033[0m

tests: compile $(ALL_TESTS)

compile:
	@$(MAKE) -C .. --no-print-directory; printf "\n";
	@rm -f $(LOG)
	@touch $(LOG)

# version tests
test_01:
	@# test if "../bcmp --version" return 0 and version text in stdout
	@(\
		CMD="$(TARGET) --version"; \
		STDOUT=$$($$CMD 2> /dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		# ignore variable parts of the output message \
		echo "$$STDOUT" | ( head -c 9; tail -c +3; ) | ( head -c 306; tail -c +8) | diff -q - message_version.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_02:
	@# test if "../bcmp -v" return 0 and version text in stdout,
	@# -v is the same as --version
	@(\
		CMD="$(TARGET) -v"; \
		STDOUT=$$($$CMD 2> /dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		# ignore variable parts of the output message \
		echo "$$STDOUT" | ( head -c 9; tail -c +3; ) | ( head -c 306; tail -c +8) | diff -q - message_version.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

# help tests
test_03:
	@# test if "../bcmp" with no parameters returns 2 and help text in stderr,
	@# lack of required arguments is an error and shows help text
	@(\
		CMD="$(TARGET)"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_help.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_04:
	@# test if "../bcmp --help" returns 0 and help text in stdout,
	@# when requesting help text is not treated as an error
	@(\
		CMD="$(TARGET) --help"; \
		STDOUT=$$($$CMD 2> /dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_help.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_05:
	@# test if "../bcmp --quiet --help" return 0 and help text in stdout,
	@# --quiet does not suppress --help
	@(\
		CMD="$(TARGET) --quiet --help"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_help.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_06:
	@# test if "../bcmp -q -h" returns 0 and help text in stdout,
	@# -q  does not suppress -h,
	@# -q and -h are the same as --quiet and --help
	@(\
		CMD="$(TARGET) -q -h"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_help.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

# equal files tests
test_07:
	@# test if "../bcmp file_01.bin file_01.bin" returns 0 and message in stdout,
	@# file is equal to itself
	@(\
		CMD="$(TARGET) file_01.bin file_01.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_01.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_08:
	@# test if "../bcmp file_01.bin file_02.bin" return 0 and message in stdout,
	@# equal files
	@(\
		CMD="$(TARGET) file_01.bin file_02.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_01.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_09:
	@# test if "../bcmp -s0x800 file_01.bin file_02.bin" return 0 and message in stdout,
	@# equal files,
	@# skip number of bytes specified in hexadecimal
	@(\
		CMD="$(TARGET) file_01.bin file_02.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_01.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_10:
	@# test if "../bcmp -s2048 file_01.bin file_02.bin" return 0 and message in stdout,
	@# equal files,
	@# skip number of bytes specified in decimal
	@(\
		CMD="$(TARGET) -s2048 file_01.bin file_02.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_01.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_11:
	@# test if "../bcmp -q file_01.bin file_02.bin" returns 0 and no message 
	@# equal files 
	@# quiet mode
	@(\
		CMD="$(TARGET) -q file_01.bin file_02.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDOUT" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

# different files tests
test_12:
	@# test if "../bcmp file_01.bin file_03.bin" returns 1 and message in stdout,
	@# files differ
	@(\
		CMD="$(TARGET) file_01.bin file_03.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_02.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_13:
	@# test if "../bcmp file_07.bin file_08.bin" return 1 and message in stdout,
	@# files differ,
	@# files with 0x00 in the beginning
	@(\
		CMD="$(TARGET) file_07.bin file_08.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_09.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		# this case documents that message_09.txt has 2 lines and so all differences are shown (this will matter in next test)... \
		# ... this is easier than check STDOUT number of lines believe me \
		LINES_COUNT=$$(cat message_09.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "2" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_14:
	@# test if "../bcmp -q file_01.bin file_03.bin" return 1 and no message in stdout,
	@# files differ,
	@# quiet mode
	@(\
		CMD="$(TARGET) -q file_01.bin file_03.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDOUT" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

# different files tests with skip
test_15:
	@# test if "../bcmp -s1 file_07.bin file_08.bin" return 1 and message in stdout,
	@# files differ,
	@# files with 0x00 in the beginning,
	@# skipping first byte that is equal in both, no change in output compared with no skip
	@(\
		CMD="$(TARGET) file_07.bin file_08.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_09.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		# this case documents that message_09.txt has 2 lines and so all differences are still shown (like in previous test) ... \
		# ... this is easier than check STDOUT number of lines believe me \
		LINES_COUNT=$$(cat message_09.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "2" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_16:
	@# test if "../bcmp -s2 file_07.bin file_08.bin" return 1 and message in stdout,
	@# files differ,
	@# files with 0x00 in the beginning,
	@# skipping two bytes, so output shows one difference less
	@(\
		CMD="$(TARGET) -s2 file_07.bin file_08.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_10.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		# this case documents that message_10.txt has 1 line and so one difference less is shown) ... \
		# ... this is easier than check STDOUT number of lines believe me \
		LINES_COUNT=$$(cat message_10.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "1" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_17:
	@# test if "../bcmp --skip 2 file_07.bin file_08.bin" return 1 and message in stdout,
	@# --skip is the same as -s,
	@# files differ,
	@# files with 0x00 in the beginning,
	@# skipping two first bytes, so output shows one difference less
	@(\
		CMD="$(TARGET) --skip 2 file_07.bin file_08.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_10.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		# this case documents that message_10.txt has 1 line and so one difference less is shown) ... \
		# ... this is easier than check STDOUT number of lines believe me \
		LINES_COUNT=$$(cat message_10.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "1" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_18:
	@# test if "../bcmp -s3 file_07.bin file_08.bin" returns 1 and messages in stdout,
	@# files differ,
	@# files with 0x00 in the beginning, 
	@# skipping all bytes, skips all differences, making files being considered equal
	@(\
		CMD="$(TARGET) -s3 file_07.bin file_08.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_01.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)	

# many differences tests
test_19:
	@# test if "../bcmp file_01.bin file_04.bin" returns 1 and messages in stdout,
	@# files with many differences,
	@# shows by default the first 100 differences
	@(\
		CMD="$(TARGET) file_01.bin file_04.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_03.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		# this case documents that message_03.txt has 101 lines and so the limit is correct (100 outputs and one message) ... \
		# ... this is easier than check STDOUT number of lines beleive me \
		LINES_COUNT=$$(cat message_03.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "101" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_20:
	@# test if "../bcmp -n10 file_01.bin file_04.bin" returns 1 and messages in stdout,
	@# files with many differences,
	@# shows the requested first 10 differences
	@(\
		CMD="$(TARGET) -n10 file_01.bin file_04.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_04.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		# this case documents that message_04.txt has 11 lines and so the limit is correct (100 outputs and one message) ... \
		# ... this is easier than check STDOUT number of lines believe me \
		LINES_COUNT=$$(cat message_04.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "11" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_21:
	@# test if "../bcmp -n0 file_01.bin file_04.bin" returns 1 and messages in stdout,
	@# files with many differences,
	@# shows by request all differences
	@(\
		CMD="$(TARGET) -n0 file_01.bin file_04.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_07.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		# this case documents that message_07.txt has 4075 lines and so the limit is correct (100 outputs and one message) ... \
		# ... this is easier than check STDOUT number of lines believe me \
		LINES_COUNT=$$(cat message_07.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "4075" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

# many differences quiet tests
test_22:
	@# test if "../bcmp -q file_01.bin file_04.bin" returns 1 and no messages in stdout, 
	@# files with many differences,
	@# quiet mode,
	@# stops by default after the first 100 differences (no way to test it as it shows none)
	@(\
		CMD="$(TARGET) -q file_01.bin file_04.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDOUT" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_23:
	@# test if "../bcmp -q -n10 file_01.bin file_04.bin" returns 1 and no message in stdout 
	@# files with many differences,
	@# quiet mode
	@# stops by request after the first 10 differences (no way to test it as it shows none)
	@(\
		CMD="$(TARGET) -q -n10 file_01.bin file_04.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDOUT" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_24:
	@# test if "../bcmp -q -n0 file_01.bin file_04.bin" returns 1 and no messages,
	@# files with many differences,
	@# quiet mode, 
	@# search bye request all differences (no way to test it as it shows none), 
	@(\
		CMD="$(TARGET) -q -n10 file_01.bin file_04.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDOUT" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

# files of different sizes
test_25:
	@# test if "../bcmp file_01.bin file_05.bin" returns 1 and message in stdout,
	@# files of different sizes, 
	@# files with differences before the end of the smaller one
	@(\
		CMD="$(TARGET) file_01.bin file_05.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_05.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		# this case documents that message_05.txt has 2 lines and so the limit is correct (100 outputs and one message) ... \
		# ... this is easier than check STDOUT number of lines believe me \
		LINES_COUNT=$$(cat message_05.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "2" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_26:
	@# test if "../bcmp -s0x5ed file_01.bin file_05.bin" returns 1 and messages in stdout,
	@# files of different sizes,
	@# skipping number of bytes specified in hexadecimal,
	@# files with differences before the end of the smaller one,
	@# it skips all differences but files are of different sizes are different
	@(\
		CMD="$(TARGET)  -s0x5ed file_01.bin file_05.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_08.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		# this case documents that message_08.txt has 1 line and so the limit is correct (100 outputs and one message) ... \
		# ... this is easier than check STDOUT number of lines believe me \
		LINES_COUNT=$$(cat message_08.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "1" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)


test_27:
	@# test if "../bcmp file_01.bin file_06.bin" return 1 and message in stdout,
	@# files of different sizes, 
	@# files are equal until the last byte of the smaller one,
	@# still considers files different as file sizes are different 
	@(\
		CMD="$(TARGET) file_01.bin file_06.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_06.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		# this case documents that message_06.txt has 1 line and so the limit is correct (100 outputs and one message) ... \
		# ... this is easier than check STDOUT number of lines believe me \
		LINES_COUNT=$$(cat message_06.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "1" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)


# files of different sizes quiet tests
test_28:
	@# test if "../bcmp -q file_01.bin file_05.bin" return 1 and no message in stdout,
	@# files of different sizes,
	@# files different before the end of the smaller one,
	@# quiet mode
	@(\
		CMD="$(TARGET) -q file_01.bin file_05.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDOUT" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)


test_29:
	@# test if "../bcmp -q file_01.bin file_06.bin" return 1 and no message in stdout,
	@# files of different sizes,
	@# files equal until the last byte of the smaller one,
	@# quiet mode
	@(\
		CMD="$(TARGET) -q file_01.bin file_06.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDOUT" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

# TODO two tests with both files of different sizes reversed

# error tests
test_30:
	@# test if "../bcmp file_00.bin file_01.bin" returns 2 and error message in stderr,
	@# first argument with non existent file 
	@(\
		rm -f file_00.bin; \
		CMD="$(TARGET) file_00.bin file_01.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_11.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_31:
	@# test if "../bcmp file_01.bin file_00.bin" returns 2 and error message in stderr,
	@# second argument with non existent file
	@(\
		rm -f file_00.bin; \
		CMD="$(TARGET) file_01.bin file_00.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_11.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_32:
	@# test if "../bcmp file_00.bin file_00.bin" both arguments with non existent files returns 2 and error message in stderr
	@(\
		rm -f file_00.bin; \
		CMD="$(TARGET) file_00.bin file_00.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_11.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_33:
	@# test if "../bcmp $(TMPDIR)/file_09.bin file_01.bin" returns 2 and error message in stderr,
	@# first argument with file without read permission
	@# using $(TMPDIR) because some daemons like Dropbox restore removed read permissions
	@(\
		rm -f $(TMPDIR)/file_09.bin; \
		cp file_09.bin $(TMPDIR); \
		chmod 224 $(TMPDIR)/file_09.bin; \
		CMD="$(TARGET) $(TMPDIR)/file_09.bin file_01.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_12.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		rm -f $(TMPDIR)/file_09.bin; \
		printf "\n"; \
	)

test_34:
	@# test if "../bcmp file_01.bin $(TMPDIR)/file_09.bin" returns 2 and error message in stderr,
	@# second argument with file without read permission
	@# using $(TMPDIR) because some daemons like Dropbox restore removed read permissions
	@(\
		rm -f $(TMPDIR)/file_09.bin; \
		cp file_09.bin $(TMPDIR); \
		chmod 224 $(TMPDIR)/file_09.bin; \
		CMD="$(TARGET) file_01.bin $(TMPDIR)/file_09.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_12.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		rm -f $(TMPDIR)/file_09.bin; \
		printf "\n"; \
	)

test_35:
	@# test if "../bcmp $(TMPDIR)/file_09.bin $(TMPDIR)/file_09.bin" returns 2 and error message in stderr,
	@# both arguments with files without read permission
	@# using $(TMPDIR) because some daemons like Dropbox restore removed read permissions
	@(\
		rm -f $(TMPDIR)/file_09.bin; \
		cp file_09.bin $(TMPDIR); \
		chmod 224 $(TMPDIR)/file_09.bin; \
		CMD="$(TARGET) $(TMPDIR)/file_09.bin $(TMPDIR)/file_09.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_12.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		rm -f $(TMPDIR)/file_09.bin; \
		printf "\n"; \
	)

test_36:
	@# test if "../bcmp -s4 file_07.bin file_01.bin" returns 2 and error message in stderr,
	@# skips past the end of first file
	@(\
		CMD="$(TARGET) -s4 file_07.bin file_01.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_13.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_37:
	@# test if "../bcmp -s4 ile_01.bin file_07.bin " returns 2 and error message in stderr,
	@# skips past the end of second file
	@(\
		CMD="$(TARGET) -s4 file_01.bin file_07.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_13.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_38:
	@# test if "../bcmp -s4 file_07.bin file_07.bin " returns 2 and error message in stderr,
	@# skips past the end of both files
	@(\
		CMD="$(TARGET) -s4 file_01.bin file_07.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_13.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

# options and argument error tests (not dependent on getopt)
test_39:
	@# test if "../bcmp -s-10 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in decimal on argument for numeric option -s without space
	@(\
		CMD="$(TARGET) -s-10 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_14.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_40:
	@# test if "../bcmp -s -10 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in decimal on argument for numeric option -s with space
	@(\
		CMD="$(TARGET) -s -10 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_14.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_41:
	@# test if "../bcmp -s-0xa0 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in hexadecimal on argument for numeric option -s without space
	@(\
		CMD="$(TARGET) -s-0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_15.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_42:
	@# test if "../bcmp -s -0xa0 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in hexadecimal on argument for numeric option -s with space
	@(\
		CMD="$(TARGET) -s -0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_15.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)


test_43:
	@# test if "../bcmp --skip -10 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in decimal on argument for numeric option --skip with space
	@(\
		CMD="$(TARGET) --skip -10 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_14.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_44:
	@# test if "../bcmp --skip -0xa0 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in hexadecimal on argument for numeric option --skip with space
	@(\
		CMD="$(TARGET) --skip -0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_15.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_45:
	@# test if "../bcmp -n-10 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in decimal on argument for numeric option -n without space
	@(\
		CMD="$(TARGET) -n-10 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_14.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_46:
	@# test if "../bcmp -n -10 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in decimal on argument for numeric option -n with space
	@(\
		CMD="$(TARGET) -n -10 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_14.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_47:
	@# test if "../bcmp -n-0xa0 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in hexadecimal on argument for numeric option -n without space
	@(\
		CMD="$(TARGET) -n-0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_15.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_48:
	@# test if "../bcmp -n -0xa0 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in hexadecimal on argument for numeric option -n with space
	@(\
		CMD="$(TARGET) -n -0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_15.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_49:
	@# test if "../bcmp --limit -10 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in decimal on argument for numeric option --limit with space
	@(\
		CMD="$(TARGET) --limit -10 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_14.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_50:
	@# test if "../bcmp --limit -0xa0 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in hexadecimal on argument for numeric option --limit with space
	@(\
		CMD="$(TARGET) --limit -0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_15.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

# TODO test files bigger than 54536 equal and different skipping more than 65536 byes in a file bigger than that equal and different

# options and argument error tests (dependent on getopt behavior put here to clarify its behavior)
test_51:
	@# test if "../bcmp --skip-10 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in decimal on argument for numeric option --skip without space
	@# long options need an space before argument
	@(\
		CMD="$(TARGET) --skip-10 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_16.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_52:
	@# test if "../bcmp --skip-0xa0 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in hexadecimal on argument for numeric option --skip without space
	@# long options need an space before argument
	@(\
		CMD="$(TARGET) --skip-0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_17.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_53:
	@# test if "../bcmp -s file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# -s requires a numerical argument it takes anything after it and tries to convert
	@(\
		CMD="$(TARGET) -s file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_18.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_54:
	@# test if "../bcmp --limit-10 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in decimal on argument for numeric option --limit without space
	@# long options need an space before argument
	@(\
		CMD="$(TARGET) --limit-10 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_19.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_55:
	@# test if "../bcmp --limit-0xa0 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in hexadecimal on argument for numeric option --limit without space
	@# long options need an space before argument
	@(\
		CMD="$(TARGET) --limit-0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_20.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_56:
	@# test if "../bcmp -n file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# -n requires a numerical argument it takes anything after it and tries to convert
	@(\
		CMD="$(TARGET) -n file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_18.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_57:
	@# test if "../bcmp file_01.bin file_02.bin -n" returns 2 and error message in stderr,
	@# -n option requires a numerical argument
	@(\
		CMD="$(TARGET) file_01.bin file_02.bin -n"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_21.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_58:
	@# test if "../bcmp file_01.bin file_02.bin --limit" returns 2 and error message in stderr,
	@# --limit option requires a numerical argument
	@(\
		CMD="$(TARGET) file_01.bin file_02.bin --limit"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_22.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_59:
	@# test if "../bcmp file_01.bin file_02.bin -s" returns 2 and error message in stderr,
	@# -s option requires a numerical argument
	@(\
		CMD="$(TARGET) file_01.bin file_02.bin -s"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_23.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_60:
	@# test if "../bcmp file_01.bin file_02.bin --skip" returns 2 and error message in stderr,
	@# --skip option requires a numerical argument
	@(\
		CMD="$(TARGET) file_01.bin file_02.bin --skip"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_24.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

# options and argument behavior (dependent on getopt behavior put here to clarify its behavior)
test_61:
	@# test if "../bcmp -var" return 0 and version text in stdout
	@# if the first letter of a one letter option with no argument matches one expected it is used and others ignored
	@(\
		CMD="$(TARGET) -var"; \
		STDOUT=$$($$CMD 2> /dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		# ignore variable parts of the output message \
		echo "$$STDOUT" | ( head -c 9; tail -c +3; ) | ( head -c 306; tail -c +8) | diff -q - message_version.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_62:
	@# test if "../bcmp -vh" return 0 and version text in stdout
	@# if the first letter of a one letter option with no argument matches one expected it is used and others ignored
	@(\
		CMD="$(TARGET) -vh"; \
		STDOUT=$$($$CMD 2> /dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		# ignore variable parts of the output message \
		echo "$$STDOUT" | ( head -c 9; tail -c +3; ) | ( head -c 306; tail -c +8) | diff -q - message_version.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_63:
	@# test if "../bcmp -hv" return 0 and help text in stdout
	@# if the first letter of a one letter option with no argument matches one expectedit is used and others ignored
	@(\
		CMD="$(TARGET) -hv"; \
		STDOUT=$$($$CMD 2> /dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_help.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_64:
	@# test if "../bcmp -not" return 2 and error message in stderr,
	@# if the first letter of a one letter option with no and matches one expected it is used and the rest is used as argument
	@(\
		CMD="$(TARGET) -not"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_25.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_65:
	@# test if "../bcmp --skip0xa0 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# long name options with arguments need an space separating both
	@(\
		CMD="$(TARGET) --skip0xa0"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_26.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_66:
	@# test if "../bcmp --helpa" returns 2 and error message and help text in stderr,
	@# long option names must match completely
	@(\
		CMD="$(TARGET) --helpa"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_27.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_67:
	@# test if "../bcmp -qs4097 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# one letter options can be fused in one, here -q -s4097
	@(\
		CMD="$(TARGET) -qs4097 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_28.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)


# tests for files bigger than the buffer size
test_68:
	@# test if "../bcmp file_13.bin file_14.bin" returns 0 and message in stdout,
	@# files are equal
	@# files are bigger than 65535 bytes (the size of the buffer)
	@(\
		CMD="$(TARGET) file_13.bin file_14.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_01.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_69:
	@# test if "../bcmp -n0 file_13.bin file_15.bin" returns 1 and message in stdout,
	@# files are different
	@# files are bigger than 65536 bytes (the size of the buffer)
	@(\
		CMD="$(TARGET) -n0 file_13.bin file_15.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_30.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_70:
	@# test if "../bcmp -n0 file_15.bin file_13.bin" returns 1 and message in stdout,
	@# files are different
	@# files are bigger than 65536 bytes (the size of the buffer)
	@(\
		CMD="$(TARGET) -n0 file_15.bin file_13.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_31.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_71:
	@# test if "../bcmp -s131500 -n0 file_13.bin file_14.bin" returns 0 and message in stdout,
	@# files are equal
	@# skipping more then 65536 bytes
	@# files are bigger than 65536 bytes (the size of the buffer)
	@(\
		CMD="$(TARGET) -n0 file_13.bin file_14.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_01.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_72:
	@# test if "../bcmp -s131500 -n0 file_13.bin file_15.bin" returns 1 and message in stdout,
	@# files are different
	@# skipping more then 65536 bytes
	@# files are bigger than 65536 bytes (the size of the buffer)
	@(\
		CMD="$(TARGET) -s131500 -n0 file_13.bin file_15.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_32.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_73:
	@# test if "../bcmp -s131500 -n0 file_15.bin file_13.bin" returns 1 and message in stdout,
	@# files are different
	@# skipping more then 65536 bytes
	@# files are bigger than 65536 bytes (the size of the buffer)
	@(\
		CMD="$(TARGET) -s131500 -n0 file_15.bin file_13.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_33.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

# big files tests
test_74:
	@# test if "../bcmp --skip 4800000000 file_5gb.bin file_5gb.bin" returns 0 and message in stdout,
	@# files bigger than 2Gb
	@# files are the same
	@(\
		FS_TYPE=$$(stat -f -c %T . 2>/dev/null || echo "unknown"); \
		printf "$@ "; \
		if [ "$$FS_TYPE" = "ext2/ext3" ] || [ "$$FS_TYPE" = "ext4" ] || [ "$$FS_TYPE" = "xfs" ] || [ "$$FS_TYPE" = "apfs" ]; then \
			rm -f $(TMPDIR)/file_5gb.bin; \
			truncate -s 5G $(TMPDIR)/file_5gb.bin; \
			CMD="$(TARGET) --skip 4800000000 $(TMPDIR)/file_5gb.bin $(TMPDIR)/file_5gb.bin"; \
			STDOUT=$$($$CMD >&1 2>/dev/null); \
			EXIT_VAL=$$?; \
			printf "item 1: "; \
			if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
			\
			echo "$$STDOUT" | diff -q - message_01.txt > /dev/null 2>&1; \
			EXIT_VAL=$$?; \
			printf "$@ item 2: "; \
			if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
			rm -f $(TMPDIR)/file_5gb.bin; \
			printf "\n"; \
		else \
			printf "$(YELLOW)Skipped$(RESET): file system '$$FS_TYPE' may not support sparse files.\n"; \
			# necessary to count the two items skipped \
			printf "Skipped\nSkipped\n" >> $(LOG); \
		fi; \
	)

test_75:
	@# test if "../bcmp --skip 4800000000 file_5gb_1.bin file_5gb_2.bin" returns 0 and message in stdout,
	@# files bigger than 2Gb
	@# files are different
	@(\
		FS_TYPE=$$(stat -f -c %T . 2>/dev/null || echo "unknown"); \
		printf "$@ "; \
		if [ "$$FS_TYPE" = "ext2/ext3" ] || [ "$$FS_TYPE" = "ext4" ] || [ "$$FS_TYPE" = "xfs" ] || [ "$$FS_TYPE" = "apfs" ]; then \
			rm -f $(TMPDIR)/file_5gb_1.bin; \
			rm -f $(TMPDIR)/file_5gb_2.bin; \
			truncate -s 5G $(TMPDIR)/file_5gb_1.bin; \
			printf '\xC\xB\xA' >> $(TMPDIR)/file_5gb_1.bin; \
			truncate -s 5G $(TMPDIR)/file_5gb_2.bin; \
			printf '\xA\xB\xC' >> $(TMPDIR)/file_5gb_2.bin; \
			CMD="$(TARGET) --skip 4800000000 $(TMPDIR)/file_5gb_1.bin $(TMPDIR)/file_5gb_2.bin"; \
			STDOUT=$$($$CMD >&1 2>/dev/null); \
			EXIT_VAL=$$?; \
			printf "item 1: "; \
			if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
			\
			echo "$$STDOUT" | diff -q - message_29.txt > /dev/null 2>&1; \
			EXIT_VAL=$$?; \
			printf "$@ item 2: "; \
			if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
			rm -f $(TMPDIR)/file_5gb_1.bin; \
			rm -f $(TMPDIR)/file_5gb_2.bin; \
			printf "\n"; \
		else \
			printf "$(YELLOW)Skipped$(RESET): file system '$$FS_TYPE' may not support sparse files.\n"; \
			# necessary to count the two itens skipped \
			printf "Skipped\nSkipped\n" >> $(LOG); \
		fi; \
	)

test_76:
	@# test if "../bcmp -n0x8000000000000000 file_01.bin file_03.bin" returns 2 and message in stderr,
	@# passing a parameter that overflows off_t used internally
	@(\
		CMD="$(TARGET) -n0x8000000000000000 file_01.bin file_03.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_34.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_77:
	@# test if "../bcmp -n0x10000000000000000 file_01.bin file_03.bin" returns 2 and message in stderr,
	@# passing a parameter that overflows unsigned long long for parameters
	@(\
		CMD="$(TARGET) -n0x10000000000000000 file_01.bin file_03.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_35.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_78:
	@# test if "../bcmp -n0x7FFFFFFFFFFFFFFF file_01.bin file_03.bin" returns 1 and message in stdout,
	@# passing maximum value possible for off_t used internally
	@(\
		CMD="$(TARGET) -n0x7FFFFFFFFFFFFFFF file_01.bin file_03.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_02.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_79:
	@# test if "../bcmp -n0xFFFFFFFFFFFFFFFF file_01.bin file_03.bin" returns 1 and message in stdout,
	@# passing maximum value possible for a parameter
	@# but this value overflows off_t used internally giving the correspondent error 
	@(\
		CMD="$(TARGET) -n0xFFFFFFFFFFFFFFFF file_01.bin file_03.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_36.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

# tests receiving file from stdin
test_80:
	@# test if "cat file_01.bin | ../bcmp - file_02.bin" return 0 and message in stdout,
	@# equal files
	@# file is received from stdin on first parameter
	@(\
		CMD="$(TARGET) - file_02.bin"; \
		STDOUT=$$(cat file_01.bin | $$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_01.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_81:
	@# test if "cat file_02.bin | ../bcmp file_01.bin -" return 0 and message in stdout,
	@# equal files
	@# file is received from stdin on second parameter
	@(\
		CMD="$(TARGET) file_01.bin -"; \
		STDOUT=$$(cat file_02.bin | $$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_01.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_82:
	@# test if "cat file_01.bin | ../bcmp - file_03.bin" returns 1 and message in stdout,
	@# files differ
	@# file is received from stdin on first parameter
	@(\
		CMD="$(TARGET) - file_03.bin"; \
		STDOUT=$$(cat file_01.bin | $$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_02.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_83:
	@# test if "cat file_03.bin | ../bcmp file_01.bin -" returns 1 and message in stdout,
	@# files differ
	@# file is received from stdin on second parameter
	@(\
		CMD="$(TARGET) file_01.bin -"; \
		STDOUT=$$(cat file_03.bin | $$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_02.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_84:
	@# test if "cat file_01.bin | ../bcmp -s0x019A - file_03.bin" returns 1 and message in stdout,
	@# files differ
	@# file is received from stdin on first parameter
	@# skips the first difference
	@(\
		CMD="$(TARGET) -s0x019A - file_03.bin"; \
		STDOUT=$$(cat file_01.bin | $$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_37.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_85:
	@# test if "cat file_03.bin | ../bcmp -s0x019A file_01.bin -" returns 1 and message in stdout,
	@# files differ
	@# file is received from stdin on second parameter
	@# skips the first difference
	@(\
		CMD="$(TARGET) -s0x019A file_01.bin -"; \
		STDOUT=$$(cat file_03.bin | $$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_37.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_86:
	@# test if "cat file_01.bin | ../bcmp -s4097 - file_03.bin" returns 2 and error message in stderr,
	@# files differ
	@# file is received from stdin on first parameter
	@# skips past the end of stream
	@(\
		CMD="$(TARGET) -s4097 - file_03.bin"; \
		STDERR=$$(cat file_01.bin | $$CMD 2>&1 >/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_38.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_87:
	@# test if "cat file_03.bin | ../bcmp -s4097 file_01.bin -" returns 2 and message in stderr,
	@# files differ
	@# file is received from stdin on second parameter
	@# skips past the end of file
	@(\
		CMD="$(TARGET) -s4097 file_01.bin -"; \
		STDERR=$$(cat file_03.bin | $$CMD 2>&1 >/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_39.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_88:
	@# test if "head -c 4095 file_01.bin | ../bcmp -s4096 - file_03.bin" returns 2 and message in stderr,
	@# files differ
	@# file is received from stdin on second parameter
	@# skips past the end of file
	@(\
		CMD="$(TARGET) -s4096 - file_03.bin"; \
		STDERR=$$(head -c 4095 file_01.bin | $$CMD 2>&1 >/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_40.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_89:
	@# test if "head -c 4095 file_02.bin | ../bcmp -s4096 file_01.bin -" returns 2 and message in stderr,
	@# files differ
	@# file is received from stdin on second parameter
	@# skips past the end of file
	@(\
		CMD="$(TARGET) -s4096 file_01.bin -"; \
		STDERR=$$(head -c 4095 file_03.bin | $$CMD 2>&1 >/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_40.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_90:
	@# test if "cat file_03.bin | ../bcmp - -" returns 2 and message in stderr,
	@# file is received from stdin on second parameter
	@# skips past the end of file
	@(\
		CMD="$(TARGET) - -"; \
		STDERR=$$(cat file_03.bin | $$CMD 2>&1 >/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDERR" | diff -q - message_41.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

# tests for -S, --silent options suppressing messages in stdout
test_91:
	@# test if "../bcmp --silent --help" return 0 and help text in stdout,
	@# --silent does not suppress --help
	@(\
		CMD="$(TARGET) --silent --help"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_help.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_92:
	@# test if "../bcmp -S -h" returns 0 and help text in stdout,
	@# -S does not suppress -h,
	@# -S and -h are the same as --silent and --help
	@(\
		CMD="$(TARGET) -S -h"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		echo "$$STDOUT" | diff -q - message_help.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)


test_93:
	@# test if "../bcmp -S file_01.bin file_02.bin" returns 0 and no message in stdout, 
	@# equal files,
	@# silent mode,
	@# suppress "Files are equal." message
	@(\
		CMD="$(TARGET) -S file_01.bin file_02.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDOUT" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_94:
	@# test if "../bcmp -S file_01.bin file_03.bin" return 1 and no message in stdout,
	@# files differ,
	@# silent mode,
	@# suppress showing different bytes
	@(\
		CMD="$(TARGET) -S file_01.bin file_03.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDOUT" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_95:
	@# test if "../bcmp -S file_01.bin file_04.bin" returns 1 and no message in stdout, 
	@# files with many differences,
	@# silent mode,
	@# stops by default after the first 100 differences (no way to test it as it shows none)
	@(\
		CMD="$(TARGET) -S file_01.bin file_04.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDOUT" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_96:
	@# test if "../bcmp -S -n10 file_01.bin file_04.bin" returns 1 and no message in stdout, 
	@# files with many differences,
	@# silent mode,
	@# stops by request after the first 10 differences (no way to test it as it shows none)
	@(\
		CMD="$(TARGET) -S -n10 file_01.bin file_04.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDOUT" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_97:
	@# test if "../bcmp -S -n0 file_01.bin file_04.bin" returns 1 and no messages in stdout,
	@# files with many differences,
	@# silent mode, 
	@# search bye request all differences (no way to test it as it shows none), 
	@(\
		CMD="$(TARGET) -S -n10 file_01.bin file_04.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDOUT" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_98:
	@# test if "../bcmp -S file_01.bin file_05.bin" return 1 and no message in stdout,
	@# files of different sizes,
	@# files different before the end of the smaller one,
	@# silent mode
	@(\
		CMD="$(TARGET) -S file_01.bin file_05.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDOUT" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)


test_99:
	@# test if "../bcmp -S file_01.bin file_06.bin" return 1 and no message in stdout,
	@# files of different sizes,
	@# files equal until the last byte of the smaller one,
	@# silent mode
	@(\
		CMD="$(TARGET) -S file_01.bin file_06.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDOUT" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

# tests for -S, --silent options suppressing error messages in stderr
test_100:
	@# test if "../bcmp -S" with no parameters returns 2 and and no message at stderr,
	@# lack of required arguments is an error,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_101:
	@# test if "../bcmp -S file_00.bin file_01.bin" returns 2 and no error message in stderr,
	@# first argument with non existent file
	@# silent mode shows no error message
	@(\
		rm -f file_00.bin; \
		CMD="$(TARGET) -S file_00.bin file_01.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_102:
	@# test if "../bcmp -S file_01.bin file_00.bin" returns 2 and no error message in stderr,
	@# second argument with non existent file,
	@# silent mode shows no error message
	@(\
		rm -f file_00.bin; \
		CMD="$(TARGET) -S file_00.bin file_01.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_103:
	@# test if "../bcmp -S file_00.bin file_00.bin" returns 2 and no error message in stderr,
	@# both arguments with non existent files,
	@# silent mode shows no error message
	@(\
		rm -f file_00.bin; \
		CMD="$(TARGET) -S file_00.bin file_01.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_104:
	@# test if "../bcmp -S  $(TMPDIR)/file_09.bin file_01.bin" returns 2 and no error message in stderr,
	@# first argument with file without read permission,
	@# silent mode shows no error message,
	@# using $(TMPDIR) because some daemons like Dropbox restore removed read permissions
	@(\
		rm -f $(TMPDIR)/file_09.bin; \
		cp file_09.bin $(TMPDIR); \
		chmod 224 $(TMPDIR)/file_09.bin; \
		CMD="$(TARGET) -S $(TMPDIR)/file_09.bin file_01.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_105:
	@# test if "../bcmp -S file_01.bin $(TMPDIR)/file_09.bin " returns 2 and no error message in stderr,
	@# second argument with file without read permission,
	@# silent mode shows no error message,
	@# using $(TMPDIR) because some daemons like Dropbox restore removed read permissions
	@(\
		rm -f $(TMPDIR)/file_09.bin; \
		cp file_09.bin $(TMPDIR); \
		chmod 224 $(TMPDIR)/file_09.bin; \
		CMD="$(TARGET) -S file_01.bin $(TMPDIR)/file_09.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_106:
	@# test if "../bcmp -S $(TMPDIR)/file_09.bin $(TMPDIR)/file_09.bin" returns 2 and no error message in stderr,
	@# both arguments with files without read permission,
	@# silent mode shows no error message,
	@# using $(TMPDIR) because some daemons like Dropbox restore removed read permissions
	@(\
		rm -f $(TMPDIR)/file_09.bin; \
		cp file_09.bin $(TMPDIR); \
		chmod 224 $(TMPDIR)/file_09.bin; \
		CMD="$(TARGET) -S file_01.bin $(TMPDIR)/file_09.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_107:
	@# test if "../bcmp -S -s4 file_07.bin file_01.bin" returns 2 and no error message in stderr,
	@# skips past the end of first file,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S -s4 file_07.bin file_01.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_108:
	@# test if "../bcmp -S -s4 file_01.bin file_07.bin" returns 2 and no error message in stderr,
	@# skips past the end of second file,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S -s4 file_01.bin file_07.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_109:
	@# test if "../bcmp -S -s4 file_07.bin file_07.bin" returns 2 and no error message in stderr,
	@# skips past the end of both files,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S -s4 file_07.bin file_07.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_110:
	@# test if "../bcmp -S -s-10 file_01.bin file_02.bin" returns 2 and no error message in stderr,
	@# negative value specified in decimal on argument for numeric option -s without space,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S -s-10 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_111:
	@# test if "../bcmp -S -s -10 file_01.bin file_02.bin" returns 2 and no error message in stderr,
	@# negative value specified in decimal on argument for numeric option -s with space,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S -s -10 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_112:
	@# test if "../bcmp -S -s-0xa0 file_01.bin file_02.bin" returns 2 and no error message in stderr,
	@# negative value specified in hexadecimal on argument for numeric option -s without space,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S -s-0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_113:
	@# test if "../bcmp -S -s -0xa0 file_01.bin file_02.bin" returns 2 and no error message in stderr,
	@# negative value specified in hexadecimal on argument for numeric option -s with space,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S -s -0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)


test_114:
	@# test if "../bcmp -S --skip -10 file_01.bin file_02.bin" returns 2 and no error message in stderr,
	@# negative value specified in decimal on argument for numeric option --skip with space,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S --skip -10 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_115:
	@# test if "../bcmp -S --skip -0xa0 file_01.bin file_02.bin" returns 2 and no error message in stderr,
	@# negative value specified in hexadecimal on argument for numeric option --skip with space,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S --skip -0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_116:
	@# test if "../bcmp -S -n-10 file_01.bin file_02.bin" returns 2 and no error message in stderr,
	@# negative value specified in decimal on argument for numeric option -n without space,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S -n-10 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_117:
	@# test if "../bcmp -S -n -10 file_01.bin file_02.bin" returns 2 and no error message in stderr,
	@# negative value specified in decimal on argument for numeric option -n with space,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S -n -10 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_118:
	@# test if "../bcmp -S -n-0xa0 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in hexadecimal on argument for numeric option -n without space,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S -n-0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_119:
	@# test if "../bcmp -S -n -0xa0 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in hexadecimal on argument for numeric option -n with space,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S -n -0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_120:
	@# test if "../bcmp -S --limit -10 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in decimal on argument for numeric option --limit with space,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S --limit -10 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

test_121:
	@# test if "../bcmp -S --limit -0xa0 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in hexadecimal on argument for numeric option --limit with space,
	@# silent mode shows no error message
	@(\
		CMD="$(TARGET) -S --limit -0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		\
		printf "$@ item 2: "; \
		if [ -z "$$STDERR" ]; then printf "$(GREEN)Pass$(RESET).\n" | tee -a $(LOG); else printf "$(RED)Fail$(RESET).\n" | tee -a $(LOG); fi; \
		printf "\n"; \
	)

summary:
	@(\
		if [ -f "$(LOG)" ]; then \
			TOTAL=$$(cat $(LOG) | wc -l ); \
			PASSED=$$(cat $(LOG) | grep Pass | wc -l); \
			FAILS=$$(cat $(LOG) | grep Fail | wc -l); \
			SKIPS=$$(cat $(LOG) | grep Skipped | wc -l); \
			\
			printf "\n"; \
			printf "Results\n\n"; \
			printf "Total tests: $$TOTAL\n"; \
			printf "Passed: $$PASSED\n"; \
			printf "Failed: $$FAILS\n"; \
			printf "Skipped: $$SKIPS\n"; \
			\
			rm -f $(LOG); \
		else\
			printf "'summary' target can not be called directly.\n"; \
		fi; \
	)