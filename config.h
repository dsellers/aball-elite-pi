/*
Copyright 2020 Richard Sutherland

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#define POINTING_DEVICE_DEBUG               // QMK logs this automatically if debug is enabled
#define SPI_DRIVER SPID0                    // Use RP2040 SPI0 peripheral for ADNS-9800 (matches GP20/22/23 wiring)

// ADNS-9800 wiring
// #define POINTING_DEVICE_MOTION_PIN  GP27    // MOT pin: A1 on Elite-Pi = GP27 on RP2040
#define ADNS9800_CS_PIN             GP26    // SEL / NCS on A0
#define SPI_SCK_PIN                 GP22    // D22 (SCK0)
#define SPI_MOSI_PIN                GP23    // D23 (MOSI0)
#define SPI_MISO_PIN                GP20    // D20 (MISO0)

// Optional invert
#define POINTING_DEVICE_INVERT_X            // keep or remove as needed
