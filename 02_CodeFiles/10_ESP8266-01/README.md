# ESP8266-01

***

## Hardware 


* ESP8266 With DHT11 Sensor

![ESP8266_DHT11.jpg](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/01_Images/ESP8266_DHT11.jpg)

* Firmware Uploader

![ESP8266_DHT11_Basic.jpg](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/01_Images/ESP8266_DHT11_Basic.jpg)

* Bread Board

![ESP8266_DHT11_BreadBoard.jpg](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/01_Images/ESP8266_DHT11_BreadBoard.jpg)


***

## Software For Arduino

* Source Codes
[DHT11sensorWithMQTT_Ver0.1.ino](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/02_Codes/DHT11sensorWithMQTT_Ver0.1.ino)


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
