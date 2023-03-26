#include <SPI.h>              //Library for using SPI Communication 
#include <mcp2515.h>          //Library for using CAN Communication

struct can_frame canMsg; 
MCP2515 mcp2515(10);                 // SPI CS Pin 10 
 
void setup() {
  
  SPI.begin();                       //инициализируем связь по протоколу SPI
  Serial.begin(9600);                //инициализируем последовательную связь со скоростью 9600 бод 
  
  mcp2515.reset();                          
  mcp2515.setBitrate(CAN_500KBPS,MCP_8MHZ); //устанавливаем скорость шины CAN 500 кбит/с и частоту кварцевого генератора 8 МГц
  mcp2515.setNormalMode();                  //устанавливаем CAN-шину в обычный режим
}
void loop() 
{
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) // To receive data (Poll Read)
  {
     int x = canMsg.data[0];         
     int y = canMsg.data[1];       
      
//показываем принятые значения температуры и влажности на ЖК дисплее 16x2             
      Serial.print("Humidity : ");
      Serial.println(x);
      Serial.print("Temp : ");
      Serial.println(y);
      delay(1000);
    }
}