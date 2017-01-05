/**********************************************************************************
*  Arduino tank that uses the BlueControl android application (availble from Google play)
*  to controlmovement. 
*   Note this app requires an Arduino Mega and Blyetooth board (JY-MCU)
*   
* Support the following optional sensors:
*  * Sonar: Detects objects in path as well as table edges
*  * GPS 
*  
*
***********************************************************************************
*/
#include "MSMotorShield.h"
#include "Tank.h"

#define trigPin 0
#define echoPin 1

Tank tank;
byte ledPin = 13;  // use the built in LED on pin 13 of the Uno
byte on_brd_led = 8; // On-board LED pin detail 
byte  input=0;

void setup() {
  // Bluetooth setup  
  // sets the pins as outputs:
    pinMode(ledPin, OUTPUT);     // test to make the arduino uno led blink
    blink_led();
    Serial.begin(9600); // Default connection rate for my BT module
    
    // Setup A0 and A1 for the sonor (trigger and echo)
    pinMode(A0, OUTPUT);
    pinMode(A1, INPUT);

    tank.stop();// dont start moving until commanded by android.
    //tank_stop(); // dont start moving until commanded by android.
 
}

// Wait for bluetooth command. otherwise move forward
void loop() {
   // If an onstacle is in front of us, move away...
  if(obstacle())
  {
    if(tank.getspeed()>0)
     {
       tank.stop();
       blink_led();
       delay(100);
       tank.lrotate(3000);
       tank.stop();
       delay(1000);
       tank.forward();
       if(!obstacle())
          tank.go();
     }
    else  blink_led();  
  } 
  input=' ';
  if(Serial.available() > 0)
    {
      input = Serial.read(); 
      set_led();
      switch (input) 
        {
         case 'U': tank.forward(); break;
         case 'D': tank.backward();break;
         case 'L': tank.left(); break;
         case 'R': tank.right(); break;  
         case 'C': tank.stop(); break;
         case 'a': blink_led(); break;
         case 'c': tank.rrotate(2000); break;
         case 'b': tank.testleft(); break;
         case 'd': tank.fullspeedforward(); break;
         case 'e': tank.testright(); break;
         case 'f': tank.lrotate(2000); break;
         case 'g': tank.right(); break;
         case 'h': tank.fullspeedbackward(); break;
         default:    ; //ignore
       }
       tank.go();
       delay(100); 
       clear_led();
    }
}

// blink led on Arduino board
void blink_led()
{
  for (int i=1; i<4; i++){
  digitalWrite(ledPin, HIGH); // turn ON LED
  delay(250);  // Just wait 1s
  digitalWrite(ledPin, LOW); //  switch OFF
  delay(250); 
  }
}
// set  led on Arduino board
void set_led()
{digitalWrite(ledPin, HIGH); // turn ON LED
}
// set  led on Arduino board
void clear_led()
{ digitalWrite(ledPin, LOW); //  switch OFF
}

