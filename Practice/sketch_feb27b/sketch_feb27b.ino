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
      
      if(RX_string == "ledON") {
        RX_string = "";
        Serial.println("led turning on...");
        digitalWrite(pushButton, HIGH);
        delay(1500);
        Serial.println("led turning on...");
        Serial.println("Waiting for new input...");
      }
      
      else if(RX_string == "ledOFF") {
        RX_string == "";
      }
      
      else {
        Serial.println("Unknown command " + RX_string + " try \'ledON\' or \'ledOFF\'");
      }
    }
  }
}
