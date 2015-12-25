/*
 * arch/score/mm/init.c
 *
 * Score Processor version.
 *
 * Copyright (C) 2009 Sunplus Core Technology Co., Ltd.
 *  Lennox Wu <lennox.wu@sunplusct.com>
 *  Chen Liqin <liqin.chen@sunplusct.com>
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

#include <linux/errno.h>
#include <linux/bootmem.h>
#include <linux/kernel.h>
#include <linux/gfp.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <linux/mman.h>
#include <linux/pagemap.h>
#include <linux/kcore.h>
#include <linux/sched.h>
#include <linux/initrd.h>

#include <asm/sections.h>
#include <asm/tlb.h>

#define __page_aligned(order) __attribute__((__aligned__(PAGE_SIZE<<order)))
pgd_t swapper_pg_dir[PTRS_PER_PGD] __page_aligned(PTE_ORDER);

unsigned long empty_zero_page;
EXPORT_SYMBOL_GPL(empty_zero_page);

void __init mem_init(void)
{
}

void __init_refok free_initmem(void)
{
}
