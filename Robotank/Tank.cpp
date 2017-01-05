
/**********************************************************************************
*  Tank.cpp
*  Class for Tank Movement (forward, backward, left, right, etc)
*   
*  
*
***********************************************************************************
*/
#include "Arduino.h"
#include "MSMotorShield.h"
#include "Tank.h"


MS_DCMotor motor_left(1);//Left Tank Tread
MS_DCMotor motor_right(2);//Right Tank Tread

Tank::Tank()
{
   //motor_left(1);//Left Tank Tread
   //MS_DCMotor motor_right(2);//Right Tank Tread
   
   min_speed=150;   // seems to be the minimum o start the motor
   max_speed=255;   // defined max for motorsheild is 255.
   tank_direction = FORWARD;
   tank_speed = min_speed;
   left_increase = 0;
   right_increase = 0;
   left_speed=min_speed;
   right_speed=min_speed;
}

int Tank::getspeed()
{
  return(tank_speed);
}
void Tank::forward()
{
  left_increase=0;
  right_increase=0;

  if (tank_direction == BACKWARD)
         {
           if (tank_speed <= min_speed) stop();
           else tank_speed-=25;
         }
  else {
           tank_direction = FORWARD;
           tank_speed+=25;     // increment speed just a little on both treads
       } 

  setspeed();
}

void Tank::backward()
{
  left_increase=0;
  right_increase=0;
   if (tank_direction == FORWARD)
         {
           if (tank_speed <= min_speed) stop();
           else tank_speed-=25;
         }
  else {
           tank_direction = BACKWARD;
           tank_speed+=25;     // increment speed just a little on both treads
       } 
  setspeed();
}
// move left tread jus a little bit faster fro each left button on the Anbdroid app
// This will seem to beantural mve to the left 
void Tank::left()
{
left_increase+=25;
right_increase-=25;
setspeed();
}
// move left tread jus a little bit faster fro each right button on the Anbdroid app
// This will seem to beantural mve to the tight 
void Tank::right()
{ 
left_increase-=25;
right_increase=+25;
setspeed();
}
// full stop 
// sets spped to 0 and RELEASES the motors.
void Tank::stop() {
  tank_speed=0;
  motor_left.setSpeed(tank_speed);
  motor_right.setSpeed(tank_speed);
  motor_left.run(RELEASE);
  motor_right.run(RELEASE);
  left_increase=0;   //reset offsets used for left/right turns
  right_increase=0; 
  tank_direction=BRAKE;
}
void Tank::go()
{
  motor_left.setSpeed(left_speed);
  motor_right.setSpeed(right_speed);
  motor_left.run(tank_direction);
  motor_right.run(tank_direction);
}

// Attempts to rotate the tank left
// by moving the tread in opposite directions
 void Tank::lrotate(int duration) {
  motor_right.setSpeed(255);
  motor_right.run(BACKWARD);  
  delay(500);
  motor_left.setSpeed(255);
  motor_left.run(FORWARD); 
  delay(duration);
  stop();
 } 
 
 // Attempts to rotate the tank right
// by moving the tread in opposite directions
 void Tank::rrotate(int duration) {
  motor_left.setSpeed(255);
  motor_left.run(BACKWARD);  
  delay(500);
  motor_right.setSpeed(255);
  motor_right.run(FORWARD); 
  delay(duration);
  stop();
 }
 
// Moves the right tread 
 void Tank::testright() {
  motor_right.setSpeed(200);
  motor_right.run(FORWARD); 
  delay(2000);
  stop();
 }
 
 //Moves the left tread
 void Tank::testleft() {
     motor_left.setSpeed(200);
  motor_left.run(FORWARD); 
  delay(2000);
  stop();
 }
 
 // Moves the tank forward at full speed
 void Tank::fullspeedforward() 
 {
    tank_speed=max_speed;  
    forward();
    go();
 }
 // Moves the tank backward at full speed
 void Tank::fullspeedbackward()
 {
   tank_speed=max_speed;  
   backward();
   go();
 }
 
 // Checks to make sure tank is between the min  and max speeds
void Tank::setspeed()
{
  left_speed=tank_speed + left_increase;
  right_speed=tank_speed + right_increase;
  // check for max and min speeds (between 100 and 255)
  if (left_speed > max_speed) left_speed=max_speed;      
  else if (left_speed < min_speed) left_speed=min_speed; 
  if (right_speed > max_speed) right_speed=max_speed;      
  else if (right_speed < min_speed) right_speed=min_speed;  
}
