#ifndef AUTO_H_
#define AUTO_H_
#include "LobotServoController.h"
LobotServoController spider;
const int tilt=20;//yun tai
const int pan=19;
long currdist;
void turnleft(){
  spider.runActionGroup(7,7);
}
void turnright(){
  spider.runActionGroup(8,7);
}
void go_back(){
  spider.runActionGroup(6,3);
}
void yun_left(){
  spider.moveServo(19,2500,1000);
}
void yun_right(){
  spider.moveServo(19,500,1000);
}
const int EchoPin=3;
const int TrigPin=2;
long MeasuringDistance()
{
    long distance,sum=0;
    long dis[10];
    for(int i=0; i<5; i++)
    {
        digitalWrite(TrigPin,LOW);
        delayMicroseconds(2);
        digitalWrite(TrigPin,HIGH);
        delayMicroseconds(5);
        digitalWrite(TrigPin,LOW);
        dis[i]=pulseIn(EchoPin,HIGH)*0.017;
        sum+=dis[i];
    }
    distance=sum/5;
    return distance;
}
int sound_scan()
{
    int tempdist=MeasuringDistance();
    Serial.print("Current Distance:");
    Serial.println(tempdist);
    return tempdist;
}
void yun_reset()
{
    spider.moveServo(20,1500,1000);
    delay(1000);
    spider.moveServo(19,1500,1000);
    delay(1000);
}
#endif
