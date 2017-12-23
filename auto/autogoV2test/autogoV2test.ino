#include "LobotServoController.h"

LobotServoController spider;
void setup()
{    
      Serial1.begin(9600);
  while(!Serial1);
  spider.runActionGroup(0,1);
    spider.runActionGroup(7,7
    );
}
void loop()
{      

    
}
