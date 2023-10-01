#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include<Servo.h>
Servo sl;// defining a object to use the Servo function
void setup() {
  // put your setup code here, to run once:
sl.attach(5);// Attaching the digital pin 9 to the servo motor object 
Dabble.begin(9600); 
Serial.begin(19200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Dabble.processInput();  
  if(GamePad.isRightPressed())
  {
   for (int i=0; i<=2500;i++){
      sl.writeMicroseconds(i);// sending a 1ms width pulse to the servo motor to read and apply and then slowly increasing the pulse by 0.5
      delay(1);}
      Serial.print("Right");
      Serial.print('\n');
  } 
  if(GamePad.isLeftPressed())
  {
    for (int i=2500; i>0;i--){
      sl.writeMicroseconds(i);// sending a 1ms width pulse to the servo motor to read and apply and then slowly increasing the pulse by 0.5
      delay(1);                     
    }
    Serial.print("Left");
    Serial.print('\n');
  }
}
