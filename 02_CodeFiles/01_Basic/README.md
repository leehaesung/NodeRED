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

 generate sentence:
```````````````````````````````````````````````````
number = msg.payload;
if(number < 5){
    msg.payload = "Number " + number + " is a low number";
} else {
    msg.payload = "Number " + number + " is a high number";
}
return msg;
```````````````````````````````````````````````````

***

* Rando function - (3)

 ![randomFunction03.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/01_Basic/ImageFiles/randomFunction03.png)
```````````````````````````````````````````````````
[{"id":"5a3c1199.b44fe","type":"inject","z":"aefb1539.565828","name":"inject","topic":"Number ","payload":"","payloadType":"date","repeat":"5","crontab":"","once":false,"x":189.66665649414062,"y":129.66665649414062,"wires":[["3e5ff6a2.dbcc5a"]]},{"id":"4a0e753c.e6104c","type":"debug","z":"aefb1539.565828","name":"output","active":false,"console":"false","complete":"payload","x":769.6666564941406,"y":129.66665649414062,"wires":[]},{"id":"3e5ff6a2.dbcc5a","type":"random","z":"aefb1539.565828","name":"random","low":"1","high":"10","inte":"true","x":399.6666564941406,"y":129.66665649414062,"wires":[["3a60847a.d58fac"]]},{"id":"3a60847a.d58fac","type":"function","z":"aefb1539.565828","name":"function","func":"if(msg.payload < 5)\n{\n  a = msg.payload.number = \"Number \";\n  b = msg.payload;\n  c = msg.paylaod = \" is a low number\";\n\n  msg.payload = a + b + c;\n  \n  return msg;\n}\n\nelse if(msg.payload > 5)\n{\n  a = msg.payload.number = \"Number \";\n  b = msg.payload;\n  c = msg.paylaod = \" is a high number\";\n\n  msg.payload = a + b + c;\n  \n  return msg;\n}\n\nreturn null;","outputs":1,"noerr":0,"x":599.6666564941406,"y":129.66665649414062,"wires":[["4a0e753c.e6104c"]]}]
```````````````````````````````````````````````````

function:
```````````````````````````````````````````````````
if(msg.payload < 5)
{
  a = msg.payload.number = "Number ";
  b = msg.payload;
  c = msg.paylaod = " is a low number";

  msg.payload = a + b + c;
  
  return msg;
}

else if(msg.payload > 5)
{
  a = msg.payload.number = "Number ";
  b = msg.payload;
  c = msg.paylaod = " is a high number";

  msg.payload = a + b + c;
  
  return msg;
}

return null;
```````````````````````````````````````````````````

***

* Restaurant Menus Web - (3)

 ![menuWeb.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/01_Basic/ImageFiles/menuWeb.png)
 ![menuWeb_output.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/01_Basic/ImageFiles/menuWeb_output.png)
 ![menuSpecials_output.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/01_Basic/ImageFiles/menuSpecials_output.png)
```````````````````````````````````````````````````
[{"id":"b0c3f86a.278208","type":"template","z":"fd8b5730.ad96f8","name":"format html page","field":"payload","fieldType":"msg","format":"handlebars","syntax":"mustache","template":"<h1>Drinks available on : {{payload.day}}</h1>\n\n<ul>\n{{#payload.drinks}}\n<li>{{drink}}</li>    \n{{/payload.drinks}}\n</ul>\n\n<h3>Specials:</h3> \n<hr>\n<ul>\n{{^payload.specials}}\nNone today, sorry      \n{{/payload.specials}}\n\n{{#payload.specials}}\n<li>{{drink}}</li>\n{{/payload.specials}}\n</ul>","x":530,"y":177,"wires":[["e3db6dd2.464e9"]]},{"id":"ea682cbc.ccf68","type":"function","z":"fd8b5730.ad96f8","name":"Drinks","func":"msg.payload =   \n         {'day':'Monday',\n          'drinks':[{'drink': 'coffee'}, \n                    {'drink': 'tea'}, \n                    {'drink': 'orange juice'}]\n         };\nreturn msg;","outputs":1,"noerr":0,"x":330,"y":157,"wires":[["b0c3f86a.278208"]]},{"id":"a5bf2762.e254c8","type":"function","z":"fd8b5730.ad96f8","name":"Specials","func":"msg.payload = \n         {'day':'Monday',\n          'drinks':[{'drink': 'coffee'}, \n                    {'drink': 'tea'}, \n                    {'drink': 'orange juice'}],\n          'specials':[{'drink': 'hot chocolate'}, \n                      {'drink': 'espresso'}]\n         };\nreturn msg;","outputs":1,"noerr":0,"x":340,"y":197,"wires":[["b0c3f86a.278208"]]},{"id":"62bf888e.ceedc8","type":"http in","z":"fd8b5730.ad96f8","name":"/menu","url":"/menu","method":"get","swaggerDoc":"","x":170,"y":157,"wires":[["ea682cbc.ccf68"]]},{"id":"9dfe7bc3.42ec18","type":"http response","z":"fd8b5730.ad96f8","name":"","x":892.9999771118164,"y":177,"wires":[]},{"id":"24dfc2d4.f6c3be","type":"http in","z":"fd8b5730.ad96f8","name":"/specials","url":"/specials","method":"get","swaggerDoc":"","x":180,"y":197,"wires":[["a5bf2762.e254c8"]]},{"id":"e3db6dd2.464e9","type":"function","z":"fd8b5730.ad96f8","name":"setHTTPheader","func":"// If sending JSON data the content type is:\n//msg.headers={\"Content-Type\":\"application/json\"}\n\n// For HTML use the content type line below:\nmsg.headers={\"Content-Type\":\"text/html\"};\nreturn msg;","outputs":1,"noerr":0,"x":720,"y":177,"wires":[["9dfe7bc3.42ec18"]]}]
```````````````````````````````````````````````````

Drinks
```````````````````````````````````````````````````
msg.payload =   
         {'day':'Monday',
          'drinks':[{'drink': 'coffee'}, 
                    {'drink': 'tea'}, 
                    {'drink': 'orange juice'}]
         };
return msg;
```````````````````````````````````````````````````

Specials
```````````````````````````````````````````````````
msg.payload = 
         {'day':'Monday',
          'drinks':[{'drink': 'coffee'}, 
                    {'drink': 'tea'}, 
                    {'drink': 'orange juice'}],
          'specials':[{'drink': 'hot chocolate'}, 
                      {'drink': 'espresso'}]
         };
return msg;
```````````````````````````````````````````````````

format html page
```````````````````````````````````````````````````
<h1>Drinks available on : {{payload.day}}</h1>

<ul>
{{#payload.drinks}}
<li>{{drink}}</li>    
{{/payload.drinks}}
</ul>

<h3>Specials:</h3> 
<hr>
<ul>
{{^payload.specials}}
None today, sorry      
{{/payload.specials}}

{{#payload.specials}}
<li>{{drink}}</li>
{{/payload.specials}}
</ul>
```````````````````````````````````````````````````

setHTTPheader
```````````````````````````````````````````````````
// If sending JSON data the content type is:
//msg.headers={"Content-Type":"application/json"}

// For HTML use the content type line below:
msg.headers={"Content-Type":"text/html"};
return msg;
```````````````````````````````````````````````````




< END >
