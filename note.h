#pragma once

class Note {
    public:
        Note();
        Note(double frequency);
        double getFrequency();
    private:
        double frequency;
};