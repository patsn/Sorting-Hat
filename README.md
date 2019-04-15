# Sorting-Hat
Sorting Hat .c for Raspberry Pi 3 B+ using Wiring-Pi

A .c script playing a random House-Soundfile each time a button is pressed on the chosen GPIO PIN.

## PUFFER
'PUFFER' is used, to not have a big spike between two Houses or more.
For Example: If PUFFER is set to 5, the following is possible...

>G S H R
>
>0 5 5 5

But following is not, because G and R are more than PUFFER(=5) apart.

>G S H R
>
>0 5 5 6

