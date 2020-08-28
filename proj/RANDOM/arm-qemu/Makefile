#CROSS_PREFIX=aarch64-linux-gnu-
CROSS_PREFIX=arm-none-eabi-

.PHONY: all clean run

all: test.elf

startup.o: startup.s
	$(CROSS_PREFIX)as -g -c $< -o $@

test.o: test.c
	$(CROSS_PREFIX)gcc -c $< -o $@

test.elf: startup.o test.ld
	$(CROSS_PREFIX)ld -Ttest.ld startup.o -o $@

run:
	qemu-system-arm -M virt -nographic -kernel test.elf -serial mon:stdio

clean:
	rm -f test.elf startup.o test.o
