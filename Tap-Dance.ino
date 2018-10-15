/*************************************************** 
  Project control code using Adafruit 16-channel PWM & Servo driver
  Continuous servo is at address 0x40
  180 degree servo is at address 0x41


  Written for 12 characters:

  Servos 0-7 are Penguiettes that dance in chase and alternating patterns within 90 degree rotations back and forth on the beat

  Servo 8 is Buddy and continuously rotates clockwise

  Servo 9 is Jovie rotates to her own dance within 90 degree rotations back and forth

  Servos 10 and 11 are the feet of the tap dancing penguins with small movements of Tap and Shuffle

  

  Written by Sean Henry for use in covert projects
 ****************************************************/

// continuous servo test 1.5ms pulse to stop, 2 ms pulse to go forward, 1ms pulse to go backwards

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(&Wire, 0x40);

// min and max range for non-continuous servos.  different servos will vary
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)



void setup() {
  Serial.begin(9600);

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

}



void loop() {

  #define SERVOSTOP 2
  #define SERVOFWD 500 // 500
  #define SERVOREV 8
  
  #define penguinRight 150
  #define penguinLeft 600

  #define jovieLeft 150
  #define jovieRight 170
  
  #define tapRight 180
  #define tapLeft 150
  #define shuffleRight 185
  #define shuffleLeft 150
  
  #define beat 222 // matches the BPM of the music

  #define Jovie 9 // Jovie's servo address
  
  #define Tap1 10 // Left penguin's servo address
  #define Tap2 11 // Right penguin's servo address

  long revtime = 300;  // appears to be the revolution time in units for the continuous motor  




  
  // the arduino appears to continuously execute its program so a loop is not required

 
pwm.setPWM(8, 0, SERVOFWD);

pwm.setPWM(0, 0, penguinRight);
pwm.setPWM(Jovie, 0, jovieRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);





pwm.setPWM(1, 0, penguinRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);





pwm.setPWM(2, 0, penguinRight);
pwm.setPWM(Jovie, 0, jovieLeft);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);




pwm.setPWM(3, 0, penguinRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);





pwm.setPWM(4, 0, penguinRight);
pwm.setPWM(Jovie, 0, jovieRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);





pwm.setPWM(5, 0, penguinRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);





pwm.setPWM(6, 0, penguinRight);
pwm.setPWM(Jovie, 0, jovieLeft);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);




pwm.setPWM(7, 0, penguinRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);




// Rotate Back

pwm.setPWM(0, 0, penguinLeft);
pwm.setPWM(Jovie, 0, jovieRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, shuffleRight);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, shuffleRight);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, shuffleRight);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, shuffleRight);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);






pwm.setPWM(1, 0, penguinLeft);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);






pwm.setPWM(2, 0, penguinLeft);
pwm.setPWM(Jovie, 0, jovieLeft);


pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);









pwm.setPWM(3, 0, penguinLeft);
pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);





pwm.setPWM(4, 0, penguinLeft);
pwm.setPWM(Jovie, 0, jovieRight);


pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);





pwm.setPWM(5, 0, penguinLeft);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);



pwm.setPWM(6, 0, penguinLeft);
pwm.setPWM(Jovie, 0, jovieLeft);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);


delay(beat/2);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);



pwm.setPWM(7, 0, penguinLeft);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);


delay(beat);






// REPEAT!




pwm.setPWM(0, 0, penguinRight);
pwm.setPWM(Jovie, 0, jovieRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);





pwm.setPWM(1, 0, penguinRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);





pwm.setPWM(2, 0, penguinRight);
pwm.setPWM(Jovie, 0, jovieLeft);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);




pwm.setPWM(3, 0, penguinRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);





pwm.setPWM(4, 0, penguinRight);
pwm.setPWM(Jovie, 0, jovieRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);





pwm.setPWM(5, 0, penguinRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);





pwm.setPWM(6, 0, penguinRight);
pwm.setPWM(Jovie, 0, jovieLeft);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);




pwm.setPWM(7, 0, penguinRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);




// Rotate Back

pwm.setPWM(0, 0, penguinLeft);
pwm.setPWM(Jovie, 0, jovieRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, shuffleRight);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, shuffleRight);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, shuffleRight);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, shuffleRight);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);






pwm.setPWM(1, 0, penguinLeft);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);






pwm.setPWM(2, 0, penguinLeft);
pwm.setPWM(Jovie, 0, jovieLeft);


pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);









pwm.setPWM(3, 0, penguinLeft);
pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);





pwm.setPWM(4, 0, penguinLeft);
pwm.setPWM(Jovie, 0, jovieRight);


pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);





pwm.setPWM(5, 0, penguinLeft);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);



pwm.setPWM(6, 0, penguinLeft);
pwm.setPWM(Jovie, 0, jovieLeft);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);


delay(beat/2);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);



pwm.setPWM(7, 0, penguinLeft);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);


delay(beat);


// NEW!






pwm.setPWM(0, 0, penguinRight);
pwm.setPWM(Jovie, 0, jovieRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);





pwm.setPWM(7, 0, penguinRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);





pwm.setPWM(1, 0, penguinRight);
pwm.setPWM(Jovie, 0, jovieLeft);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);




pwm.setPWM(6, 0, penguinRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);





pwm.setPWM(2, 0, penguinRight);
pwm.setPWM(Jovie, 0, jovieRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);





pwm.setPWM(5, 0, penguinRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);





pwm.setPWM(3, 0, penguinRight);
pwm.setPWM(Jovie, 0, jovieLeft);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);




pwm.setPWM(4, 0, penguinRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);




// Rotate Back

pwm.setPWM(4, 0, penguinLeft);
pwm.setPWM(Jovie, 0, jovieRight);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, shuffleRight);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, shuffleRight);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, shuffleRight);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, shuffleRight);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);






pwm.setPWM(3, 0, penguinLeft);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);






pwm.setPWM(5, 0, penguinLeft);
pwm.setPWM(Jovie, 0, jovieLeft);


pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);









pwm.setPWM(2, 0, penguinLeft);
pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);





pwm.setPWM(6, 0, penguinLeft);
pwm.setPWM(Jovie, 0, jovieRight);


pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/8);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/4);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/4);





pwm.setPWM(1, 0, penguinLeft);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);

delay(beat/2);



pwm.setPWM(7, 0, penguinLeft);
pwm.setPWM(Jovie, 0, jovieLeft);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);


delay(beat/2);

pwm.setPWM(Tap1, 0, tapRight);
pwm.setPWM(Tap2, 0, tapRight);

delay(beat/2);

pwm.setPWM(0, 0, penguinLeft);

pwm.setPWM(Tap1, 0, tapLeft);
pwm.setPWM(Tap2, 0, tapLeft);


delay(beat);

/* the loop loops and the servos keep dancing! */


}

