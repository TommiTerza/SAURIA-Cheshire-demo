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
#include "sauria_io.h"

/* SAURIA base address define */
#define SAURIA_REG_START_ADDRESS 0x40000000

#define SAURIA_MEM_START_ADDRESS 0x45000000

int main(void) {

    *(volatile uint32_t *) (SAURIA_REG_START_ADDRESS + SAURIA_CFG_REGS_IDX1_OFFSET) = 0x1 ;

    *(volatile uint32_t *) (SAURIA_MEM_START_ADDRESS + SAURIA_SRAMA_OFFSET) = 0xDEADBEEF ;

    return 0;
}
