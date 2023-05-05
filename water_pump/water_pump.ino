#include <Wire.h> 
#include <iarduino_RTC.h> 
iarduino_RTC watch(RTC_DS1302, 2, 3, 4);
int T_pump = 40;
int T_tmp = 0;
String current_time = "";
void setup() {
    // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  watch.begin();
  //  watch.settime(0,19,21, 5, 5,23,5); 
  Serial.begin(9600);
  current_time = watch.gettime("H:i:s");
  Serial.println(current_time);
}
void Pump_ON() {
  digitalWrite(13, HIGH);
  digitalWrite(8, LOW);
  analogWrite(11, 255);
  Serial.println("PUMP_ON");
}

void Pump_OFF() {
  digitalWrite(13, HIGH);
  digitalWrite(8, LOW);
  analogWrite(11, 0);
  Serial.println("PUMP_OFF");
}

void loop() {
  // put your main code here, to run repeatedly:
  // if (Serial.available()) {
  //   T_tmp = Serial.parseInt();
  //   T_pump = T_tmp;
  //   Serial.print("Setted T_pump = ");
  //   Serial.println(T_pump);
  // }

  if (millis()%1000==0) {
    current_time = watch.gettime("H:i:s");
    Serial.println(current_time);
    Serial.println(T_pump);
    
    if ((current_time == "21:35:00") and (watch.day % 2)) {
      while (watch.seconds < T_pump) {
        Pump_ON();
        current_time = watch.gettime("H:i:s");
        delay(500);
      }
    } else {
      Pump_OFF();
    }
    delay(10);
  }
}

