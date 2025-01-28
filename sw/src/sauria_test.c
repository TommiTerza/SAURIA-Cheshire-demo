/*
 * Copyright 2025 PoliTo
 * Solderpad Hardware License, Version 2.1, see LICENSE.md for details.
 * SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
 *
 * Author: Tommaso Terzano <tommaso.terzano@polito.it> 
 *                         <tommaso.terzano@gmail.com>
 *  
 * Info: Test of the SAURIA demostrator
 */

#include "regs/cheshire.h"
#include "dif/clint.h"
#include "dif/uart.h"
#include "params.h"
#include "util.h"
#include "sauria_regs.h"

/* SAURIA base address define */
#define SAURIA_PERIPH_START_ADDRESS 0x20000000

/* 
 * Function to print a string via UART
 */
void uart_print(const char *str) {
    /* Get the RTC frequency from the corresponding register */
    uint32_t rtc_freq = *reg32(&__base_regs, CHESHIRE_RTC_FREQ_REG_OFFSET);
    
    /* Calculate the core frequency based on the RTC frequency and a multiplier */
    uint64_t reset_freq = clint_get_core_freq(rtc_freq, 2500);
    
    /* Initialize the UART with the calculated core frequency and a predefined baud rate */
    uart_init(&__base_uart, reset_freq, __BOOT_BAUDRATE);
    
    /* Send the string to the UART */
    uart_write_str(&__base_uart, str, strlen(str));
    
    /* Ensure all data is transmitted */
    uart_write_flush(&__base_uart);
}

/*
 * Function to write a register
 */
static inline void write_register( uint32_t  p_val,
                                  uint32_t  p_offset,
                                  uint32_t  p_mask,
                                  uint8_t   p_sel,
                                  uint32_t  p_addr)
{
    /*
     * The index is computed to avoid needing to access the structure
     * as a structure.
     */
    uint8_t index = p_offset / sizeof(uint32_t);
    /*
     * An intermediate variable "value" is used to prevent writing twice into
     * the register.
     */
    uint32_t value  =  (( uint32_t * ) p_addr ) [ index ];
    value           &= ~( p_mask << p_sel );
    value           |= (p_val & p_mask) << p_sel;
    (( uint32_t * ) p_addr ) [ index ] = value;
}

int main(void) {
    char str[] = "Hello World!\r\n";

    write_register(SAURIA_PERIPH_START_ADDRESS, 0, 0xFFFFFFFF, 0, SAURIA_CFG_REGS_IDX0_OFFSET);
    
    /* Call uart_print to send the message */
    uart_print(str);

    return 0;
}
