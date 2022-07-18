// Setup für Uhr
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;

/****** IN SETUP
  // ntp Server init
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  */

/////////////////////////////////////////////////////////////////////////// ZEIT
void Zeit_Datum()
{
  tm local;
  getLocalTime(&local);
  
  Serial.println(&local, "%d.%m.%y");
}

void Zeit_Uhrzeit()
{
  tm local;
  getLocalTime(&local);
  
  Serial.println(&local, "%H:%M");
}