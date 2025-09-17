/*
 * File:   LED_Shifting.c
 * Author: pooja
 *
 * Created on 16 May, 2025, 2:57 PM
 */


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

#include <xc.h>

void main(void) 
{
    int i;
    unsigned int arr[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
    
    TRISB = 0X00; //PORT B AS AN OUTPUT
    LED = 0X00;
    while(1)
    {
        for(i=0;i<8;i++)
        {
         LED = arr[i];
         __delay_ms(200);
        }   
    }
    return;
}