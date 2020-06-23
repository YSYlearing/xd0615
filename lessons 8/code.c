/*
  Calibration

 Demonstrates one technique for calibrating sensor input.  The
 sensor readings during the first five seconds of the sketch
 execution define the minimum and maximum of expected values
 attached to the sensor pin.

 The sensor minimum and maximum initial values may seem backwards.
 Initially, you set the minimum high and listen for anything
 lower, saving it as the new minimum. Likewise, you set the
 maximum low and listen for anything higher as the new maximum.

 The circuit:
 * Analog sensor (potentiometer will do) attached to analog input 0
 * LED attached from digital pin 9 to ground

 created 29 Oct 2008
 By David A Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://www.arduino.cc/en/Tutorial/Calibration

 This example code is in the public domain.

 */

// These constants won't change:
const int sensorPin = A0;    //传感器连接AO模拟引脚
const int ledPin = 9;        //LED灯连接数字9引脚

// variables:
int sensorValue = 0;         // 定义传感器变量，赋初值
int sensorMin = 1023;        // 定义最小值
int sensorMax = 0;           // 定义最大值


void setup() 
{
  pinMode(13, OUTPUT);//设定板载灯输出模式
  digitalWrite(13, HIGH);//点亮灯，表示校准开始

  
  while (millis() < 5000)//限定程序开始5秒内，模拟信号的校准
  {
    sensorValue = analogRead(sensorPin);
    //从指定的模拟接口读取值，Arduino对该模拟值10-bit的数字转换
    // 不停地获取光敏电阻的数值，以此在这5秒钟内得到其中的最大和最小数值。
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }
    //比较获取到的数值，如果比sensorMax数值大，则赋值给sensorMax，以此记录最终得到的最大值。
   
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
    //比较获取到的数值，如果比sensorMin数值小，则赋值给sensorMin，以此记录最终得到的最小 值。
  }

  
  digitalWrite(13, LOW);
} //5秒钟过后，将13号数字引脚的数值设置为低电压，以此熄灭Arduino UNO电路板自带的那盏LED灯。

void loop() {
  // 读取传感器的值
  sensorValue = analogRead(sensorPin);
  //映射传感器校准的值，将校准结果应用到传感器读取中
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  //限制传感器获取值的区间范围
  sensorValue = constrain(sensorValue, 0, 255);

  //使用传感器的校准值，写入接口
  analogWrite(ledPin, sensorValue);
}	