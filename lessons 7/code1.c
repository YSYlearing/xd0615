#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define S1 8
#define LT 6
#define BT 7
void setup()
{
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐  
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(S1,HIGH);

  Serial.begin(9600);
}
void loop(){
  byte income, i=0;
  for(i=0; i<11; i++){
    if(i==10)
      i=0; 
    income=i;
    digitalWrite (S1, LOW) ;
    digitalWrite (2, income&0x1) ;
    digitalWrite (3, (income>>1) &0x1) ;
    digitalWrite (4, (income>>2) &0x1) ;
    digitalWrite (5, (income>>3) &0x1) ;
    delay (1000) ;   
  }
}
