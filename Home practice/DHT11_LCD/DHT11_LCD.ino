#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

dht DHT;

#define DHT11_PIN 7

void setup(){
  //Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  DHT.read11(DHT11_PIN);
  float t = DHT.temperature;
  float h = DHT.humidity;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  //Serial.print("Temp: ");
  lcd.print(t+273, 0);
  //Serial.print(t);
  //lcd.print((char)223);
  lcd.print(" K");
  //Serial.println(" K");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  //Serial.print("Humidity: ");
  lcd.print(h, 0);
  //Serial.print(h);
  lcd.print("%");
  //Serial.println("%");
  delay(2000);
}
