ENTRY(_start)
MEMORY
{
	rom (rx): ORIGIN = 0x0, LENGTH = 0x4000
	ram (rwx): ORIGIN = 0x4000, LENGTH = 0x4000
}

SECTIONS
{
	. = 0x0;
	.startup . : {
		startup.o(.text)
	}
	.text : { 
		*(.text)
	}
	.data : {
		*(.data)
	}
	.bss : {
		*(.bss COMMON)
	}
	. = ALIGN(8);
	. = . + 0x1000; /* 4kB of stack memory */
	stack_top = .;
}
