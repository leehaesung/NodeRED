# Code files

***

* Basic connection

![basic_NodeRED.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/01_Basic/ImageFiles/Basic%20connection.png)
````````````````````````````
[{"id":"fd2bc921.ad6598","type":"inject","z":"578c9d4d.52cba4","name":"","topic":"","payload":"","payloadType":"date","repeat":"","crontab":"","once":false,"x":240,"y":140,"wires":[["cf9141a6.43926"]]},{"id":"cf9141a6.43926","type":"debug","z":"578c9d4d.52cba4","name":"","active":true,"console":"false","complete":"false","x":490,"y":140,"wires":[]}]
````````````````````````````

***

* Rando function - (1)

 ![randomFunction01.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/01_Basic/ImageFiles/randomFunction01.png)

```````````````````````````````````````````````````
[{"id":"3ca7df69.1d235","type":"inject","z":"aca45f70.7fe43","name":"","topic":"","payload":"","payloadType":"date","repeat":"2","crontab":"","once":false,"x":264.8333435058594,"y":130.33333587646484,"wires":[["c09d6093.70fcc"]]},{"id":"c09d6093.70fcc","type":"debug","z":"aca45f70.7fe43","name":"Random Test","active":false,"console":"false","complete":"true","x":723.8333129882812,"y":128.3333282470703,"wires":[]},{"id":"10b577ff.018368","type":"random","z":"aca45f70.7fe43","name":"","low":"1","high":"6","inte":"true","x":484.8333435058594,"y":128.33333587646484,"wires":[[]]}]
```````````````````````````````````````````````````

***

* Rando function - (2)

 ![randomFunction02.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/01_Basic/ImageFiles/randomFunction02.png)
```````````````````````````````````````````````````
[{"id":"6cc496b9.5ee938","type":"random","z":"aca45f70.7fe43","name":"random number","low":"0","high":"10","inte":"true","x":460,"y":260,"wires":[["6b211122.583ca"]]},{"id":"72992d28.8b9cd4","type":"debug","z":"aca45f70.7fe43","name":"debug","active":false,"console":"false","complete":"payload","x":810,"y":260,"wires":[]},{"id":"4d10738c.91e21c","type":"inject","z":"aca45f70.7fe43","name":"","topic":"","payload":"","payloadType":"date","repeat":"5","crontab":"","once":false,"x":279,"y":260,"wires":[["6cc496b9.5ee938"]]},{"id":"6b211122.583ca","type":"function","z":"aca45f70.7fe43","name":"generate sentence","func":"number = msg.payload;\nif(number < 5){\n    msg.payload = \"Number \" + number + \" is a low number\";\n} else {\n    msg.payload = \"Number \" + number + \" is a high number\";\n}\nreturn msg;","outputs":1,"noerr":0,"x":650,"y":260,"wires":[["72992d28.8b9cd4"]]}]
```````````````````````````````````````````````````

* generate sentence:
```````````````````````````````````````````````````
number = msg.payload;
if(number < 5){
    msg.payload = "Number " + number + " is a low number";
} else {
    msg.payload = "Number " + number + " is a high number";
}
return msg;
```````````````````````````````````````````````````

< END >
