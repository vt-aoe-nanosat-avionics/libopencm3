/** @addtogroup quadspi_defines
 * @author Chuck McManis <cmcmanis@mcmanis.com> 2016
 * @copyright SPDX: LGPL-3.0-or-later
 * @{
 */

#pragma once

/** @addtogroup quadspi_registers QuadSPI Registers
 * @{
 */
/** QUADSPI Control register */
#define QUADSPI_CR      MMIO32(QUADSPI_BASE + 0x0U)

/** QUADSPI Device Configuration */
#define QUADSPI_DCR     MMIO32(QUADSPI_BASE + 0x4U)

/** QUADSPI Status Register */
#define QUADSPI_SR      MMIO32(QUADSPI_BASE + 0x8U)

/** QUADSPI Flag Clear Register */
#define QUADSPI_FCR     MMIO32(QUADSPI_BASE + 0xCU)

/** QUADSPI Data Length Register */
#define QUADSPI_DLR     MMIO32(QUADSPI_BASE + 0x10U)

/** QUADSPI Communication Configuration Register */
#define QUADSPI_CCR     MMIO32(QUADSPI_BASE + 0x14U)

/** QUADSPI address register */
#define QUADSPI_AR      MMIO32(QUADSPI_BASE + 0x18U)

/** QUADSPI alternate bytes register */
#define QUADSPI_ABR     MMIO32(QUADSPI_BASE + 0x1CU)

/** QUADSPI data register */
#define QUADSPI_DR      MMIO32(QUADSPI_BASE + 0x20U)
/** BYTE addressable version for fetching bytes from the interface */
#define QUADSPI_BYTE_DR     MMIO8(QUADSPI_BASE + 0x20U)

/** QUADSPI polling status */
#define QUADSPI_PSMKR     MMIO32(QUADSPI_BASE + 0x24U)

/** QUADSPI polling status match */
#define QUADSPI_PSMAR     MMIO32(QUADSPI_BASE + 0x28U)

/** QUADSPI polling interval register */
#define QUADSPI_PIR     MMIO32(QUADSPI_BASE + 0x2CU)

/** QUADSPI low power timeout */
#define QUADSPI_LPTR      MMIO32(QUADSPI_BASE + 0x30U)
/**@}*/

#define QUADSPI_CR_PRESCALE_MASK  0xff
#define QUADSPI_CR_PRESCALE_SHIFT 24
#define QUADSPI_CR_PMM      (1 << 23)
#define QUADSPI_CR_APMS     (1 << 22)
/* bit 21 is reserved */
#define QUADSPI_CR_TOIE     (1 << 20)
#define QUADSPI_CR_SMIE     (1 << 19)
#define QUADSPI_CR_FTIE     (1 << 18)
#define QUADSPI_CR_TCIE     (1 << 17)
#define QUADSPI_CR_TEIE     (1 << 16)

/* bits 15:13 reserved */
#define QUADSPI_CR_FTHRES_MASK    0x1f
#define QUADSPI_CR_FTHRES_SHIFT   8
#define QUADSPI_CR_FSEL     (1 << 7)
#define QUADSPI_CR_DFM      (1 << 6)
/* bit 5 reserved */
#define QUADSPI_CR_SSHIFT   (1 << 4)
#define QUADSPI_CR_TCEN     (1 << 3)
/* bit 2 reserved on h7, DMAEN on f4 */
#define QUADSPI_CR_ABORT    (1 << 1)
#define QUADSPI_CR_EN     (1 << 0)

/* bits 31:21 reserved */
#define QUADSPI_DCR_FSIZE_MASK    0x1f
#define QUADSPI_DCR_FSIZE_SHIFT   16
/* bits 15:11 reserved */
#define QUADSPI_DCR_CSHT_MASK   0x7
#define QUADSPI_DCR_CSHT_SHIFT    8
/* bits 7:1 reserved */
#define QUADSPI_DCR_CKMODE    (1 << 0)

/* bits 31:14 reserved */
#define QUADSPI_SR_FLEVEL_MASK    0x3f
#define QUADSPI_SR_FLEVEL_SHIFT   8

/* bits 7:6 reserved */
#define QUADSPI_SR_BUSY     (1 << 5)
#define QUADSPI_SR_TOF      (1 << 4)
#define QUADSPI_SR_SMF      (1 << 3)
#define QUADSPI_SR_FTF      (1 << 2)
#define QUADSPI_SR_TCF      (1 << 1)
#define QUADSPI_SR_TEF      (1 << 0)

/* bits 31:5 reserved */
#define QUADSPI_FCR_CTOF    (1 << 4)
#define QUADSPI_FCR_CSMF    (1 << 3)
/* bit 2 reserved */
#define QUADSPI_FCR_CTCF    (1 << 1)
#define QUADSPI_FCR_CTEF    (1 << 0)

#define QUADSPI_CCR_DDRM    (1 << 31)
#define QUADSPI_CCR_DHHC    (1 << 30)
/* bit 29 reserved on F4, FRCM on H7 */
#define QUADSPI_CCR_SIOO    (1 << 28)
#define QUADSPI_CCR_FMODE_MASK    0x3
#define QUADSPI_CCR_FMODE_SHIFT   26
#define QUADSPI_CCR_DMODE_MASK    0x3
#define QUADSPI_CCR_DMODE_SHIFT   24
/* bit 23 reserved */
#define QUADSPI_CCR_DCYC_MASK   0x1f
#define QUADSPI_CCR_DCYC_SHIFT    18

#define QUADSPI_CCR_ABSIZE_MASK   0x3
#define QUADSPI_CCR_ABSIZE_SHIFT  16

#define QUADSPI_CCR_ABMODE_MASK   0x3
#define QUADSPI_CCR_ABMODE_SHIFT  14

#define QUADSPI_CCR_ADSIZE_MASK   0x3
#define QUADSPI_CCR_ADSIZE_SHIFT  12

#define QUADSPI_CCR_ADMODE_MASK   0x3
#define QUADSPI_CCR_ADMODE_SHIFT  10

#define QUADSPI_CCR_IMODE_MASK    0x3
#define QUADSPI_CCR_IMODE_SHIFT   8

#define QUADSPI_CCR_INST_MASK   0xff
#define QUADSPI_CCR_INST_SHIFT    0

/* ABSIZE values */
#define QUADSPI_CCR_ABSIZE_8BIT   0
#define QUADSPI_CCR_ABSIZE_16BIT  1
#define QUADSPI_CCR_ABSIZE_24BIT  2
#define QUADSPI_CCR_ABSIZE_32BIT  3

/* ADSIZE values */
#define QUADSPI_CCR_ADSIZE_8BIT   0
#define QUADSPI_CCR_ADSIZE_16BIT  1
#define QUADSPI_CCR_ADSIZE_24BIT  2
#define QUADSPI_CCR_ADSIZE_32BIT  3

/* MODE values */
#define QUADSPI_CCR_MODE_NONE   0
#define QUADSPI_CCR_MODE_1LINE    1
#define QUADSPI_CCR_MODE_2LINE    2
#define QUADSPI_CCR_MODE_4LINE    3

/* FMODE values */
#define QUADSPI_CCR_FMODE_IWRITE  0
#define QUADSPI_CCR_FMODE_IREAD   1
#define QUADSPI_CCR_FMODE_APOLL   2
#define QUADSPI_CCR_FMODE_MEMMAP  3

/**@}*/


/**
 * @defgroup quadspi_file QuadSPI peripheral API
 * @brief APIs for the specialized SPI Flash peripheral
 * @ingroup peripheral_apis
 * @copyright SPDX: LGPL-3.0-or-later
 *
 * The QUADSPI is a specialized communication interface targeting single,
 * dual or quad SPI Flash memories
 * @{
 */

BEGIN_DECLS

/**
 * Enable the quadspi peripheral.
 */
//void quadspi_enable(void);
//
///**
// * Disable the quadspi peripheral.
// */
//void quadspi_disable(void);
//
//void quadspi_set_flash_size(uint8_t size);
//void quadspi_set_high_time(uint8_t high_time);
//void quadspi_clear_flag(uint8_t flag);
//uint8_t quadspi_get_flag(uint8_t flag);
//void quadspi_set_prescaler(uint8_t prescaler);
//void quadspi_enable_sample_shift(void);
//void quadspi_disable_sample_shift(void);
//uint8_t quadspi_get_busy(void);
//void quadspi_set_fmode(uint8_t mode);
//void quadspi_set_data_mode(uint8_t mode);
//void quadspi_set_num_dummy_cycles(uint8_t cycles);
//void quadspi_set_alternate_byte_size(uint8_t size);
//void quadspi_set_alternate_byte_mode(uint8_t mode);
//void quadspi_set_address_size(uint8_t size);
//void quadspi_set_address_mode(uint8_t mode);
//void quadspi_set_address(uint32_t address);
//void quadspi_set_instruction_mode(uint8_t mode);
//void quadspi_set_instruction(uint8_t instruction);
//void quadspi_set_data_length(uint8_t length);
//void quadspi_set_data(uint32_t data);
//uint8_t quadspi_get_data(void);
//void quadspi_set_fifo_threshold(uint8_t threshold);
//void quadspi_send_instruction(uint8_t instruction, uint8_t dataMode);
//void quadspi_write_register(uint8_t instruction, uint8_t dataMode, uint8_t data);
//void quadspi_read_register(uint8_t instruction, uint8_t dataMode);
//
//END_DECLS

/**@}*/
