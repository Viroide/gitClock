#include "RTClib.h"
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Arduino_JSON.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Wire.h>
#include <NTPClient.h>
#include <WiFiUdp.h>


#define MATRIX_PIN 5      // pin D1
#define MATRIX_HEIGHT 8   
#define MATRIX_WIDTH 32   

#define RTC_SDA 14        // pin D5
#define RTC_SCL 12        // pin D6

#define GMT_PLUS_1 3600

#define UPADTE_INTERVAL 60

JSONVar prList;
#define TIME_BUFFER_SIZE 5
char timeBuffer[TIME_BUFFER_SIZE];
bool firstTime = true;
DateTime lastUpdate;
DateTime now;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);
RTC_DS3231 rtc;

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_PIN,
                            NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
                            NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                            NEO_GRB            + NEO_KHZ800);

#include "colors.h"
#include "readPrInfo.h"
#include "wifiConfig.h"
#include "writeDate.h"
#include "writePrInfo.h"

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(20);
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print('.');
  }

  Wire.begin(RTC_SDA, RTC_SCL);
  if (!rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }

  timeClient.begin();
  timeClient.update();
  Serial.print("NTP date:");
  Serial.println(timeClient.getFormattedTime());
  rtc.adjust(DateTime(timeClient.getEpochTime() + GMT_PLUS_1));
}


void loop() {
  matrix.fillScreen(0);

  now = rtc.now();
  sprintf(timeBuffer, "%02d:%02d ",  now.hour(), now.minute());
  writeDate();

  if (firstTime || (lastUpdate.unixtime() + UPADTE_INTERVAL < now.unixtime()) ) {
    firstTime = false;
    readPrInfo();
    lastUpdate = now;
  }

  writePrInfo();
  matrix.show();
  delay(500);
}
