# Code files

***

* [Writing functions: http://nodered.org/docs/writing-functions](http://nodered.org/docs/writing-functions)

***

* Basic Functions

![functions.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/02_Function/functions.png)
```````````````````````````````````````````````````
[{"id":"4fcc146b.22285c","type":"debug","z":"ba94f081.1dae4","name":"Output","active":true,"console":"false","complete":"payload","x":973.6666259765625,"y":328,"wires":[]},{"id":"cd44319.cdc57d","type":"debug","z":"ba94f081.1dae4","name":"2nd Output","active":true,"console":"false","complete":"payload","x":993.6666259765625,"y":408,"wires":[]},{"id":"b625f00f.97836","type":"debug","z":"ba94f081.1dae4","name":"3rd Output","active":true,"console":"false","complete":"payload","x":993.6666259765625,"y":488,"wires":[]},{"id":"e79bda80.4b3be8","type":"function","z":"ba94f081.1dae4","name":"Array","func":"var msg1 = { payload:\"first message\" };\nvar msg2 = { payload:\"second message\" };\nvar msg3 = { payload:\"third message\" };\nvar msg4 = { payload:\"fourth message\" };\nreturn [msg1, msg2, msg3, msg4];","outputs":1,"noerr":0,"x":473.6666259765625,"y":228,"wires":[["4fcc146b.22285c"]]},{"id":"ac8adf00.006a2","type":"function","z":"ba94f081.1dae4","name":"Array in Array","func":"var msg1 = { payload:\"first message\" };\nvar msg2 = { payload:\"second message\" };\nvar msg3 = { payload:\"third message\" };\nvar msg4 = { payload:\"fourth message\" };\nreturn [[msg1, msg2, msg3, msg4]]","outputs":1,"noerr":0,"x":443.6666259765625,"y":268,"wires":[["4fcc146b.22285c"]]},{"id":"b9b157fe.eea018","type":"function","z":"ba94f081.1dae4","name":"Multiple returns","func":"var msg1 = { payload:\"first message\" };\nvar msg2 = { payload:\"second message\" };\nvar msg3 = { payload:\"third message\" };\nvar msg4 = { payload:\"fourth message\" };\nreturn [msg1, msg2, msg3, msg4];\n","outputs":"3","noerr":0,"x":443.6666259765625,"y":348,"wires":[["4fcc146b.22285c"],["cd44319.cdc57d"],["b625f00f.97836"]]},{"id":"a8559bb0.04d1c8","type":"function","z":"ba94f081.1dae4","name":"Multiple returns array in array","func":"var msg1 = { payload:\"first message\" };\nvar msg2 = { payload:\"second message\" };\nvar msg3 = { payload:\"third message\" };\nvar msg4 = { payload:\"fourth message\" };\nreturn [msg1, [msg2, msg3], msg4];\n","outputs":"3","noerr":0,"x":403.6666259765625,"y":408,"wires":[["4fcc146b.22285c"],["cd44319.cdc57d"],["b625f00f.97836"]]},{"id":"31f96873.1dfe98","type":"function","z":"ba94f081.1dae4","name":"Create JSON Object","func":"msg.payload = {\"a\" : { \"b\" : \"test\"}};\nreturn msg;","outputs":1,"noerr":0,"x":423.6666259765625,"y":488,"wires":[["4fcc146b.22285c","774b237a.b12a8c"]]},{"id":"6b789133.b2b1c","type":"function","z":"ba94f081.1dae4","name":"Create JSON String","func":"msg.payload = '{\"a\" : { \"b\" : \"test\"}}';\nreturn msg;","outputs":1,"noerr":0,"x":433.6666259765625,"y":528,"wires":[["4fcc146b.22285c","774b237a.b12a8c"]]},{"id":"790aec7f.7a8ad4","type":"function","z":"ba94f081.1dae4","name":"Create JSON String in msg.payload","func":"msg.payload = '{\"a\" : { \"b\" : \"test\"}}';\nreturn msg;","outputs":1,"noerr":0,"x":383.6666259765625,"y":568,"wires":[["4fcc146b.22285c","fae55e97.e1e78"]]},{"id":"be2ef565.32e018","type":"function","z":"ba94f081.1dae4","name":"return string in object","func":"return {\"payload\" : \"Hello Coursera\"};","outputs":1,"noerr":0,"x":423.6666259765625,"y":128,"wires":[["4fcc146b.22285c"]]},{"id":"fae55e97.e1e78","type":"json","z":"ba94f081.1dae4","name":"","x":613.6666259765625,"y":568,"wires":[["cd44319.cdc57d","774b237a.b12a8c"]]},{"id":"774b237a.b12a8c","type":"function","z":"ba94f081.1dae4","name":"retrieve data from Object","func":"msg.payload = msg.payload.a.b;\nreturn msg;","outputs":1,"noerr":0,"x":773.6666259765625,"y":478,"wires":[["b625f00f.97836"]]},{"id":"a4fd0d8d.66ab6","type":"inject","z":"ba94f081.1dae4","name":"","topic":"","payload":"","payloadType":"none","repeat":"","crontab":"","once":false,"x":133.6666259765625,"y":228,"wires":[["e79bda80.4b3be8"]]},{"id":"50f62fb8.19888","type":"inject","z":"ba94f081.1dae4","name":"","topic":"","payload":"","payloadType":"none","repeat":"","crontab":"","once":false,"x":133.6666259765625,"y":268,"wires":[["ac8adf00.006a2"]]},{"id":"a4a4c409.604188","type":"inject","z":"ba94f081.1dae4","name":"","topic":"","payload":"","payloadType":"str","repeat":"","crontab":"","once":false,"x":133.6666259765625,"y":348,"wires":[["b9b157fe.eea018"]]},{"id":"96f8fd84.14e4b","type":"inject","z":"ba94f081.1dae4","name":"","topic":"","payload":"","payloadType":"str","repeat":"","crontab":"","once":false,"x":133.6666259765625,"y":408,"wires":[["a8559bb0.04d1c8"]]},{"id":"b979ba73.09e488","type":"inject","z":"ba94f081.1dae4","name":"","topic":"","payload":"","payloadType":"none","repeat":"","crontab":"","once":false,"x":133.6666259765625,"y":488,"wires":[["31f96873.1dfe98"]]},{"id":"775ac295.ec15fc","type":"inject","z":"ba94f081.1dae4","name":"","topic":"","payload":"","payloadType":"none","repeat":"","crontab":"","once":false,"x":133.6666259765625,"y":528,"wires":[["6b789133.b2b1c"]]},{"id":"74f0b255.d7602c","type":"inject","z":"ba94f081.1dae4","name":"","topic":"","payload":"","payloadType":"str","repeat":"","crontab":"","once":false,"x":133.6666259765625,"y":568,"wires":[["790aec7f.7a8ad4"]]},{"id":"2d3b875e.cd5f08","type":"inject","z":"ba94f081.1dae4","name":"","topic":"","payload":"","payloadType":"none","repeat":"","crontab":"","once":false,"x":133.6666259765625,"y":128,"wires":[["be2ef565.32e018"]]},{"id":"1fed1ed5.a0cea1","type":"function","z":"ba94f081.1dae4","name":"Status and logging functions","func":"node.status({text:\"started\"});\n\nsetTimeout(function() {\n    node.status({fill:\"red\",shape:\"ring\",text:\"stage 1\"});\n    \n    setTimeout(function() {\n        node.status({fill:\"green\",shape:\"dot\",text:\"stage 2\"});\n        node.error(\"This is an error\", {'payload' : 'Caught error'});\n        \n        setTimeout(function() {\n            node.error(\"Second error\");\n            node.status({});\n            node.send({'payload' : 'Completed'});\n        }, 1000);\n        \n    }, 1000);\n    \n}, 1000);\n\nnode.warn(\"Exiting node\");\nreturn;","outputs":1,"noerr":0,"x":403.6666259765625,"y":628,"wires":[["4fcc146b.22285c"]]},{"id":"5a1506af.c34fb8","type":"inject","z":"ba94f081.1dae4","name":"","topic":"","payload":"","payloadType":"str","repeat":"","crontab":"","once":false,"x":133.6666259765625,"y":628,"wires":[["1fed1ed5.a0cea1"]]},{"id":"ebe37a21.2b4e18","type":"catch","z":"ba94f081.1dae4","name":"Catch node","scope":["1fed1ed5.a0cea1"],"x":453.6666259765625,"y":668,"wires":[["10944414.b7e54c"]]},{"id":"e8968498.0ecd08","type":"function","z":"ba94f081.1dae4","name":"return string","func":"return 'This is a string';","outputs":1,"noerr":0,"x":453.6666259765625,"y":88,"wires":[["4fcc146b.22285c"]]},{"id":"fdffa1d6.898b3","type":"inject","z":"ba94f081.1dae4","name":"","topic":"","payload":"","payloadType":"str","repeat":"","crontab":"","once":false,"x":133.6666259765625,"y":88,"wires":[["e8968498.0ecd08"]]},{"id":"10944414.b7e54c","type":"debug","z":"ba94f081.1dae4","name":"entire msg","active":true,"console":"false","complete":"true","x":993.6666259765625,"y":568,"wires":[]}]
```````````````````````````````````````````````````

***

* Random Generator Function

![randomGenerator.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/02_Function/randomGenerator.png)
```````````````````````````````````````````````````
[{"id":"e3ba4e21.e1766","type":"http in","z":"fd8b5730.ad96f8","name":"http in","url":"/randomGenerator","method":"get","swaggerDoc":"","x":170,"y":1560,"wires":[["c8cc30ef.e476c"]]},{"id":"50485145.e9091","type":"template","z":"fd8b5730.ad96f8","name":"Random Number Web","field":"","fieldType":"msg","format":"handlebars","syntax":"mustache","template":"<h1> Random Number : {{ payload }} </h1>","x":640,"y":1566,"wires":[["c254ff4f.94f4d"]]},{"id":"c254ff4f.94f4d","type":"http response","z":"fd8b5730.ad96f8","name":"http response","x":859,"y":1566,"wires":[]},{"id":"fe30aee0.6bc7d","type":"inject","z":"fd8b5730.ad96f8","name":"Inject1","topic":"Topic1","payload":"1,100","payloadType":"str","repeat":"","crontab":"","once":true,"x":190,"y":1520,"wires":[["c8cc30ef.e476c"]]},{"id":"c8cc30ef.e476c","type":"function","z":"fd8b5730.ad96f8","name":"Random Function","func":"if (msg.topic == \"Topic1\") {\n var words = msg.payload.split(\" \");\n var range = words[0];\n var minmax = range.split(\",\");\n var min = minmax[0];\n var max = minmax[1];\n var d = Math.round(min + (Math.random() * (max - min)));\n context.myValue = d+\"\";\n msg.payload = context.myValue;\n return [msg,null];\n} else {\n msg.payload = context.myValue||\"\";\n return [null,msg];\n}","outputs":"2","noerr":0,"x":390,"y":1560,"wires":[["b1881012.8fac4"],["50485145.e9091"]]},{"id":"b1881012.8fac4","type":"debug","z":"fd8b5730.ad96f8","name":"Debug1","active":true,"console":"false","complete":"true","x":603,"y":1521,"wires":[]}]
```````````````````````````````````````````````````

(1) Random Function
```````````````````````````````````````````````````
if (msg.topic == "Topic1") {
 var words = msg.payload.split(" ");
 var range = words[0];
 var minmax = range.split(",");
 var min = minmax[0];
 var max = minmax[1];
 var d = Math.round(min + (Math.random() * (max - min)));
 context.myValue = d+"";
 msg.payload = context.myValue;
 return [msg,null];
} else {
 msg.payload = context.myValue||"";
 return [null,msg];
}
```````````````````````````````````````````````````

(2) Random Number Web
```````````````````````````````````````````````````
<h1> Random Number : {{ payload }} </h1>
```````````````````````````````````````````````````

* IBM Default Sample

![DEFAULTnode_IBM_DEFAULT.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/02_Function/DEFAULTnode_IBM_DEFAULT.png)

```````````````````````````````````````````````````
[{"id":"3e77d543.c1882a","type":"ibmiot in","z":"463d14f9.38077c","authentication":"quickstart","apiKey":"","inputType":"evt","deviceId":"LivingRoomThermo1","applicationId":"","deviceType":"+","eventType":"+","commandType":"","format":"json","name":"IBM IoT App In","service":"quickstart","allDevices":false,"allApplications":false,"allDeviceTypes":true,"allEvents":true,"allCommands":false,"allFormats":false,"x":100,"y":400,"wires":[["ae0082ac.51ff8","c0c482df.3f3b8"]]},{"id":"ae0082ac.51ff8","type":"function","z":"463d14f9.38077c","name":"temp","func":"return {payload:msg.payload.d.temp};","outputs":1,"x":290,"y":400,"wires":[["ff6ad0d9.00953"]]},{"id":"ff6ad0d9.00953","type":"switch","z":"463d14f9.38077c","name":"temp thresh","property":"payload","propertyType":"msg","rules":[{"t":"lte","v":"40","vt":"str"},{"t":"gt","v":"40","vt":"str"}],"checkall":"true","outputs":2,"x":450,"y":400,"wires":[["80621eff.7f9de"],["8e1706a.f71e8f8"]]},{"id":"5dad02b7.a252fc","type":"debug","z":"463d14f9.38077c","name":"cpu status","active":true,"complete":"false","x":790,"y":400,"wires":[]},{"id":"c0c482df.3f3b8","type":"debug","z":"463d14f9.38077c","name":"device data","active":true,"console":"false","complete":"true","x":310,"y":480,"wires":[]},{"id":"80621eff.7f9de","type":"template","z":"463d14f9.38077c","name":"safe","fieldType":"msg","syntax":"mustache","template":"Temperature ({{payload}}) within safe limits","x":610,"y":380,"wires":[["5dad02b7.a252fc"]]},{"id":"8e1706a.f71e8f8","type":"template","z":"463d14f9.38077c","name":"danger","fieldType":"msg","syntax":"mustache","template":"Temperature ({{payload}}) critical","x":620,"y":420,"wires":[["5dad02b7.a252fc"]]},{"id":"cbe1a0b7.cd877","type":"ibmiot out","z":"463d14f9.38077c","authentication":"boundService","apiKey":"","outputType":"evt","deviceId":"LivingRoomThermo1","deviceType":"thermostat","eventCommandType":"update","format":"json","data":"temp:10","name":"Send to IBM IoT Platform","service":"registered","x":570,"y":120,"wires":[]},{"id":"5917a925.6a3c08","type":"inject","z":"463d14f9.38077c","name":"Send Data","topic":"","payload":"true","payloadType":"bool","repeat":"","crontab":"","once":false,"x":100,"y":120,"wires":[["6b4a591c.014b18"]]},{"id":"6b4a591c.014b18","type":"function","z":"463d14f9.38077c","name":"Device payload","func":"// Thermostat's location:\nvar longitude1 = -98.49;\nvar latitude1 = 29.42;\n\n// Array of pseudo random temperatures\nvar temp1 = [15,17,18.5,50,21.5,23,24,22.2,80,95];\n\n// Array of pseudo random relative humidities\nvar humidity1 = [50,55,61,68,65,60,53,49,45,47];\n\n// Counter to select from array.\nvar counter1 = context.get('counter1')||0;\ncounter1 = counter1+1;\nif(counter1 > 9) counter1 = 0;\ncontext.set('counter1',counter1);\n\n// Create MQTT message in JSON\nmsg = {\n  payload: JSON.stringify(\n    {\n      d:{\n        \"temp\" : temp1[counter1],\n        \"humidity\" : humidity1[counter1],\n        \"location\" :\n        {\n          \"longitude\" : longitude1,\n          \"latitude\" : latitude1\n        },\n      }\n    }\n  )\n};\nreturn msg;\n","outputs":1,"noerr":0,"x":320,"y":120,"wires":[["cbe1a0b7.cd877","805c97ee.3ed9e8"]]},{"id":"805c97ee.3ed9e8","type":"debug","z":"463d14f9.38077c","name":"Debug output payload","active":true,"console":"false","complete":"payload","x":560,"y":180,"wires":[]},{"id":"86df0b6c.af90c8","type":"comment","z":"463d14f9.38077c","name":"Device Simulator","info":"Sends simulated device sensor data to IBM Watson IoT Plaform.\n\nCan be configured to send on click or on an automatic interval.\n\n\n#Prerequisite\nOutput node device type and device ID need to match a device that it registered in a running IBM Watson IoT Platform service.\n\n# Watson IoT Platform docs\n[Connecting devices](https://www.bluemix.net/docs/services/IoT/iotplatform_task.html)","x":100,"y":40,"wires":[]},{"id":"141b7c7.ad42a84","type":"comment","z":"463d14f9.38077c","name":"1. Configure target","info":"","x":550,"y":80,"wires":[]},{"id":"c2dd8ed5.7dd7f","type":"comment","z":"463d14f9.38077c","name":"2. Click to send data","info":"To automatically send data:\n1. Change *Repeat* to interval.\n2. Click Deploy button.\n","x":110,"y":160,"wires":[]},{"id":"7926c7b2.86d938","type":"comment","z":"463d14f9.38077c","name":"Temperature Monitor","info":"","x":110,"y":300,"wires":[]},{"id":"188a5e87.e775a1","type":"comment","z":"463d14f9.38077c","name":"Configure source","info":"","x":100,"y":360,"wires":[]}]
```````````````````````````````````````````````````

(1) Device payload
```````````````````````````````````````````````````
// Thermostat's location:
var longitude1 = -98.49;
var latitude1 = 29.42;

// Array of pseudo random temperatures
var temp1 = [15,17,18.5,50,21.5,23,24,22.2,80,95];

// Array of pseudo random relative humidities
var humidity1 = [50,55,61,68,65,60,53,49,45,47];

// Counter to select from array.
var counter1 = context.get('counter1')||0;
counter1 = counter1+1;
if(counter1 > 9) counter1 = 0;
context.set('counter1',counter1);

// Create MQTT message in JSON
msg = {
  payload: JSON.stringify(
    {
      d:{
        "temp" : temp1[counter1],
        "humidity" : humidity1[counter1],
        "location" :
        {
          "longitude" : longitude1,
          "latitude" : latitude1
        },
      }
    }
  )
};
return msg;
```````````````````````````````````````````````````

(2) temp
```````````````````````````````````````````````````
return {payload:msg.payload.d.temp};
```````````````````````````````````````````````````

(3) safe
```````````````````````````````````````````````````
Temperature ({{payload}}) within safe limits
```````````````````````````````````````````````````

(4) danger
```````````````````````````````````````````````````
Temperature ({{payload}}) critical
```````````````````````````````````````````````````

(4) Results
![DEFAULTnode_IBM_DEFAULT_output1.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/02_Function/DEFAULTnode_IBM_DEFAULT_output1.png)

![DEFAULTnode_IBM_DEFAULT_output2.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/02_Function/DEFAULTnode_IBM_DEFAULT_output2.png)

![DEFAULTnode_IBM_DEFAULT_output3.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/02_Function/DEFAULTnode_IBM_DEFAULT_output3.png)





