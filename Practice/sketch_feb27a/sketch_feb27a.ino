int pushButton = 2;
String RX_string = "";
char RX_byte = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(pushButton, INPUT);   // digital sensor is on digital pin pushButton
  
}

void loop() {
  if (Serial.available() > 0) {
    RX_byte = Serial.read();
    
    if (RX_byte != '\n') {
      RX_string += RX_byte;
      
      if(RX_string == "?k") {
        RX_string = "";
        while(true) {
          // put your main code here, to run repeatedly:
          // read the input pin:
          int buttonState = digitalRead(pushButton);
          // print out the state of the button:
          Serial.println(buttonState);
          delay(1000);        // delay in between reads for stability
          
          RX_byte = Serial.read();
          Serial.println(RX_byte);
          if (RX_byte != '\n') {
            RX_string += RX_byte;
            if(RX_string == "b") {
              break;
            }
          }
        }
      }
    }
    else {
      Serial.println("Unknown command, try \'?k\'");
      RX_string = "";
    }
  }
  else {
    Serial.println("Waiting for input...");
    delay(300);
  }
}
