// Setup für Uhr
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;

/****** IN SETUP
  // ntp Server init
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  */

void Zeit_Uhrzeit()
{
  tm local;
  getLocalTime(&local);
  
  Serial.println(&local, "%H:%M");

          tft.setCursor(20,93);
          tft.setTextColor(TFT_WHITE,TFT_BLACK);
          tft.setTextSize(1);
          tft.print(&local, "%H:%M");   

}



/////////////////////////////////////////////////////////////////////////// ZEIT
void Zeit_Datum()
{
  tm local;
  getLocalTime(&local);
  
  Serial.println(&local, "%d.%m.%y");

          tft.setCursor(85,93);
          tft.setTextColor(TFT_WHITE,TFT_BLACK);
          tft.setTextSize(1);
          tft.print(&local, "%d.%m.%y");    

}

