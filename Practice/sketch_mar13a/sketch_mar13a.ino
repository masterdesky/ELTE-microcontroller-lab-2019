String RX_string = "";
String RX_string_displayed = "";
int RX_string_length = 0;
char RX_byte = '\n';

int sensorPin = A0;
int sensorValue = 0;
int outputValue = 0;
int ledPin = 13;

// include the library code:
#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"

// Connect via i2c, default address #0 (A0-A2 not jumpered)
Adafruit_LiquidCrystal lcd(0);

void setup() {
  
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  // lcd.print("hello, world!");
}

void loop() {
  
  lcd.setCursor(0, 0);
  lcd.print("                ");

  sensorValue = analogRead(sensorPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  lcd.setCursor(0, 0);
  lcd.print("LED light = ");

  lcd.setCursor(13, 0);
  lcd.print(outputValue);
  analogWrite(ledPin, outputValue);
  delay(100);
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);
}
