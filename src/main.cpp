#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "index.h"
#include "notfound.h"
#include "unathorized.h"

#define FURNACE_ON_OFF_BTN D0

ESP8266WebServer server(80);
IPAddress ip(192, 168, 8, 104);
IPAddress gateway(192, 168, 8, 1);
IPAddress subnet(255, 255, 255, 0);

bool isLEDOn = false;
unsigned long ledTimer = millis();

/// Blinks builtin LED.
/// \param period - Defines how long in ms LED stays on and long.
/// \example When period is set to 500, LED will shine for 500ms and then turn off for 500ms.
void blink(unsigned long period) {
    if (millis() >= ledTimer + period) {
        isLEDOn = !isLEDOn;
        ledTimer = millis();
    }

    digitalWrite(LED_BUILTIN, isLEDOn);
}

/// Redirects to specified path.
/// \param url - Location to where user will be redirected.
void redirect(const char* url) {
    server.sendHeader("Location", url, true);
    server.send(302, "text/plain", "");
}

void homepagePage() {
    server.send(200, "text/html", INDEX_page);
}

/// Turns central heating furnace off. Redirects to homepage.
void turn_furnace_off() {
    digitalWrite(FURNACE_ON_OFF_BTN, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(300);
    digitalWrite(FURNACE_ON_OFF_BTN, LOW);
    digitalWrite(LED_BUILTIN, LOW);


    redirect("/");
}

void notFoundPage() {
    server.send(404, "text/html", NOTFOUND_page);
}

void setup() {
    pinMode(FURNACE_ON_OFF_BTN, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);

    digitalWrite(FURNACE_ON_OFF_BTN, LOW);
    digitalWrite(LED_BUILTIN, LOW);

    Serial.begin(115200);

    WiFi.disconnect();
    WiFi.setAutoConnect(true);
    WiFi.config(ip, gateway, subnet);
    WiFi.mode(WIFI_STA);
    WiFi.begin("jan router trzeci laczy sieci", "qwerty12345");


    Serial.print("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED) {
        blink(250);
        delay(250);
        Serial.print(".");
    }
    Serial.println();

    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", HTTP_GET, homepagePage);
    server.on("/turn-furnace-off", HTTP_POST, turn_furnace_off);
    server.onNotFound(notFoundPage);

    server.begin();
}

void loop() {
    server.handleClient();

    blink(1000);
}
