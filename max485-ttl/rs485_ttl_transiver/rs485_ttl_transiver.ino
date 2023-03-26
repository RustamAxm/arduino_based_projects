#include <SoftwareSerial.h>           // Подключаем библиотеку SoftwareSerial
SoftwareSerial Master(10, 11);        // Указываем выводы RO и RI
char val;                             // Создаем переменную val
int DE_RE=4;                          // Указываем выводы DE и RE
 
void setup() 
{
  Serial.begin(19200);                // Открываем последовательную связь
  Serial.println("Master!");          // Отправка текста  
  Master.begin(19200);                // Открываем последовательную связь
  pinMode(DE_RE,OUTPUT);              // Задаем DE_RE как выход 
  digitalWrite(DE_RE,LOW);            // Устанавливаем DE_RE в LOW 
}
 
void loop() { 
  while (Serial.available()) {        // Проверяем,поступили ли данные 
    digitalWrite(DE_RE,HIGH);         // Устанавливаем DE_RE в HIGH
    val = Serial.read();              // Копируем данные val
    Master.write(val);                // Отправка данных
  }
 
  digitalWrite(DE_RE,LOW);            // Устанавливаем DE_RE в LOW  
  while(Master.available()) {         // Проверяем,поступили ли данные  
    val = Master.read();              // Копируем данные val
    Serial.write(val);                // Отправка данных         
  }
}