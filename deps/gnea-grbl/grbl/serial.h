/*
  serial.c - Low level functions for sending and recieving bytes via the serial port
  Part of Grbl

  Copyright (c) 2011-2016 Sungeun K. Jeon for Gnea Research LLC
  Copyright (c) 2009-2011 Simen Svale Skogsrud

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef serial_h
#define serial_h

#ifdef __cplusplus
extern "C" {
#endif

// #include <zephyr/drivers/ua>
#include <stdint.h>
#include <stdbool.h>

#ifndef RX_BUFFER_SIZE
  #define RX_BUFFER_SIZE 1024
#endif

#define TX_BUFFER_SIZE_BYTES 1024
#define TX_BUFFER_SIZE_WORDS (TX_BUFFER_SIZE_BYTES/4)
#define SERIAL_NO_DATA 0xff


void serial_init();

// Writes one byte to the TX serial buffer. Called by main program.
void serial_write(uint8_t data);

// Fetches the first byte in the serial read buffer. Called by main program.
uint8_t serial_read();

// Reset and empty data in read buffer. Used by e-stop and reset.
void serial_reset_read_buffer();

// Returns the number of bytes available in the RX serial buffer.
uint32_t serial_get_rx_buffer_available();

// Returns the number of bytes used in the RX serial buffer.
// NOTE: Deprecated. Not used unless classic status reports are enabled in config.h.
uint32_t serial_get_rx_buffer_count();

// Returns the number of bytes used in the TX serial buffer.
// NOTE: Not used except for debugging and ensuring no TX bottlenecks.
// uint32_t serial_get_tx_buffer_count();

void serial_reset_transmit_buffer ();
uint32_t serial_buffer_append (const char *str);
uint32_t serial_buffer_appendln (const char *str);

void serial_disable_irqs ();
void serial_enable_irqs ();
int serial_get_tx_line (uint32_t *buffer, uint8_t bufSize);
bool serial_is_initialized ();
bool serial_check_real_time_command(char data) ;

#ifdef __cplusplus
}
#endif

#endif
