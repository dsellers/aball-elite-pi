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

#define CONSOLE_ENABLED                     // As soon as the sensor detects movement, the MOT pin is pulled low (active)
#define POINTING_DEVICE_DEBUG               // QMK logs this automatically if debug is enabled

// ADNS-9800 wiring
#define ADNS9800_CS_PIN             A0      // SEL / NCS on A0
#define POINTING_DEVICE_MOTION_PIN  G27     // MOT pin: A1 on Elite-Pi = GP27 on RP2040
#define POINTING_DEVICE_INVERT_X            // keep or remove as needed

// SPI mapping for Elite-Pi
#define SPI_SCK_PIN                 D22
#define SPI_MOSI_PIN                D23
#define SPI_MISO_PIN                D20
