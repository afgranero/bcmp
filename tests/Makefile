SHELL=/bin/bash

TARGET = ../bcmp

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
			test_67


RED   = \033[31m
GREEN = \033[32m
RESET = \033[0m

tests: $(ALL_TESTS)

# version tests
test_01:
	@# test if "../bcmp --version" return 0 and version text in stdout
	@(\
		CMD="$(TARGET) --version"; \
		STDOUT=$$($$CMD 2> /dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_version.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_version.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

# help tests
test_03:
	@# test if "../bcmp" with no paramters returns 2 and help text in stderr,
	@# lack of required arguments is an error and shows help text
	@(\
		CMD="$(TARGET)"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_help.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_04:
	@# test if "../bcmp --help" returns 0 and help text in stdout,
	@# when resquesting help text is not treated as an error
	@(\
		CMD="$(TARGET) --help"; \
		STDOUT=$$($$CMD 2> /dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_help.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_05:
	@# test if "../bcmp --quiet --help" return 0 and help text in stdout,
	@# --quiet does not supress --help
	@(\
		CMD="$(TARGET) --quiet --help"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_help.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_06:
	@# test if "../bcmp -q -h" returns 0 and help text in stdout,
	@# -q  does not supress -h,
	@# -q and -h are the same as --quiet and --help
	@(\
		CMD="$(TARGET) -q -h"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_help.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_01.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_01.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_01.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_01.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_11:
	@# test if "../bcmp -q file_01.bin file_02.bin" returns 0 and no message 
	@# equal files 
	@# quiet
	@(\
		CMD="$(TARGET) -q file_01.bin file_02.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		printf "$@ item 2: "; \
		if [ -z $$STDOUT ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_02.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_13:
	@# test if "../bcmp file_07.bin file_08.bin" return 1 and message in stdout,
	@# files differ,
	@# files with 0x00 in the begining
	@(\
		CMD="$(TARGET) file_07.bin file_08.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_09.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		# this case documents that message_09.txt has 2 lines and so all differences are shown (this will matter in next test)... \
		# ... this is easier than check STDOUT number of lines beleive me \
		LINES_COUNT=$$(cat message_09.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "2" ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_14:
	@# test if "../bcmp -q file_01.bin file_03.bin" return 1 and no message,
	@# files differ,
	@# quiet mode
	@(\
		CMD="$(TARGET) -q file_01.bin file_03.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		printf "$@ item 2: "; \
		if [ -z $$STDOUT ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

# different files tests with skip
test_15:
	@# test if "../bcmp -s1 file_07.bin file_08.bin" return 1 and message in stdout,
	@# files differ,
	@# files with 0x00 in the begining,
	@# skipping first byte that is equal in both, no change in output compared with no skip
	@(\
		CMD="$(TARGET) file_07.bin file_08.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_09.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		# this case documents that message_09.txt has 2 lines and so all differences are still shown (like in previous test) ... \
		# ... this is easier than check STDOUT number of lines beleive me \
		LINES_COUNT=$$(cat message_09.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "2" ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_16:
	@# test if "../bcmp -s2 file_07.bin file_08.bin" return 1 and message in stdout,
	@# files differ,
	@# files with 0x00 in the begining,
	@# skipping two bytes, so output shows one difference less
	@(\
		CMD="$(TARGET) -s2 file_07.bin file_08.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_10.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		# this case documents that message_10.txt has 1 line and so one difference less is shown) ... \
		# ... this is easier than check STDOUT number of lines beleive me \
		LINES_COUNT=$$(cat message_10.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "1" ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_17:
	@# test if "../bcmp --skip 2 file_07.bin file_08.bin" return 1 and message in stdout,
	@# --skip is the same as -s,
	@# files differ,
	@# files with 0x00 in the begining,
	@# skipping two first bytes, so output shows one difference less
	@(\
		CMD="$(TARGET) --skip 2 file_07.bin file_08.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_10.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		# this case documents that message_10.txt has 1 line and so one difference less is shown) ... \
		# ... this is easier than check STDOUT number of lines beleive me \
		LINES_COUNT=$$(cat message_10.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "1" ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_18:
	@# test if "../bcmp -s3 file_07.bin file_08.bin" returns 1 and messages in stdout,
	@# files differ,
	@# files with 0x00 in the begining, 
	@# skipping all bytes, skips all differences, making files being considered equal
	@(\
		CMD="$(TARGET) -s3 file_07.bin file_08.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_01.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_03.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		# this case documents that message_03.txt has 101 lines and so the limit is correct (100 outputs and one message) ... \
		# ... this is easier than check STDOUT number of lines beleive me \
		LINES_COUNT=$$(cat message_03.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "101" ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_04.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		# this case documents that message_04.txt has 11 lines and so the limit is correct (100 outputs and one message) ... \
		# ... this is easier than check STDOUT number of lines beleive me \
		LINES_COUNT=$$(cat message_04.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "11" ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_07.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		# this case documents that message_07.txt has 4075 lines and so the limit is correct (100 outputs and one message) ... \
		# ... this is easier than check STDOUT number of lines beleive me \
		LINES_COUNT=$$(cat message_07.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "4075" ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

# many differences quiet tests
test_22:
	@# test if "../bcmp -q file_01.bin file_04.bin" returns 1 and no messages, 
	@# files with many differences,
	@# quiet mode
	@# stops by default after the first 100 differences (no way to test it as it shows none)
	@(\
		CMD="$(TARGET) -q file_01.bin file_04.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		printf "$@ item 2: "; \
		if [ -z $$STDOUT ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_23:
	@# test if "../bcmp -q -n10 file_01.bin file_04.bin" returns 1 and message in stdout 
	@# files with many differences,
	@# quiet mode
	@# stops by request after the first 10 differences (no way to test it as it shows none)
	@(\
		CMD="$(TARGET) -q -n10 file_01.bin file_04.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		printf "$@ item 2: "; \
		if [ -z $$STDOUT ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_24:
	@# test if "../bcmp -q -n0 file_01.bin file_04.bin" returns 1 and no messages,
	@# iles with many differences,
	@# quiet mode, 
	@# search bye request all differences (no way to test it as it shows none), 
	@(\
		CMD="$(TARGET) -q -n10 file_01.bin file_04.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		printf "$@ item 2: "; \
		if [ -z $$STDOUT ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_05.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		# this case documents that message_05.txt has 2 lines and so the limit is correct (100 outputs and one message) ... \
		# ... this is easier than check STDOUT number of lines beleive me \
		LINES_COUNT=$$(cat message_05.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "2" ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_26:
	@# test if "../bcmp -s0x5ed file_01.bin file_05.bin" returns 1 and messages in stdout,
	@# files of different sizes,
	@# skipping number of bytes specified in hexadecimal,
	@# files with differences before the end of the smaller one,
	@# it skips all differences but files are of differente sizes are different
	@(\
		CMD="$(TARGET)  -s0x5ed file_01.bin file_05.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_08.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		# this case documents that message_08.txt has 1 line and so the limit is correct (100 outputs and one message) ... \
		# ... this is easier than check STDOUT number of lines beleive me \
		LINES_COUNT=$$(cat message_08.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "1" ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_06.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		# this case documents that message_06.txt has 1 line and so the limit is correct (100 outputs and one message) ... \
		# ... this is easier than check STDOUT number of lines beleive me \
		LINES_COUNT=$$(cat message_06.txt | wc -l); \
		printf "$@ item 3: "; \
		if [ $$LINES_COUNT -eq "1" ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)


# files of different sizes quiet tests
test_28:
	@# test if "../bcmp -q file_01.bin file_05.bin" return 1 and no message,
	@# files of different sizes,
	@# files different before the end of the smaller one,
	@# quiet mode
	@(\
		CMD="$(TARGET) -q file_01.bin file_05.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		printf "$@ item 2: "; \
		if [ -z $$STDOUT ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)


test_29:
	@# test if "../bcmp -q file_01.bin file_06.bin" return 1 and no message,
	@# files of different size,
	@# files equal until the last byte os the smaller one,
	@# quiet mode
	@(\
		CMD="$(TARGET) -q file_01.bin file_06.bin"; \
		STDOUT=$$($$CMD >&1 2>/dev/null); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 1 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		printf "$@ item 2: "; \
		if [ -z $$STDOUT ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_11.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_11.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_11.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_33:
	@# test if "../bcmp /tmp/file_09.bin file_01.bin" returns 2 and error message in stderr,
	@# first argument with file without read permission
	@# using /tmp because some deamons like Dropbox restore removed read permissions
	@(\
		rm -f /tmp/file_09.bin; \
		cp file_09.bin /tmp; \
		chmod 224 /tmp/file_09.bin; \
		CMD="$(TARGET) /tmp/file_09.bin file_01.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_12.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		rm -f /tmp/file_09.bin; \
		printf "\n"; \
	)

test_34:
	@# test if "../bcmp file_01.bin /tmp/file_09.bin" returns 2 and error message in stderr,
	@# second argument with file without read permission
	@# using /tmp because some deamons like Dropbox restore removed read permissions
	@(\
		rm -f /tmp/file_09.bin; \
		cp file_09.bin /tmp; \
		chmod 224 /tmp/file_09.bin; \
		CMD="$(TARGET) file_01.bin /tmp/file_09.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_12.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		rm -f /tmp/file_09.bin; \
		printf "\n"; \
	)

test_35:
	@# test if "../bcmp /tmp/file_09.bin /tmp/file_09.bin" returns 2 and error message in stderr,
	@# both arguments with files without read permission
	@# using /tmp because some deamons like Dropbox restore removed read permissions
	@(\
		rm -f /tmp/file_09.bin; \
		cp file_09.bin /tmp; \
		chmod 224 /tmp/file_09.bin; \
		CMD="$(TARGET) /tmp/file_09.bin /tmp/file_09.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_12.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		rm -f /tmp/file_09.bin; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_13.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_13.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_38:
	@# test if "../bcmp -s4 ile_07.bin file_07.bin " returns 2 and error message in stderr,
	@# skips past the end of both files
	@(\
		CMD="$(TARGET) -s4 file_01.bin file_07.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_13.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_14.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_14.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_15.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_15.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_14.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_44:
	@# test if "../bcmp --skip -0xa0 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in hexdecimal on argument for numeric option --skip with space
	@(\
		CMD="$(TARGET) --skip -0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_15.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_14.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_14.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_15.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_15.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_14.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_50:
	@# test if "../bcmp --limit -0xa0 file_01.bin file_02.bin" returns 2 and error message in stderr,
	@# negative value specified in hexdecimal on argument for numeric option --limit with space
	@(\
		CMD="$(TARGET) --limit -0xa0 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_15.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_16.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_17.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_18.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_19.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_20.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_18.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_21.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_22.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_23.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_24.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_version.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_version.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDOUT" | diff -q - message_help.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_25.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
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
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_26.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_66:
	@# test if "../bcmp --helpa" returns 2 and error messaage and help text in stderr
	@# long option names must match completelly
	@(\
		CMD="$(TARGET) --helpa"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_27.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)

test_67:
	@# test if "../bcmp -qs4097 file_01.bin file_02.bin" returns 2 and error messaage in stderr
	@# one letter options can be fused in one, here -q -s4097
	@(\
		CMD="$(TARGET) -qs4097 file_01.bin file_02.bin"; \
		STDERR=$$($$CMD 2>&1 >/dev/null ); \
		EXIT_VAL=$$?; \
		printf "$@ item 1: "; \
		if [ $$EXIT_VAL -eq 2 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		\
		echo "$$STDERR" | diff -q - message_28.txt > /dev/null 2>&1; \
		EXIT_VAL=$$?; \
		printf "$@ item 2: "; \
		if [ $$EXIT_VAL -eq 0 ]; then printf "$(GREEN)Pass$(RESET).\n"; else printf "$(RED)Fail$(RESET).\n"; fi; \
		printf "\n"; \
	)