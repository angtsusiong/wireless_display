#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
Problem Description:
  You are developing a wireless display module (ARM based Linux OS). This module allows the mobile phone to cast images onto the screen via wireless network. The module need to update the status to the screen every second, including the number of connected devices and the casting is active or not. The screen will respond user configuration, including brightness and contrast to the module.

If there is no device casting, the module need to show the user configuration on the frame buffer.

Here are the information about how to communicate between the module and the screen:
  1. The module and the screen communicate via UART (baud rate: 115200).
  2. This structure represents the format sent from the module to the screen.
    Structure:
      | Field     | Size (bits) | Description                                         |
      |-----------|-------------|-----------------------------------------------------|
      | Header    | 8           | Start byte indicating the beginning of a command    |
      | Connected | 6           | Number of connected devices                         |
      | Reserverd | 10          | Reserverd                                           |
      | Actived   | 8           | Is there a device that is casting                   |
      | End       | 8           | End byte indicating the end of a command            |
  
  3. This structure represents the format sent from the screen to the module.
    Structure:
      | Field        | Size (bits) | Description                                        |
      |--------------|-------------|----------------------------------------------------|
      | Header       | 8           | Start byte indicating the beginning of a response  |
      | Brightness   | 8           | Brightness of the screen                           |
      | Contrast     | 8           | Contrast of the screen                             |
      | End          | 8           | End byte indicating the end of a response          |
  4. The Header and End bytes are fixed values. Header: 0x55, End: 0xAA

Here are the information about frame buffer:
  1. The size of frame buffer is 1920x1080 pixels and suppose it is grayscale.
  2. The frame buffer is stored in the memory with the following format:
    | Pixel 1 | Pixel 2 | ... | Pixel 1920 |
    | Pixel 1 | Pixel 2 | ... | Pixel 1920 |
    | ...     | ...     | ... | ...        |
    | Pixel 1 | Pixel 2 | ... | Pixel 1920 |
  3. The image size of user configuration is 640x480 pixels and suppose it is grayscale.
  4. The user configuration is stored in the memory with the following format:
    | Pixel 1 | Pixel 2 | ... | Pixel 640 |
    | Pixel 1 | Pixel 2 | ... | Pixel 640 |
    | ...     | ...     | ... | ...       |
    | Pixel 1 | Pixel 2 | ... | Pixel 640 |
  5. The user configuration need to show at the left bottom corner of the entire frame buffer. (memory copy)
*/

// Helper functions:
// Open the UART communication with the device
int uart_open(const char *device_name, int baud_rate);
// Write the data to the device
int uart_write(uint8_t *data, int data_size);
// Read the data from the device
int uart_read(uint8_t *data, int data_size);
// Close the UART communication with the device
int uart_close();
// Register the callback function to get latest status
void register_status_callback(void (*callback)(int connected, int actived));

// Get the pointer of the entire frame buffer
void framebuffer_get_screen(uint8_t **pointer);
// Generate the user configuration image
void framebuffer_gen_img_buffer(uint8_t *buf, int size, int brightness, int contrast);
// Update the frame buffer to the screen
void framebuffer_update();

int main(int argc, char *argv[]) {
  // TODO: Implement the main function
  return 0;
}
