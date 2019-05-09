int buzzerPin = 9;
int LedPin_state = 13;
int LedPin_Mega = 7;
int LedPin_Soviet[] = {
  3, 4, 5
};
String readString;

#include "pitches.h"

// MEGALOVANIA
int megalovania[] = {
  NOTE_D4, NOTE_D4, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D5,
  NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_B3, NOTE_B3, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4,
  NOTE_F4, NOTE_G4, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_D4,
  NOTE_D4, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D5, NOTE_A4,
  NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_B3, NOTE_B3, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4,
  NOTE_G4, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4
};

// note durations and delays in milliseconds
int megalovania_noteDurations[] = {
  125, 125, 250, 250, 125, 250, 250, 125, 125, 125, 125, 125, 125, 125, 250,
  375, 125, 250, 250, 125, 125, 125, 125, 125, 250, 375, 125, 250, 250, 125,
  125, 125, 62, 62, 62, 62, 250, 375, 125, 250, 250, 125, 125, 125, 125,
  125, 250, 375, 125, 250, 250, 125, 125, 125, 125, 125, 125, 125, 250, 375,
  125, 250, 250, 125, 125, 125, 125, 125, 250, 375, 125, 250, 250, 125, 125,
  125, 62, 62, 62, 62, 250, 375, 125, 250, 250, 125, 125, 125
};

int megalovaniaDelays[] = {
  125, 125, 250, 375, 250, 250, 250, 125, 125, 125, 62, 62, 62, 62, 250,
  375, 250, 250, 250, 125, 125, 125, 125, 125, 250, 375, 250, 250, 250, 125,
  125, 125, 62, 62, 62, 62, 250, 375, 250, 250, 250, 125, 125, 125, 125,
  125, 250, 375, 250, 250, 250, 125, 125, 125, 62, 62, 62, 62, 250, 375,
  250, 250, 250, 125, 125, 125, 125, 125, 250, 375, 250, 250, 250, 125,
  125, 125, 62, 62, 62, 62, 250, 375, 250, 250, 250, 125, 125
};

// RUSSIAN ANTHEM
int soviet[] = {
  NOTE_DS4, NOTE_AS3,
  NOTE_DS4, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_G3, NOTE_G3,
  NOTE_C4, NOTE_AS3, NOTE_GS3, NOTE_AS3, NOTE_DS3, NOTE_DS3,
  NOTE_F3, NOTE_F3, NOTE_G3, NOTE_GS3, NOTE_GS3, NOTE_AS3,
  NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_AS3,
  NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_F4, NOTE_D4, NOTE_AS3,
  NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_G3, NOTE_G3,
  NOTE_C4, NOTE_AS3, NOTE_GS3, NOTE_AS3, NOTE_DS3,
  NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_AS3,
  NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_DS4,
  NOTE_F4, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_D4, NOTE_F4,
  NOTE_DS4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_C4,
  NOTE_D4, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_GS3, NOTE_AS3,
  NOTE_DS4, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_C4, NOTE_D4,
  NOTE_DS4, NOTE_C4, NOTE_DS4, NOTE_GS4,
  NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_F4,
  NOTE_G4, NOTE_DS4, NOTE_DS4,
  NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_D4,
  NOTE_DS4, NOTE_C4, NOTE_C4,
  NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_DS3, NOTE_DS3,
  NOTE_AS3, NOTE_C4, NOTE_D4,
  NOTE_DS4
};

// note durations and delays in milliseconds
int soviet_noteDurations[] = {
  2571, 429,
  857, 642, 204, 857, 429, 429,
  857, 642, 204, 857, 429, 429,
  857, 429, 429, 857, 429, 429,
  857, 429, 429, 1285, 429,
  857, 642, 204, 857, 429, 429,
  857, 642, 204, 857, 429, 429,
  857, 642, 204, 857, 857,
  857, 642, 204, 1285, 204,
  1714, 429, 429, 429, 429,
  1285, 429, 429, 429, 429, 429,
  1285, 429, 429, 429, 429, 429,
  1285, 429, 429, 429, 429, 429,
  857, 642, 429, 857, 642, 429,
  857, 429, 429, 1714,
  1714, 429, 429, 429, 429,
  1285, 429, 1714,
  1714, 429, 429, 429, 429,
  1285, 429, 1714,
  857, 429, 429, 857, 642, 204,
  1846, 923, 923,
  3692
};

int sovietDelays[] = {
  2571, 429,
  857, 642, 204, 857, 429, 429,
  857, 642, 204, 857, 429, 429,
  857, 429, 429, 857, 429, 429,
  857, 429, 429, 1285, 429,
  857, 642, 204, 857, 429, 429,
  857, 642, 204, 857, 429, 429,
  857, 642, 204, 857, 857,
  857, 642, 204, 1285, 204,
  1714, 429, 429, 429, 429,
  1285, 429, 429, 429, 429, 429,
  1285, 429, 429, 429, 429, 429,
  1285, 429, 429, 429, 429, 429,
  857, 642, 429, 857, 642, 429,
  857, 429, 429, 1714,
  1714, 429, 429, 429, 429,
  1285, 429, 1714,
  1714, 429, 429, 429, 429,
  1285, 429, 1714,
  857, 429, 429, 857, 642, 204,
  1846, 923, 923,
  3692
};

// FINAL COUNTDOWN
int final[] = {
  NOTE_G4, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_G4,
  NOTE_DS4, NOTE_DS5, NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_C5,
  NOTE_C5, NOTE_DS5, NOTE_D5, NOTE_DS5, NOTE_G4,
  NOTE_F4, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5,
  NOTE_G4, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_G4,
  NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_C5,
  NOTE_C5, NOTE_DS5, NOTE_D5, NOTE_DS5, NOTE_G4,
  NOTE_DS4, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5,
  NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5,
  NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_DS5,
  NOTE_D5, NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_C5,
  NOTE_D5,
  NOTE_G4, // 6 * 1/4 NOTE_G4
  NOTE_G4, NOTE_F4,
  NOTE_D4, NOTE_AS4, NOTE_A4, NOTE_F4,
  NOTE_G4,
  NOTE_G5, NOTE_G5, NOTE_A5, NOTE_AS5,  // 2 * 1/8 NOTE_A5
  NOTE_A5, NOTE_G5,
  NOTE_G5, NOTE_G5, NOTE_A5, NOTE_AS5,  // 2 * 1/8 NOTE_A5 + 2 * 1/8 NOTE_AS5
  NOTE_G5 // 5 * 1/8 NOTE_G5
};

// note durations and delays in milliseconds
int final_noteDurations[] = {
  500, 125, 125, 500, 500,
  500, 125, 125, 250, 250, 500,
  500, 125, 125, 500, 500,
  500, 125, 125, 250, 250, 250, 250,
  500, 125, 125, 500, 500,
  500, 125, 125, 250, 250, 500,
  500, 125, 125, 500, 500,
  500, 125, 125, 250, 250, 250, 250,
  750, 125, 125, 750, 125, 125,
  250, 250, 250, 250, 500, 500,
  1500, 125, 125, 125, 125,
  2000,
  3000,
  500, 500,
  500, 500, 500, 500,
  2000,
  250, 750, 125, 500, 250,
  500, 500,
  250, 750, 375, 500, 1250
};

int finalDelays[] = {
  625, 125, 125, 500, 500,
  625, 125, 125, 250, 250, 500,
  625, 125, 125, 500, 500,
  625, 125, 125, 250, 250, 250, 250,
  625, 125, 125, 500, 500,
  625, 125, 125, 250, 250, 500,
  625, 125, 125, 500, 500,
  625, 125, 125, 250, 250, 250, 250,
  750, 125, 125, 750, 125, 125,
  250, 250, 250, 250, 500, 500,
  1500, 125, 125, 125, 125,
  2000,
  3000,
  500, 500,
  500, 500, 500, 500,
  2750,
  250, 750, 375, 250,
  500, 2250,
  250, 750, 375, 500, 642
};

void setup() {
  Serial.begin(9600);
  Serial.println("Serial switch test 0015"); // so I can keep track
}

/*
void playMegalovania() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 87; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = megalovania_noteDurations[thisNote];
    digitalWrite(LedPin_Mega, HIGH);
    tone(buzzerPin, megalovania[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    int pauseBetweenNotes = megalovaniaDelays[thisNote];
    digitalWrite(LedPin_state, HIGH);
    delay(pauseBetweenNotes);
    digitalWrite(LedPin_state, LOW);
    // stop the tone playing:
    noTone(buzzerPin);
    digitalWrite(LedPin_Mega, LOW);
  }
}*/

void playSoviet() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 106; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = soviet_noteDurations[thisNote];
    digitalWrite(LedPin_Soviet[thisNote % 3], HIGH);
    //delay(noteDuration);
    tone(buzzerPin, soviet[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    int pauseBetweenNotes = sovietDelays[thisNote];
    digitalWrite(LedPin_state, HIGH);
    delay(pauseBetweenNotes);
    digitalWrite(LedPin_state, LOW);
    // stop the tone playing:
    noTone(buzzerPin);
    digitalWrite(LedPin_Soviet[thisNote % 3], LOW);
  }
}

void playFinal() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 64; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = final_noteDurations[thisNote];
    digitalWrite(LedPin_Mega, HIGH);
    tone(buzzerPin, final[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    int pauseBetweenNotes = finalDelays[thisNote];
    digitalWrite(LedPin_state, HIGH);
    delay(pauseBetweenNotes);
    digitalWrite(LedPin_state, LOW);
    // stop the tone playing:
    noTone(buzzerPin);
    digitalWrite(LedPin_Mega, LOW);
  }
}

void loop() {
  while (Serial.available()) {
    delay(3);
    char c = Serial.read();
    readString += c;
  }
  readString.trim();
  if (readString.length() > 0) {
    /*if (readString == "megalovania") {
      Serial.println("Playing Megalovania....");
      playMegalovania();
    }*/
    if (readString == "soviet")
    {
      Serial.println("Playing soviet anthem....");
      playSoviet();
    }
    if (readString == "final")
    {
      Serial.println("Playing Final Countdown....");
      playFinal();
    }
    readString = "";
  }
}
