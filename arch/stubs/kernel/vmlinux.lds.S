/*
 * arch/score/kernel/vmlinux.lds.S
 *
 * Score Processor version.
 *
 * Copyright (C) 2009 Sunplus Core Technology Co., Ltd.
 *  Chen Liqin <liqin.chen@sunplusct.com>
 *  Lennox Wu <lennox.wu@sunplusct.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see the file COPYING, or write
 * to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <asm-generic/vmlinux.lds.h>
#include <asm/cache.h>
#include <asm/thread_info.h>
#include <asm/page.h>

#define START LOAD_OFFSET

OUTPUT_FORMAT("elf32-i386")
OUTPUT_ARCH(i386)
ENTRY(phys_start)

jiffies = jiffies_64;

SECTIONS
{
	. = START;
	phys_start = START - LOAD_OFFSET;
	__init_begin = .;
	HEAD_TEXT_SECTION
	INIT_TEXT_SECTION(PAGE_SIZE)
	INIT_DATA_SECTION(16)
	PERCPU_SECTION(L1_CACHE_BYTES)
	__init_end = .;

	.text : {
		_stext = .;	/* Text and read-only data */
		TEXT_TEXT
		SCHED_TEXT
		LOCK_TEXT
		KPROBES_TEXT
		*(.text.*)
		*(.fixup)
		_etext = .;	/* End of text section */
	}

	_sdata =  .;			/* Start of data section */
	RO_DATA_SECTION(PAGE_SIZE)
	RW_DATA_SECTION(32, PAGE_SIZE, THREAD_SIZE)
	_edata =  .;			/* End of data section */

	EXCEPTION_TABLE(16)
	NOTES

	BSS_SECTION(0, 0, 0)
	_end = .;

	STABS_DEBUG
	DWARF_DEBUG

	DISCARDS
}
