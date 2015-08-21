#include <avr/io.h>
#include <util/delay.h>

#define DELAYTIME 85
#define ledPort PORTB
#define ledPin PINB
#define ledDDR DDRB

 int main(void)
{
	uint8_t i;
	ledDDR = 0b11111111;

	while(1){
		while(i<7){

			ledPort = (1<<i); // does the inverse ~(1<<i)
			_delay_ms(DELAYTIME);
			i++;
		}

	while(i>0){

		ledPort = (1<<i);
		_delay_ms(DELAYTIME);
		i--;
	}

	}
	return 0;
}