# Code files

***

* [Writing Node HTML: http://nodered.org/docs/creating-nodes/node-html](http://nodered.org/docs/creating-nodes/node-html)

***

* Basic Web

![simpleWeb01.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/03_Simple_Web/simpleWeb01.png)
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
