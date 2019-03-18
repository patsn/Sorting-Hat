#include <stdio.h>
#include <wiringPi.h>
int main (void)
{
  wiringPiSetup () ;
  pinMode (1, OUTPUT) ;
  for (;;)
  {
    digitalWrite (1, HIGH) ; delay (50) ;
    digitalWrite (1,  LOW) ; delay (50) ;
  }
  return 0 ;
}