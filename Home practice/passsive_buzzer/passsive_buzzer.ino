LedPin_1 = 13;
LedPin_2 = 4;

#include "pitches.h"

// notes in the melody:

//D4 //D4 //D5 //A4 //Ab4 //G4 //F4 //D4 //F4 //G4 //C4 //C4 //C4 //C4 //D5

////////

//A4 //Ab4 //G4 //F4 //D4 //F4 //G4 //B3 //B3 //D5 //A4 //Ab4 //G4 //F4 //D4

////////

//F4 //G4 //Bb3 //Bb3 //Bb3 //Bb3 //D5 //A4 //Ab4 //G4 //F4 //D4 //F4 //G4 //D4

////////

//D4 //D5 //A4 //Ab4 //G4 //F4 //D4 //F4 //G4 //C4 //C4 //C4 //C4 //D5 //A4

////////

//Ab4 //G4 //F4 //D4 //F4 //G4 //B3 //B3 //D5 //A4 //Ab4 //G4 //F4 //D4 //F4

////////

//G4 //Bb3 //Bb3 //Bb3 //Bb3 //D5 //A4 //Ab4 //G4 //F4 //D4 //F4 //G4
int melody[] = {
  NOTE_D4, NOTE_D4, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D5,
  NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_B3, NOTE_B3, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4,
  NOTE_F4, NOTE_G4, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_D4,
  NOTE_D4, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D5, NOTE_A4,
  NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_B3, NOTE_B3, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4,
  NOTE_G4, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  125, 125, 250, 250, 125, 250, 250, 125, 125, 125, 125, 125, 125, 125, 250,
  375, 125, 250, 250, 125, 125, 125, 125, 125, 250, 375, 125, 250, 250, 125,
  125, 125, 62, 62, 62, 62, 250, 375, 125, 250, 250, 125, 125, 125, 125,
  125, 250, 375, 125, 250, 250, 125, 125, 125, 125, 125, 125, 125, 250, 375,
  125, 250, 250, 125, 125, 125, 125, 125, 250, 375, 125, 250, 250, 125, 125,
  125, 62, 62, 62, 62, 250, 375, 125, 250, 250, 125, 125, 125
};



int delays[] = {
  125, 125, 250, 375, 250, 250, 250, 125, 125, 125, 62, 62, 62, 62, 250,
  375, 250, 250, 250, 125, 125, 125, 125, 125, 250, 375, 250, 250, 250, 125,
  125, 125, 62, 62, 62, 62, 250, 375, 250, 250, 250, 125, 125, 125, 125,
  125, 250, 375, 250, 250, 250, 125, 125, 125, 62, 62, 62, 62, 250, 375,
  250, 250, 250, 125, 125, 125, 125, 125, 250, 375, 250, 250, 250, 125,
  125, 125, 62, 62, 62, 62, 250, 375, 250, 250, 250, 125, 125
};


void setup() {
  // Nothing....
}

void loop() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 87; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = noteDurations[thisNote];
    digitalWrite(LedPin_1, HIGH);
    tone(9, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    int pauseBetweenNotes = delays[thisNote];
    digitalWrite(LedPin_1, LOW);
    digitalWrite(LedPin_2, HIGH);
    delay(paueBetweenNotes);
    digitalWrite(LedPin_2, LOW);
    // stop the tone playing:
    //noTone(9);
  }
  delay(4125);
}
