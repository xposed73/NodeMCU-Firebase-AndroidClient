#include <Firebase.h>  
#include <FirebaseArduino.h>  
#include <FirebaseCloudMessaging.h>  
#include <FirebaseError.h>  
#include <FirebaseHttpClient.h>  
#include <FirebaseObject.h>  
#include <ESP8266WiFi.h>  
#include <FirebaseArduino.h>  
  
// Change this  
#define FIREBASE_HOST "iot-nk.firebaseio.com"  
#define FIREBASE_AUTH "lpZtk2szNYXDyZZchFs8DMUd07piF3wpcVH10Ztw"  
#define WIFI_SSID "NK73"  
#define WIFI_PASSWORD "00000000000"  

int pin = 13;

void setup() {  
  Serial.begin(9600);  
  
  // connect to wifi.  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  
  Serial.print("connecting");  
  while (WiFi.status() != WL_CONNECTED) {  
    Serial.print("Device Successfully Connected to Wifi...");
    delay(500);  
  }
  Serial.println();  
  Serial.print("connected: ");  
  Serial.println(WiFi.localIP());  
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);  
  pinMode(pin, OUTPUT);  
  Firebase.set("LED_STATUS",0);
}  
  
int n = 0;

void loop() {  
  // set value  
  n=Firebase.getInt("LED_STATUS");  
  // handle error  
  if (n==1) {  
      Serial.print("LED is ON");  
      digitalWrite(pin, HIGH);  
      Serial.println(Firebase.error());   
      return;  
      //delay(100);  
  }  
 else{  
   Serial.print("LED is OFF");  
   digitalWrite(pin, LOW); 
 }  
    
}  
