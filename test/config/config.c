/*
 * This file is part of the superbitrf project.
 *
 * Copyright (C) 2013 Freek van Tienen <freek.v.tienen@gmail.com>
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

#include <libopencm3/stm32/rcc.h>

#include <stdio.h>
#include <stdlib.h>

/* Load the modules */
#include "modules/cdcacm.h"
#include "modules/console.h"
#include "modules/config.h"

int main(void) {
	// Setup the clock
	rcc_clock_setup_in_hse_12mhz_out_72mhz();

	// Initialize the modules
	cdcacm_init();
	console_init();
	config_init();

	/* The main loop */
	while (1) {
		cdcacm_process();
		console_run();
	}

	return 0;
}
