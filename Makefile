# Makefile for JamesM's kernel tutorials.
# The C and C++ rules are already setup by default.
# The only one that needs changing is the assembler
# rule, as we use nasm instead of GNU as.

SOURCES=src/boot.o src/main.o

CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-Tlink.ld -m elf_i386
ASFLAGS=-felf

all: $(SOURCES) link clean-src

clean:
	rm bin/kernel
clean-src:
	rm src/*.o
link:
	mkdir -p bin
	ld $(LDFLAGS) -o bin/kernel $(SOURCES)

.s.o:
	nasm $(ASFLAGS) $<
