#include <RobotLL.cpp>
#include <Dynamixel_Serial.h>
#include <ServoTimers.h>

//Drive with wheels; first var - speed on Left wheel from 0 to 255, second var - speed on Rigwdwadwadwa 255
void moveWheels(int speedL, int speedR){
  
  if(speedL>0){
  digitalWrite(DIR_1,HIGH); 
  }

  else{
    digitalWrite(DIR_1,LOW); 
  }

  if(speedR>0){
  digitalWrite(DIR_2,HIGH); 
  }

  else{
    digitalWrite(DIR_2,LOW); 
  }

  analogWrite(PWM_1,abs(speedL));
  
  analogWrite(PWM_2,abs(speedR));
  
}

//Control LED brightness
void ledBrightness(int brigtness){

analogWrite(LED_Pin,brigtness);

}

//rotate motor with ID:0000
void rotateBase (int angle){
turnAngle(0, angle, 100);
}

//rotate motor with ID:0001
void rotateFirst (int angle){
turnAngle(1, angle, 100);
}

//rotate motor with ID:0002
void rotateSecond (int angle){
turnAngle(2, angle, 100);
}

//ID - spike ID, dir - 0x00 - LEFT, 0x01 - HIGH
void rotateSpike(int ID, int dir){
  Dynamixel.wheel(ID,dir,0x3FF); 
}

//values from 10 to 170
void moveServo(int degrees){
  if(degrees<=10 || degrees>=170){
    }
  else{
 servoArm.write(degrees);
  }
}
/*

////////////////////////////Функции для проверки двигателей, для использования - раскомментить

//Движение вперёд
void moveForward(int ){
  analogWrite(PWM_1,150);
  digitalWrite(DIR_1,LOW);
  analogWrite(PWM_2,150);
  digitalWrite(DIR_2,LOW);
}
//Движение назад
void moveBackward(){
  digitalWrite(DIR_2, HIGH);
  analogWrite(PWM_1,150);
  analogWrite(PWM_2,150);
  digitalWrite(DIR_1, HIGH);
}

//Танковый разворот через левый бок
void tankTurnLeft(){
  analogWrite(PWM_1,150);
  digitalWrite(DIR_1,HIGH);
  analogWrite(PWM_2,150);
  digitalWrite(DIR_2,LOW);
}

//Танковый разворот через правый бок
void tankTurnRight(){
  analogWrite(PWM_1,150);
  digitalWrite(DIR_1,LOW);
  analogWrite(PWM_2,150);
  digitalWrite(DIR_2,HIGH);
}

//Движение влево(если что, исправить, пока не протестировано)
void moveLeft(){
  analogWrite(PWM_1,150);
  digitalWrite(DIR_1,HIGH);
  analogWrite(PWM_2,0);
  digitalWrite(DIR_2,HIGH);
}

//Движение вправо(если что, исправить, пока не протестировано)
void moveRight(){
  analogWrite(PWM_1,0);
  digitalWrite(DIR_1,HIGH);
  analogWrite(PWM_2,150);
  digitalWrite(DIR_2,HIGH);
}

//Полная остановка
void stopeEpta(){
  analogWrite(PWM_1,LOW);
  analogWrite(PWM_2, LOW);
}

*/
