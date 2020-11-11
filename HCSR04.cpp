#include "HCSR04.h"
#include "arduino.h"
#include <Wire.h>

HCSR04::HCSR04( int trig, int echo ){
    TRIG_PIN = trig;
    ECHO_PIN = echo;    
}

void HCSR04::begin(){
    pinMode( TRIG_PIN, OUTPUT );
    pinMode( ECHO_PIN, INPUT );
    digitalWrite( TRIG_PIN, LOW);
    delay( 100 );
}

float HCSR04::get_length(){
    int32_t duration;
    digitalWrite( TRIG_PIN, HIGH );
    delayMicroseconds( 10 );
    digitalWrite( TRIG_PIN, LOW );
    duration = pulseIn( ECHO_PIN, HIGH );
    if ( duration > 0 ){
        length = (float)duration / 2.0 * 0.034;
    }

    if (length < 2 || length > 400 ){
        length = -1;
    }

    return( length ); 
}

