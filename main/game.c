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
#include "../drivers/test/ir_uart.h"
#include "../fonts/font5x7_1.h"
#include <stdbool.h>
#include "game.h"



#define PACER_RATE 500
#define MESSAGE_RATE 10



int main (void)
{
    char character = 'P';

    system_init ();
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    navswitch_init ();
    ir_uart_init();
    pacer_init (PACER_RATE);

    while (1)
    {
        pacer_wait ();
        tinygl_update ();
        navswitch_update ();

        if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
            if (character == 'P') {
                character = 'S';
            } else if (character == 'S') {
                character = 'R';
            } else {
                character = 'P';
            }
        }

        if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
            if (character == 'P') {
                character = 'R';
            } else if (character == 'R') {
                character = 'S';
            } else {
                character = 'P';
            }
        }

        /* TODO: Transmit the character over IR on a NAVSWITCH_PUSH
           event.  */
        if (navswitch_push_event_p (NAVSWITCH_EAST)) {
            myChoice = character;
        }

        if (ir_uart_read_ready_p ()) {
            theirChoice = ir_uart_getc ();
        }

        if (button_push_event_p (BUTTON1)) {
            ir_uart_putc(myChoice);
        }

        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
            compare();
        }

    }

    return 0;
}
