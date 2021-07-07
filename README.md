# central-heating-esp8266
My central heating computer does not have a remote to turn it off, so I connected ESP8266 with a transistor to it.

## Config
This project requires a file named `secrets.h` in directory `include`.
It stores 3 values:
* WIFI's SSID (const char WIFI_SSID[])
* WIFI's password (const char WIFI_PASSWORD[])
* Device IP const (IPAddress IP(xxx, xxx, xxx, xxx))

Example:
```cpp
#include <ESP8266WiFi.h>
const char WIFI_SSID[] = "Your WIFI SSID";
const char WIFI_PASSWORD[] = "Your WIFI password";
const IPAddress IP(192, 168, 1, 2);
```
