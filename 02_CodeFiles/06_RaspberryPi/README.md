# Code files

***

* Gathering CPU temperature on Raspberry Pi

![CPU_Temperature.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/06_RaspberryPi/CPU_Temperature.png)
![CPU_Temperature02.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/06_RaspberryPi/CPU_Temperature02.png)
```````````````````````````````````````````````````
[{"id":"92740c52.1301b","type":"inject","z":"2ffd8ed7.2b41ea","name":"","topic":"","payload":"","payloadType":"num","repeat":"5","crontab":"","once":true,"x":106,"y":59,"wires":[["4a145a6.a05b624"]]},{"id":"4a145a6.a05b624","type":"exec","z":"2ffd8ed7.2b41ea","command":"vcgencmd","addpay":false,"append":"measure_temp","useSpawn":"","timer":"","name":"getCPUtemp","x":189,"y":149.5,"wires":[["5812990c.8f9288"],[],[]]},{"id":"4d29f125.690d58","type":"debug","z":"2ffd8ed7.2b41ea","name":"","active":true,"console":"false","complete":"payload","x":503,"y":199.5,"wires":[]},{"id":"5812990c.8f9288","type":"function","z":"2ffd8ed7.2b41ea","name":"msg.payload","func":"msg.payload = {\"d\":{\"temp\": parseFloat(msg.payload.replace(\"temp=\",\"\").replace(\"'C\\n\",\"\"))}};\nreturn msg;","outputs":1,"noerr":0,"x":320,"y":246,"wires":[["bb5b0ad8.077c","4d29f125.690d58"]]},{"id":"bb5b0ad8.077c","type":"wiotp out","z":"2ffd8ed7.2b41ea","authType":"d","qs":"true","qsDeviceId":"f1b88ab.1112978","deviceKey":"","deviceType":"","deviceId":"","event":"event","format":"json","name":"Device","x":508,"y":296.5,"wires":[]}]
```````````````````````````````````````````````````

msg.payload
```````````````````````````````````````````````````
msg.payload = {"d":{"temp": parseFloat(msg.payload.replace("temp=","").replace("'C\n",""))}};
return msg;
```````````````````````````````````````````````````

