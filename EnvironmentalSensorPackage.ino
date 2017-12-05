
#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 3
#define DHTTYPE DHT22

LiquidCrystal disp(6, 5, 9, 10, 11, 12);

//degree bitmap
byte degree[8] = {
  B01000,
  B10100,
  B01000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

const int pResistor = A1;

int selector = 0;
int buttonState = 0;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //create degree bitmap
  disp.createChar(0, degree);

  //16x2 LCD screen
  disp.begin(16, 2);

  pinMode(13, INPUT);
  pinMode(pResistor, INPUT);
  Serial.begin(9600);
}


void loop() {
  disp.clear();

  buttonState = digitalRead(13);

  //Serial data stream
  Serial.println(dht.readTemperature(true));
  float rawLum = analogRead(pResistor);
  Serial.println(rawLum/1023*100);
  Serial.println(dht.readHumidity());
  
  readButton();
  if (selector == 0){
    disp.print("Air Temperature:") ;

    float roundedTempF = dht.readTemperature(true);

    //print temperature on bottom line
    disp.setCursor(0,1);
    disp.print(roundedTempF, 0);
    disp.write(byte(0));
    disp.print("F");
    delay(1000);
  }
  else if (selector == 1){
    disp.print("Luminosity:");
    float raw = analogRead(pResistor);
    disp.setCursor(0,1);
    disp.print(raw/1023*100);
    disp.print("%");
    delay(1000);
  }
  else if (selector == 2) {
    disp.print("Humidity:");
    float hum = dht.readHumidity();
    disp.setCursor(0,1);
    disp.print(hum);
    delay(1000);
  }
  else{
    selector = -1;
  }
  
}

int readButton(){
  if (buttonState == HIGH) {
    selector++;
  }
}

