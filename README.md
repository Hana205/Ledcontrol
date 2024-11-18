# Ledcontrol
control Neopixel ring with esp32 and blynk app
* install Arduino version 1.8.18 here : https://www.arduino.cc/en/software/OldSoftwareReleases
* install esp 32: add this line on the preferences and Additional Boards management URLs : https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
*Open Boards Manager from Tools > Board menu and install esp32 platform (and don't forget to select your ESP32 board from Tools > Board menu after installation).
* install Neopixel library: in Arduino software: go to the tool: manage library: and select Adafruit _Neopixel
    - You can also download the zip file and add it to the library file on your  documents- Arduino file the Zip is here https://github.com/adafruit/Adafruit_NeoPixel
* test your installation: open examples: neopixel : standard-test: change the pin attached to your Neopixel Data wire and the number of LEDs 
You should have your Leds illuminated with animation.

Blynk Setup
To get started, log in to your Blynk account. If you don't have an account yet, create one quickly and free of charge here : https://blynk.cloud/dashboard/login.


-Blynk Template
Once you log in, select "+ New Template".
To create the template successfully, you only need to assign:
1) Name : LED Control
2) Select the device to be used : esp32
3) Connection type : WIFI
4) A description of the template configuration
5) As the info page indicates, we must use the "Template ID" and "Device Name", as well as an Authentication Token (which will be automatically generated in the next steps), at the top of our main firmware code. Due to this, keep this essential info into consideration when making changes to the corresponding code, in the following steps.

   * Blynk Datastreams: https://blynk.cloud/dashboard/

To configure the data flow between our device and Blynk Cloud, we must configure some "Datastreams" as we did when we created the template above. Like creating a Template, refer to the "Datastream" option, and select "+ New Datastream."
Subsequently, when adding the Datastream, you must select the "Virtual Pin" option. Then, include all the corresponding information.
For this project, we need to configure 2 Virtual Pin DataStreams, “RGB”, and “On/OFF”. Both will control the desired color we want to reflect on the lamp and the button added is to turn Onn/Off the LEDs

Make sure to carefully follow the instructions below for the creation of the datastreams to ensure a proper communication operation.
*On/off Datastream Creation
For the Datastream creation, virtual PIN :V0 dataType : integer.

*RGB Datastream Creation
For the Datastream creation, virtual PIN :V1 dataType : Float.
To finish, make sure to press the “Save” green button, located at the upper right side corner of the site to save all the changes made on the Datastream settings.
Blynk Device

To create our first device at Blynk Cloud, we must select the first option in the menu located on the left side of the platform. You can easily recognize it as the option of the magnifying glass icon. At this point, we must click on "+ New Device", to proceed with the creation.

In the following window, choose the first option "From Template" (The one we just created!)

To finish, select the Template previously created “LED Control”, and assign the name desired for your new device or, if you prefer, leave it as default.

Once the device is successfully created, you will notice a pop-up within the platform highlighting all the credentials needed to compile and connect our device with Blynk Cloud successfully. Remember that we need to use these credentials when compiling our firmware in the WisBlock WiFi Core.


Blynk Widgets

The last step to be able to control our device remotely, is to create a dashboard. However, for one of the widgets we need for the project; "zeRGBa", we will need to use the mobile version of Blynk. Depending on the operating system of your phone, download the corresponding application:

Download for iOS : https://apps.apple.com/us/app/blynk-iot/id1559317868
Download for Android
-Now go to the Widget box (on the right) to add widgets.
-Add a bottom and the ZRGBa widget.
-Go to Button widget settings.
-Enter the name, select Datastream, Then exit.
Once the widgets are added, make sure each of them is properly interconnected within the previously created datastreams on the platform. For this, click on the widgets and make sure to choose the proper datastream for each one of the widgets.
From Arduino IDE

Now let’s add the color magic. To start, flash the following code using the same steps provided above and just make some small modifications, based on your Blynk Template Configuration.

As you could notice over the steps of the Blynk Template and Device configuration, a "Template ID", "Device Name", and “Authentication Token” were generated. At this point, you must add those keys generated at the top of our main firmware code. In my case, the keys generated were the following ones:

#define BLYNK_TEMPLATE_ID "your"
#define BLYNK_DEVICE_NAME "your"
#define BLYNK_AUTH_TOKEN "your"
In addition to the keys to be added, you must assign the following parameters where they are indicated in the code:

Your WiFi network SSID
Your WiFi network Password
Now, just copy and paste the following code : https://github.com/Hana205/Ledcontrol/blob/main/BlynkLed-change-your-IDS.ino
to the Arduino IDE, change the respective parameters, and you are ready to go!

If your esp32 is not recognized please install the driver


