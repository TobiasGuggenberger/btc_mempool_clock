/////////////////////////////////////////////////////////////////////////// BTC Kurs 
void btc_btc_mempool(){

WiFiClient client;
HTTPClient http;

// Send request
http.begin("https://min-api.cryptocompare.com/data/pricemulti?fsyms=BTC&tsyms=USD");
int httpCode = http.GET();

  if (httpCode > 0) { //Check for the returning code
  
    String payload = http.getString();

          const size_t capacity = 2 * JSON_OBJECT_SIZE(1) + 10;
          DynamicJsonDocument doc(capacity);

          String json = payload;

          //const char* json = "{\"XRP\":{\"ZAR\":4.20}}";

          deserializeJson(doc, json);

          String BTC_USD = doc["BTC"]["USD"]; 
          
          Serial.println("BTC Wert ausgeben");
          Serial.println(BTC_USD);


  }
  
  else {
    Serial.println("Error on HTTP request");
  }

	
http.end(); //Free the resources


}