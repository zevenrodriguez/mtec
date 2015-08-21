/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#endif

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
#include <delays.h>
/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

void main (void)
{

 unsigned long counter = 0;
    OSCCON = 0b01110000;

    //TRISAbits.RA2 = 0;
    TRISBbits.RB0 = 0;

    //LATAbits.LA2 = 1;
    LATBbits.LB0 = 1;

    while(1){
        
         counter = 0;
        while(counter < 120000){ //max value of counter is 65535
            counter++;
        }

        //^= makes LA1 toggle its value
       // LATAbits.LA2 ^= 1;
         LATBbits.LB0 ^= 1;
    }
    {

    }

}