RS_SRCS=$(shell ls src/*)
C_SRCS=$(shell ls *.c)
PROG=main

RS_BUILD=release
CARGO_FLAGS=--$(RS_BUILD)
CFLAGS=-std=c11 -Wall -Wextra -Wconversion

main: $(RS_SRCS) $(C_SRCS)
	cargo build $(CARGO_FLAGS)
	gcc $(CFLAGS) $(C_SRCS) target/$(RS_BUILD)/libccr.dylib -o $(PROG)

.PHONY: clean

clean:
	rm $(PROG)
	cargo clean
