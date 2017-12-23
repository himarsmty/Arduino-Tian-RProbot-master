const int EchoPin=3;
const int TrigPin=2;
long currdist;
long MeasuringDistance()
{
    long distance,sum=0;
    long dis[10];
    for(int i=0;i<10;i++)
    {
    digitalWrite(TrigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(TrigPin,LOW);
    dis[i]=pulseIn(EchoPin,HIGH)*0.017;
    sum+=dis[i];
    }
    distance=sum/10;
    return distance;
}
void setup()
{
      Serial.begin(9600);
    Serial.print("Ultrasonic sensor:\n");
    pinMode(EchoPin,INPUT);
    pinMode(TrigPin,OUTPUT);
}
void loop()
{
     currdist=MeasuringDistance();
    Serial.print("Current Distance:");
    Serial.println(currdist);
}

