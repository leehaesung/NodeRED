# Code files

****

* Basic connection

![basic_NodeRED.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/01_Basic/ImageFiles/basic_NodeRED.png)
````````````````````````````
[{"id":"fd2bc921.ad6598","type":"inject","z":"578c9d4d.52cba4","name":"","topic":"","payload":"","payloadType":"date","repeat":"","crontab":"","once":false,"x":240,"y":140,"wires":[["cf9141a6.43926"]]},{"id":"cf9141a6.43926","type":"debug","z":"578c9d4d.52cba4","name":"","active":true,"console":"false","complete":"false","x":490,"y":140,"wires":[]}]
````````````````````````````

* Rando function - (1)
```````````````````````````````````````````````````
[{"id":"3ca7df69.1d235","type":"inject","z":"aca45f70.7fe43","name":"","topic":"","payload":"","payloadType":"date","repeat":"2","crontab":"","once":false,"x":264.8333435058594,"y":130.33333587646484,"wires":[["c09d6093.70fcc"]]},{"id":"c09d6093.70fcc","type":"debug","z":"aca45f70.7fe43","name":"Random Test","active":false,"console":"false","complete":"true","x":723.8333129882812,"y":128.3333282470703,"wires":[]},{"id":"10b577ff.018368","type":"random","z":"aca45f70.7fe43","name":"","low":"1","high":"6","inte":"true","x":484.8333435058594,"y":128.33333587646484,"wires":[[]]}]
```````````````````````````````````````````````````

< END >
