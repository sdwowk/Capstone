/*
 * alt_sys_init.c - HAL initialization source
 *
 * Machine generated for CPU 'cpu' in SOPC Builder design 'niosII_system'
 * SOPC Builder design path: ../../niosII_system.sopcinfo
 *
 * Generated: Thu Apr 11 16:02:32 MDT 2013
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#include "system.h"
#include "sys/alt_irq.h"
#include "sys/alt_sys_init.h"

#include <stddef.h>

/*
 * Device headers
 */

#include "altera_nios2_irq.h"
#include "altera_avalon_cfi_flash.h"
#include "altera_avalon_jtag_uart.h"
#include "altera_avalon_lcd_16207.h"
#include "altera_avalon_sysid.h"
#include "altera_avalon_timer.h"
#include "altera_avalon_uart.h"
#include "altera_ro_zipfs.h"
#include "dm9000a.h"

/*
 * Allocate the device storage
 */

ALTERA_NIOS2_IRQ_INSTANCE ( CPU, cpu);
ALTERA_AVALON_CFI_FLASH_INSTANCE ( EXT_FLASH, ext_flash);
ALTERA_AVALON_JTAG_UART_INSTANCE ( JTAG_UART, jtag_uart);
ALTERA_AVALON_LCD_16207_INSTANCE ( LCD_DISPLAY, lcd_display);
ALTERA_AVALON_SYSID_INSTANCE ( SYSID, sysid);
ALTERA_AVALON_TIMER_INSTANCE ( HIGH_RES_TIMER, high_res_timer);
ALTERA_AVALON_TIMER_INSTANCE ( SYS_CLK_TIMER, sys_clk_timer);
ALTERA_AVALON_UART_INSTANCE ( UART_0, uart_0);
ALTERA_AVALON_UART_INSTANCE ( UART_1, uart_1);
ALTERA_RO_ZIPFS_INSTANCE ( ALTERA_RO_ZIPFS, altera_ro_zipfs);
DM9000A_INSTANCE ( DM9000A_INST, dm9000a_inst);

/*
 * Initialize the interrupt controller devices
 * and then enable interrupts in the CPU.
 * Called before alt_sys_init().
 * The "base" parameter is ignored and only
 * present for backwards-compatibility.
 */

void alt_irq_init ( const void* base )
{
    ALTERA_NIOS2_IRQ_INIT ( CPU, cpu);
    alt_irq_cpu_enable_interrupts();
}

/*
 * Initialize the non-interrupt controller devices.
 * Called after alt_irq_init().
 */

void alt_sys_init( void )
{
    ALTERA_AVALON_TIMER_INIT ( HIGH_RES_TIMER, high_res_timer);
    ALTERA_AVALON_TIMER_INIT ( SYS_CLK_TIMER, sys_clk_timer);
    ALTERA_AVALON_CFI_FLASH_INIT ( EXT_FLASH, ext_flash);
    ALTERA_AVALON_JTAG_UART_INIT ( JTAG_UART, jtag_uart);
    ALTERA_AVALON_LCD_16207_INIT ( LCD_DISPLAY, lcd_display);
    ALTERA_AVALON_SYSID_INIT ( SYSID, sysid);
    ALTERA_AVALON_UART_INIT ( UART_0, uart_0);
    ALTERA_AVALON_UART_INIT ( UART_1, uart_1);
    ALTERA_RO_ZIPFS_INIT ( ALTERA_RO_ZIPFS, altera_ro_zipfs);
    DM9000A_INIT ( DM9000A_INST, dm9000a_inst);
}
