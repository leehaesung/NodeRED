# Code files

***

* [Writing Node HTML: http://nodered.org/docs/creating-nodes/node-html](http://nodered.org/docs/creating-nodes/node-html)

***

* Basic JavaScript Web

![simpleWeb01.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/03_Simple_Web/simpleWeb01.png)
![simpleWeb01_output.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/03_Simple_Web/simpleWeb01_output.png)
```````````````````````````````````````````````````
[{"id":"7ef2a3b4.965c6c","type":"http in","z":"fd8b5730.ad96f8","name":"/test","url":"/test","method":"get","swaggerDoc":"","x":170,"y":80,"wires":[["88fdb43a.9b6e18"]]},{"id":"88fdb43a.9b6e18","type":"function","z":"fd8b5730.ad96f8","name":"function","func":"/* Test 02  */\nmsg.payload = \"Hello Stephen\";\nreturn msg;\n// So, this is going to work on the web.\n\n\n//Additional Important Memo\n//return { \"payload\" : \"Hello Coursera\" };\n// You will get (\"No response object\").\n// So, this is not working on the web.","outputs":1,"noerr":0,"x":358,"y":80,"wires":[["3e75cdd2.cab1e2"]]},{"id":"3e75cdd2.cab1e2","type":"http response","z":"fd8b5730.ad96f8","name":"test","x":555.9999694824219,"y":80,"wires":[]}]
```````````````````````````````````````````````````

function:
```````````````````````````````````````````````````
/* Test 02  */
msg.payload = "Hello Stephen";
return msg;
// So, this is going to work on the web.


//Additional Important Memo
//return { "payload" : "Hello Coursera" };
// You will get ("No response object").
// So, this is not working on the web.
```````````````````````````````````````````````````

***

* Basic (JavaScript + HTML) Web

![simpleWeb02.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/03_Simple_Web/simpleWeb02.png)
![simpleWeb02_output.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/03_Simple_Web/simpleWeb02_output.png)

```````````````````````````````````````````````````
[{"id":"a67aefd3.3a8e4","type":"http in","z":"fd8b5730.ad96f8","name":"/simpleweb","url":"/simpleweb","method":"get","swaggerDoc":"","x":190,"y":277,"wires":[["6820518.084c3b"]]},{"id":"3a19d72d.7e1688","type":"http response","z":"fd8b5730.ad96f8","name":"/simpleweb","x":810,"y":277,"wires":[]},{"id":"38541dbf.2e3422","type":"template","z":"fd8b5730.ad96f8","name":"simple html page","field":"payload","fieldType":"msg","format":"handlebars","syntax":"mustache","template":"<h1>What's today? {{payload.day}}</h1>\n","x":590,"y":277,"wires":[["3a19d72d.7e1688"]]},{"id":"6820518.084c3b","type":"function","z":"fd8b5730.ad96f8","name":"day","func":"msg.payload = {'day':'Today is my birthday'};\nreturn msg;","outputs":1,"noerr":0,"x":390,"y":277,"wires":[["38541dbf.2e3422"]]}]
```````````````````````````````````````````````````

function:
```````````````````````````````````````````````````
<h1> What's today? {{payload.day}} </h1>
<h2> What's today? {{payload.day}} </h2>
<h3> What's today? {{payload.day}} </h3>
<h4> What's today? {{payload.day}} </h4>
<h5> What's today? {{payload.day}} </h5>
```````````````````````````````````````````````````

***

* Basic (JavaScript + HTML) Web 02

![simpleWeb03.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/03_Simple_Web/simpleWeb03.png)
![simpleWeb03_output.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/03_Simple_Web/simpleWeb03_output.png)

```````````````````````````````````````````````````
[{"id":"f2ab6a8f.36e608","type":"http in","z":"fd8b5730.ad96f8","name":"/simpleweb02","url":"/simpleweb02","method":"get","swaggerDoc":"","x":190,"y":340,"wires":[["364b0dd7.d857e2"]]},{"id":"9c23bea5.ade7c","type":"function","z":"fd8b5730.ad96f8","name":"setHTTPheader","func":"// If sending JSON data the content type is:\n//msg.headers={\"Content-Type\":\"application/json\"}\n\n// For HTML use the content type line below:\nmsg.headers={\"Content-Type\":\"text/html\"};\nreturn msg;","outputs":1,"noerr":0,"x":820,"y":340,"wires":[["9adcfb72.1cd328"]]},{"id":"c22da339.5f8c","type":"template","z":"fd8b5730.ad96f8","name":"simple html page","field":"payload","fieldType":"msg","format":"handlebars","syntax":"mustache","template":"<h1> What's data? <h1> \n</h2> This is temperature data: {{payload.temperature}} degree celsius </h2>\n","x":610,"y":340,"wires":[["9c23bea5.ade7c"]]},{"id":"364b0dd7.d857e2","type":"function","z":"fd8b5730.ad96f8","name":"Temp DATA Buffer","func":"msg.payload = {'temperature':30.87};\nreturn msg;","outputs":1,"noerr":0,"x":390,"y":340,"wires":[["c22da339.5f8c"]]},{"id":"9adcfb72.1cd328","type":"http response","z":"fd8b5730.ad96f8","name":"","x":1008,"y":340,"wires":[]}]
```````````````````````````````````````````````````

(1) Temp DATA Buffer:
```````````````````````````````````````````````````
msg.payload = {'temperature':30.87};
return msg;
```````````````````````````````````````````````````

(2) simple html page:
```````````````````````````````````````````````````
<h1> What's data? <h1> 
</h2> This is temperature data: {{payload.temperature}} degree celsius </h2>
```````````````````````````````````````````````````

(3) setHTTPheader:
```````````````````````````````````````````````````
// If sending JSON data the content type is:
//msg.headers={"Content-Type":"application/json"}

// For HTML use the content type line below:
msg.headers={"Content-Type":"text/html"};
return msg;
```````````````````````````````````````````````````

