/* Copyright 2020 Richard Sutherland
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "print.h"
#include "debug.h"
#include "spi_master.h"
#include "wait.h"

// Dummy
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {{{ KC_NO }}};

void keyboard_post_init_user(void) {
    debug_enable = true;
    debug_keyboard = true;
    debug_mouse = true;
    print("ABALL BOOTED\r\n");
    xprintf("ABALL xprintf booted\r\n");
}

// void housekeeping_task_user(void) {
//     static uint32_t last_print = 0;
//     if (timer_elapsed32(last_print) > 2000) {
//         last_print = timer_read32();
        
//         // Try to read ADNS9800 Product ID (register 0x00, should return 0x33)
//         spi_start(GP26, false, 3, 8);  // CS=GP26, MSB first, Mode 3, divisor 8 (~2MHz)
//         spi_write(0x00);               // Read register 0x00
//         uint8_t product_id = spi_read();
//         spi_stop();
        
//         xprintf("ADNS Product ID: 0x%02X (expected 0x33)\n", product_id);
//     }
// }

// void housekeeping_task_user(void) {
//     static uint32_t last_print = 0;
//     if (timer_elapsed32(last_print) > 2000) {
//         last_print = timer_read32();
        
//         // Test 1: Can we control CS manually?
//         gpio_set_pin_output(GP26);
//         gpio_write_pin_high(GP26);
//         xprintf("CS pin set high\n");
        
//         // Test 2: Does spi_init succeed?
//         spi_init();
//         xprintf("SPI init called\n");
        
//         // Test 3: Try the read with proper timing
//         gpio_write_pin_low(GP26);
//         wait_us(1);
//         spi_write(0x00);
//         wait_us(100);
//         uint8_t id = spi_read();
//         gpio_write_pin_high(GP26);
        
//         xprintf("Product ID: 0x%02X\n", id);
        
//         // Test 4: What does CS pin read back as?
//         xprintf("CS pin state: %lu\n", gpio_read_pin(GP26));
//     }
// }

// void housekeeping_task_user(void) {
//     static uint32_t last_print = 0;
//     static bool inited = false;
    
//     if (!inited) {
//         gpio_set_pin_output(GP26);  // CS
//         gpio_set_pin_output(GP22);  // SCK
//         gpio_set_pin_output(GP23);  // MOSI
//         gpio_set_pin_input(GP20);   // MISO
//         gpio_write_pin_high(GP26);  // CS idle high
//         gpio_write_pin_low(GP22);   // SCK idle low for mode 3? Actually high
//         inited = true;
//         xprintf("GPIO init done\n");
//     }
    
//     if (timer_elapsed32(last_print) > 2000) {
//         last_print = timer_read32();
        
//         // Bit-bang SPI Mode 3: read register 0x00
//         gpio_write_pin_high(GP22);  // SCK idle high (Mode 3)
//         gpio_write_pin_low(GP26);   // CS low - start
//         wait_us(1);
        
//         // Send 0x00 (read product ID register)
//         for (int i = 7; i >= 0; i--) {
//             gpio_write_pin_low(GP22);
//             gpio_write_pin_low(GP23);  // sending 0x00, all bits are 0
//             wait_us(1);
//             gpio_write_pin_high(GP22);
//             wait_us(1);
//         }
        
//         wait_us(100);  // tSRAD
        
//         // Read 8 bits
//         uint8_t id = 0;
//         for (int i = 7; i >= 0; i--) {
//             gpio_write_pin_low(GP22);
//             wait_us(1);
//             gpio_write_pin_high(GP22);
//             if (gpio_read_pin(GP20)) {
//                 id |= (1 << i);
//             }
//             wait_us(1);
//         }
        
//         gpio_write_pin_high(GP26);  // CS high - end
        
//         xprintf("Bit-bang Product ID: 0x%02X\n", id);
//     }
// }

void housekeeping_task_user(void) {
    static uint32_t last_print = 0;
    static bool state = false;
    
    if (timer_elapsed32(last_print) > 2000) {
        last_print = timer_read32();
        state = !state;
        
        // Print what GP26 actually resolves to
        xprintf("GP26=%u, GP22=%u, GP23=%u, GP20=%u, GP4=%u\n", 
                (unsigned)GP26, (unsigned)GP22, (unsigned)GP23, (unsigned)GP20, (unsigned)GP4);
        
        // Test D4 (GPIO 4) - assuming you have nothing connected here
        gpio_set_pin_output(4);
        gpio_set_pin_output(26);
        gpio_set_pin_output(22);
        gpio_set_pin_output(23);
        gpio_set_pin_output(20);
        
        if (state) {
            gpio_write_pin_high(4);
            gpio_write_pin_high(26);
            gpio_write_pin_high(22);
            gpio_write_pin_high(23);
            gpio_write_pin_high(20);
            xprintf("Pins HIGH\n");
        } else {
            gpio_write_pin_low(4);
            gpio_write_pin_low(26);
            gpio_write_pin_low(22);
            gpio_write_pin_low(23);
            gpio_write_pin_low(20);
            xprintf("Pins LOW\n");
        }
    }
}
