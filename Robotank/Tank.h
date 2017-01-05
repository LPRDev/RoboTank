/**********************************************************************************
*  Tank.h
*  Class for Tank Movement (forward, backward, left, right, etc)
*   
*  
*
***********************************************************************************
*/


class Tank
{
  public:
       Tank();
       void forward();
       void fullspeedforward();
       void backward();
       void fullspeedbackward();
       void left();
       void right();
       void lrotate(int);
       void rrotate(int);
       void testleft();
       void testright();
       void stop();
       void go();
       int  getspeed();
       
  private:
       void setspeed();
       //MS_DCMotor motor_left;
       //MS_DCMotor motor_right;
       int min_speed;          // seems to be the minimum o start the motor
       int max_speed;          // defined max for motorsheild is 255.
       int tank_direction;     // defined in Motorsheild.h
       int tank_speed;         // min_speed is around 100 on a fully charged battery, but varies dependant on the battery power
       int left_increase;      // used for turning left
       int right_increase;     // used for turning right
       int left_speed;         
       int right_speed;
  
};
