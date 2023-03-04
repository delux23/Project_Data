#include <Adafruit_SSD1306.h>
#define OLED_Address 0x3C // 0x3C device address of I2C OLED. Few other OLED has 0x3D
Adafruit_SSD1306 oled(128, 32); // create our screen object setting resolution to 128x64
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <OneWire.h>
#include <DallasTemperature.h>
 #define SENSOR_PIN 2
 #define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
int a=0;
int bb=0;
int lasta=0;
int lastb=0;
int LastTime=0;
int ThisTime;
bool BPMTiming=false;
bool BeatComplete=false;
int BPM=0;
#define UpperThreshold 560
#define LowerThreshold 530
OneWire oneWire(SENSOR_PIN);         // setup a oneWire instance
DallasTemperature tempSensor(&oneWire); // pass oneWire to DallasTemperature library

String tempString;
 
void setup() {
oled.begin(SSD1306_SWITCHCAPVCC, OLED_Address);
oled.clearDisplay();
oled.setTextSize(2);
tempSensor.begin();     // initialize the sensor
  tempString.reserve(10); // to avoid fragmenting memory when using String
 Serial.begin(9600);
 Serial.println("Hello");
 delay(1000);
 while(!Serial){}
}
 
void loop()
{
  if (bb<100)
  {
if(a>127)
{
oled.clearDisplay();
a=0;
lasta=a;
}
 
ThisTime=millis();
int value=analogRead(0);
oled.setTextColor(WHITE);
int b=60-(value/16);
//oled.writeLine(lasta,lastb,a,b,WHITE);
lastb=b;
lasta=a;
 
if(value>UpperThreshold)
{
if(BeatComplete)
{
BPM=ThisTime-LastTime;
BPM=int(60/(float(BPM)/1000));
BPMTiming=false;
BeatComplete=false;
tone(8,1000,250);
}
if(BPMTiming==false)
{
LastTime=millis();
BPMTiming=true;
}
}
if((value<LowerThreshold)&(BPMTiming))
BeatComplete=true;
 
oled.writeFillRect(0,10,128,4,BLACK);
oled.setCursor(0,4);
oled.print("BPM:");
oled.print(BPM);
 
oled.display();
//Serial.println(SCREEN_WIDTH);
Serial.println(BPM);
delay(500);
Serial.println(tempCelsius);
delay(500);
a++;
if (Serial.available() >0){
  String data = Serial.readStringUntil('\n');
  Serial.print("you");
  //Serial.println(SCREEN_WIDTH);
Serial.println(BPM);
//delay(500);
}


bb++;
}

else
{
tempSensor.requestTemperatures();             // send the command to get temperatures
  float tempCelsius = tempSensor.getTempCByIndex(0);  // read temperature in Celsius
  
  oled.clearDisplay(); // clear display

  oled.setTextSize(2);          // text size
  oled.setTextColor(WHITE);     // text color
  oled.setCursor(0, 10);
oled.print("TEMP:");
oled.print(tempCelsius);
 oled.display();
delay(1000);
  Serial.println(tempCelsius); // print the temperature in Celsius to Serial Monitor
  delay(1000);
oled.clearDisplay();
if (Serial.available() > 0){
  String data = Serial.readStringUntil('\n');
  //Serial.println(SCREEN_WIDTH);
  Serial.print("you");
Serial.println(tempCelsius);
delay(1000);
}
bb=0;
}
}

