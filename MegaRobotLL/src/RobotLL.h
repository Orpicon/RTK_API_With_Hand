#include <Arduino.h>
#define DIR_2 5
#define PWM_2 6
#define PWM_1 11
#define DIR_1 10
#define LED_Pin 13/*Insert PIN for LED with PWM support*/


//Drive with wheels; first var - speed on Left wheel from 0 to 255, second var - speed on Right wheel from 0 to 255
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

//Arm Control(empty)
void armControls(){
  //А тут пусто :D , я пока хз как рукой управлять
}

//Drive with Spikes; first var - speed on Left wheel from 0 to 255, second var - speed on Right wheel from 0 to 255
void moveSpikes(int speedL, int speedR){

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
