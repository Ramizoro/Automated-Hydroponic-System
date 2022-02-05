#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ThingSpeak.h>
#define SensorPin 0          // the pH meter Analog output is connected with the Arduino’s Analog
#define pump D2

// Thingspeak Connection 
const char* ssid = "MINT";
const char* password = "MINTCSE499";
WiFiClient client;
unsigned long myChannelNumber = 833658;
const char * myWriteAPIKey = "CXL2LZOUPNCCFRRC"; 

void setup()
{ 
  Serial.begin(9600);  
  Serial.println("Ready");    //Test the serial monitor
  pinMode(pump,OUTPUT);
  
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop()
{
  //for(int i=0; i < 28; i++){
   //delay(900000);
   pinMode(pump,HIGH);
   float s = analogRead(SensorPin)/100.0;
   Serial.println(s);
   ThingSpeak.writeField(myChannelNumber, 7, s , myWriteAPIKey);
   delay(5000);
   if(s >= 6.5){
    Serial.println("Motor on");
    pinMode(pump,LOW);
    delay(3000);
   }
  //}

   //delay(75600000);
}