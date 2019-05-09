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
// peter.vella@gmail.com
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
  3500, 583,
  1167, 875, 292, 1167, 583, 583,
  1167, 875, 292, 1167, 583, 583,
  1167, 583, 583, 1167, 583, 583,
  1167, 583, 583, 1750, 583,
  1167, 875, 292, 1167, 583, 583,
  1167, 875, 292, 1167, 583, 583,
  1167, 875, 292, 1167, 1167,
  1167, 875, 292, 1750, 292,
  2334, 583, 583, 583, 583,
  1750, 583, 583, 583, 583, 583,
  1750, 583, 583, 583, 583, 583,
  1750, 583, 583, 583, 583, 583,
  1167, 875, 583, 1167, 875, 583,
  1167, 583, 583, 2334,
  2334, 583, 583, 583, 583,
  1750, 583, 2334,
  2334, 583, 583, 583, 583,
  1750, 583, 2334,
  1167, 583, 583, 1167, 875, 292,
  2500, 1250, 1250,
  5000
};

int sovietDelays[] = {
  1167, 292,
  583, 437, 292, 583, 292, 292,
  583, 437, 292, 583, 292, 292,
  583, 292, 292, 583, 292, 292,
  583, 292, 292, 875, 292,
  583, 437, 292, 583, 292, 292,
  583, 437, 292, 583, 292, 292,
  583, 437, 292, 583, 583,
  583, 437, 292, 875, 292,
  1167, 292, 292, 292, 292,
  875, 292, 292, 292, 292, 292,
  875, 292, 292, 292, 292, 292,
  875, 292, 292, 292, 292, 292,
  583, 437, 292, 538, 437, 292,
  583, 292, 292, 1167,
  1167, 292, 292, 292, 292,
  875, 292, 1167,
  1167, 292, 292, 292, 292,
  875, 292, 1167,
  583, 292, 292, 583, 437, 292,
  1250, 625, 625,
  2500
};

// FINAL COUNTDOWN
int final[] = {
  NOTE_G4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_G4,
  NOTE_DS4
};

void setup() {
  Serial.begin(9600);
  Serial.println("Serial switch test 0012"); // so I can keep track
}

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
}

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

void loop() {
  while (Serial.available()) {
    delay(3);
    char c = Serial.read();
    readString += c;
  }
  readString.trim();
  if (readString.length() > 0) {
    if (readString == "megalovania") {
      Serial.println("Playing megalovania....");
      playMegalovania();
    }
    if (readString == "soviet")
    {
      Serial.println("Playing soviet anthem....");
      playSoviet();
    }
    readString = "";
  }
}
