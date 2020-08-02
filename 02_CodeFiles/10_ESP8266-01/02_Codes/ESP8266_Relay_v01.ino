#include <ESP8266WiFi.h>
#include <PubSubClient.h>
// There are 2 Ports like P0(0), P2(2) in ESP8266-01.
#define P0 0
#define P2 2

// Update these with values suitable for your network.
const char* ssid = "iPhone7_leehaesung";   
const char* password = "l24482448";
//const char* ssid = "elite4";   
//const char* password = "elite1234";
const char* mqtt_server = "13.211.139.200";  // You can chose any mqtt sever web.
// another MQTT Servers:
// "broker.mqtt-dashboard.com"
// "broker.hivemq.com"

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup() {
  Serial.begin(115200);
  pinMode(P0, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
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
     Serial.println("LOW");
     digitalWrite(P0, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is acive low on the ESP-01
  } 
  if ((char)payload[0] == '0') {
     Serial.println("HIGH");
     digitalWrite(P0, HIGH);  // Turn the LED off by making the voltage HIGH
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("event", "Internet Condition");
      // ... and resubscribe
      client.subscribe("event");
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
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 1000) {
    lastMsg = now;
    ++value;
    snprintf (msg, 75, "Internet Working #%ld", value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("event", msg);
  }
}
