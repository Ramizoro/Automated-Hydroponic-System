#include <DHT.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#define DHTPIN D1
#define fan D2
int maxhum=88;
int maxTemp=28;

#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
const char* ssid = "MINT";
const char* password = "MINTCSE499";
WiFiClient client;
unsigned long myChannelNumber = 833658;
const char * myWriteAPIKey = "CXL2LZOUPNCCFRRC";
uint8_t temperature, humidity;


void setup()
{
  Serial.begin(9600);
  pinMode(fan,OUTPUT);
  dht.begin();
  delay(10);
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
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  Serial.print("Temperature Value is :");
  Serial.print(temperature);
  Serial.println("C");
  Serial.print("Humidity Value is :");
  Serial.print(humidity);
  Serial.println("%");
  ThingSpeak.writeField(myChannelNumber, 4, temperature, myWriteAPIKey);
  delay(10);
  ThingSpeak.writeField(myChannelNumber, 5, humidity, myWriteAPIKey);
 
 if(isnan(humidity)||isnan(temperature))
 {
    Serial.println("Failed to read from DHT11 sensor");
  return;
  }
 if(humidity>maxhum||temperature>maxTemp)
  {
    pinMode(fan, LOW);
    delay(1000);
     Serial.println("ON");
  }
  else
  {
    pinMode(fan, HIGH);
    delay(1000);
  }
  

  
  delay(5000); // ThingSpeak will only accept updates every 15 seconds.
}