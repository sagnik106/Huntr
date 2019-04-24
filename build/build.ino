int c1=2;//channel 1
int c2=4;//channel 2
int dir1 = 12;//direction control motor 1
int dir2 = 13;//direction control motor 2
int pwm1 = 3;//speed contol motor 1
int pwm2 = 5;//speed control motor 2
void setup() 
{
  Serial.begin(9600);
  pinMode(c1,INPUT);
  pinMode(c2,INPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
}

void loop() 
{
  int ch1=pulseIn(c1,HIGH);
  int ch2=pulseIn(c2,HIGH);
  Serial.println(ch1);
  ch1=map(ch1,1190,1890,-255,255);
  ch2=map(ch2,1650,1300,-255,255);
  if(ch2>12)
    forward(ch2);
  else if(ch2<-21)
    backward(255-ch2);
  else
  {
    if(ch1<-18)
      left(255-ch1);
    else if(ch1>18)
      right(ch1);
    else
      forward(0);
  }
}
void forward(int pwm)
{
  digitalWrite(dir1,LOW);
  analogWrite(pwm1,pwm);
  digitalWrite(dir2,LOW);
  analogWrite(pwm2,pwm);
}
void backward(int pwm)
{
  digitalWrite(dir1,HIGH);
  analogWrite(pwm1,pwm);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm2,pwm);  
}
void left(int pwm)
{
  digitalWrite(dir2,HIGH);
  analogWrite(pwm1,pwm);
  digitalWrite(dir1,LOW);
  analogWrite(pwm2,pwm); 
}
void right(int pwm)
{
  digitalWrite(dir1,HIGH);
  analogWrite(pwm1,pwm);
  digitalWrite(dir2,LOW);
  analogWrite(pwm2,pwm);
}
