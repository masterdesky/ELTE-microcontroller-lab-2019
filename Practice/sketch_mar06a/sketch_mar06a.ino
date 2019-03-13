String RX_string = "";
String RX_string_displayed = "";
int RX_string_length = 0;
char RX_byte = '\n';

// include the library code:
#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"

// Connect via i2c, default address #0 (A0-A2 not jumpered)
Adafruit_LiquidCrystal lcd(0);

void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Waiting for input...");
  
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  // lcd.print("hello, world!");
}

void loop() {

  if(Serial.available() > 0) {
    RX_byte = Serial.read();
    
    if(RX_byte != '0' && RX_string_length != 16) {

      Serial.println(RX_byte);

      if(RX_byte != '\n') {
        RX_string += RX_byte;
        RX_string_length += 1;
      }
    }
  
    else {
      lcd.setCursor(0, 0);
      lcd.print("                ");
      RX_string_displayed = RX_string;
      RX_string = "";
      RX_string_length = 0;
  
      Serial.println(RX_string_displayed);
      lcd.setCursor(0, 0);
      lcd.print(RX_string_displayed);
    }
  }
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);
}
