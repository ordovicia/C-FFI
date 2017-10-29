OS=$(shell uname)

# Rust
RUST_SRCS=$(shell find src -name "*.rs")
RUST_LIBNAME=cpp_call_rust
RUST_BUILD=debug
CARGO_FLAGS=

ifeq ($(OS),Linux)
	RUST_DYLIB_EXT=so
else ifeq ($(OS),Darwin)
	RUST_DYLIB_EXT=dylib
else ifeq ($(OS),Windows_NT)
	RUST_DYLIB_EXT=dll
else
	@echo "Couldn't detect OS"
endif

RUST_DYLIB=target/$(RUST_BUILD)/lib$(RUST_LIBNAME).$(RUST_DYLIB_EXT)

# C++
CXX_SRCS=$(shell ls *.cpp)
CXX_FLAGS=-std=c++14 -Wall -Wextra -Wconversion

PROG=main

.PHONY: rust clean

$(PROG): $(CXX_SRCS) rust
	$(CXX) $(CXX_FLAGS) $(CXX_SRCS) $(RUST_DYLIB) -o $(PROG)

rust: $(RUST_SRCS)
	cargo build $(CARGO_FLAGS)

clean:
	rm $(PROG)
	cargo clean
