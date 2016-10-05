# Code files

***

* Speech about a tweet("#readtweet") from Tweeter to IBM Blumex 

![Text2Speech01.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/07_Text2Speech/Text2Speech01.png)

```````````````````````````````````````````````````
[{"id":"c3bb18eb.7c6a98","type":"inject","z":"f660048.417b2f8","name":"","topic":"","payload":"hello world","payloadType":"string","repeat":"","crontab":"","once":false,"x":120,"y":100,"wires":[["ba9833ed.d6f1d","2e1967ae.4ee088"]]},{"id":"ba9833ed.d6f1d","type":"debug","z":"f660048.417b2f8","name":"","active":true,"console":"false","complete":"false","x":368,"y":50,"wires":[]},{"id":"2e1967ae.4ee088","type":"watson-text-to-speech","z":"f660048.417b2f8","name":"","lang":"english","voice":"en-US_LisaVoice","format":"audio/wav","x":308,"y":187,"wires":[["abaf118f.6fd2e","cc320fc4.e3aab"]]},{"id":"abaf118f.6fd2e","type":"debug","z":"f660048.417b2f8","name":"","active":true,"console":"false","complete":"speech","x":546,"y":122,"wires":[]},{"id":"1a7f2158.21fd5f","type":"play audio","z":"f660048.417b2f8","name":"","x":674.5,"y":198,"wires":[]},{"id":"cc320fc4.e3aab","type":"change","z":"f660048.417b2f8","name":"set speech as payload","rules":[{"t":"set","p":"payload","to":"speech","tot":"msg"},{"t":"delete","p":"speech"}],"action":"","property":"","from":"","to":"","reg":false,"x":476.5,"y":266,"wires":[["1a7f2158.21fd5f"]]},{"id":"e0ed4665.9c64a8","type":"twitter in","z":"f660048.417b2f8","twitter":"","tags":"#readtweet","user":"false","name":"","topic":"tweets","x":74.5,"y":438,"wires":[["2c5adc55.2f6e94"]]},{"id":"2c5adc55.2f6e94","type":"change","z":"f660048.417b2f8","name":"clean tweet","rules":[{"t":"change","p":"payload","from":"#readtweet","to":"","re":false}],"action":"","property":"","from":"","to":"","reg":false,"x":190.5,"y":314,"wires":[["2e1967ae.4ee088","94829dab.e88b3"]]},{"id":"94829dab.e88b3","type":"debug","z":"f660048.417b2f8","name":"","active":true,"console":"false","complete":"false","x":434.5,"y":372,"wires":[]}]
```````````````````````````````````````````````````
