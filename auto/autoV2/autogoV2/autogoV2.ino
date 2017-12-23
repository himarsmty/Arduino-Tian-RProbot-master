#include "LobotServoController.h"
#include "auto.h"
const int scan_delay = 4000;
/*
  ##########################################
  tilt=20, pan=19;
  turnleft(); //spider turn left
  turnright(); //spider turn right
  yun_left(); yun turn left
  yun_right(); yun turn right
  go_back();//spider go back;
  sound_scan();//sound scan one time
  yun_reset()

  云台 pan:500  右转
    pan:2500 左转
    pan:1500 正前
    tilt：2500 俯视
    tilt：1500 正视
    tilt：500  仰望星空
    tilt合理范围：
    1000-1500 扫描上前方
    1500-1700 扫描下前方
  ###########################################
*/
void scan_down()
{
  spider.moveServo(20, 1600, 1000);
}
void scan_up()
{
  spider.moveServo(20,1350,1000);
}
void begin_Go()//第一程
{
  currdist = sound_scan();
  delay(1000);
  yun_left();
  delay(6000);
  yun_reset();
  delay(2000);
     spider.runActionGroup(5, 2);
    delay(2000);
    spider.runActionGroup(7, 1);
    delay(1000);
      spider.runActionGroup(5, 2);
    delay(2000);
    spider.runActionGroup(7, 1);
    delay(1000);
      spider.runActionGroup(5, 2);
    delay(2000);
    spider.runActionGroup(7, 1);
    delay(1000);
      spider.runActionGroup(5, 2);
    delay(2000);
    spider.runActionGroup(7, 1);
    delay(1000);
  spider.runActionGroup(5, 2);
    delay(2000);
    spider.runActionGroup(7, 1);
    delay(1000);
  turnleft();
  delay(5000);
}
void search_front_wall()//正前方
{
  /////////////////////////////
  //2
  for (int i = 0; i < 3; i++)
  {
    spider.runActionGroup(5, 1);
    delay(2000);
    spider.runActionGroup(7, 1);
    delay(1000);
  }
      spider.runActionGroup(5, 2);
    delay(2000);
    spider.runActionGroup(7, 1);
    delay(1000);
  yun_right();
  delay(1000);
  scan_up();
  delay(1000);
  delay(8000);
  ///////////////////////////////////
  spider.runActionGroup(6,1);
  delay(1000);
  
  spider.runActionGroup(7, 2);
  delay(3000);
  spider.runActionGroup(5,1);
  delay(1000);
  spider.runActionGroup(7,2);
  delay(2000);
  ///////////////////////////
  //3
  for (int i = 0; i < 4; i++)
  {
    spider.runActionGroup(5, 2);
    delay(2000);
    spider.runActionGroup(7, 1);
    delay(1000);
  }
  spider.runActionGroup(8, 3);
  delay(1000);
  delay(8000);
  /////////////////////////////////////

  //////////////////////////////////////////////

  //4
  for (int i = 0; i < 3; i++)
  {
    spider.runActionGroup(5, 2);
    delay(2000);
    spider.runActionGroup(7, 1);
    delay(1000);
  }
  delay(9000);
  ////////////////////////////////////////////
}

void search_left_wall()//左墙
{
  yun_reset();
  delay(4000);
  turnleft();
  delay(5000);

  /////////////////////////////////////////////

  //5
  spider.runActionGroup(5, 3);
  delay(2000);
  spider.runActionGroup(8, 5);
  delay(9000);
  spider.runActionGroup(7, 7);
  delay(4000);
  ///////////////////////////////////////////////
  //6
  while (1)
  {
    currdist = sound_scan();
    if (currdist < 35) {
      break;
    }
    spider.runActionGroup(5, 1);
    delay(1000);
    spider.runActionGroup(7, 1);
    delay(1000);
  }
  delay(1000);
  scan_down();
  delay(8000);
  yun_reset();
  delay(1000);
  ////////////////////////////

  ///////////////////////////////////////////
  //7
  turnleft();
  delay(10000);
  //////////////////////////////////////////////
}
void search_rand()//小障碍
{
  yun_reset();
  delay(2000);
  spider.runActionGroup(5, 1);
delay(1000);
  /////////////////////////////////////
  //8
      spider.runActionGroup(8, 3);
delay(4000);
  spider.runActionGroup(5, 5);
  delay(8000);
  ////////////////////////////
  //9
  spider.runActionGroup(7, 5);
  delay(6000);
  yun_right();
  delay(2000);
  scan_down();
  
  delay(8000);
  yun_reset();
  delay(1000);
  //////////////////////////
spider.runActionGroup(5,2);
delay(2000);
  turnleft();
  delay(4000);
   yun_right();
   delay(2000);
  spider.runActionGroup(5,3);
  delay(2000);
  delay(8000);
    yun_left();
    delay(8000);

    spider.runActionGroup(6, 2);
    delay(1000);
  delay(100000);
}

void complete()//mission compeled
{
  go_back();
  spider.runActionGroup(0, 1);
  yun_reset();
  delay(1000000);
}
void setup()
{
  Serial1.begin(9600);
  Serial.begin(9600);
  SerialUSB.begin(9600);
  Serial.print("Ultrasonic sensor:\n");
  pinMode(EchoPin, INPUT);
  pinMode(TrigPin, OUTPUT);
  while (!Serial1);



delay(10000);
   yun_reset();
  delay(1000);
  spider.runActionGroup(0, 1);
  delay(2000);
 
  ///////////////////////////////
 // //1

  //////////////////////////////
}
void loop()
{
  begin_Go();
  search_front_wall();
  search_left_wall();
  search_rand();
  complete();
}
