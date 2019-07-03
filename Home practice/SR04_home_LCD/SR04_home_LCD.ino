// LCD 16x2
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

// SR04 Ultrasound sensor
#include "SR04.h"

int TRIG_PIN = 9;
int ECHO_PIN = 10;
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);

// Store distance value
long distance;
// Store HIGH pulse duration
long duration;

void setup() {
  //Serial.begin(9600);
  lcd.begin(16, 2);

  // Define input and output for initiating and detecting pulses
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
   
  delay(1000);
}

void loop() {
  // More code: https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/
  distance = sr04.Distance();
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Dist: ");
  //Serial.print(distance);
  //Serial.println(" cm");
  lcd.print(distance);
  lcd.print(" cm");
  delay(1000);
}
