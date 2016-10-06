# Code files

***

* [Writing Google JavaScript Map: https://developers.google.com/maps/documentation/javascript/](https://developers.google.com/maps/documentation/javascript/)
* [GPS-coordinates](http://www.gps-coordinates.net/)


***

* Simple GPS Mab Web

![simpleGPSWeb01.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/04_GPS_Web/simpleGPSWeb01.png)
![simpleGPSWeb01_output.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/04_GPS_Web/simpleGPSWeb01_output.png)
```````````````````````````````````````````````````
[{"id":"26d30ddb.23e7c2","type":"http in","z":"fd8b5730.ad96f8","name":"/gpslocation","url":"/gpslocation","method":"get","swaggerDoc":"","x":190,"y":1380,"wires":[["3e2ddac4.213de6"]]},{"id":"4b1d372c.66e9a8","type":"http response","z":"fd8b5730.ad96f8","name":"/gpslocation","x":650,"y":1380,"wires":[]},{"id":"3e2ddac4.213de6","type":"template","z":"fd8b5730.ad96f8","name":"Simple GPS Web","field":"payload","fieldType":"msg","format":"handlebars","syntax":"mustache","template":"<!DOCTYPE html>\n<html>\n  <head>\n    <title>My Smart IoT Device Map</title>\n    <meta name=\"viewport\" content=\"initial-scale=1.0\">\n    <meta charset=\"utf-8\">\n    <style>\n      html, body {\n        height: 100%;\n        margin: 0;\n        padding: 0;\n      }\n      #map {\n        height: 100%;\n      }\n    </style>\n  </head>\n  <body>\n    <div id=\"map\"></div>\n    <script>\n      var map;\n      function initMap() {\n        map = new google.maps.Map(document.getElementById('map'), {\n          center: {lat: -33.8722567, lng: 151.20816519999994},\n          zoom: 14\n        });\n      }\n    </script>\n    <script src=\"https://maps.googleapis.com/maps/api/js?key=AIzaSyDhA8Lb-e_JvMYmEh2RLA3rFBeEllQYsFI&callback=initMap\"\n    async defer></script>\n  </body>\n</html>","x":430,"y":1380,"wires":[["4b1d372c.66e9a8"]]}]
```````````````````````````````````````````````````

function:
```````````````````````````````````````````````````
<!DOCTYPE html>
<html>
  <head>
    <title>My Smart IoT Device Map</title>
    <meta name="viewport" content="initial-scale=1.0">
    <meta charset="utf-8">
    <style>
      html, body {
        height: 100%;
        margin: 0;
        padding: 0;
      }
      #map {
        height: 100%;
      }
    </style>
  </head>
  <body>
    <div id="map"></div>
    <script>
      var map;
      function initMap() {
        map = new google.maps.Map(document.getElementById('map'), {
          center: {lat: -33.8722567, lng: 151.20816519999994},
          zoom: 14
        });
      }
    </script>
    <script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDhA8Lb-e_JvMYmEh2RLA3rFBeEllQYsFI&callback=initMap"
    async defer></script>
  </body>
</html>
```````````````````````````````````````````````````

***

* Where IS My IoT Device?(Tracking GPS Location)

![simpleGPSWeb02.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/04_GPS_Web/simpleGPSWeb02.png)
![simpleGPSWeb02_output.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/04_GPS_Web/simpleGPSWeb02_output.png)
```````````````````````````````````````````````````
[{"id":"6442f245.d4c76c","type":"template","z":"fd8b5730.ad96f8","name":"My IoT Device Location","field":"payload","fieldType":"msg","format":"handlebars","syntax":"mustache","template":"<!DOCTYPE html>\n<html>\n  <head>\n    <style>\n       #map {\n        height: 400px;\n        width: 100%;\n       }\n    </style>\n  </head>\n  <body>\n    <h2>Where is my IoT device?</h2>\n    <h2>My IoT Device Location: Latitude: {{payload.latitude}}  , Longitude: {{payload.longitude}} </h2>\n    <div id=\"map\"></div>\n    <script>\n      function initMap() {\n        var IoTDevice = {lat: {{payload.latitude}},lng: {{payload.longitude}} };\n        var map = new google.maps.Map(document.getElementById('map'), {\n          zoom: 18,\n          center: IoTDevice\n        });\n        var marker = new google.maps.Marker({\n          position: IoTDevice,\n          map: map\n        });\n      }\n    </script>\n    <script async defer\n        src=\"https://maps.googleapis.com/maps/api/js?key=AIzaSyDhA8Lb-e_JvMYmEh2RLA3rFBeEllQYsFI&callback=initMap\">\n    </script>\n  </body>\n</html>","x":550,"y":2020,"wires":[["3401c10.c232f4"]]},{"id":"9b241876.582ff8","type":"http in","z":"fd8b5730.ad96f8","name":"/whereIsMyDevice","url":"/whereIsMyDevice","method":"get","swaggerDoc":"","x":250,"y":1900,"wires":[["52d9874.e3ba578"]]},{"id":"3401c10.c232f4","type":"http response","z":"fd8b5730.ad96f8","name":"/whereIsMyDevice","x":750,"y":2080,"wires":[]},{"id":"52d9874.e3ba578","type":"function","z":"fd8b5730.ad96f8","name":"RemoteData","func":"msg.payload = {'latitude':-33.87559993931576,'longitude':151.21599197387695};\nreturn msg;","outputs":1,"noerr":0,"x":390,"y":1960,"wires":[["6442f245.d4c76c"]]}]
```````````````````````````````````````````````````

(1) RemoteData
```````````````````````````````````````````````````
msg.payload = {'latitude':-33.87559993931576,'longitude':151.21599197387695};
return msg;
```````````````````````````````````````````````````

(2) My IoT Device Location
```````````````````````````````````````````````````
<!DOCTYPE html>
<html>
  <head>
    <style>
       #map {
        height: 400px;
        width: 100%;
       }
    </style>
  </head>
  <body>
    <h2>Where is my IoT device?</h2>
    <h2>My IoT Device Location: Latitude: {{payload.latitude}}  , Longitude: {{payload.longitude}} </h2>
    <div id="map"></div>
    <script>
      function initMap() {
        var IoTDevice = {lat: {{payload.latitude}},lng: {{payload.longitude}} };
        var map = new google.maps.Map(document.getElementById('map'), {
          zoom: 18,
          center: IoTDevice
        });
        var marker = new google.maps.Marker({
          position: IoTDevice,
          map: map
        });
      }
    </script>
    <script async defer
        src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDhA8Lb-e_JvMYmEh2RLA3rFBeEllQYsFI&callback=initMap">
    </script>
  </body>
</html>
```````````````````````````````````````````````````

***

* Gathring a single latitude from Python GPS Simulator

![GathringGPSDATA.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/04_GPS_Web/GathringGPSDATA.png)
![GathringGPSDATA_output.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/04_GPS_Web/GathringGPSDATA_output.png)
```````````````````````````````````````````````````
[{"id":"edfa8b96.7979c8","type":"http in","z":"38a6560e.175e8a","name":"/gatherFromDevice","url":"/gatherFromDevice","method":"get","swaggerDoc":"","x":170,"y":300,"wires":[["7dc0c9e9.0134a8"]]},{"id":"f2fa2518.5fc8e8","type":"function","z":"38a6560e.175e8a","name":"setHTTPheader","func":"// If sending JSON data the content type is:\n//msg.headers={\"Content-Type\":\"application/json\"};\n\n// For HTML use the content type line below:\nmsg.headers={\"Content-Type\":\"text/html\"}\nreturn msg;","outputs":1,"noerr":0,"x":840,"y":300,"wires":[["c50b72b.7659e9"]]},{"id":"d2b2ca21.e5e598","type":"debug","z":"38a6560e.175e8a","name":"","active":true,"console":"false","complete":"false","x":830,"y":340,"wires":[]},{"id":"1e20af41.4bc971","type":"debug","z":"38a6560e.175e8a","name":"","active":true,"console":"false","complete":"false","x":610,"y":100,"wires":[]},{"id":"878c8694.5c8388","type":"template","z":"38a6560e.175e8a","name":"simple html page","field":"payload","fieldType":"msg","format":"handlebars","syntax":"mustache","template":"<h1> What's the data from a GPS Sensor? </h1>\n<h1> This is a single latitude : {{payload}} </h1>\n","x":630,"y":300,"wires":[["f2fa2518.5fc8e8","d2b2ca21.e5e598"]]},{"id":"7dc0c9e9.0134a8","type":"function","z":"38a6560e.175e8a","name":"Retrieving Gps Data","func":"//context.data = context.data || new Object();\n//context.data.payload = msg.payload.d;\n//return msg;\n\n//var d = context.global.d;\n\nmsg.payload = JSON.stringify(context.global.d);\n\nreturn msg;","outputs":1,"noerr":0,"x":402,"y":300,"wires":[["878c8694.5c8388","d9c1830.10d748"]]},{"id":"d9c1830.10d748","type":"debug","z":"38a6560e.175e8a","name":"","active":true,"console":"false","complete":"false","x":611,"y":340,"wires":[]},{"id":"c50b72b.7659e9","type":"http response","z":"38a6560e.175e8a","name":"","x":1030,"y":300,"wires":[]},{"id":"b236c6a4.74a8b8","type":"function","z":"38a6560e.175e8a","name":"Gathering GPS Data","func":"var d = msg.payload.d;\ncontext.global.d = d;\nreturn msg;\n","outputs":1,"noerr":0,"x":400,"y":100,"wires":[["1e20af41.4bc971"]]},{"id":"ed70df3c.e7d3f","type":"ibmiot in","z":"38a6560e.175e8a","authentication":"boundService","apiKey":"","inputType":"evt","deviceId":"iotgateway001","applicationId":"","deviceType":"iotgateway001","eventType":"+","commandType":"","format":"json","name":"iotgateway001","service":"registered","allDevices":"","allApplications":"","allDeviceTypes":"","allEvents":true,"allCommands":"","allFormats":"","qos":0,"x":170,"y":100,"wires":[["b236c6a4.74a8b8","4f586701.7fb768"]]},{"id":"4f586701.7fb768","type":"debug","z":"38a6560e.175e8a","name":"","active":true,"console":"false","complete":"false","x":370,"y":160,"wires":[]},{"id":"592c566a.388e28","type":"comment","z":"38a6560e.175e8a","name":"From GPS Sensor to IBM Cloud","info":"","x":215,"y":54,"wires":[]},{"id":"9a62cec4.9e34","type":"comment","z":"38a6560e.175e8a","name":"Web","info":"","x":130,"y":260,"wires":[]}]
```````````````````````````````````````````````````

(1) Python GPS Simulator
```````````````````````````````````````````````````
import time
import numpy as np
import ibmiotf.gateway
from sense_hat import SenseHat
import math

try:
    gatewayOptions = {"org": "of6naa", "type": "iotgateway001", "id": "iotgateway001", "auth-method": "token", "auth-token": "12345678"}
    gatewayCli = ibmiotf.gateway.Client(gatewayOptions)
    gatewayCli.connect()

    while True:
        myData = {'d':-33.87} # a single latitude
        gatewayCli.publishDeviceEvent("iotgateway001", "iotgateway001", "iotgateway001", "json", myData, qos=1 )
        time.sleep(5)


except ibmiotf.ConnectionException  as e:
    print(e)
```````````````````````````````````````````````````

(2) Gathering GPS Data
```````````````````````````````````````````````````
var d = msg.payload.d;
context.global.d = d;
return msg;
```````````````````````````````````````````````````

(3) Retrieving Gps Data
```````````````````````````````````````````````````
msg.payload = JSON.stringify(context.global.d);

return msg;
```````````````````````````````````````````````````

(4) simple html page
```````````````````````````````````````````````````
<h1> What's the data from a GPS Sensor? </h1>
<h1> This is a single latitude : {{payload}} </h1>
```````````````````````````````````````````````````

(5) setHTTPheader
```````````````````````````````````````````````````
// If sending JSON data the content type is:
//msg.headers={"Content-Type":"application/json"};

// For HTML use the content type line below:
msg.headers={"Content-Type":"text/html"}
return msg;
```````````````````````````````````````````````````







