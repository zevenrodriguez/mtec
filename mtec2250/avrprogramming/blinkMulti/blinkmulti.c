
                                                       /* Blinker Demo */

// ------- Preamble -------- //
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */

void POV(uint8_t oneByte){

  PORTB = oneByte;
  _delay_ms(2);

}

int main(void) {

  // -------- Inits --------- //
  DDRB = 0xff;            /* Data Direction Register B:
                                   writing a enable all output. */

  // ------ Event loop ------ //
  while (1) {
    POV(0b00001110);
    POV(0b00011000);
    POV(0b10111101);
    POV(0b01110110);
    POV(0b00111100);
    POV(0b00111100);
    POV(0b00111100);
    POV(0b01110110);
    POV(0b10111101);
    POV(0b00011000);
    POV(0b00001110);

    PORTB = 0;
    _delay_ms(10);
  
  }                                                  /* End event loop */
  return (0);                            /* This line is never reached */
}
