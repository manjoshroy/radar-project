
#define vcc A0
#define trigpin A1
#define echopin A2
#define gnd A3
float duration=0.0,distance=0.0;
int numberOfPins=0;
float getDistance();
void setup()
{
  pinMode(vcc, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(gnd, OUTPUT);
  digitalWrite(vcc, HIGH);
  digitalWrite(gnd, LOW);
  for(int i=2;i<12;i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop()
{
  if(getDistance()>50)
  {
    for(int i=2;i<12;i++)
    {
      digitalWrite(i,LOW);
    }
  }
  else if(getDistance()<=50)
  {
    for(int i=2;i<12;i++)
    {
      digitalWrite(i,LOW);
    }
    for(int i=2;i<12;i++)
    {
      digitalWrite(i,LOW);
    }
    numberOfPins=12-getDistance()/5;
    for(int i=2;i<=numberOfPins;i++)
    {
      digitalWrite(i,HIGH);
    }
  }
}
float getDistance()
{
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=duration*0.034/2;
  return distance;
}