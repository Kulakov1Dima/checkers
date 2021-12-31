#include "Configuration.h"
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel ledMatrix = Adafruit_NeoPixel(32, matrixLed, NEO_GRB + NEO_KHZ800);

String x = "";
String y = "";

String checkersMatrix[] = {"H8", "F8", "D8", "B8", "A7", "C7", "E7", "G7", "H6",
"F6", "D6", "B6", "A5", "C5", "E5", "G5", "H4", "F4", "D4", "B4", "A3", "C3", "E3",
"G3", "H2", "F2", "D2", "B2", "A1", "C1", "E1", "G1"};

int foundLEDs[] = {32, 32};

void matrixON(){
    ledMatrix.setBrightness(50);
    ledMatrix.begin();
    for (int i = 0; i < 12; i++) {
        ledMatrix.setPixelColor(i, ledMatrix.Color(255, 255, 255));
        ledMatrix.show();
    }
    for (int i = 20; i < 32; i++) {
        ledMatrix.setPixelColor(i, ledMatrix.Color(255,0,0));
        ledMatrix.show();
    }
}

void matrixLoop(String* data){

    String dataMain = *data;
    dataMain.replace(" ", "");
    dataMain.toUpperCase();

    byte q = 0;
    for (int i = 0; i < dataMain.length(); i++) {
        for (char w = '1'; w < '9'; w++)
            if (dataMain.charAt(i) == w) {
                q++;
                if (q == 1)x = dataMain.substring(i - 1, i + 1);
                if (q == 2)y = dataMain.substring(i - 1, i + 1);
            }
    }

    String nulPozition = "";

    if (x.charAt(0) - 2 == y.charAt(0)) {
        nulPozition = char(x.charAt(0) - 1);
        int x1 = x.charAt(1) - 48;
        int y1 = y.charAt(1) - 48;
        if (x1 - 2 == y1)nulPozition = nulPozition + (y1 + 1);
        if (x1 + 2 == y1)nulPozition = nulPozition + (y1 - 1);
    }

    if (x.charAt(0) + 2 == y.charAt(0)) {
        int x1 = x.charAt(1) - 48;
        int y1 = y.charAt(1) - 48;
        nulPozition = char (x.charAt(0) + 1);
        if (x1 - 2 == y1)nulPozition = nulPozition + (y1 + 1);
        if (x1 + 2 == y1)nulPozition = nulPozition + (y1 - 1);
    }
    Serial.println("Data Server:");
    Serial.println(x);
    Serial.println(y);    
    game(nulPozition);
}

void definition_of_LEDs(){
    bool firstLed = true;
    for(int matrixLeds = 0; matrixLeds < 32; matrixLeds++){
        if(firstLed)if(x == checkersMatrix[matrixLeds]){
                        foundLEDs[0] = matrixLeds;
                        firstLed = false;
                    }
        if(y == checkersMatrix[matrixLeds]) foundLEDs[1] = matrixLeds;
    }
}

void game(String killPawn){
    definition_of_LEDs();
    if(foundLEDs[0] != 0){
        if(ledMatrix.getPixelColor(foundLEDs[1]) == 0){
            uint32_t color = ledMatrix.getPixelColor(foundLEDs[0]);
            ledMatrix.setPixelColor(foundLEDs[0], 0);
            ledMatrix.setPixelColor(foundLEDs[1], color);
            if(killPawn.length()>0)killedPawn(&killPawn);
            ledMatrix.show();
        }
    }
}

void killedPawn(String* killPawn){
    for(int matrixLeds = 0; matrixLeds < 32; matrixLeds++)
        if(*killPawn == checkersMatrix[matrixLeds])ledMatrix.setPixelColor(matrixLeds, 0);
} 