// RISC-V Compliance Test Header File
// Copyright (c) 2017, Codasip Ltd. All Rights Reserved.
// See LICENSE for license details.
//
// Description: Common header file for RV32I tests

#ifndef _COMPLIANCE_TEST_H
#define _COMPLIANCE_TEST_H

#include "riscv_test.h"

#define PN_HALT  				   .word 0x0000000B 
#define PN_CFLUSH(BASE, REG)       .word (0x300B | ((REG) << 15) | (((BASE) & 0xfff) << 20))
        

//-----------------------------------------------------------------------
// RV Compliance Macros
//-----------------------------------------------------------------------

#define RV_COMPLIANCE_HALT                                                    \
		la x7, begin_signature;												  \
		la x8, end_signature;												  \
1:																			  \
		PN_CFLUSH(0,7);														  \
		addi x7, x7, 16;		/* Add cache line */						  \
		bge x8, x7, 1b;														  \
        PN_HALT;															  \
 
 
#undef RVTEST_FAIL
#define RVTEST_FAIL															  \
		RV_COMPLIANCE_HALT 			 								     	  \
        
#define RV_COMPLIANCE_RV32M                                                   \
        RVTEST_RV32M                                                          \

#define RV_COMPLIANCE_CODE_BEGIN                                              \
        RVTEST_CODE_BEGIN                                                     \

#define RV_COMPLIANCE_CODE_END                                                \
        RVTEST_CODE_END                                                       \

#define RV_COMPLIANCE_DATA_BEGIN                                              \
        RVTEST_DATA_BEGIN                                                     \

#define RV_COMPLIANCE_DATA_END                                                \
        RVTEST_DATA_END                                                       \

#endif
