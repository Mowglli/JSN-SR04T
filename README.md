# JSN-SR04T

# Mode 0
For at sætte sensoren i mode 0 behøver du ikke at gøre noget ved den, da dette er den konfiguration, den leveres i.
Den kode, vi vil bruge, er i det væsentlige identisk med den kode, vi før har brugt til HC-SR04, hvilket giver mening, da Mode 0 er den tilstand, der emulerer en HC-SR04. 
En ændring er dog, at jeg har øget triggerpulsens pulsbredde til 20us, da jeg fandt den mere stabil på den måde.
# Mode 1
Tilstand 1-test vil bruge den samme tilslutning som den forrige test, men du skal først indstille sensoren til tilstand 1. 
Gør dette ved at bygge bro mellem "m1"-puderne på sensorens printkort.
Anvend mode 1.ino, til at læse dataene fra JSN-SRT04T.
