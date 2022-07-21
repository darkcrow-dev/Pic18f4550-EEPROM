#include <Eeprom.h>
#include <LCD_ports.c>

int boton = 0;
int16 valor = 0;

void main()
{
   lcd_init();
   setup_oscillator(OSC_8MHZ|OSC_INTRC|OSC_31250|OSC_PLL_OFF);
   set_tris_A(0b00001110);
   set_tris_B(0b00000000);
   set_tris_E(0b0000000);
   
   while(1)
   {
   if(input(PIN_A1) == 1 && input(PIN_A2) == 0 && input(PIN_A3) == 0 && boton == 0)
   {
   boton = 1;
   }
   else if(input(PIN_A1) == 0 && input(PIN_A2) == 0 && input(PIN_A3) == 0 && boton == 1)
   {
   boton = 0;
   valor = 255;
   write_eeprom(0,valor);
   }
   else if(input(PIN_A1) == 0 && input(PIN_A2) == 1 && input(PIN_A3) == 0 && boton == 0)
   {
   boton = 2;
   }
   else if(input(PIN_A1) == 0 && input(PIN_A2) == 0 && input(PIN_A3) == 0 && boton == 2)
   {
   boton = 0;
   valor = read_eeprom(0);
   printf(lcd_putc, "\f%Lu", valor);
   }
   else if(input(PIN_A1) == 0 && input(PIN_A2) == 0 && input(PIN_A3) == 1 && boton == 0)
   {
   boton = 3;
   }
   else if(input(PIN_A1) == 0 && input(PIN_A2) == 0 && input(PIN_A3) == 0 && boton == 3)
   {
   boton = 0;
   write_eeprom(0,0);
   }
   
   
   }
}
