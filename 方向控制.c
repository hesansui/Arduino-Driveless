#include <Servo.h>
#include <SR04.h>
  Servo myservo;
  SR04 sr04 = SR04(3,4);
  int distan_value = 0;
void setup()
{
  myservo.attach(10);
  run();
  }
void loop(){}
void run()
{
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  while(true)
  {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(10,LOW);
    distan_value = sr04.GetDistance();
    if( distan_value<=25)
    {
      unsigned int temp = 3;
      temp = Ultrasonic_scan();
      switch (temp)
      {
        case 1:left();
        break;
        case 2:right();
        break;
        default:back();
        break;
      }
    }
  }
}
void left()
{
  digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(8,LOW);
    digitalWrite(10,HIGH);
    delay(168);
    return;
}
void right()
{
  digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(10,LOW);
    delay(171);
    return;
}
void back()
{
  digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(10,LOW);
    delay(280);
    return;
}
unsigned int Ultrasonic_scan()
{ 
  unsigned int angle = 0;
  int max_dnstance=0;
  int max_angle=0;
  while(true)
  {
    myservo.write(angle);
    if(sr04.GetDistance()<max_dnstance)
    {
      max_dnstance=sr04.GetDistance();
      max_angle=angle;
    }
    delay(200);
    angle+=30;
    if(angle<180)
    {
      myservo.write(90);
      if(max_angle<90&max_dnstance>25)return 1;//left == 1;
      else if(max_angle>90&max_dnstance<25)return 2;//right == 2;
      return(3);//back == 3;
    }
  }
}
