/** @defgroup CM3_scb_file SCB
 *
 * @ingroup CM3_files
 *
 * @brief <b>libopencm3 Cortex-M System Control Block</b>
 *
 * The System Control Block (SCB) is a section of the System Control Space
 * which provides status information and control features for the processor core.
 * It allows, amongst other:
 * * software reset control
 * * exception management and grouping
 * * fault information
 * * power management
 * * debug status information
 *
 * @see ARMv7m Architecture Reference Manual (Chapter B3.2.1 About the SCB)
 *
 * LGPL License Terms @ref lgpl_license
 * @{
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Gareth McMullin <gareth@blacksphere.co.nz>
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

#include <stdlib.h>

#include <libopencm3/cm3/scb.h>

/* Those are defined only on CM3 or CM4 */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
void scb_reset_core(void)
{
	SCB_AIRCR = SCB_AIRCR_VECTKEY | SCB_AIRCR_VECTRESET;

	while (1);
}
#endif

void scb_reset_system(void)
{
	SCB_AIRCR = SCB_AIRCR_VECTKEY | SCB_AIRCR_SYSRESETREQ;

	while (1);
}

void scb_set_sleepdeep(void)
{
	SCB_SCR |= SCB_SCR_SLEEPDEEP;
}

void scb_clear_sleepdeep(void)
{
	SCB_SCR &= ~SCB_SCR_SLEEPDEEP;
}

void scb_set_sleeponexit(void)
{
	SCB_SCR |= SCB_SCR_SLEEPONEXIT;
}

void scb_clear_sleeponexit(void)
{
	SCB_SCR &= ~SCB_SCR_SLEEPONEXIT;
}

/* Those are defined only on CM3 or CM4 */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
void scb_set_priority_grouping(uint32_t prigroup)
{
	SCB_AIRCR = SCB_AIRCR_VECTKEY | prigroup;
}
#endif

/**@}*/