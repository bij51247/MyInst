#ifndef HCSR04_h
#define HCSR04_h
#include "Arduino.h"

class HCSR04
{
    public:
        HCSR04( int trig, int echo );
        void begin();
        float get_length();
    private:
        int TRIG_PIN, ECHO_PIN;
        float length;
};

#endif

