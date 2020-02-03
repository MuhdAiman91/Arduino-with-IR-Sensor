/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 04/02/2019
Author  : 
Company : 
Comments: 


Chip type               : ATmega328P
Program type            : Application
AVR Core Clock frequency: 16,000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega328p.h>
#include <lcd_i2c_cvavr.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
// Declare your global variables here
#define button1 PIND.7;
#define button2 PINB.0;
#define button3 PINB.1;
#define button4 PINB.2;
#define Trigger PORTC.0;
#define ECHO PINC.1;
int eeprom;
char buff[5], buff2[5];
int mode = 4, hitung, count, brng = 0;
float jarak, jrk;
unsigned char baca_sensor()
{
 //SEND TRIGGER 
 count = 0;
 PORTC.1 = 1;
 delay_us(15);
 PORTC.1 = 0;
 
 //RESET COUNTER
 delay_us(2);
 while (PINC.0 == 0)
 { 
    brng = 0;
 };
 while (PINC.0 == 1)
 {
    count++;
 }   
 jrk = count*0.020242/2;  
 brng = 1;
 return jrk;
}
// Standard Input/Output functions
#include <stdio.h>
#include <stdlib.h>
// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
// Reinitialize Timer 0 value
TCNT0=0x06;
// Place your code here

}

// Voltage Reference: AVCC pin
#define ADC_VREF_TYPE ((0<<REFS1) | (1<<REFS0) | (0<<ADLAR))

// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | ADC_VREF_TYPE;
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=(1<<ADSC);
// Wait for the AD conversion to complete
while ((ADCSRA & (1<<ADIF))==0);
ADCSRA|=(1<<ADIF);
return ADCW;
}

void main(void)
{
// Declare your local variables here

// Crystal Oscillator division factor: 1
#pragma optsize-
CLKPR=(1<<CLKPCE);
CLKPR=(0<<CLKPCE) | (0<<CLKPS3) | (0<<CLKPS2) | (0<<CLKPS1) | (0<<CLKPS0);
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif

// Input/Output Ports initialization
// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=P Bit1=P Bit0=P 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (1<<PORTB2) | (1<<PORTB1) | (1<<PORTB0);

// Port C initialization
// Function: Bit6=In Bit5=Out Bit4=Out Bit3=In Bit2=In Bit1=Out Bit0=In 
DDRC=(0<<DDC6) | (1<<DDC5) | (1<<DDC4) | (0<<DDC3) | (0<<DDC2) | (1<<DDC1) | (0<<DDC0);
// State: Bit6=T Bit5=0 Bit4=0 Bit3=T Bit2=T Bit1=0 Bit0=T 
PORTC=(0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (0<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (1<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=P Bit6=T Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=T Bit0=T 
PORTD=(1<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 250,000 kHz
// Mode: Normal top=0xFF
// OC0A output: Disconnected
// OC0B output: Disconnected
// Timer Period: 1 ms
TCCR0A=(0<<COM0A1) | (0<<COM0A0) | (0<<COM0B1) | (0<<COM0B0) | (0<<WGM01) | (0<<WGM00);
TCCR0B=(0<<WGM02) | (0<<CS02) | (1<<CS01) | (1<<CS00);
TCNT0=0x06;
OCR0A=0x00;
OCR0B=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2A output: Disconnected
// OC2B output: Disconnected
ASSR=(0<<EXCLK) | (0<<AS2);
TCCR2A=(0<<COM2A1) | (0<<COM2A0) | (0<<COM2B1) | (0<<COM2B0) | (0<<WGM21) | (0<<WGM20);
TCCR2B=(0<<WGM22) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2A=0x00;
OCR2B=0x00;

// Timer/Counter 0 Interrupt(s) initialization
TIMSK0=(0<<OCIE0B) | (0<<OCIE0A) | (1<<TOIE0);

// Timer/Counter 1 Interrupt(s) initialization
TIMSK1=(0<<ICIE1) | (0<<OCIE1B) | (0<<OCIE1A) | (0<<TOIE1);

// Timer/Counter 2 Interrupt(s) initialization
TIMSK2=(0<<OCIE2B) | (0<<OCIE2A) | (0<<TOIE2);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// Interrupt on any change on pins PCINT0-7: Off
// Interrupt on any change on pins PCINT8-14: Off
// Interrupt on any change on pins PCINT16-23: Off
EICRA=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
EIMSK=(0<<INT1) | (0<<INT0);
PCICR=(0<<PCIE2) | (0<<PCIE1) | (0<<PCIE0);

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART0 Mode: Asynchronous
// USART Baud Rate: 9600
UCSR0A=(0<<RXC0) | (0<<TXC0) | (0<<UDRE0) | (0<<FE0) | (0<<DOR0) | (0<<UPE0) | (0<<U2X0) | (0<<MPCM0);
UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (1<<RXEN0) | (1<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);
UCSR0C=(0<<UMSEL01) | (0<<UMSEL00) | (0<<UPM01) | (0<<UPM00) | (0<<USBS0) | (1<<UCSZ01) | (1<<UCSZ00) | (0<<UCPOL0);
UBRR0H=0x00;
UBRR0L=0x67;

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
// Digital input buffer on AIN0: On
// Digital input buffer on AIN1: On
DIDR1=(0<<AIN0D) | (0<<AIN1D);

// ADC initialization
// ADC Clock frequency: 1000,000 kHz
// ADC Voltage Reference: AVCC pin
// ADC Auto Trigger Source: Free Running
// Digital input buffers on ADC0: On, ADC1: On, ADC2: On, ADC3: On
// ADC4: On, ADC5: On
DIDR0=(0<<ADC5D) | (0<<ADC4D) | (0<<ADC3D) | (0<<ADC2D) | (0<<ADC1D) | (0<<ADC0D);
ADMUX=ADC_VREF_TYPE;
ADCSRA=(1<<ADEN) | (0<<ADSC) | (1<<ADATE) | (0<<ADIF) | (0<<ADIE) | (1<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);
ADCSRB=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

// Global enable interrupts
#asm("sei")
lcd_begin(0x27, 16,2); // alamat lcd i2c
lcd_clear();
while (1)
      {
      // Place your code here 
      if (!PINB.2)
       {
            PORTD.5 = 1;
            PORTD.4 = 0;
            PORTD.3 = 0;
            PORTD.2 = 0;
            mode = 3;
            delay_ms(500);
       }
       else if (!PIND.7)
       {
            PORTD.5 = 0;
            PORTD.4 = 1;
            PORTD.3 = 0;
            PORTD.2 = 0;
            mode = 1;
            delay_ms(500);
       }
       else if (!PINB.0)
       {
            PORTD.5 = 0;
            PORTD.4 = 0;
            PORTD.3 = 1;
            PORTD.2 = 0;
            mode = 2;
            delay_ms(500);
       } 
       else if (!PINB.1)
       {
            PORTD.5 = 0;
            PORTD.4 = 0;
            PORTD.3 = 0;
            PORTD.2 = 1;
            mode = 0;
            delay_ms(500);
       } 
       else if (mode == 1)
       {
            lcd_gotoxy(0,1);
            lcd_print("Manual +");
            hitung = hitung + 1;
            sprintf(buff2, "%d", hitung);
            lcd_gotoxy(9,1);
            lcd_print(buff2);  
            delay_ms(500);
       }
       else if (mode == 2)
       {
            lcd_print("Manual -");
            hitung = hitung - 1;
            sprintf(buff2, "%d", hitung);
            lcd_gotoxy(0,1);
            lcd_print(buff2);  
            delay_ms(500);
       }      
       else if (mode == 3)
       {
            lcd_clear(); 
            jarak = baca_sensor();
            if (jarak >= 1)
            {                
              lcd_gotoxy(0,1);
              lcd_print("Autom-");
              hitung = hitung - 1;
              sprintf(buff2, "%d", hitung);
              lcd_gotoxy(9,1);
              lcd_print(buff2);  
              delay_ms(500);
            } 
            else if (jarak <= 0)
            {         
              lcd_gotoxy(0,1);
              lcd_print("Gak Terdeteksi"); 
              delay_ms(500);
            }
       }     
       else if (mode == 0)
       {
            jarak = baca_sensor();
            if (jarak >= 1)
            {    
              lcd_gotoxy(0,1);
              lcd_print("Autom+");
              hitung = hitung + 1;
              sprintf(buff2, "%d", hitung);
              lcd_gotoxy(9,1);
              lcd_print(buff2);  
              delay_ms(500);
            } 
            else if (jarak <= 1)
            {    
              lcd_gotoxy(0,1);
              lcd_print("Gak Terdeteksi");  
              delay_ms(500);
            }
       }
       else if (mode == 4)
       {
          jarak = baca_sensor();
          lcd_clear();
          if (jrk > 15){jrk = 0;brng = 0;}//limit is 15 inch or 38.1cm
          else if(jrk <0){jrk = 0;brng = 0;}
          lcd_print("JARAK= ");
          ftoa (jrk,2,buff);  
          lcd_gotoxy(7,0);
          lcd_print(buff);
          lcd_gotoxy(12,0);
          lcd_print("Inch");
          lcd_gotoxy(0,1);
          lcd_print("Jumlah = "); 
          if(jrk >0 && jrk <= 5)
          {
          hitung = hitung + brng;
          } 
          else if(jrk >5 && jrk <= 15)
          { 
          hitung = hitung - brng;
          }
          sprintf(buff2, "%d", hitung);
          lcd_gotoxy(9,1);
          lcd_print(buff2);  
          delay_ms(1000);
       }     
      }
}
