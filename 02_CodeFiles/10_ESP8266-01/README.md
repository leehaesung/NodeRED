# ESP8266-01 with DHT11 For IoT Data Analytics

***
### (1) Data Analytics

![SigFoxArduinoForIoTDataAnalytics.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/01_Images/SigFoxArduinoForIoTDataAnalytics.png)

* [Python Code For Jupyter-notebook](http://nbviewer.jupyter.org/github/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/02_Codes/SQLite3_with_Monitoring_IoT_ESP8266-01_Temp_Hum_Sensor_MQTT_VER_0.1.ipynb)


### (2) Hardware 


* ESP8266 With DHT11 Sensor

![ESP8266_DHT11.jpg](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/01_Images/ESP8266_DHT11.jpg)

* Firmware Uploader

![ESP8266_DHT11_Basic.jpg](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/01_Images/ESP8266_DHT11_Basic.jpg)

* Bread Board

![ESP8266_DHT11_BreadBoard.jpg](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/01_Images/ESP8266_DHT11_BreadBoard.jpg)


***

### (3) Software For Arduino


#### How To Setup

(1) Configurate the ESP8266 board, (using Arduino IDE):
  - Add the following 3rd party board manager under "File -> Preferences -> Additional Boards Manager URLs":
       http://arduino.esp8266.com/stable/package_esp8266com_index.json
  - Open the "Tools -> Board -> Board Manager" and click install for the ESP8266"
  - Select your ESP8266 in "Tools -> Board -> Generic ESP8266 Module"


(2) Put the below the libries 
  - Down load the libries. (Use wget or git clone.)
  
        https://github.com/adafruit/Adafruit_Sensor   
        
        https://github.com/knolleary/pubsubclient/tree/master/src  
  
  - Put the libries at /home/ubuntu/Arduino/libraries
  
  - Please restart the Arduino IDE.



* Source Codes
[DHT11sensorWithMQTT_Ver0.1.ino](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/02_Codes/DHT11sensorWithMQTT_Ver0.1.ino)

````````````````
/*
 Date: Wed 14 Dec 2016
 Edited by Stephen LEE
 Device: ESP8266-01 with DHT11 Sensor(Humidity & Temperature)
 Used knolleary's mqtt esp8266 code.
 https://github.com/knolleary/pubsubclient/blob/master/examples/mqtt_esp8266/mqtt_esp8266.ino
 
 Basic ESP8266 MQTT example
 This sketch demonstrates the capabilities of the pubsub library in combination
 with the ESP8266 board/library.
 It connects to an MQTT server then:
  - publishes "hello world" to the topic "outTopic" every two seconds
  - subscribes to the topic "inTopic", printing out any messages
    it receives. NB - it assumes the received payloads are strings not binary
  - If the first character of the topic "inTopic" is an 1, switch ON the ESP Led,
    else switch it off
 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.
 To install the ESP8266 board, (using Arduino 1.6.4+):
  - Add the following 3rd party board manager under "File -> Preferences -> Additional Boards Manager URLs":
       http://arduino.esp8266.com/stable/package_esp8266com_index.json
  - Open the "Tools -> Board -> Board Manager" and click install for the ESP8266"
  - Select your ESP8266 in "Tools -> Board"
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.

// Update these with values suitable for your network.

const char* ssid = "OBWS";   
const char* password = "buyfirst";
const char* mqtt_server = "iot.eclipse.org";  // You can chose any mqtt sever web.

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50],msgh[50],msgt[50];
int value = 0;


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  
  Serial.begin(115200);
  Serial.println("DHT11 with MQTT test!");

  
  pinMode(2, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
}


void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is acive low on the ESP-01)
  } else {
    digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
  }  
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  //DHT11 Sesnor To measure both humidity & temperature
  //sprintf(msgh, "%d.%02d", (int)h, (int)(h*100)%100); //OK
  dtostrf(h, 2, 2, msgh); //OK  Arduino didn't support the conversion from float to char.
  client.publish("hum", msgh);
  
  //sprintf(msgt, "%d.%02d", (int)t, (int)(t*100)%100);  //OK
  dtostrf(t, 2, 2, msgt); //OK   Arduino didn't support the conversion from float to char.
  client.publish("tem", msgt);
  

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");



  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
    snprintf (msg, 75, "hello world #%ld", value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("outTopic", msg);
  }
  
}
````````````````

***

## Software For Node-RED

* Source Codes
[ESP8266withDHT11_Node-RED.txt](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/02_Codes/ESP8266withDHT11_Node-RED.txt)

`````````````````
[{"id":"c1489ac4.5e0518","type":"mqtt in","z":"53b6f2e6.47e18c","name":"MQTT: hum","topic":"hum","qos":"2","broker":"8d263ea0.db314","x":150,"y":100,"wires":[["fdd382e4.1042f","dca777d8.bc24a8","8254ffdf.97a44"]]},{"id":"fdd382e4.1042f","type":"debug","z":"53b6f2e6.47e18c","name":"","active":true,"console":"false","complete":"false","x":323.99998474121094,"y":170,"wires":[]},{"id":"a3b32737.2b48c8","type":"mqtt in","z":"53b6f2e6.47e18c","name":"MQTT: tem","topic":"tem","qos":"2","broker":"8d263ea0.db314","x":155.99994659423828,"y":300.33327865600586,"wires":[["8ce61e13.1b5f9","fb641e26.87e1e","13cb511b.761fef"]]},{"id":"8ce61e13.1b5f9","type":"debug","z":"53b6f2e6.47e18c","name":"","active":true,"console":"false","complete":"false","x":347,"y":356,"wires":[]},{"id":"fb641e26.87e1e","type":"ui_gauge","z":"53b6f2e6.47e18c","name":"Temperature [°C]","group":"43ca2768.88beb8","order":1,"width":"","height":"","gtype":"gage","title":"","label":"","format":"{{value}}","min":0,"max":"100","colors":["#00b500","#e6e600","#ca3838"],"seg1":"","seg2":"","x":362.5077590942383,"y":280.48952865600586,"wires":[]},{"id":"dca777d8.bc24a8","type":"ui_gauge","z":"53b6f2e6.47e18c","name":"Humidity [%]","group":"dc0f7e51.66c23","order":1,"width":"","height":"","gtype":"gage","title":"Humidity","label":"[ % ]","format":"{{value}}","min":0,"max":"100","colors":["#00b500","#e6e600","#ca3838"],"seg1":"","seg2":"","x":339.3975143432617,"y":97.1110954284668,"wires":[]},{"id":"13cb511b.761fef","type":"ui_chart","z":"53b6f2e6.47e18c","name":"Temperature [°C]","group":"43ca2768.88beb8","order":2,"width":"","height":"","label":"","chartType":"line","xformat":"HH:mm:ss","interpolate":"linear","nodata":"No Data","dot":false,"ymin":"","ymax":"","removeOlder":1,"removeOlderPoints":"","removeOlderUnit":"86400","cutout":"","useOneColor":false,"colors":["#1f77b4","#aec7e8","#ff7f0e","#2ca02c","#98df8a","#d62728","#ff9896","#9467bd","#c5b0d5"],"useOldStyle":true,"x":364.64748764038086,"y":317.61108684539795,"wires":[[],[]]},{"id":"8254ffdf.97a44","type":"ui_chart","z":"53b6f2e6.47e18c","name":"Humidity [%]","group":"dc0f7e51.66c23","order":2,"width":"","height":"","label":"","chartType":"line","xformat":"HH:mm:ss","interpolate":"linear","nodata":"No Data","dot":false,"ymin":"","ymax":"","removeOlder":1,"removeOlderPoints":"","removeOlderUnit":"86400","cutout":"","useOneColor":false,"colors":["#1f77b4","#aec7e8","#ff7f0e","#2ca02c","#98df8a","#d62728","#ff9896","#9467bd","#c5b0d5"],"useOldStyle":true,"x":345.6475143432617,"y":133.36111068725586,"wires":[[],[]]},{"id":"8d28edb1.ee012","type":"comment","z":"53b6f2e6.47e18c","name":"Temperature & Humidity - Gauge & Chart","info":"","x":219.98703002929688,"y":46.777679443359375,"wires":[]},{"id":"7bbd2a68.d89bd4","type":"serial in","z":"53b6f2e6.47e18c","name":"","serial":"406452e7.61daec","x":170,"y":500,"wires":[["b7027367.426be","90ff124d.5024"]]},{"id":"b7027367.426be","type":"debug","z":"53b6f2e6.47e18c","name":"","active":true,"console":"false","complete":"true","x":327.86183166503906,"y":550.1677398681641,"wires":[]},{"id":"90ff124d.5024","type":"ui_text","z":"53b6f2e6.47e18c","group":"84db8a02.817db8","order":0,"width":"6","height":"2","name":"","label":"","format":"{{msg.payload}}","layout":"row-spread","x":330,"y":500,"wires":[]},{"id":"8d263ea0.db314","type":"mqtt-broker","z":"","broker":"iot.eclipse.org","port":"1883","clientid":"","usetls":false,"compatmode":true,"keepalive":"60","cleansession":true,"willTopic":"","willQos":"0","willPayload":"","birthTopic":"","birthQos":"0","birthPayload":""},{"id":"43ca2768.88beb8","type":"ui_group","z":"","name":"Temperature","tab":"baa1b526.a8c0f8","order":1,"disp":true,"width":"6"},{"id":"dc0f7e51.66c23","type":"ui_group","z":"","name":"Humidity","tab":"baa1b526.a8c0f8","order":2,"disp":true,"width":"6"},{"id":"406452e7.61daec","type":"serial-port","z":"","serialport":"/dev/ttyUSB0","serialbaud":"115200","databits":"8","parity":"none","stopbits":"1","newline":"\\n","bin":"false","out":"char","addchar":true},{"id":"84db8a02.817db8","type":"ui_group","z":"","name":"Serial with ESP8266","tab":"baa1b526.a8c0f8","order":4,"disp":true,"width":"6"},{"id":"baa1b526.a8c0f8","type":"ui_tab","z":"","name":"ESP8266 with DHT11","icon":"dashboard"}]

`````````````````

* Node-RED Image
![ESP8266_DHT11_NodeRED.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/01_Images/ESP8266_DHT11_NodeRED.png)

* DashBoard Image
![ESP8266withDHT11_DashBoard_Node-RED.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/01_Images/ESP8266withDHT11_DashBoard_Node-RED.png)

***
### (4) SQLite3 with ESP8266-01 & DHT11 Sensor

* [Source Code: Node-RED](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/02_Codes/SQLiteWithESP8266-01DHT_Node-RED.txt)


* Node-RED Image

![ESP8266withDHT11_Node-RED.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/01_Images/ESP8266withDHT11_Node-RED.png)


* DashBoard Image 

![SQLite3WithESP8266-01DHT11.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/01_Images/SQLite3WithESP8266-01DHT11.png)



***

## References

* Where To Buy:  http://www.buildcircuit.com.au/blog/three-important-lessons-for-beginners-using-esp8266-wifi-module/

* [EXPERIMENT WITH DHT11 AND ARDUINO](http://www.buildcircuit.com/experiment-with-dht11-and-arduino/)

* [PID-Control-for-BBQ-Bot](https://www.instructables.com/id/PID-Control-for-BBQ-Bot/)



***
