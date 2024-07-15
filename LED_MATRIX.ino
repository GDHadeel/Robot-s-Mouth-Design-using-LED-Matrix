#include <LedControl.h>

int DIN = 11;
int CS =  10;
int CLK = 13;
LedControl lc = LedControl(DIN, CLK, CS, 1); 

byte circle[8] = {
    B00000000,
    B00000000,
    B00000000,
    B01111110,
    B10000001,
    B10000001,
    B01111110,
    B00000000
};

byte line[8] = {
    B00000000,
    B00000000,
    B00000000,
    B01111110,
    B10000001,
    B10000001,
    B01000010,
    B00111100
};

void setup() {
    lc.shutdown(0, false);       
    lc.setIntensity(0, 15);      
}

void loop() { 
    // circle pattern
    for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, circle[i]);
    }
    delay(100);

    // line pattern
    for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, line[i]);
    }
    delay(100);
}
