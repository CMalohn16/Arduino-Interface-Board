#include "song.h"

Song::Song(String startName, int tempo, double pattern[]) : name(startName) {
    int i = 0;
    while (pattern[i] > 0 && i < 100)
    {
        notes[i] = pattern[i];
        i++;
    }
    length = i;
    //Convert from Beats per minute to seconds per beat
    noteDelay = 1.0 / (tempo / 60.0);
}

void Song::playSong(int pin) {
    for (int i = 0; i < length; i++)
    {
        tone(pin, notes[i]);
        delay(noteDelay * 1000);
    }
    noTone(pin);
}

String Song::getName() {
    return name;
}