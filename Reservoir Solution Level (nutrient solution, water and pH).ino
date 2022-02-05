#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h> 

//ThingSpeak SetUp//.................................................................//
const char* ssid = "MINT";
const char* password = "MINTCSE499";
WiFiClient client;
unsigned long myChannelNumber = 833658;
const char * myWriteAPIKey = "CXL2LZOUPNCCFRRC";
//...............................................................................................//

#define trigPinpH D0  
#define echoPinpH D1  
#define trigPinSol D2  
#define echoPinSol D3  
#define trigPinWat D4 
#define echoPinWat D5  

// defines variables
long duration;
int distancepH;
int distanceSol;
int distanceWat;

void setup() {
pinMode(trigPinpH, OUTPUT); 
pinMode(echoPinpH, INPUT); 
pinMode(trigPinSol, OUTPUT); 
pinMode(echoPinSol, INPUT);
pinMode(trigPinWat, OUTPUT); 
pinMode(echoPinWat, INPUT); 
Serial.begin(9600); 

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

void loop() {

// **** 1st sensor ****
digitalWrite(trigPinpH, LOW);
delayMicroseconds(2);

digitalWrite(trigPinpH, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinpH, LOW);

duration = pulseIn(echoPinpH, HIGH);

distancepH= duration*0.034/2;
Serial.print("Distance 1 : ");
Serial.println(distancepH);
ThingSpeak.writeField(myChannelNumber, 2, distanceWat, myWriteAPIKey);
delay(200);                                                                                                                                                        
// **** 2nd sensor ****
digitalWrite(trigPinSol, LOW);
delayMicroseconds(2);

digitalWrite(trigPinSol, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinSol, LOW);

duration = pulseIn(echoPinSol, HIGH);

distanceSol= duration*0.034/2;
Serial.print("Distance 2 : ");
Serial.println(distanceSol);
ThingSpeak.writeField(myChannelNumber, 1, distanceSol, myWriteAPIKey);
delay(200);
// **** 3nd sensor ****
digitalWrite(trigPinWat, LOW);
delayMicroseconds(2);

digitalWrite(trigPinWat, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinWat, LOW);

duration = pulseIn(echoPinWat, HIGH);

distanceWat= duration*0.034/2;
Serial.print("Distance 3 : ");
Serial.println(distanceWat);

ThingSpeak.writeField(myChannelNumber, 6, distanceWat, myWriteAPIKey);
delay(200);
}