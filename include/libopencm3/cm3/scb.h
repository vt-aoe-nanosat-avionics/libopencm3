/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_SCB_H
#define LIBOPENCM3_SCB_H

/**
 * @defgroup cm_scb Cortex-M System Control Block
 * @ingroup CM3_defines
 *
 * The System Control Block is a section of the System Control Space.
 * Other members of the SCS are, for instance, DWT, ITM, SYSTICKK.
 * The exact details of the SCB are defined in the "Architecture Reference
 * Manual" for either ARMv7-M or ARMV6-m.
 * @{
 */
#include <libopencm3/cm3/memorymap.h>
#include <libopencm3/cm3/common.h>

/** @defgroup cm_scb_registers SCB Registers
 * @ingroup cm_scb
 * @{
 */

/** CPUID: CPUID base register */
#define SCB_CPUID				MMIO32(SCB_BASE + 0x00)

/** ICSR: Interrupt Control State Register */
#define SCB_ICSR				MMIO32(SCB_BASE + 0x04)

/** VTOR: Vector Table Offset Register */
#define SCB_VTOR				MMIO32(SCB_BASE + 0x08)

/** AIRCR: Application Interrupt and Reset Control Register */
#define SCB_AIRCR				MMIO32(SCB_BASE + 0x0C)

/** SCR: System Control Register */
#define SCB_SCR					MMIO32(SCB_BASE + 0x10)

/** CCR: Configuration Control Register */
#define SCB_CCR					MMIO32(SCB_BASE + 0x14)

/** System Handler Priority 8 bits Registers, SHPR1/2/3.
 * @note: 12 8bit Registers
 * @note: 2 32bit Registers on CM0, requires word access,
 * (shpr1 doesn't actually exist)
 */
#if defined(__ARM_ARCH_6M__)
#define SCB_SHPR32(ipr_id)		MMIO32(SCS_BASE + 0xD18 + ((ipr_id) * 4))
#else
#define SCB_SHPR(ipr_id)		MMIO8(SCS_BASE + 0xD18 + (ipr_id))
#endif

/** SHCSR: System Handler Control and State Register */
#define SCB_SHCSR				MMIO32(SCB_BASE + 0x24)

/** DFSR: Debug Fault Status Register */
#define SCB_DFSR				MMIO32(SCB_BASE + 0x30)

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/** CFSR: Configurable Fault Status Registers */
#define SCB_CFSR				MMIO32(SCB_BASE + 0x28)

/** HFSR: Hard Fault Status Register */
#define SCB_HFSR				MMIO32(SCB_BASE + 0x2C)

/** MMFAR: Memory Manage Fault Address Register */
#define SCB_MMFAR				MMIO32(SCB_BASE + 0x34)

/** BFAR: Bus Fault Address Register */
#define SCB_BFAR				MMIO32(SCB_BASE + 0x38)

/** AFSR: Auxiliary Fault Status Register */
#define SCB_AFSR				MMIO32(SCB_BASE + 0x3C)

/** ID_PFR0: Processor Feature Register 0 */
#define SCB_ID_PFR0				MMIO32(SCB_BASE + 0x40)

/** ID_PFR1: Processor Feature Register 1 */
#define SCB_ID_PFR1				MMIO32(SCB_BASE + 0x44)

/** ID_DFR0: Debug Features Register 0 */
#define SCB_ID_DFR0				MMIO32(SCB_BASE + 0x48)

/** ID_AFR0: Auxiliary Features Register 0 */
#define SCB_ID_AFR0				MMIO32(SCB_BASE + 0x4C)

/** ID_MMFR0: Memory Model Feature Register 0 */
#define SCB_ID_MMFR0				MMIO32(SCB_BASE + 0x50)

/** ID_MMFR1: Memory Model Feature Register 1 */
#define SCB_ID_MMFR1				MMIO32(SCB_BASE + 0x54)

/** ID_MMFR2: Memory Model Feature Register 2 */
#define SCB_ID_MMFR2				MMIO32(SCB_BASE + 0x58)

/** ID_MMFR3: Memory Model Feature Register 3 */
#define SCB_ID_MMFR3				MMIO32(SCB_BASE + 0x5C)

/** ID_ISAR0: Instruction Set Attributes Register 0 */
#define SCB_ID_ISAR0				MMIO32(SCB_BASE + 0x60)

/** ID_ISAR1: Instruction Set Attributes Register 1 */
#define SCB_ID_ISAR1				MMIO32(SCB_BASE + 0x64)

/** ID_ISAR2: Instruction Set Attributes Register 2 */
#define SCB_ID_ISAR2				MMIO32(SCB_BASE + 0x68)

/** ID_ISAR3: Instruction Set Attributes Register 3 */
#define SCB_ID_ISAR3				MMIO32(SCB_BASE + 0x6C)

/** ID_ISAR4: Instruction Set Attributes Register 4 */
#define SCB_ID_ISAR4				MMIO32(SCB_BASE + 0x70)

/** CPACR: Coprocessor Access Control Register */
#define SCB_CPACR				MMIO32(SCB_BASE + 0x88)

/** FPCCR: Floating-Point Context Control Register */
#define SCB_FPCCR				MMIO32(SCB_BASE + 0x234)

/** FPCAR: Floating-Point Context Address Register */
#define SCB_FPCAR				MMIO32(SCB_BASE + 0x238)

/** FPDSCR: Floating-Point Default Status Control Register */
#define SCB_FPDSCR				MMIO32(SCB_BASE + 0x23C)

/** MVFR0: Media and Floating-Point Feature Register 0 */
#define SCB_MVFR0				MMIO32(SCB_BASE + 0x240)

/** MVFR1: Media and Floating-Point Feature Register 1 */
#define SCB_MVFR1				MMIO32(SCB_BASE + 0x244)
#endif

/* Those defined only on ARMv7EM and above */
#if defined(__ARM_ARCH_7EM__)
/** CLIDR: Cache Level ID Register */
#define SCB_CLIDR				MMIO32(SCB_BASE + 0x78)

/** CTR: Cache Type Register */
#define SCB_CTR				MMIO32(SCB_BASE + 0x7C)

/** CCSIDR: Cache Size ID Registers */
#define SCB_CCSIDR				MMIO32(SCB_BASE + 0x80)

/** CSSELR: Cache Size Selection Register */
#define SCB_CCSELR				MMIO32(SCB_BASE + 0x84)

/** ICIALLU: I-cache invalidate all to Point of Unification */
#define SCB_ICIALLU				MMIO32(SCB_BASE + 0x250)

/** ICIMVAU: I-cache invalidate by MVA to Point of Unification */
#define SCB_ICIMVAU				MMIO32(SCB_BASE + 0x258)

/** DCIMVAC: D-cache invalidate by MVA to Point of Coherency */
#define SCB_DCIMVAC				MMIO32(SCB_BASE + 0x25C)

/** DCISW: D-cache invalidate by set-way */
#define SCB_DCISW				MMIO32(SCB_BASE + 0x260)

/** DCCMVAU: D-cache clean by MVA to Point of Unification */
#define SCB_DCCMVAU				MMIO32(SCB_BASE + 0x264)

/** DCCMVAC: D-cache clean by MVA to Point of Coherency */
#define SCB_DCCMVAC				MMIO32(SCB_BASE + 0x268)

/** DCISW: D-cache clean by set-way */
#define SCB_DCCSW				MMIO32(SCB_BASE + 0x26C)

/** DCCIMVAC: D-cache clean and invalidate by MVA to Point of Coherency */
#define SCB_DCCIMVAC			MMIO32(SCB_BASE + 0x270)

/** DCCISW: D-cache clean and invalidate by set-way */
#define SCB_DCCISW				MMIO32(SCB_BASE + 0x274)

/** BPIALL: Branch predictor invalidate all */
#define SCB_BPIALL				MMIO32(SCB_BASE + 0x278)
#endif

/**@}*/

/* --- SCB values ---------------------------------------------------------- */

/**
 * @defgroup cm3_scb_cpuid_values SCB_CPUID Values
 * @{
 */
/** Implementer[31:24]: Implementer code */
#define SCB_CPUID_IMPLEMENTER_LSB	24
#define SCB_CPUID_IMPLEMENTER		(0xFF << SCB_CPUID_IMPLEMENTER_LSB)
/** Variant[23:20]: Variant number */
#define SCB_CPUID_VARIANT_LSB		20
#define SCB_CPUID_VARIANT		(0xF << SCB_CPUID_VARIANT_LSB)
/** Constant[19:16]
 * Reads as 0xF (ARMv7-M) M3, M4
 * Reads as 0xC (ARMv6-M) M0, M0+
 */
#define SCB_CPUID_CONSTANT_LSB		16
#define SCB_CPUID_CONSTANT		(0xF << SCB_CPUID_CONSTANT_LSB)
#define SCB_CPUID_CONSTANT_ARMV6	(0xC << SCB_CPUID_CONSTANT_LSB)
#define SCB_CPUID_CONSTANT_ARMV7	(0xF << SCB_CPUID_CONSTANT_LSB)

/** PartNo[15:4]: Part number of the processor */
#define SCB_CPUID_PARTNO_LSB		4
#define SCB_CPUID_PARTNO		(0xFFF << SCB_CPUID_PARTNO_LSB)
/** Revision[3:0]: Revision number */
#define SCB_CPUID_REVISION_LSB			0
#define SCB_CPUID_REVISION		(0xF << SCB_CPUID_REVISION_LSB)
/**@}*/

/**
 * @defgroup cm3_scb_icsr_values SCB_ICSR Values
 * @{
 */
/** NMIPENDSET: NMI set-pending bit */
#define SCB_ICSR_NMIPENDSET		(1 << 31)
/* Bits [30:29]: reserved - must be kept cleared */
/** PENDSVSET: PendSV set-pending bit */
#define SCB_ICSR_PENDSVSET		(1 << 28)
/** PENDSVCLR: PendSV clear-pending bit */
#define SCB_ICSR_PENDSVCLR		(1 << 27)
/** PENDSTSET: SysTick exception set-pending bit */
#define SCB_ICSR_PENDSTSET		(1 << 26)
/** PENDSTCLR: SysTick exception clear-pending bit */
#define SCB_ICSR_PENDSTCLR		(1 << 25)
/* Bit 24: reserved - must be kept cleared */
/** Bit 23: reserved for debug - reads as 0 when not in debug mode */
#define SCB_ICSR_ISRPREEMPT		(1 << 23)
/** ISRPENDING: Interrupt pending flag, excluding NMI and Faults */
#define SCB_ICSR_ISRPENDING		(1 << 22)
/** VECTPENDING[21:12] Pending vector */
#define SCB_ICSR_VECTPENDING_LSB	12
#define SCB_ICSR_VECTPENDING		(0x1FF << SCB_ICSR_VECTPENDING_LSB)
/** RETOBASE: Return to base level */
#define SCB_ICSR_RETOBASE		(1 << 11)
/* Bits [10:9]: reserved - must be kept cleared */
/** VECTACTIVE[8:0] Active vector */
#define SCB_ICSR_VECTACTIVE_LSB		0
#define SCB_ICSR_VECTACTIVE		(0x1FF << SCB_ICSR_VECTACTIVE_LSB)
/**@}*/

/**
 * @defgroup cm3_scb_vtor_values SCB_VTOR Values
 * @{
 */

/* IMPLEMENTATION DEFINED */

#if defined(__ARM_ARCH_6M__)

#define SCB_VTOR_TBLOFF_LSB		7
#define SCB_VTOR_TBLOFF			(0x1FFFFFF << SCB_VTOR_TBLOFF_LSB)

#elif defined(CM1)
/* VTOR not defined there */

#elif defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)

/* Bits [31:30]: reserved - must be kept cleared */
/* TBLOFF[29:9]: Vector table base offset field */
/* inconsistent datasheet - LSB could be 11 */
/* BUG: TBLOFF is in the ARMv6 Architecture reference manual defined from b7 */
#define SCB_VTOR_TBLOFF_LSB		9
#define SCB_VTOR_TBLOFF			(0x7FFFFF << SCB_VTOR_TBLOFF_LSB)

#endif
/**@}*/


/**
 * @defgroup cm3_scb_aicr_values SCB_AICR Values
 * @{
 */
/** VECTKEYSTAT[31:16]/ VECTKEY[31:16] Register key */
#define SCB_AIRCR_VECTKEYSTAT_LSB	16
#define SCB_AIRCR_VECTKEYSTAT		(0xFFFF << SCB_AIRCR_VECTKEYSTAT_LSB)
#define SCB_AIRCR_VECTKEY		(0x05FA << SCB_AIRCR_VECTKEYSTAT_LSB)

/** ENDIANNESS Data endianness bit */
#define SCB_AIRCR_ENDIANESS			(1 << 15)

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/* Bits [14:11]: reserved - must be kept cleared */
/** PRIGROUP[10:8]: Interrupt priority grouping field */
#define SCB_AIRCR_PRIGROUP_GROUP16_NOSUB	(0x3 << 8)
#define SCB_AIRCR_PRIGROUP_GROUP8_SUB2		(0x4 << 8)
#define SCB_AIRCR_PRIGROUP_GROUP4_SUB4		(0x5 << 8)
#define SCB_AIRCR_PRIGROUP_GROUP2_SUB8		(0x6 << 8)
#define SCB_AIRCR_PRIGROUP_NOGROUP_SUB16	(0x7 << 8)
#define SCB_AIRCR_PRIGROUP_MASK			(0x7 << 8)
#define SCB_AIRCR_PRIGROUP_SHIFT		8
/* Bits [7:3]: reserved - must be kept cleared */
#endif

/** SYSRESETREQ System reset request */
#define SCB_AIRCR_SYSRESETREQ			(1 << 2)
/** VECTCLRACTIVE clears state information for exceptions */
#define SCB_AIRCR_VECTCLRACTIVE			(1 << 1)

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/** VECTRESET cause local system reset */
#define SCB_AIRCR_VECTRESET			(1 << 0)
#endif
/**@}*/

/**
 * @defgroup cm3_scb_scr_values SCB_SCR Values
 * @{
 */
/* Bits [31:5]: reserved - must be kept cleared */
/** SEVONPEND Send Event on Pending bit */
#define SCB_SCR_SEVONPEND			(1 << 4)
/* Bit 3: reserved - must be kept cleared */
/** SLEEPDEEP implementation defined */
#define SCB_SCR_SLEEPDEEP			(1 << 2)
/** SLEEPONEXIT sleep when exiting ISR */
#define SCB_SCR_SLEEPONEXIT			(1 << 1)
/* Bit 0: reserved - must be kept cleared */
/**@}*/

/**
 * @defgroup cm3_scb_ccr_values SCB_CCR Values
 * @{
 */
/* Bits [31:10]: reserved - must be kept cleared */
/** STKALIGN set to zero to break things :) */
#define SCB_CCR_STKALIGN			(1 << 9)

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/** BFHFNMIGN set to attempt ignoring faults in handlers */
#define SCB_CCR_BFHFNMIGN			(1 << 8)
/* Bits [7:5]: reserved - must be kept cleared */
/** DIV_0_TRP set to trap on divide by zero*/
#define SCB_CCR_DIV_0_TRP			(1 << 4)
#endif

/** UNALIGN_TRP set to trap on unaligned */
#define SCB_CCR_UNALIGN_TRP			(1 << 3)

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/* Bit 2: reserved - must be kept cleared */
/** USERSETMPEND set to allow unprivileged access to STIR */
#define SCB_CCR_USERSETMPEND			(1 << 1)
/** NONBASETHRDENA set to allow non base priority threads */
#define SCB_CCR_NONBASETHRDENA			(1 << 0)
#endif

/* Those defined only on ARMv7EM and above */
#if defined(__ARM_ARCH_7EM__)
/** BP set to enable branch predictor */
#define SCB_CCR_BP					(1 << 18)
/** IC set to enable instruction cache */
#define SCB_CCR_IC					(1 << 17)
/** DC set to enable data cache */
#define SCB_CCR_DC					(1 << 16)
#endif

/**@}*/

/* These numbers are designed to be used with the SCB_SHPR() macro */
/* SCB_SHPR1 */
#define SCB_SHPR_PRI_4_MEMMANAGE	0
#define SCB_SHPR_PRI_5_BUSFAULT		1
#define SCB_SHPR_PRI_6_USAGEFAULT	2
#define SCB_SHPR_PRI_7_RESERVED		3
/* SCB_SHPR2  */
#define SCB_SHPR_PRI_8_RESERVED		4
#define SCB_SHPR_PRI_9_RESERVED		5
#define SCB_SHPR_PRI_10_RESERVED	6
#define SCB_SHPR_PRI_11_SVCALL		7
/* SCB_SHPR3 */
#define SCB_SHPR_PRI_12_RESERVED	8
#define SCB_SHPR_PRI_13_RESERVED	9
#define SCB_SHPR_PRI_14_PENDSV		10
#define SCB_SHPR_PRI_15_SYSTICK		11

/* --- SCB_SHCSR values ---------------------------------------------------- */

/* Bits [31:19]: reserved - must be kept cleared */

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/* USGFAULTENA: Usage fault enable */
#define SCB_SHCSR_USGFAULTENA			(1 << 18)
/* BUSFAULTENA: Bus fault enable */
#define SCB_SHCSR_BUSFAULTENA			(1 << 17)
/* MEMFAULTENA: Memory management fault enable */
#define SCB_SHCSR_MEMFAULTENA			(1 << 16)
#endif

/* SVCALLPENDED: SVC call pending */
#define SCB_SHCSR_SVCALLPENDED			(1 << 15)

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/* BUSFAULTPENDED: Bus fault exception pending */
#define SCB_SHCSR_BUSFAULTPENDED		(1 << 14)
/* MEMFAULTPENDED: Memory management fault exception pending */
#define SCB_SHCSR_MEMFAULTPENDED		(1 << 13)
/* USGFAULTPENDED: Usage fault exception pending */
#define SCB_SHCSR_USGFAULTPENDED		(1 << 12)
/* SYSTICKACT: SysTick exception active */
#define SCB_SHCSR_SYSTICKACT			(1 << 11)
/* PENDSVACT: PendSV exception active */
#define SCB_SHCSR_PENDSVACT			(1 << 10)
/* Bit 9: reserved - must be kept cleared */
/* MONITORACT: Debug monitor active */
#define SCB_SHCSR_MONITORACT			(1 << 8)
/* SVCALLACT: SVC call active */
#define SCB_SHCSR_SVCALLACT			(1 << 7)
/* Bits [6:4]: reserved - must be kept cleared */
/* USGFAULTACT: Usage fault exception active */
#define SCB_SHCSR_USGFAULTACT			(1 << 3)
/* Bit 2: reserved - must be kept cleared */
/* BUSFAULTACT: Bus fault exception active */
#define SCB_SHCSR_BUSFAULTACT			(1 << 1)
/* MEMFAULTACT: Memory management fault exception active */
#define SCB_SHCSR_MEMFAULTACT			(1 << 0)

/* --- SCB_CFSR values ----------------------------------------------------- */

/* Bits [31:26]: reserved - must be kept cleared */
/* DIVBYZERO: Divide by zero usage fault */
#define SCB_CFSR_DIVBYZERO			(1 << 25)
/* UNALIGNED: Unaligned access usage fault */
#define SCB_CFSR_UNALIGNED			(1 << 24)
/* Bits [23:20]: reserved - must be kept cleared */
/* NOCP: No coprocessor usage fault */
#define SCB_CFSR_NOCP				(1 << 19)
/* INVPC: Invalid PC load usage fault */
#define SCB_CFSR_INVPC				(1 << 18)
/* INVSTATE: Invalid state usage fault */
#define SCB_CFSR_INVSTATE			(1 << 17)
/* UNDEFINSTR: Undefined instruction usage fault */
#define SCB_CFSR_UNDEFINSTR			(1 << 16)
/* BFARVALID: Bus Fault Address Register (BFAR) valid flag */
#define SCB_CFSR_BFARVALID			(1 << 15)
/* Bits [14:13]: reserved - must be kept cleared */
/* STKERR: Bus fault on stacking for exception entry */
#define SCB_CFSR_STKERR				(1 << 12)
/* UNSTKERR: Bus fault on unstacking for a return from exception */
#define SCB_CFSR_UNSTKERR			(1 << 11)
/* IMPRECISERR: Imprecise data bus error */
#define SCB_CFSR_IMPRECISERR			(1 << 10)
/* PRECISERR: Precise data bus error */
#define SCB_CFSR_PRECISERR			(1 << 9)
/* IBUSERR: Instruction bus error */
#define SCB_CFSR_IBUSERR			(1 << 8)
/* MMARVALID: Memory Management Fault Address Register (MMAR) valid flag */
#define SCB_CFSR_MMARVALID			(1 << 7)
/* Bits [6:5]: reserved - must be kept cleared */
/* MSTKERR: Memory manager fault on stacking for exception entry */
#define SCB_CFSR_MSTKERR			(1 << 4)
/* MUNSTKERR: Memory manager fault on unstacking for a return from exception */
#define SCB_CFSR_MUNSTKERR			(1 << 3)
/* Bit 2: reserved - must be kept cleared */
/* DACCVIOL: Data access violation flag */
#define SCB_CFSR_DACCVIOL			(1 << 1)
/* IACCVIOL: Instruction access violation flag */
#define SCB_CFSR_IACCVIOL			(1 << 0)

/* --- SCB_HFSR values ----------------------------------------------------- */

/* DEBUG_VT: reserved for debug use */
#define SCB_HFSR_DEBUG_VT			(1 << 31)
/* FORCED: Forced hard fault */
#define SCB_HFSR_FORCED				(1 << 30)
/* Bits [29:2]: reserved - must be kept cleared */
/* VECTTBL: Vector table hard fault */
#define SCB_HFSR_VECTTBL			(1 << 1)
/* Bit 0: reserved - must be kept cleared */

/* --- SCB_MMFAR values ---------------------------------------------------- */

/* MMFAR [31:0]: Memory management fault address */

/* --- SCB_BFAR values ----------------------------------------------------- */

/* BFAR [31:0]: Bus fault address */

#if defined(__ARM_ARCH_7EM__)
/* --- SCB_CTR values ------------------------------------------------------ */
/* FORMAT: implemented CTR format */
#define SCB_CTR_FORMAT_SHIFT	29
#define SCB_CTR_FORMAT_MASK		0x7
/* CWG: Cache Write-back Granule */
#define SCB_CTR_CWG_SHIFT		24
#define SCB_CTR_CWG_MASK		0xf
/* ERG: Exclusives Reservation Granule */
#define SCB_CTR_ERG_SHIFT		20
#define SCB_CTR_ERG_MASK		0xf
/* DMINLINE: log2 of number of words in smallest cache line of all data caches */
#define SCB_CTR_DMINLINE_SHIFT	16
#define SCB_CTR_DMINLINE_MASK	0x1f
/* IMINLINE: log2 of number of words in smallest cache line of all instruction caches */
#define SCB_CTR_IMINLINE_SHIFT	0
#define SCB_CTR_IMINLINE_MASK	0xf

#endif

/* --- SCB_CPACR values ---------------------------------------------------- */

/* CPACR CPn: Access privileges values */
#define SCB_CPACR_NONE			0	/* Access denied */
#define SCB_CPACR_PRIV			1	/* Privileged access only */
#define SCB_CPACR_FULL			3	/* Full access */

/* CPACR [20:21]: Access privileges for coprocessor 10 */
#define SCB_CPACR_CP10			(1 << 20)
/* CPACR [22:23]: Access privileges for coprocessor 11 */
#define SCB_CPACR_CP11			(1 << 22)
#endif

/* --- SCB functions ------------------------------------------------------- */

BEGIN_DECLS

struct scb_exception_stack_frame {
	uint32_t r0;
	uint32_t r1;
	uint32_t r2;
	uint32_t r3;
	uint32_t r12;
	uint32_t lr;
	uint32_t pc;
	uint32_t xpsr;
} __attribute__((packed));

#define SCB_GET_EXCEPTION_STACK_FRAME(f)				\
	do {								\
		__asm__ volatile ("mov %[frameptr], sp"			\
			      : [frameptr]"=r" (f));			\
	} while (0)

void scb_reset_system(void) __attribute__((noreturn));
void scb_set_sleepdeep(void);
void scb_clear_sleepdeep(void);
void scb_set_sleeponexit(void);
void scb_clear_sleeponexit(void);

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
void scb_reset_core(void) __attribute__((noreturn));
void scb_set_priority_grouping(uint32_t prigroup);
#endif

END_DECLS

/**@}*/

#endif
