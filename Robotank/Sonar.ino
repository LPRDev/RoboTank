#include "Ultrasonic.h"

#define trigPin A0
#define echoPin A1
int obstacle_distance=12;


boolean obstacle(){
  long duration,distance;
  digitalWrite(trigPin, LOW);//begin sensor pulse
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);//actual pulse
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);//end sensor pulse
  duration = pulseIn(echoPin, HIGH);//take pulse numbers
  distance = (duration/2)/29.1;//calculate distance in cm
  if (distance < obstacle_distance){ //less than 82cm
    return true;
  }
  else{
    return false;
  }
}
