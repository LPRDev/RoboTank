# RoboTank
<a href="https://github.com/LPRDev/RoboTank/blob/master/images/RoboTank1.jpg">
<img src="https://github.com/LPRDev/RoboTank/blob/master/images/RoboTank1.jpg" align="right" width="25%" height="25%">
</a>

An entry level Arduino based project that builds a minature tank contolled by Blue Control (a free Andoid app)

Robo Tank is a project that explores robotics by creating a semi autonomous tank that can explore its surroundings.

Manual control is provided using an existing free Android application called Blue control (see details below). Blue Control sends commands to the Tank which are received by a Bluetooth shield and sent to the main processor for making adjustments to the tanks speed/direction. This allows starting/stopping, and turning controls.

Once the Tank is moving, it can maneuver around object objects and continue moving. A sonar based sensor can detect objects in its path and make appropriate turns to go around the object.

# Power
A power switch is located under the front of the tank. Use this to conserve the battery drain when not using, Note that when the power is turned back on the Blue Control app must “reconnect” to the HC-06 device (the Bluetooth shield on the Tank). 

To Recharge the batteries pull out the connector labeled “Recharge” and plug into the Recharge station (12V battery with a DC converter set to 6.5 V). Note that the power switch should be set to “off” before recharging.

# Hardware

The Robo Tank was assembled using the following parts:

* <a href="https://www.arduino.cc/en/Main/ArduinoBoardUno"> Aruduino UNO </a> (Any Ardino that can mount the LD293 should do)
* <a href="http://www.tamiya.com/english/products/70108tracked_vehicle/index.htm">Tamiya Tank kit </a>, a small 8 inch model tank platform
* <a href="http://www.tamiya.com/english/products/70168double_gearbox/index.htm"> Tamiya double motor gear box </a>
* <a href="http://playground.arduino.cc/Main/AdafruitMotorShield">Arduino Motor Shield (LD293)</a>
* <a href="http://f4cvm.free.fr/realisation/connexion/bluetooth/data/explications-1.pdf">HC-06 Bluetooth “shield” </a>, for receiving command from the Blue Control application
*  <a href="http://www.micropik.com/PDF/HCSR04.pdf"> HC-SR04 Sonor Sensor</a> for detecting object in the tanks path.
* <a href="https://play.google.com/store/apps/details?id=com.gundel.bluecontrol&hl=en"> Blue Control android app </a>(free)

Approximate cost for this project is about $60, not including an Adroid device to run Blue Control.

# Blue Control

<a href="https://play.google.com/store/apps/details?id=com.gundel.bluecontrol&hl=en"> BlueControl </a> “Blue Control” is a free Android app, available from Google Play. Blue control provides a set of directional arrows to control the direction (Front,Back, Right, Left, and Stop) as well as 8 extra buttons for controls (A-H). Here’s what they do for the Robo Tank:

A: Blink the Led on the Arduino Board (Good for connectivity testing).
B: Spin Left (amount depends on battery power)
C: Run the Left tread only (Good for a wire test)
D: Move forward at top speed
E:Nothing
F: Spin Right (amount depends on battery power)
G: Run the right tread only (good for a wire test)
H: Move Backward at top speed

## Connecting to the Tank via Bluetooth

Before Blue Control can send command it must “connect” to the Tanks Bluetooth shield. To do this first turn on the power to the Tank (switch on the bottom of the Tank). Note that the Bluetooth controller should start blinking when this happens. On the Android invoke the Blue Control app and select the configure button on the android device (usually three or so horizontal lines). Select “connect to device”. The app will search for available devices and it should present an “HC-06” device. Select the HC-06 and it should return to it main screen and display a “connected to device HC-06” message within a few seconds.Select the forward button to start the Tank.
# Notes
## Gearbox 

GearBox_TamiyaThe Tamyia Double Gearbox was assembled using the 114.7:1 gear ratio. Using a lower gear ration proved to be too much for the small motors to handle. The Gearbox can be reconfigured to one of four gear ratio settings. To get higher speeds on can reconfigure the box for a lower gear ratio, however the tank may be difficult to start and may shorten the battery life.
## Battery

A five cell (5.2 V) packaged rechargeable battery was found to provide the goof charge/performance for the tank. A single battery (versus two for separating the controller and the motor) was chosen to lessen the battery maintenance burden. One can add a second battery to the main Arduino board and remove the jumper on the motor shield to provide this capability.

Another option is a cheap cell phone battery battery charger that provides as least 500 mah. These are very convient, charge from a usb, will provide 10 minutes or more of active time with the Robotank.

