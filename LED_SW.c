/*
 * File:   LED_SW.c
 * Author: pooja
 *
 * Created on 16 May, 2025, 2:33 PM
 */


// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic16f877a.h>
#define _XTAL_FREQ 20000000
#define LED PORTB
#define SW RC0

void LED_Blinking();
void LED_Alternate();
void LED_Shifting();

void main(void) 
{
    int count = 0;
    TRISC0 = 1; //INPUT
    TRISB = 0X00; //Output
    
    SW = 0; 
    LED = 0X00; //LED'S ARE OFF
    while(1)
    {
        if(SW == 1)
        {
            __delay_ms(50);//Debouncing delay
            if(count<=3)
            {
                count++;
            }
            if(count>3)
            {
                count = 0;
            }
        }
        
        if(count == 1)
        {
            LED_Blinking();
        }
        else if(count == 2)
        {
            LED_Alternate();
        }
        else if(count == 3)
        {
            LED_Shifting();
        }
    }
    return;
}

void LED_Blinking()
{
    LED = 0XFF;
    __delay_ms(100);
    LED = 0X00;
    __delay_ms(100);
}
void LED_Alternate()
{
    LED = 0X55;
    __delay_ms(100);
    LED = 0XAA;
    __delay_ms(100);
}
void LED_Shifting()
{
    int i;
    unsigned int led_arr[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
    for(i=0;i<8;i++)
    {
        LED = led_arr[i];
        __delay_ms(100);
    }
}