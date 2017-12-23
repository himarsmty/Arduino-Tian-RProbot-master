#include "LobotServoController.h"

LobotServoController spider;
const int EchoPin_l=3;
const int TrigPin_l=2;
const int EchoPin_r=9;
const int TrigPin_r=8;
const int tilt=20;//yun tai
const int pan=19;
long currdist_L,currdist_R;
long MeasuringDistance_l()
{
    long distance;
    digitalWrite(TrigPin_l,LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin_l,HIGH);
    delayMicroseconds(5);
    digitalWrite(TrigPin_l,LOW);
    distance=pulseIn(EchoPin_l,HIGH)*0.017;
    return distance;
}
long MeasuringDistance_r()
{
    long distance;
    digitalWrite(TrigPin_r,LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin_r,HIGH);
    delayMicroseconds(5);
    digitalWrite(TrigPin_r,LOW);
    distance=pulseIn(EchoPin_r,HIGH)*0.017;
    return distance;
}
void randTurn()
{
    long randNumber;
    randomSeed(analogRead(0));
    randNumber=random(0,10);
    if(randNumber>5)
        spider.runActionGroup(7,3);// turn left 3 times
    else
        spider.runActionGroup(8,3);// turn right 3 times
}
void setup()
{
    Serial1.begin(9600);
    Serial.begin(9600);
    while(!Serial1);
    spider.runActionGroup(0,1);
    spider.setActionGroupSpeed(5,40);//set speed
    spider.setActionGroupSpeed(6,100);
    spider.setActionGroupSpeed(7,100);
    spider.setActionGroupSpeed(8,100);
    LobotServo servos[2];//yun tai
    servos[0].ID=tilt;
    servos[0].Position=1500;
    servos[1].Position=1500;
    servos[1].ID=pan;
    spider.moveServos(servos,2,1000);//reset yun tai
    pinMode(EchoPin_l,INPUT);
    pinMode(TrigPin_l,OUTPUT);
    pinMode(EchoPin_r,INPUT);
    pinMode(TrigPin_r,OUTPUT);
    Serial.print("Ultrasonic sensor:\n");
}
void loop()
{
    currdist_L=MeasuringDistance_l();
    currdist_R=MeasuringDistance_r();
    Serial.print("Current left Distance:");
    Serial.println(currdist_L);
    Serial.print("\n");
    Serial.print("Current right Distance:");
    Serial.println(currdist_R);
  
    if(currdist_L>35&&currdist_R>35)//forward
    {
        spider.runActionGroup(5,1);
    }
    else if(currdist_L<15&&currdist_R<15)//wall
    {
        spider.stopActiongGroup();
        spider.runActionGroup(6,1);
    }
    else if(currdist_L<15)//left obstacle
    {
        spider.runActionGroup(6,1);
        spider.runActionGroup(8,2);
    }
    else if(currdist_R<15)//right obstacle
    {
        spider.runActionGroup(6,1);
        spider.runActionGroup(7,2);
    }
    else
        randTurn (); 
    spider.moveServo(tilt,500,10000);// scan
    spider.moveServo(tilt,2500,10000);
    spider.moveServo(tilt,1500,10000);
    spider.moveServo(pan,500,10000);
    spider.moveServo(pan,2500,10000);
    spider.moveServo(pan,1500,10000);
    delay(2000);
}
