void readPrInfo() {
    HTTPClient http;
    WiFiClient client;
    String url = "http://viroide-gitclock.netlify.app/.netlify/functions/getPrList";

    if (WiFi.status() == WL_CONNECTED) {
      if (http.begin(client, url)) {
      Serial.print("[HTTP] GET...\n");
      int httpCode = http.GET();  // Realizar petición

      if (httpCode > 0) {
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {

          String payload = http.getString();   // Obtener respuesta
          Serial.println(payload);   // Mostrar respuesta por serial
          prList = JSON.parse(payload);
        }
      }
      else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
       http.end();
    }
    else {
      Serial.printf("[HTTP] Unable to connect\n");
    }
  } else {
    Serial.printf("WIFI down\n");
  }
} 
