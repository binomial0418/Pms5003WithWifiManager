include <Arduino.h>
#include <FS.h>
#include <ArduinoJson.h>

const char* WIFI_FILE     = "/wifi.ini";

void setup()
{
  writeWifiConfigFile(WIFI_FILE,String('123'),String('456'));
}

void loop()
{
 
}

void writeWifiConfigFile(String typ,String ssid,String pwd){
  String str;
  StaticJsonDocument<200> json_doc;
  char json_output[100];
  json_doc["ssid"] = ssid + "#";
  json_doc["pwd"]  = pwd + "#";
  serializeJson(json_doc, json_output);
 
  SPIFFS.begin();
  File f = SPIFFS.open(typ, "w");  
  if (!f) {
    Serial.println("Failed to open config file for writing");
  }
  f.println(json_output);
  f.close();
}
