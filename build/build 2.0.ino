//3,5,6,9,10,11
int channel1=3;
int channel2=5;
int channel3=6;
int channel4=9;
int channel5=10;
int channel6=11;
#define pwml A0
#define pwmr A1
int dirl=2;
int dirr=4;

void setup() 
{
  Serial.begin(9600);
  pinMode(channel1,INPUT);
  pinMode(channel2,INPUT);
  pinMode(channel3,INPUT);
  pinMode(channel4,INPUT);
  pinMode(channel5,INPUT);
  pinMode(channel6,INPUT);
}

void loop() 
{
  pinMode(dirl,OUTPUT);
  pinMode(dirr,OUTPUT);
  pinMode(pwml,OUTPUT);
  pinMode(pwmr,OUTPUT);
  int Channel1 = (pulseIn (channel1, HIGH)); // Checks the value of channel1
  int Channel2 = (pulseIn (channel2, HIGH));
  int Channel3 = (pulseIn (channel3, HIGH));
  int Channel4 = (pulseIn (channel4, HIGH));
  int Channel5 = (pulseIn (channel5, HIGH));
  int Channel6 = (pulseIn (channel6, HIGH));
  int f=(Channel6>1507)?0:1; 
  if(Channel1==0 || Channel2==0 || Channel3==0 || Channel4==0 || Channel5==0 || Channel6==0)
  {
    Serial.println("STOP");
    Stop();
  }
  else
  {
    if(Channel2>=1276 && Channel2<=1610) 
    {
      //UP, RIGHT STICK
      int up=map(Channel2,1610,1276,0,255);
      rightmotor(up,0,f);
      leftmotor(up,0,f);
      Serial.println("UP,RIGHT STICK");
    }
    else if(Channel2>=1627 && Channel2<=1946)
    {
      //DOWN, RIGHT STICK
      int down=map(Channel2,1627,1945,0,255);
      rightmotor(down,1,f);
      leftmotor(down,1,f);
      Serial.println("DOWN,RIGHT STICK");
    }
    else if(Channel4>=1217 && Channel4<=1580)
    {
      //RIGHT, LEFT STICK
      int right=map(Channel4,1580,1217,0,255);
      rightmotor(right,1,f);
      leftmotor(right,0,f);
      Serial.println("RIGHT,LEFT STICK");
    }
    else if(Channel4>=1595 && Channel4<=1953)
    {
      //LEFT, LEFT STICK
      int left=map(Channel4,1595,1953,0,255);
      rightmotor(left,0,f);
      leftmotor(left,1,f);
      Serial.println("LEFT,LEFT STICK");
    }
    else
    {
      Serial.println("Stop");
      Stop();
    }
  }
}
void rightmotor(int x,int y,int f)//f is for flip condition
{
  if(y^f==0)
  digitalWrite(dirr,LOW);
  else
  digitalWrite(dirr,HIGH);
  analogWrite(pwmr,x); 
}
void leftmotor(int x,int y,int f)
{
  if(y^f==0)
  digitalWrite(dirl,LOW);
  else
  digitalWrite(dirl,HIGH);
  analogWrite(pwml,x); 
}
void Stop()
{
  rightmotor(0,0,0);
  leftmotor(0,0,0);
}
