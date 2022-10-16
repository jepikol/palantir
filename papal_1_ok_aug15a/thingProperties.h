// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)

void onColor1Change();
void onColor2Change();

int color1;
int color2;

void initProperties(){

  ArduinoCloud.addProperty(color1, READWRITE, ON_CHANGE, onColor1Change);
  ArduinoCloud.addProperty(color2, READWRITE, ON_CHANGE, onColor2Change);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
