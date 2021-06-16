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
  if (x == "A1")led = 0;
  if (x == "A3")led = 8;
  if (x == "A5")led = 16;
  if (x == "A7")led = 24;
  if (x == "B2")led = 7;
  if (x == "B4")led = 15;
  if (x == "B6")led = 23;
  if (x == "B8")led = 31;
  if (x == "C1")led = 1;
  if (x == "C3")led = 9;
  if (x == "C5")led = 17;
  if (x == "C7")led = 25;
  if (x == "D2")led = 6;
  if (x == "D4")led = 14;
  if (x == "D6")led = 22;
  if (x == "D8")led = 30;
  if (x == "E1")led = 2;
  if (x == "E3")led = 10;
  if (x == "E5")led = 18;
  if (x == "E7")led = 26;
  if (x == "F2")led = 5;
  if (x == "F4")led = 13;
  if (x == "F6")led = 21;
  if (x == "F8")led = 29;
  if (x == "G1")led = 3;
  if (x == "G3")led = 11;
  if (x == "G5")led = 19;
  if (x == "G7")led = 27;
  if (x == "H2")led = 4;
  if (x == "H4")led = 12;
  if (x == "H6")led = 20;
  if (x == "H8")led = 28;

  if (y == "A1")ledY = 0;
  if (y == "A3")ledY = 8;
  if (y == "A5")ledY = 16;
  if (y == "A7")ledY = 24;
  if (y == "B2")ledY = 7;
  if (y == "B4")ledY = 15;
  if (y == "B6")ledY = 23;
  if (y == "B8")ledY = 31;
  if (y == "C1")ledY = 1;
  if (y == "C3")ledY = 9;
  if (y == "C5")ledY = 17;
  if (y == "C7")ledY = 25;
  if (y == "D2")ledY = 6;
  if (y == "D4")ledY = 14;
  if (y == "D6")ledY = 22;
  if (y == "D8")ledY = 30;
  if (y == "E1")ledY = 2;
  if (y == "E3")ledY = 10;
  if (y == "E5")ledY = 18;
  if (y == "E7")ledY = 26;
  if (y == "F2")ledY = 5;
  if (y == "F4")ledY = 13;
  if (y == "F6")ledY = 21;
  if (y == "F8")ledY = 29;
  if (y == "G1")ledY = 3;
  if (y == "G3")ledY = 11;
  if (y == "G5")ledY = 19;
  if (y == "G7")ledY = 27;
  if (y == "H2")ledY = 4;
  if (y == "H4")ledY = 12;
  if (y == "H6")ledY = 20;
  if (y == "H8")ledY = 28;

  if (nulPozition == "A1")n = 0;
  if (nulPozition == "A3")n = 8;
  if (nulPozition == "A5")n = 16;
  if (nulPozition == "A7")n = 24;
  if (nulPozition == "B2")n = 7;
  if (nulPozition == "B4")n = 15;
  if (nulPozition == "B6")n = 23;
  if (nulPozition == "B8")n = 31;
  if (nulPozition == "C1")n = 1;
  if (nulPozition == "C3")n = 9;
  if (nulPozition == "C5")n = 17;
  if (nulPozition == "C7")n = 25;
  if (nulPozition == "D2")n = 6;
  if (nulPozition == "D4")n = 14;
  if (nulPozition == "D6")n = 22;
  if (nulPozition == "D8")n = 30;
  if (nulPozition == "E1")n = 2;
  if (nulPozition == "E3")n = 10;
  if (nulPozition == "E5")n = 18;
  if (nulPozition == "E7")n = 26;
  if (nulPozition == "F2")n = 5;
  if (nulPozition == "F4")n = 13;
  if (nulPozition == "F6")n = 21;
  if (nulPozition == "F8")n = 29;
  if (nulPozition == "G1")n = 3;
  if (nulPozition == "G3")n = 11;
  if (nulPozition == "G5")n = 19;
  if (nulPozition == "G7")n = 27;
  if (nulPozition == "H2")n = 4;
  if (nulPozition == "H4")n = 12;
  if (nulPozition == "H6")n = 20;
  if (nulPozition == "H8")n = 28;

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
