/*************************************************************
  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "yourID"
#define BLYNK_TEMPLATE_NAME         "yourDevice"
#define BLYNK_AUTH_TOKEN            "yourToken"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Adafruit_NeoPixel.h>

#define PIN 4 
#define NUMPIXELS 12 // Number of LEDs in the strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Your WiFi credentials
char ssid[] = "yourSSID";
char pass[] = "your PSWD";

// Declare global variables
bool ledOn = false;    // LEDs on/off state
uint32_t currentColor = pixels.Color(0, 0, 0);  // Initial color (off)

BlynkTimer timer;
// Function prototype (declaration) of updateLEDs
void updateLEDs() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, ledOn ? currentColor : pixels.Color(0, 0, 0)); // Turn on/off LEDs
  }
  pixels.show();
}

// This function is called every time the Virtual Pin 0 state changes (button press)
BLYNK_WRITE(V0)
{
  ledOn = param.asInt();  // If 1, turn on; if 0, turn off
  updateLEDs();
}



// This function is called every time the ZeRGBa widget (V1) updates
BLYNK_WRITE(V1)
{
  float r = param[0].asFloat();  // Red component (0-255)
  float g = param[1].asFloat();  // Green component (0-255)
  float b = param[2].asFloat();  // Blue component (0-255)
   Serial.print("Received color: ");
  Serial.print("R: "); Serial.print(r);
  Serial.print(" G: "); Serial.print(g);
  Serial.print(" B: "); Serial.println(b);

  currentColor = pixels.Color(r, g, b);  // Set the current color
  updateLEDs();
}
void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(115200);

  // Initialize the Blynk connection
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Initialize the NeoPixel strip
  pixels.begin();

}

void loop() {
  Blynk.run();
}
