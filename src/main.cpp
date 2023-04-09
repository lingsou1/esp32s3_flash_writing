/*
接线说明:无

程序说明:使用闪存文件系统(SPIFFS)来对esp32s3的闪存写入数据

注意事项:根据文档好像有两种方式,一是:SPIFFS,二是:LittleFS,
(文档地址:https://docs.platformio.org/en/latest/platforms/espressif32.html#flash-mode)

函数示例:无

作者:灵首

时间:2023_3_11

*/
#include <Arduino.h>
#include <SPIFFS.h>
#include <FS.h>

String file_name = "/lingsou/notes.txt";    //定义文件名(notes.txt)以及文件所在地址



/*
# brief 对闪存文件进行格式化操作
# param 无
# retval 无
*/
void SPIFFS_Format_init(){
  Serial.print("\nSPIFFS format begin");
  SPIFFS.format();    //文件格式化的函数
  Serial.print("\nSPIFFS format finshed !!!");

}



/*
# brief 启动SPIFFS
# param 无
# retval 无
*/
void SPIFFS_start_init(){
  if(SPIFFS.begin()){
    Serial.print("\nSPIFFS Start!!!");
  }
  else{
    Serial.print("\nSPIFFS Failed to start!!!");
  }
}



void setup() {

  Serial.begin(9600);
  Serial.print("...");

  SPIFFS_Format_init();   //格式化闪存
  SPIFFS_start_init();    //启动SPIFFS

  File dataFile = SPIFFS.open(file_name,"w");   // 建立File对象用于向SPIFFS中的file对象（即/notes.txt）写入信息
  dataFile.println("welcome come to the esp32s3's world!!!");   //闪存具体的写入内容(向dataFile写入字符串信息)
  dataFile.close();   //关闭文件,打开文件进行需要的操作后要及时关闭文件

  Serial.print("\nFinshed writing data to SPIFFS");

}

void loop() {

}