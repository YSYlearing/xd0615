char ch=' ';
void setup()
{
    Serial.begin(9600);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
  Serial.println("ok");
}
/*
预定
'f'表示前进
’b'表示后退 
'r'表示右转 
'l'表示左转
*/
void loop()
{
  if(Serial.available()>0)
  {
    ch=Serial.read();
    switch(ch)
    {
      case'b':
       digitalWrite(4,HIGH);
       digitalWrite(5,LOW);
       digitalWrite(10,HIGH);
       digitalWrite(11,LOW);
      break;
      case'f':
       digitalWrite(5,HIGH);
       digitalWrite(4,LOW);
       digitalWrite(11,HIGH);
       digitalWrite(10,LOW);
      break;
      case'l':
       digitalWrite(5,HIGH);
       digitalWrite(4,LOW);
       digitalWrite(10,HIGH);
       digitalWrite(11,LOW);
      break;
      case'r':
       digitalWrite(4,HIGH);
       digitalWrite(5,LOW);
       digitalWrite(11,HIGH);
       digitalWrite(10,LOW);
      break;
      case's':
       digitalWrite(4,LOW);
       digitalWrite(5,LOW);
       digitalWrite(10,LOW);
       digitalWrite(11,LOW);
      default:
      break;
    }
  }
 
}
