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

