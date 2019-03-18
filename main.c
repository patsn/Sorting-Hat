#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#define Puffer 2


int main (void)
{

    printf ("Sorting Hat wird ausgeführt! \n") ;
    wiringPiSetup () ;
    pinMode (4,INPUT);

    int random = 0;
    int GryfMitglieder = 0;
    int SlythMitglieder = 0;
    int HuffMitglieder = 0;
    int RaveMitglieder = 0;

while(1){
    if (digitalRead(4)) {
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
                break;
                else
                RaveMitglieder++;
                system("omxplayer h-raven1.ogg ");
                break;
        };
    };



while(digitalRead(4));
delay(100);
system("clear");
printf("G S H R \n");
printf("%i %i %i %i \n",GryfMitglieder,SlythMitglieder,HuffMitglieder,RaveMitglieder);
};
return 0;
}
//system("omxplayer h-gryff1.ogg");
