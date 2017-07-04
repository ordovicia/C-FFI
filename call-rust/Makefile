RUST_SRCS=$(shell find src -name "*.rs")
RUST_LIB=cpp_call_rust
CXX_SRCS=$(shell ls *.cpp)
PROG=main

RUST_BUILD=release
CARGO_FLAGS=--$(RUST_BUILD)
CXX=/usr/local/bin/g++-7
CXX_FLAGS=-std=c++14 -Wall -Wextra -Wconversion

.PHONY: rust clean

$(PROG): $(CXX_SRCS) rust
	$(CXX) $(CXX_FLAGS) $(CXX_SRCS) target/$(RUST_BUILD)/lib$(RUST_LIB).dylib -o $(PROG)

rust: $(RUST_SRCS)
	cargo build $(CARGO_FLAGS)

clean:
	rm $(PROG)
	cargo clean
