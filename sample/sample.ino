int channel1 = 6;
int channel2 = 5;
int dir1 = 7;
int dir2 = 8;
int pwm1 = 9;
int pwm2 = 10;
int Channel1 ; 
int Channel2 ;
void  setup ()
{
   pinMode(dir1,OUTPUT);
   pinMode(dir2,OUTPUT);
   pinMode(pwm1,OUTPUT);
   pinMode(pwm2,OUTPUT);
   pinMode (channel1, INPUT);
   pinMode (channel2, INPUT);
   Serial.begin (9600);
}

void  loop ()
{
  forward();
  Channel1 = (pulseIn (channel1, HIGH));
  Serial.println(Channel1);
  if (false)
  {
  if (Channel1 < 1300)
  {
    Serial.println ("backward"); 
    back();
  }
  else if (Channel1 > 1500)
  {
    Serial.println ("forward"); 
    forward();
  }
  delayMicroseconds(Channel1);
  Channel2 = (pulseIn (channel2, HIGH));
  //Serial.println (Channel2); 
  if (Channel2 < 1300)
  {
    Serial.println ("left");
    left();
  }
  else if (Channel2 > 1900)
  {
    Serial.println ("right");
    right(); 
  }
  else if (Channel2 > 1500 && Channel2 < 1600)
  {
    stp();
  }
  delayMicroseconds(Channel2);
}
}
void forward()
{
  int pwmf = map(channel1,1800,2000,0,255);
  digitalWrite(dir1,HIGH);
  analogWrite(pwm1,pwmf);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm2,pwmf);
}
void stp()
{
  digitalWrite(dir1,LOW);
  digitalWrite(dir1,LOW);  
}
void back()
{
  int pwmb = map(channel1,1170,1180,255,0);
  digitalWrite(dir1,HIGH);
  analogWrite(pwm1,pwmb);
  digitalWrite(dir1,HIGH);
  analogWrite(pwm2,pwmb);  
}
void left()
{
  int pwml1 = map(channel2,1150,1160,255,0);
  int pwml2 = map(channel2,1150,1160,0,255);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm2,pwml1);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm2,pwml2); 
}
void right()
{
  int pwmr1 = map(channel2,1800,2000,0,255);
  int pwmr2 = map(channel2,1800,2000,255,0);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm1,pwmr1);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm2,pwmr2);
}
