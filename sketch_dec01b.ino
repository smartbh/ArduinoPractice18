#include <SoftwareSerial.h>
SoftwareSerial blueTooth(2,3);

int speed=0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(8, OUTPUT); //IN2
  pinMode(9, OUTPUT); //IN1
  pinMode(10, OUTPUT);

  speed=0; //초기속도
  digitalWrite(8, LOW); //초기 방향
  digitalWrite(9, HIGH);

  blueTooth.begin(9600);
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(blueTooth.available()==false) return;
  byte cmd = blueTooth.read();
  Serial.println(cmd);
  if(cmd == 1)
  {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }
  else if(cmd == 2)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }
  else if(cmd ==3)
  {
    speed +=50;
  }
  else if(cmd == 4)
  {
    speed -=50;
  }
  else if(cmd ==5)
  {
    speed = 0;
  }
  if(speed <0)
    speed=0;
  if(speed>256)
    speed = 255;
  analogWrite(10,speed);
  
}
