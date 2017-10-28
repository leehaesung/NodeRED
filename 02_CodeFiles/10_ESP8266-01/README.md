# ESP8266-01

***

* Schematics

* (1) ESP8266 With DHT11 Sensor

![ESP8266_DHT11.jpg](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/01_Images/ESP8266_DHT11.jpg)

* (2) Firmware Uploader

![ESP8266_DHT11_Basic.jpg](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/01_Images/ESP8266_DHT11_Basic.jpg)

* (3) Bread Board

![ESP8266_DHT11_BreadBoard.jpg](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/10_ESP8266-01/01_Images/ESP8266_DHT11_BreadBoard.jpg)


***

* Rando function - (1)

 ![randomFunction01.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/01_Basic/ImageFiles/randomFunction01.png)

```````````````````````````````````````````````````
[{"id":"3ca7df69.1d235","type":"inject","z":"aca45f70.7fe43","name":"","topic":"","payload":"","payloadType":"date","repeat":"2","crontab":"","once":false,"x":264.8333435058594,"y":130.33333587646484,"wires":[["c09d6093.70fcc"]]},{"id":"c09d6093.70fcc","type":"debug","z":"aca45f70.7fe43","name":"Random Test","active":false,"console":"false","complete":"true","x":723.8333129882812,"y":128.3333282470703,"wires":[]},{"id":"10b577ff.018368","type":"random","z":"aca45f70.7fe43","name":"","low":"1","high":"6","inte":"true","x":484.8333435058594,"y":128.33333587646484,"wires":[[]]}]
```````````````````````````````````````````````````

***

