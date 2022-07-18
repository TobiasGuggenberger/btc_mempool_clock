// Setup fuer https
String BTC_old_kurs ="0"; 

/////////////////////////////////////////////////////////////////////////// BTC Kurs 
void btc_kurs(){

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

          // TFT Ausgabe generieren
/*
          if (BTC_old_kurs < BTC_USD) {

          tft.drawBitmap(0, 0, bitcoinLogo, 128, 64, GREEN);
          tft.setCursor(24,78);
          tft.setTextColor(GREEN,BLACK);
          tft.setTextSize(2);
          tft.print("$"+BTC_USD.substring(0, 5));

          }
          else
          {
          tft.drawBitmap(0, 0, bitcoinLogo, 128, 64, RED);
          tft.setCursor(24,78);
          tft.setTextColor(RED,BLACK);
          tft.setTextSize(2);
          tft.print("$"+BTC_USD.substring(0, 5));
          }

          BTC_old_kurs = BTC_USD;

          }
*/

  }
  
  else {
    Serial.println("Error on HTTP request");
  }

	
http.end(); //Free the resources


}