#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#define LED     1

int main (void)
{
    printf ("Raspberry Pi Quick2Wire blink\n") ;

    wiringPiSetup () ;
    pinMode (LED, OUTPUT) ;
    pinMode (4,INPUT);

   for(;;) {
       if (digitalRead(4)) {

               system("omxplayer h-gryff1.ogg");

       };
   };
    return 0 ;
}