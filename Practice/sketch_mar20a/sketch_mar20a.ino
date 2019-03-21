int ledPin = 13;
int OneWireBus = 7;
float temperature = 0;


// include the library code:
#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"
#include "OneWire.h"
#include "DallasTemperature.h"

// Connect via i2c, default address #0 (A0-A2 not jumpered)
Adafruit_LiquidCrystal lcd(0);

// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(OneWireBus);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup() {
  // start serial port 
  Serial.begin(9600);
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  lcd.setCursor(0, 0);
  lcd.print(sensors.getTempCByIndex(0));

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);
}
