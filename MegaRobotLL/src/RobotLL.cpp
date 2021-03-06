//If u want to set motors count u need to set number in #define MOTOR_COUNT "n", where n - is motor count
#include "AX12A.h"
#include <Arduino.h>
#include <Dynamixel_Serial.h>
#include <Servo.h>
#define DirectionPin (10u)
#define BaudRate (57600ul)
#define Broadcast (254u)
#define MAX_ANGLE (90)
#define MOTOR_COUNT (3)
#define DIR_2 5
#define PWM_2 6
#define PWM_1 11
#define DIR_1 10
#define LED_Pin 13/*Insert pin for LED with PWM support*/
AX12A ax12a2;

int Cur_angle[MOTOR_COUNT] = {0};
long input_data[MOTOR_COUNT] = {0};

void correct_position(int &pos)
{
    pos = (pos < -MAX_ANGLE) ? -MAX_ANGLE : pos;
    pos = (pos > MAX_ANGLE) ? MAX_ANGLE : pos;
}
Servo servoArm;
 
void setup()
{
    Serial.begin(9600);
    servoArm.attach(9);
    Dynamixel.begin(57600);                                    
    Dynamixel.setDirectionPin(0x02);                           
    Dynamixel.setMode(0x01, WHEEL, 0, 0);                              
    // Serial3.begin(9600);
    ax12a2.begin(BaudRate, DirectionPin, &Serial2);
    ax12a2.setEndless(0, OFF);
    ax12a2.setEndless(1, OFF);
    ax12a2.setEndless(2, OFF);
    pinMode(DIR_1,OUTPUT);
    pinMode(DIR_2,OUTPUT);
    pinMode(PWM_1,OUTPUT);
    pinMode(PWM_2,OUTPUT);
    pinMode(LED_Pin, OUTPUT);
}


void turnAngle(unsigned char id, int angle, int _speed)
{
    if (id != 0)
    {
        correct_position(angle);
    }
    Cur_angle[id - 1] = angle;
    ax12a2.moveSpeed(id, static_cast<int>(512 + angle * 3.45), _speed);
}

void start_position(int start_angle = 0)
{
    for (int i = 0; i < MOTOR_COUNT; ++i)
        turnAngle(i, start_angle, 100);
}

void convert_data(String data)
{
    String tmp = "";
    for (int iter = 0, j = 0; iter < data.length(); ++iter)
    {
        if (data[iter] == ' ')
        {
            while (data[iter] != ' ')
                iter++;
            input_data[j] = tmp.toInt();
            tmp = "";
            ++j;
        }
        else
        {
            tmp += data[iter];
        }
    }
}

// 40.6 mm
// 71.2 mm
// 94.7 mm


/*
void loop()
{
    Serial.println("Calibrate");
    start_position();
    while (1)
    {
        if (Serial.available() > 0)
        {
            String data = Serial.readStringUntil('\n');
            Serial.read();
            // Serial.println(data);
            convert_data(data);
            for (int i = 0; i < MOTOR_COUNT; ++i)
            {
                Serial.print(input_data[i]);
                Serial.print(' ');
            }
            Serial.println();
            //Serial3.println();
            for (unsigned char iter = 0; iter < MOTOR_COUNT; ++iter)
            {
                turnAngle(iter, input_data[iter], 100);
            }
        }
    }
}
*/