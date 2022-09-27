#include <Arduino.h>
#line 1 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
#include "configurations.h"
#ifdef C_ESP8266_
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#ifndef STASSID
#define STASSID "Darlen"
#define STAPSK "4902asturias"
#endif
const char *ssid = STASSID;
const char *password = STAPSK;
#endif

#include "invernadero.h"
Inver Inver1;
#line 17 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
void setup();
#line 77 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
void loop();
#line 17 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
void setup()
{
  Serial.begin(115200);
  Serial.println(F("Booting"));
#ifdef C_ESP8266_
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.println(F("Connection Failed! Rebooting..."));
    delay(5000);
    ESP.restart();
  }
  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);
  // Hostname defaults to esp8266-[ChipID]
  ArduinoOTA.setHostname("myesp8266");
  // No authentication by default
  // ArduinoOTA.setPassword("admin");
  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA.onStart([]()
                     {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_FS
      type = "filesystem";
    }

    // NOTE: if updating FS this would be the place to unmount FS using FS.end()
    Serial.println("Start updating " + type); });
  ArduinoOTA.onEnd([]()
                   { Serial.println("\nEnd"); });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total)
                        { Serial.printf("Progress: %u%%\r", (progress / (total / 100))); });
  ArduinoOTA.onError([](ota_error_t error)
                     {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println(F("Auth Failed"));
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println(F("Begin Failed"));
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println(F("Connect Failed"));
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println(F("Receive Failed"));
    } else if (error == OTA_END_ERROR) {
      Serial.println(F("End Failed"));
    } });
  ArduinoOTA.begin();
  Serial.println(F("Ready"));
  Serial.print(F("IP address: "));
  Serial.println(WiFi.localIP());
  Inver1.begin();
#endif
}

void loop()
{
#ifdef C_ESP8266_
  ArduinoOTA.handle();
#endif
  Inver1.Control();
}
