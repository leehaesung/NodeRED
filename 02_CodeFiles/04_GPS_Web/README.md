# Code files

***

* [Writing Google JavaScript Map: https://developers.google.com/maps/documentation/javascript/](https://developers.google.com/maps/documentation/javascript/)

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

