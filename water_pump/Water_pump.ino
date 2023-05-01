#include <Wire.h> 
#include <iarduino_RTC.h> 
iarduino_RTC watch(RTC_DS1302, 2, 3, 4);
int T_pump = 30000;
void setup() {
  // put your setup code here, to run once:
 pinMode(13, OUTPUT);
 pinMode(11, OUTPUT);
 pinMode(8, OUTPUT);
 watch.begin();
 Serial.begin(9600);
 Serial.println(watch.gettime("d-m-Y, H:i:s, D"));
}
void Pump_ON()
{
 digitalWrite(13, HIGH);
 digitalWrite(8, LOW);
 analogWrite(11, 255);
 Serial.println("PUMP_ON");
 delay(T_pump);
  }

void Pump_OFF()
{
 digitalWrite(13, HIGH);
 digitalWrite(8, LOW);
 analogWrite(11, 0);
 Serial.println("PUMP_OFF");
  }

void loop() {
  // put your main code here, to run repeatedly:
if (millis()%1000==0){
  watch.gettime();
  Serial.print(watch.Hours);   Serial.print(":");  // Вывести часы.
  Serial.print(watch.minutes); Serial.print(":");  // Вывести минуты.
  Serial.print(watch.seconds); Serial.println(""); // Вывести секунды.
  if ((watch.day%2==1)and(watch.Hours==18) and (watch.minutes == 30) and (watch.seconds == 0))
  {Pump_ON();
  }
  else
  {
  Pump_OFF();
  }
  delay(1);
}
}
