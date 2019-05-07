#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <wiringPi.h>
#include <stdlib.h>

#define PIN_TRIGGER 29 // GPIO21
#define PIN_ECHO 28 // GPIO20
#define Puffer 2 // The maximum ammount of difference between the lowest and highest, allready sortet Members.
#define RangeHat 10 // Range, Sonic Sensor need to trigger.


//unnecessary, dont touch it.

long getMicrotime(){
  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);
  return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}


//int float pinMode.. you know the shit.

int main(void)
{
  wiringPiSetup();
  pinMode(PIN_TRIGGER, OUTPUT);
  digitalWrite(PIN_TRIGGER, LOW);
  pinMode(PIN_ECHO, INPUT);
  int echo, previousEcho, lowHigh, highLow;
  long startTime, stopTime, difference;
  float rangeCm;
  int random = 0;
  int GryfMitglieder = 0;
  int SlythMitglieder = 0;
  int HuffMitglieder = 0;
  int RaveMitglieder = 0;


//Sensor-Range-Check
  
 for(;;){
     digitalWrite(PIN_TRIGGER, HIGH);
     usleep(10);
     digitalWrite(PIN_TRIGGER, LOW);
     lowHigh = highLow = echo = previousEcho = 0;
        while(0 == lowHigh || highLow == 0) {
            previousEcho = echo;
            echo = digitalRead(PIN_ECHO);
                if(0 == lowHigh && 0 == previousEcho && 1 == echo) {
                    lowHigh = 1;
                    startTime = getMicrotime();
                }
                if(1 == lowHigh && 1 == previousEcho && 0 == echo) {
                     highLow = 1;
                     stopTime = getMicrotime();
                }
          }
  difference = stopTime - startTime;
  rangeCm = difference / 58;
  printf("Range: %.0f cm\n",rangeCm);
  delay(500);

   
//Sorting People to random Houses.   
//Checking if the Sensor-Module is trigged. 
   
   if (rangeCm<=RangeHat) {
        ENTER:
        random = (rand() % 4);
        switch (random) {
            case 0:
                if(GryfMitglieder>=SlythMitglieder+Puffer||GryfMitglieder>=HuffMitglieder+Puffer||GryfMitglieder>=RaveMitglieder+Puffer)
                goto ENTER;
                else
                GryfMitglieder++;
                system("omxplayer h-gryff1.ogg ");
                break;
            case 1:
                if(SlythMitglieder>=GryfMitglieder+Puffer||SlythMitglieder>=HuffMitglieder+Puffer||RaveMitglieder>=RaveMitglieder+Puffer)
                goto ENTER;
                else
                SlythMitglieder++;
                system("omxplayer h-slyth1.ogg ");
                break;
            case 2:
                if(HuffMitglieder>=GryfMitglieder+Puffer||HuffMitglieder>=SlythMitglieder+Puffer||HuffMitglieder>=RaveMitglieder+Puffer)
                goto ENTER;
                else
                HuffMitglieder++;
                system("omxplayer h-huffl1.ogg ");
                break;
            case 3:
                if(RaveMitglieder>=GryfMitglieder+Puffer||RaveMitglieder>=SlythMitglieder+Puffer||RaveMitglieder>=HuffMitglieder+Puffer)
                goto ENTER;
                else
                RaveMitglieder++;
                system("omxplayer h-raven1.ogg ");
                break;
        };
};

  
   
   
//Loop until pressed Button is released.   
//Sensor-Range-Check
   
 while(rangeCm<=RangeHat){
    digitalWrite(PIN_TRIGGER, HIGH);
    usleep(10);
    digitalWrite(PIN_TRIGGER, LOW);
    lowHigh = highLow = echo = previousEcho = 0;
        while(0 == lowHigh || highLow == 0) {
           previousEcho = echo;
           echo = digitalRead(PIN_ECHO);
                if(0 == lowHigh && 0 == previousEcho && 1 == echo) {
                     lowHigh = 1;
                     startTime = getMicrotime();
                }
                if(1 == lowHigh && 1 == previousEcho && 0 == echo) {
                     highLow = 1;
                     stopTime = getMicrotime();
                }
         }
    difference = stopTime - startTime;
    rangeCm = difference / 58;

//Statusscreen with WAITING while Button is pressed.
   
   system("clear");
   printf("G S H R \n");
   printf("%i %i %i %i \n",GryfMitglieder,SlythMitglieder,HuffMitglieder,RaveMitglieder);
   printf("Range: %.0f cm WAITING\n",rangeCm);
   delay(500);
};
   

//Statusscreen   
   
system("clear");
printf("G S H R \n");
printf("%i %i %i %i \n",GryfMitglieder,SlythMitglieder,HuffMitglieder,RaveMitglieder);
};
  return 0;
}
