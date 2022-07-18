/////////////////////////////////////////////////////////////////////////// BTC Kurs 
void btc_btc_mempool(){

WiFiClient client;
HTTPClient http;

// Send request
http.begin("https://mempool.space/api/blocks/tip/height");
int httpCode = http.GET();

  if (httpCode > 0) { //Check for the returning code
  
    String payload = http.getString();

          const size_t capacity = 2 * JSON_OBJECT_SIZE(1) + 10;
          DynamicJsonDocument doc(capacity);

          String json = payload;
          String mempool_height = json;
         
          // Mem Wert ausgeben
          Serial.print("MEMpool Block ");
          Serial.println(mempool_height);

  }
  
  else {
    Serial.println("Error on HTTP request");
  }
	
http.end(); //Free the resources


}