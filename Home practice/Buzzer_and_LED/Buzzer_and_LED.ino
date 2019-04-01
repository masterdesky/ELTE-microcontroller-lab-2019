//www.elegoo.com
//2016.12.08

int buzzer = 12;  // The pin of the active buzzer
int ledpin_1 = 8;   // The pin of the attached LED
int ledpin_2 = 7;   // The pin of the attached LED
void setup()
{
  pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
}
void loop()
{
  digitalWrite(ledpin_1, HIGH);   // turn the LED on (HIGH is the voltage level)
  //output an frequency
  for(int i=0;i<10;i++) {
    digitalWrite(buzzer,HIGH);
    delay(50);//wait for 1ms
    digitalWrite(buzzer,LOW);
    delay(50);//wait for 1ms
  }
  digitalWrite(ledpin_1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledpin_2, HIGH);   // turn the LED on (HIGH is the voltage level)
  //output another frequency
  for(int i=0;i<10;i++) {
    digitalWrite(buzzer,HIGH);
    delay(50);//wait for 2ms
    digitalWrite(buzzer,LOW);
    delay(50);//wait for 2ms
  }
  digitalWrite(ledpin_2, LOW);    // turn the LED off by making the voltage LOW
}
