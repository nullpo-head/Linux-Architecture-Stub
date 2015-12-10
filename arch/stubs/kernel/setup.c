/*
 * arch/score/kernel/setup.c
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

#include <linux/bootmem.h>
#include <linux/initrd.h>
#include <linux/ioport.h>
#include <linux/memblock.h>
#include <linux/mm.h>
#include <linux/seq_file.h>
#include <linux/screen_info.h>

#include <asm-generic/sections.h>
#include <asm/setup.h>

struct screen_info screen_info;
unsigned long kernelsp;

static char command_line[COMMAND_LINE_SIZE];
static struct resource code_resource = { .name = "Kernel code",};
static struct resource data_resource = { .name = "Kernel data",};


void __init setup_arch(char **cmdline_p)
{
}

static int show_cpuinfo(struct seq_file *m, void *v)
{
	return 0;
}

static void *c_start(struct seq_file *m, loff_t *pos)
{
	return NULL;
}

static void *c_next(struct seq_file *m, void *v, loff_t *pos)
{
	return NULL;
}

static void c_stop(struct seq_file *m, void *v)
{
}

const struct seq_operations cpuinfo_op = {
	.start	= c_start,
	.next	= c_next,
	.stop	= c_stop,
	.show	= show_cpuinfo,
};
