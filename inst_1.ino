#include "HCSR04.h";

const int TRIG = 6;
const int ECHO = 7;

const int melo = 200;
const int pin = 13;

HCSR04 hcsr04(TRIG,ECHO);

void setup() {
  // put your setup code here, to run once:
  hcsr04.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  float distance;


  distance = hcsr04.get_length();

  if(distance != -1){
    Serial.print("Distance");
    Serial.print(distance);
    Serial.println("cm");

    if(distance < 5){
      tone(pin,262,melo);//ド
    }else if(distance < 10){
      tone(pin,294,melo);//レ
    }else if(distance < 15){
      tone(pin,330,melo);//ミ
    }else if(distance < 20){
      tone(pin,349,melo);//ファ
    }else if(distance < 25){
      tone(pin,392,melo);//ソ
    }else if(distance < 30){
      tone(pin,440,melo);//ラ
    }else if(distance < 35){
      tone(pin,492,melo);//シ
    }else{
      tone(pin,523,melo);//ド
    }
    
  }else{
    Serial.println("Out range");
  }
  delay(1000);
}
