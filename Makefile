CC = clang
CCFLAGS = -std=c99 -Iinclude -g
CCWARNINGS = -Wall -Wextra -Wpedantic -Wno-declaration-after-statement -Wno-pointer-arith
CFILES = $(shell find . -type f -name "*.c")
OUTFILE = ./list

all:
	$(CC) $(CCFLAGS) $(CCWARNINGS) $(CFILES) -o $(OUTFILE)
