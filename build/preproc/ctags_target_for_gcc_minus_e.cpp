# 1 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
# 2 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 2

# 4 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 2
# 5 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 2
# 6 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 2
# 7 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 2




const char *ssid = "Darlen";
const char *password = "4902asturias";


# 16 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 2
Inver Inver1;
void setup()
{
  Serial.begin(115200);
  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(
# 20 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                (__extension__({static const char __pstr__[] __attribute__((__aligned__(4))) __attribute__((section( "\".irom0.pstr." "Inver_ota.ino" "." "20" "." "15" "\", \"aSM\", @progbits, 1 #"))) = (
# 20 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                "Booting"
# 20 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                ); &__pstr__[0];}))
# 20 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                ))));

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.println(((reinterpret_cast<const __FlashStringHelper *>(
# 26 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                  (__extension__({static const char __pstr__[] __attribute__((__aligned__(4))) __attribute__((section( "\".irom0.pstr." "Inver_ota.ino" "." "26" "." "16" "\", \"aSM\", @progbits, 1 #"))) = (
# 26 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                  "Connection Failed! Rebooting..."
# 26 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                  ); &__pstr__[0];}))
# 26 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                  ))));
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
    if (ArduinoOTA.getCommand() == 0) {
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
      Serial.println(((reinterpret_cast<const __FlashStringHelper *>(
# 59 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                    (__extension__({static const char __pstr__[] __attribute__((__aligned__(4))) __attribute__((section( "\".irom0.pstr." "Inver_ota.ino" "." "59" "." "17" "\", \"aSM\", @progbits, 1 #"))) = (
# 59 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                    "Auth Failed"
# 59 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                    ); &__pstr__[0];}))
# 59 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                    ))));
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println(((reinterpret_cast<const __FlashStringHelper *>(
# 61 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                    (__extension__({static const char __pstr__[] __attribute__((__aligned__(4))) __attribute__((section( "\".irom0.pstr." "Inver_ota.ino" "." "61" "." "18" "\", \"aSM\", @progbits, 1 #"))) = (
# 61 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                    "Begin Failed"
# 61 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                    ); &__pstr__[0];}))
# 61 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                    ))));
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println(((reinterpret_cast<const __FlashStringHelper *>(
# 63 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                    (__extension__({static const char __pstr__[] __attribute__((__aligned__(4))) __attribute__((section( "\".irom0.pstr." "Inver_ota.ino" "." "63" "." "19" "\", \"aSM\", @progbits, 1 #"))) = (
# 63 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                    "Connect Failed"
# 63 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                    ); &__pstr__[0];}))
# 63 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                    ))));
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println(((reinterpret_cast<const __FlashStringHelper *>(
# 65 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                    (__extension__({static const char __pstr__[] __attribute__((__aligned__(4))) __attribute__((section( "\".irom0.pstr." "Inver_ota.ino" "." "65" "." "20" "\", \"aSM\", @progbits, 1 #"))) = (
# 65 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                    "Receive Failed"
# 65 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                    ); &__pstr__[0];}))
# 65 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                    ))));
    } else if (error == OTA_END_ERROR) {
      Serial.println(((reinterpret_cast<const __FlashStringHelper *>(
# 67 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                    (__extension__({static const char __pstr__[] __attribute__((__aligned__(4))) __attribute__((section( "\".irom0.pstr." "Inver_ota.ino" "." "67" "." "21" "\", \"aSM\", @progbits, 1 #"))) = (
# 67 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                    "End Failed"
# 67 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                    ); &__pstr__[0];}))
# 67 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                    ))));
    } });
  ArduinoOTA.begin();
  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(
# 70 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                (__extension__({static const char __pstr__[] __attribute__((__aligned__(4))) __attribute__((section( "\".irom0.pstr." "Inver_ota.ino" "." "70" "." "22" "\", \"aSM\", @progbits, 1 #"))) = (
# 70 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                "Ready"
# 70 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
                ); &__pstr__[0];}))
# 70 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
                ))));
  Serial.print(((reinterpret_cast<const __FlashStringHelper *>(
# 71 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
              (__extension__({static const char __pstr__[] __attribute__((__aligned__(4))) __attribute__((section( "\".irom0.pstr." "Inver_ota.ino" "." "71" "." "23" "\", \"aSM\", @progbits, 1 #"))) = (
# 71 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
              "IP address: "
# 71 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino" 3
              ); &__pstr__[0];}))
# 71 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Inver_ota.ino"
              ))));
  Serial.println(WiFi.localIP());
  Inver1.begin();

}

void loop()
{

  ArduinoOTA.handle();

  Inver1.Control();
}
