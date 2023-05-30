#ifndef GAME_H
#define GAME_H

#include "../drivers/avr/system.h"
#include "../drivers/test/timer.h"
#include "../drivers/test/pio.h"
#include "../utils/tinygl.h"
#include "../drivers/button.h"
#include "../utils/font.h"
#include "../drivers/display.h"
#include "../drivers/ledmat.h"
#include "../drivers/navswitch.h"
#include "../drivers/led.h"
#include "../utils/pacer.h"
#include "../drivers/avr/ir_uart.h"
#include <stdbool.h>



char myChoice;
char theirChoice;
char result;

void compare(void);

void display_character(char character);


#endif
