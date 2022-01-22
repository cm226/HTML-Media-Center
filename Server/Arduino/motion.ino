#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>

char* ssid = "***"; // SSID
char* password = "***"; // pw needed

const int led = 13;


void setup(void){
  //pinMode(led, OUTPUT);
  //digitalWrite(led, 0);
  Serial.begin(115200);

  
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".-");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  pinMode(D3, INPUT);
  digitalWrite(D3, LOW);
  
}

void loop(void){
  
  int val = digitalRead(D3);
  if(val == HIGH){
    
    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
    client->setInsecure();

    HTTPClient http;
    http.begin(*client, "https://192.168.1.85:8442/Sensors/bedroom");
    int httpCode = http.GET();
    http.end();
    //Serial.print("HTTP Code ");
    //Serial.println(httpCode);
    //Serial.println("I see something"); 
    delay(5000);
  
  } else {
     Serial.println("nothing to see here");
  }
  delay(100);
}
  
