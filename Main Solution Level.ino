#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>                                             // Include library file for MQTT
#include "Ultrasonic.h"                                             // Include library file for ultrasonic (HC-SR04)


const char* ssid = "MINT";
const char* password = "MINTCSE499";
WiFiClient client;
unsigned long myChannelNumber = 833658;
const char * myWriteAPIKey = "CXL2LZOUPNCCFRRC";
#define pump D2
int minVal= 20;
Ultrasonic ultrasonic(D5,D6);                                       // Assign Trig PIN 14(D5),Assign Echo PIN 12(D6)
int GIu_Ultrasonic_Dist_CM;


//=====================Basic Setup ============================

void setup(){  
   Serial.begin(9600);                                              // Setup Debug uart port if you want ?
    delay(10);
    pinMode(pump,OUTPUT);
  // Connect to WiFi network
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
    
      GIu_Ultrasonic_Dist_CM=ultrasonic.Ranging(CM);     
      Serial.print(GIu_Ultrasonic_Dist_CM); 
      Serial.println(" cm" );

      if(GIu_Ultrasonic_Dist_CM <= 20)
      {
         pinMode(pump,HIGH);
         Serial.println("Motor is off");
         delay(5000);
      }
      else
      {
      pinMode(pump,LOW);
      Serial.println("Motor is on");
      }
      delay(5000);
      
      ThingSpeak.writeField(myChannelNumber, 3, GIu_Ultrasonic_Dist_CM, myWriteAPIKey); 
      delay(100);
  }
//==================================================================