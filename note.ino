
#include "note.h"

Note::Note() {
    frequency = 130.81;
}

Note::Note(double frequency) : frequency(frequency) {}

double Note::getFrequency()
{
    return frequency;
}