const int Pin1 = 3;
const int Pin2 = 5;
const int Pin3 = 6;
const int Pin4 = 9;
const int Pin5 = 10;
const int Pin6 = 11;
const int Pin7 = 13;

int bright = 0;
float fadeAmount = 5;

const int short_delay = 12;
const int delaying = 100;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
  pinMode(Pin5, OUTPUT);
  pinMode(Pin6, OUTPUT);
  pinMode(Pin7, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  analogWrite(Pin1, bright);
  analogWrite(Pin2, bright);
  analogWrite(Pin3, bright);
  analogWrite(Pin4, bright);
  analogWrite(Pin5, bright);
  analogWrite(Pin6, bright);
  analogWrite(Pin7, bright);
  // change the brightness for next time through the loop:
  bright = bright + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (bright <= 0 || bright >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(short_delay);
}
