#include "Adafruit_NeoPixel.h"

Adafruit_NeoPixel ledMatrix = Adafruit_NeoPixel(32, led, NEO_GRB + NEO_KHZ800);

String x = "";
String y = "";
int matrix[32];

void ledSetup() {
  ledMatrix.setBrightness(brightnessLevel);
  ledMatrix.begin();
  for (int i = 0; i < 12; i++) {
    ledMatrix.setPixelColor(i, colour1);
    matrix[i] = 1;
    ledMatrix.show();
    delay(3);
  }
  for (int i = 20; i < 32; i++) {
    ledMatrix.setPixelColor(i, colour2);
    matrix[i] = 2;
    ledMatrix.show();
    delay(3);
  }
}

void(* resetFunc) (void) = 0;

void mainMatrix(String dataMain) {
  // y = dataMain.substring(dataMain.length() - 2, dataMain.length());
  // x = dataMain.substring(0, 2);
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
  //if (x.length() > 2) x = x.substring(0, 2);
  //if (y.length() > 2) y = y.substring(0, 2);

  int led = 99, ledY = 99, n = 99;
  if (x == "A1")led = CH8;
  if (x == "A3")led = CH6;
  if (x == "A5")led = CH4;
  if (x == "A7")led = CH2;
  if (x == "B2")led = CG7;
  if (x == "B4")led = CG5;
  if (x == "B6")led = CG3;
  if (x == "B8")led = CG1;
  if (x == "C1")led = CF8;
  if (x == "C3")led = CF6;
  if (x == "C5")led = CF4;
  if (x == "C7")led = CF2;
  if (x == "D2")led = CE7;
  if (x == "D4")led = CE5;
  if (x == "D6")led = CE3;
  if (x == "D8")led = CE1;
  if (x == "E1")led = CD8;
  if (x == "E3")led = CD6;
  if (x == "E5")led = CD4;
  if (x == "E7")led = CD2;
  if (x == "F2")led = CC7;
  if (x == "F4")led = CC5;
  if (x == "F6")led = CC3;
  if (x == "F8")led = CC1;
  if (x == "G1")led = CB8;
  if (x == "G3")led = CB6;
  if (x == "G5")led = CB4;
  if (x == "G7")led = CB2;
  if (x == "H2")led = CA7;
  if (x == "H4")led = CA5;
  if (x == "H6")led = CA3;
  if (x == "H8")led = CA1;

  if (y == "A1")ledY = CH8;
  if (y == "A3")ledY = CH6;
  if (y == "A5")ledY = CH4;
  if (y == "A7")ledY = CH2;
  if (y == "B2")ledY = CG7;
  if (y == "B4")ledY = CG5;
  if (y == "B6")ledY = CG3;
  if (y == "B8")ledY = CG1;
  if (y == "C1")ledY = CF8;
  if (y == "C3")ledY = CF6;
  if (y == "C5")ledY = CF4;
  if (y == "C7")ledY = CF2;
  if (y == "D2")ledY = CE7;
  if (y == "D4")ledY = CE5;
  if (y == "D6")ledY = CE3;
  if (y == "D8")ledY = CE1;
  if (y == "E1")ledY = CD8;
  if (y == "E3")ledY = CD6;
  if (y == "E5")ledY = CD4;
  if (y == "E7")ledY = CD2;
  if (y == "F2")ledY = CC7;
  if (y == "F4")ledY = CC5;
  if (y == "F6")ledY = CC3;
  if (y == "F8")ledY = CC1;
  if (y == "G1")ledY = CB8;
  if (y == "G3")ledY = CB6;
  if (y == "G5")ledY = CB4;
  if (y == "G7")ledY = CB2;
  if (y == "H2")ledY = CA7;
  if (y == "H4")ledY = CA5;
  if (y == "H6")ledY = CA3;
  if (y == "H8")ledY = CA1;

  if (nulPozition == "A1")n = CH8;
  if (nulPozition == "A3")n = CH6;
  if (nulPozition == "A5")n = CH4;
  if (nulPozition == "A7")n = CH2;
  if (nulPozition == "B2")n = CG7;
  if (nulPozition == "B4")n = CG5;
  if (nulPozition == "B6")n = CG3;
  if (nulPozition == "B8")n = CG1;
  if (nulPozition == "C1")n = CF8;
  if (nulPozition == "C3")n = CF6;
  if (nulPozition == "C5")n = CF4;
  if (nulPozition == "C7")n = CF2;
  if (nulPozition == "D2")n = CE7;
  if (nulPozition == "D4")n = CE5;
  if (nulPozition == "D6")n = CE3;
  if (nulPozition == "D8")n = CE1;
  if (nulPozition == "E1")n = CD8;
  if (nulPozition == "E3")n = CD6;
  if (nulPozition == "E5")n = CD4;
  if (nulPozition == "E7")n = CD2;
  if (nulPozition == "F2")n = CC7;
  if (nulPozition == "F4")n = CC5;
  if (nulPozition == "F6")n = CC3;
  if (nulPozition == "F8")n = CC1;
  if (nulPozition == "G1")n = CB8;
  if (nulPozition == "G3")n = CB6;
  if (nulPozition == "G5")n = CB4;
  if (nulPozition == "G7")n = CB2;
  if (nulPozition == "H2")n = CA7;
  if (nulPozition == "H4")n = CA5;
  if (nulPozition == "H6")n = CA3;
  if (nulPozition == "H8")n = CA1;

  if (n < 99) {
    matrix[n] = 0;
    ledMatrix.setPixelColor(n, 0, 0, 0);
    ledMatrix.show();
  }
  if (matrix[ledY] != matrix[led]) {
    if (matrix[led] == 1) {
      ledMatrix.setPixelColor(ledY, colour1);
      ledMatrix.show();
      matrix[ledY] = 1;
      matrix[led] = 0;
      ledMatrix.setPixelColor(led, 0, 0, 0);
      ledMatrix.show();
    }
    if (matrix[led] == 2) {
      ledMatrix.setPixelColor(ledY, colour2);
      ledMatrix.show();
      matrix[ledY] = 2;
      matrix[led] = 0;
      ledMatrix.setPixelColor(led, 0, 0, 0);
      ledMatrix.show();
    }
  }
    Serial.println(dataMain);
  if(dataMain=="PEREZAGRUZGRU")resetFunc();
  if(dataMain=="ALCAPEREZAGRUZGRU")resetFunc();

}
/*void ledRandom() {
  if (millis() - timeRandomLed > 2500) {
    for (int i = 0; i < 32; i++) {
      if ((randomLightR < brightnessLevel - 2) || (randomLightG < brightnessLevel - 2) || (randomLightB < brightnessLevel - 2))ledMatrix.setPixelColor(i, ledMatrix.Color(randomLightR += random(0, 2), randomLightG += random(0, 2), randomLightB += random(0, 2)));
      else ledMatrix.setPixelColor(i, ledMatrix.Color(randomLightR -= random(0, 2), randomLightG -= random(0, 2), randomLightB -= random(0, 2)));
    }
    ledMatrix.show();
    timeRandomLed = millis();
  }
  }
*/
