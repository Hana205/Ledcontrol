# Ledcontrol
control Neopixel ring with esp32 and blynk app
* install Arduino version 1.8.18 here : https://www.arduino.cc/en/software/OldSoftwareReleases
* install esp 32 : add this line on the preferences and Additional Boards managements URLs : https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
*Open Boards Manager from Tools > Board menu and install esp32 platform (and don't forget to select your ESP32 board from Tools > Board menu after installation).
* install Neopixel library: in Arduino software:go to the tool: manage library: and select Adafruit _Neopixel
    - You can also download the zip file and add it to the library file on your  documents- Arduin file the Zip is here https://github.com/adafruit/Adafruit_NeoPixel
* test your installation : open examples : neopixel : standart-test : change the pin attached to your Neopixel Data wire and the number of Leds 
You should have your Leds illuminated with animation.

* Install Blynk IoT App to Configure Mobile Dashboard
Install the Blynk IoT app from Google Play Store or App Store. Then log in.
Go to Developer Mode.
-Tap on the template that you have already made.
-Now go to the Widget box (on the right) to add widgets.
-Add the ZRGBra.
-Go to Button widget settings.
-Enter the name, select Datastream, Mode will be Switch. Then exit.
After setting all the Buttons tap on exit.


