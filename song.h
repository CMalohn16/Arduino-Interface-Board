#pragma once

#include "note.h"

class Song {
    public:
        Song(String startName, int tempo, double pattern[]);
        void playSong(int pin);
        String getName();

    private:
        String name;
        int length;
        double noteDelay; //milliseconds
        double notes[100];
};