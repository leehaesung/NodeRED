# Code files

***

* This chart is called rada chart. It looks more professional about our resume.

***

* Rada Chart Web (My Professional Skills)

![radachart.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/05_RadaChart_Web/radachart.png)
![radachart.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/05_RadaChart_Web/radachart_output.png)
```````````````````````````````````````````````````
[{"id":"c0a387d.4279678","type":"http in","z":"fd8b5730.ad96f8","name":"/radachart","url":"/radachart","method":"get","swaggerDoc":"","x":180,"y":1280,"wires":[["1d6a0d11.089f43"]]},{"id":"1d6a0d11.089f43","type":"template","z":"fd8b5730.ad96f8","name":"My Professional IoT Skills","field":"payload","fieldType":"msg","format":"handlebars","syntax":"mustache","template":"<!DOCTYPE html>\n<html>\n  <head>\n    <meta http-equiv=\"Content-Type\" content=\"text/html;charset=utf-8\"/>\n  <title>Radar chart</title>\n    <script src=\"http://d3js.org/d3.v3.min.js\"></script>\n\t<script src=\"RadarChart.js\"></script>\n\t<style>\n\t\tbody {\n\t\t  overflow: hidden;\n\t\t  margin: 0;\n\t\t  font-size: 14px;\n\t\t  font-family: \"Helvetica Neue\", Helvetica;\n\t\t}\n\n\t\t#chart {\n\t\t  position: absolute;\n\t\t  top: 50px;\n\t\t  left: 100px;\n\t\t}\t\n\t</style>\n  </head>\n  <body>\n    <div id=\"body\">\n\t  <div id=\"chart\"></div>\n    </div>\n\t\n    <script type=\"text/javascript\" src=\"script.js\"></script>\n\n  </body>\n</html>\n\n<script>\n    var RadarChart = {\n  draw: function(id, d, options){\n  var cfg = {\n\t radius: 5,\n\t w: 600,\n\t h: 600,\n\t factor: 1,\n\t factorLegend: .85,\n\t levels: 3,\n\t maxValue: 0,\n\t radians: 2 * Math.PI,\n\t opacityArea: 0.5,\n\t ToRight: 5,\n\t TranslateX: 80,\n\t TranslateY: 30,\n\t ExtraWidthX: 100,\n\t ExtraWidthY: 100,\n\t color: d3.scale.category10()\n\t};\n\t\n\tif('undefined' !== typeof options){\n\t  for(var i in options){\n\t\tif('undefined' !== typeof options[i]){\n\t\t  cfg[i] = options[i];\n\t\t}\n\t  }\n\t}\n\tcfg.maxValue = Math.max(cfg.maxValue, d3.max(d, function(i){return d3.max(i.map(function(o){return o.value;}))}));\n\tvar allAxis = (d[0].map(function(i, j){return i.axis}));\n\tvar total = allAxis.length;\n\tvar radius = cfg.factor*Math.min(cfg.w/2, cfg.h/2);\n\tvar Format = d3.format('%');\n\td3.select(id).select(\"svg\").remove();\n\t\n\tvar g = d3.select(id)\n\t\t\t.append(\"svg\")\n\t\t\t.attr(\"width\", cfg.w+cfg.ExtraWidthX)\n\t\t\t.attr(\"height\", cfg.h+cfg.ExtraWidthY)\n\t\t\t.append(\"g\")\n\t\t\t.attr(\"transform\", \"translate(\" + cfg.TranslateX + \",\" + cfg.TranslateY + \")\");\n\t\t\t;\n\n\tvar tooltip;\n\t\n\t//Circular segments\n\tfor(var j=0; j<cfg.levels-1; j++){\n\t  var levelFactor = cfg.factor*radius*((j+1)/cfg.levels);\n\t  g.selectAll(\".levels\")\n\t   .data(allAxis)\n\t   .enter()\n\t   .append(\"svg:line\")\n\t   .attr(\"x1\", function(d, i){return levelFactor*(1-cfg.factor*Math.sin(i*cfg.radians/total));})\n\t   .attr(\"y1\", function(d, i){return levelFactor*(1-cfg.factor*Math.cos(i*cfg.radians/total));})\n\t   .attr(\"x2\", function(d, i){return levelFactor*(1-cfg.factor*Math.sin((i+1)*cfg.radians/total));})\n\t   .attr(\"y2\", function(d, i){return levelFactor*(1-cfg.factor*Math.cos((i+1)*cfg.radians/total));})\n\t   .attr(\"class\", \"line\")\n\t   .style(\"stroke\", \"grey\")\n\t   .style(\"stroke-opacity\", \"0.75\")\n\t   .style(\"stroke-width\", \"0.3px\")\n\t   .attr(\"transform\", \"translate(\" + (cfg.w/2-levelFactor) + \", \" + (cfg.h/2-levelFactor) + \")\");\n\t}\n\n\t//Text indicating at what % each level is\n\tfor(var j=0; j<cfg.levels; j++){\n\t  var levelFactor = cfg.factor*radius*((j+1)/cfg.levels);\n\t  g.selectAll(\".levels\")\n\t   .data([1]) //dummy data\n\t   .enter()\n\t   .append(\"svg:text\")\n\t   .attr(\"x\", function(d){return levelFactor*(1-cfg.factor*Math.sin(0));})\n\t   .attr(\"y\", function(d){return levelFactor*(1-cfg.factor*Math.cos(0));})\n\t   .attr(\"class\", \"legend\")\n\t   .style(\"font-family\", \"sans-serif\")\n\t   .style(\"font-size\", \"10px\")\n\t   .attr(\"transform\", \"translate(\" + (cfg.w/2-levelFactor + cfg.ToRight) + \", \" + (cfg.h/2-levelFactor) + \")\")\n\t   .attr(\"fill\", \"#737373\")\n\t   .text(Format((j+1)*cfg.maxValue/cfg.levels));\n\t}\n\t\n\tseries = 0;\n\n\tvar axis = g.selectAll(\".axis\")\n\t\t\t.data(allAxis)\n\t\t\t.enter()\n\t\t\t.append(\"g\")\n\t\t\t.attr(\"class\", \"axis\");\n\n\taxis.append(\"line\")\n\t\t.attr(\"x1\", cfg.w/2)\n\t\t.attr(\"y1\", cfg.h/2)\n\t\t.attr(\"x2\", function(d, i){return cfg.w/2*(1-cfg.factor*Math.sin(i*cfg.radians/total));})\n\t\t.attr(\"y2\", function(d, i){return cfg.h/2*(1-cfg.factor*Math.cos(i*cfg.radians/total));})\n\t\t.attr(\"class\", \"line\")\n\t\t.style(\"stroke\", \"grey\")\n\t\t.style(\"stroke-width\", \"1px\");\n\n\taxis.append(\"text\")\n\t\t.attr(\"class\", \"legend\")\n\t\t.text(function(d){return d})\n\t\t.style(\"font-family\", \"sans-serif\")\n\t\t.style(\"font-size\", \"11px\")\n\t\t.attr(\"text-anchor\", \"middle\")\n\t\t.attr(\"dy\", \"1.5em\")\n\t\t.attr(\"transform\", function(d, i){return \"translate(0, -10)\"})\n\t\t.attr(\"x\", function(d, i){return cfg.w/2*(1-cfg.factorLegend*Math.sin(i*cfg.radians/total))-60*Math.sin(i*cfg.radians/total);})\n\t\t.attr(\"y\", function(d, i){return cfg.h/2*(1-Math.cos(i*cfg.radians/total))-20*Math.cos(i*cfg.radians/total);});\n\n \n\td.forEach(function(y, x){\n\t  dataValues = [];\n\t  g.selectAll(\".nodes\")\n\t\t.data(y, function(j, i){\n\t\t  dataValues.push([\n\t\t\tcfg.w/2*(1-(parseFloat(Math.max(j.value, 0))/cfg.maxValue)*cfg.factor*Math.sin(i*cfg.radians/total)), \n\t\t\tcfg.h/2*(1-(parseFloat(Math.max(j.value, 0))/cfg.maxValue)*cfg.factor*Math.cos(i*cfg.radians/total))\n\t\t  ]);\n\t\t});\n\t  dataValues.push(dataValues[0]);\n\t  g.selectAll(\".area\")\n\t\t\t\t\t .data([dataValues])\n\t\t\t\t\t .enter()\n\t\t\t\t\t .append(\"polygon\")\n\t\t\t\t\t .attr(\"class\", \"radar-chart-serie\"+series)\n\t\t\t\t\t .style(\"stroke-width\", \"2px\")\n\t\t\t\t\t .style(\"stroke\", cfg.color(series))\n\t\t\t\t\t .attr(\"points\",function(d) {\n\t\t\t\t\t\t var str=\"\";\n\t\t\t\t\t\t for(var pti=0;pti<d.length;pti++){\n\t\t\t\t\t\t\t str=str+d[pti][0]+\",\"+d[pti][1]+\" \";\n\t\t\t\t\t\t }\n\t\t\t\t\t\t return str;\n\t\t\t\t\t  })\n\t\t\t\t\t .style(\"fill\", function(j, i){return cfg.color(series)})\n\t\t\t\t\t .style(\"fill-opacity\", cfg.opacityArea)\n\t\t\t\t\t .on('mouseover', function (d){\n\t\t\t\t\t\t\t\t\t\tz = \"polygon.\"+d3.select(this).attr(\"class\");\n\t\t\t\t\t\t\t\t\t\tg.selectAll(\"polygon\")\n\t\t\t\t\t\t\t\t\t\t .transition(200)\n\t\t\t\t\t\t\t\t\t\t .style(\"fill-opacity\", 0.1); \n\t\t\t\t\t\t\t\t\t\tg.selectAll(z)\n\t\t\t\t\t\t\t\t\t\t .transition(200)\n\t\t\t\t\t\t\t\t\t\t .style(\"fill-opacity\", .7);\n\t\t\t\t\t\t\t\t\t  })\n\t\t\t\t\t .on('mouseout', function(){\n\t\t\t\t\t\t\t\t\t\tg.selectAll(\"polygon\")\n\t\t\t\t\t\t\t\t\t\t .transition(200)\n\t\t\t\t\t\t\t\t\t\t .style(\"fill-opacity\", cfg.opacityArea);\n\t\t\t\t\t });\n\t  series++;\n\t});\n\tseries=0;\n\n\n\td.forEach(function(y, x){\n\t  g.selectAll(\".nodes\")\n\t\t.data(y).enter()\n\t\t.append(\"svg:circle\")\n\t\t.attr(\"class\", \"radar-chart-serie\"+series)\n\t\t.attr('r', cfg.radius)\n\t\t.attr(\"alt\", function(j){return Math.max(j.value, 0)})\n\t\t.attr(\"cx\", function(j, i){\n\t\t  dataValues.push([\n\t\t\tcfg.w/2*(1-(parseFloat(Math.max(j.value, 0))/cfg.maxValue)*cfg.factor*Math.sin(i*cfg.radians/total)), \n\t\t\tcfg.h/2*(1-(parseFloat(Math.max(j.value, 0))/cfg.maxValue)*cfg.factor*Math.cos(i*cfg.radians/total))\n\t\t]);\n\t\treturn cfg.w/2*(1-(Math.max(j.value, 0)/cfg.maxValue)*cfg.factor*Math.sin(i*cfg.radians/total));\n\t\t})\n\t\t.attr(\"cy\", function(j, i){\n\t\t  return cfg.h/2*(1-(Math.max(j.value, 0)/cfg.maxValue)*cfg.factor*Math.cos(i*cfg.radians/total));\n\t\t})\n\t\t.attr(\"data-id\", function(j){return j.axis})\n\t\t.style(\"fill\", cfg.color(series)).style(\"fill-opacity\", .9)\n\t\t.on('mouseover', function (d){\n\t\t\t\t\tnewX =  parseFloat(d3.select(this).attr('cx')) - 10;\n\t\t\t\t\tnewY =  parseFloat(d3.select(this).attr('cy')) - 5;\n\t\t\t\t\t\n\t\t\t\t\ttooltip\n\t\t\t\t\t\t.attr('x', newX)\n\t\t\t\t\t\t.attr('y', newY)\n\t\t\t\t\t\t.text(Format(d.value))\n\t\t\t\t\t\t.transition(200)\n\t\t\t\t\t\t.style('opacity', 1);\n\t\t\t\t\t\t\n\t\t\t\t\tz = \"polygon.\"+d3.select(this).attr(\"class\");\n\t\t\t\t\tg.selectAll(\"polygon\")\n\t\t\t\t\t\t.transition(200)\n\t\t\t\t\t\t.style(\"fill-opacity\", 0.1); \n\t\t\t\t\tg.selectAll(z)\n\t\t\t\t\t\t.transition(200)\n\t\t\t\t\t\t.style(\"fill-opacity\", .7);\n\t\t\t\t  })\n\t\t.on('mouseout', function(){\n\t\t\t\t\ttooltip\n\t\t\t\t\t\t.transition(200)\n\t\t\t\t\t\t.style('opacity', 0);\n\t\t\t\t\tg.selectAll(\"polygon\")\n\t\t\t\t\t\t.transition(200)\n\t\t\t\t\t\t.style(\"fill-opacity\", cfg.opacityArea);\n\t\t\t\t  })\n\t\t.append(\"svg:title\")\n\t\t.text(function(j){return Math.max(j.value, 0)});\n\n\t  series++;\n\t});\n\t//Tooltip\n\ttooltip = g.append('text')\n\t\t\t   .style('opacity', 0)\n\t\t\t   .style('font-family', 'sans-serif')\n\t\t\t   .style('font-size', '13px');\n  }\n};\n</script>\n\n<script>\nvar w = 500,\n\th = 500;\n\nvar colorscale = d3.scale.category10();\n\n//Legend titles\nvar LegendOptions = ['Personal Goal','Now'];\n\n//Data\nvar d = [\n\t\t  [ //Goal(Future) \n\t\t    //Software Skills\n\t\t\t{axis:\"Embedded C\",value:1.0},\n\t\t\t{axis:\"Python\",value:1.0},\n\t\t\t{axis:\"JavaScript&HTML&CSS\",value:0.60},\n\t\t\t{axis:\"Node.js\",value:0.59},\n\t\t\t{axis:\"Node-RED\",value:1.00},\n\t\t\t{axis:\"DB:NoSQL\",value:0.88},\n\t\t\t{axis:\"Data Structure&Algorithm\",value:0.86},\n\t\t\t//Hardware Skills\n\t\t\t{axis:\"Linux Embedded\",value:0.80},\n\t\t\t{axis:\"Sensor & Electronics\",value:1.0},\n\t\t\t{axis:\"Cloud Computing\",value:0.90},\n\t\t\t{axis:\"IoT Protocols: MQTT,CoaP\",value:1.00},\n\t\t\t{axis:\"wireless communication: LoRA,ZigBee,Beacon\",value:0.90},\n\t\t\t//Data Science Skills\n\t\t\t{axis:\"Spark & Hadoop\",value:0.80},\n\t\t\t{axis:\"Statistics\",value:0.80},\n\t\t\t{axis:\"Machine Learning\",value:0.70},\n\t\t\t{axis:\"R\",value:0.90},\n\t\t\t{axis:\"GitHub\",value:0.90},\n\t\t\t//{axis:\"--\",value:0.00},\n\t\t\t//{axis:\"--\",value:0.00},\n\t\t\t//{axis:\"--\",value:0.00},\n\t\t\t//{axis:\"--\",value:0.00},\n\t\t\t//{axis:\"--\",value:0.00}\n\t\t  ],[//Now\n\t\t\t//Software Skills\n\t\t\t{axis:\"Embedded C\",value:0.9},\n\t\t\t{axis:\"Python\",value:0.70},\n\t\t\t{axis:\"JavaScript&HTML&CSS\",value:0.30},\n\t\t\t{axis:\"Node.js\",value:0.35},\n\t\t\t{axis:\"Node-RED\",value:0.90},\n\t\t\t{axis:\"DB:NoSQL\",value:0.20},\n\t\t\t{axis:\"Data Structure&Algorithm\",value:0.46},\n\t\t\t//Hardware Skills\n\t\t\t{axis:\"Linux Embedded\",value:0.70},\n\t\t\t{axis:\"Sensor & Electronics\",value:1.0},\n\t\t\t{axis:\"Cloud Computing\",value:0.50},\n\t\t\t{axis:\"IoT Protocols: MQTT,CoaP\",value:0.74},\n\t\t\t{axis:\"wireless communication: LoRA,ZigBee,Beacon\",value:0.40},\n\t\t\t//Data Science Skills\n\t\t\t{axis:\"Spark & Hadoop\",value:0.30},\n\t\t\t{axis:\"Statistics\",value:0.5},\n\t\t\t{axis:\"Machine Learning\",value:0.44},\n\t\t\t{axis:\"R\",value:0.80},\n\t\t\t{axis:\"GitHub\",value:0.80},\n\t\t\t//{axis:\"--\",value:0.00},\n\t\t\t//{axis:\"--\",value:0.00},\n\t\t\t//{axis:\"--\",value:0.00},\n\t\t\t//{axis:\"--\",value:0.00},\n\t\t\t//{axis:\"--\",value:0.00},\n\t\t\t//{axis:\"--\",value:0.00}\n\t\t  ]\n\t\t];\n\n//Options for the Radar chart, other than default\nvar mycfg = {\n  w: w,\n  h: h,\n  maxValue: 0.6,\n  levels: 6,\n  ExtraWidthX: 300\n}\n\n//Call function to draw the Radar chart\n//Will expect that data is in %'s\nRadarChart.draw(\"#chart\", d, mycfg);\n\n////////////////////////////////////////////\n/////////// Initiate legend ////////////////\n////////////////////////////////////////////\n\nvar svg = d3.select('#body')\n\t.selectAll('svg')\n\t.append('svg')\n\t.attr(\"width\", w+300)\n\t.attr(\"height\", h)\n\n//Create the title for the legend\nvar text = svg.append(\"text\")\n\t.attr(\"class\", \"title\")\n\t.attr('transform', 'translate(90,0)') \n\t.attr(\"x\", w - 70)\n\t.attr(\"y\", 10)\n\t.attr(\"font-size\", \"12px\")\n\t.attr(\"fill\", \"#404040\")\n\t.text(\"My IoT Technology & Data Science Skills(2016)\");\n\t\t\n//Initiate Legend\t\nvar legend = svg.append(\"g\")\n\t.attr(\"class\", \"legend\")\n\t.attr(\"height\", 100)\n\t.attr(\"width\", 200)\n\t.attr('transform', 'translate(90,20)') \n\t;\n\t//Create colour squares\n\tlegend.selectAll('rect')\n\t  .data(LegendOptions)\n\t  .enter()\n\t  .append(\"rect\")\n\t  .attr(\"x\", w - 65)\n\t  .attr(\"y\", function(d, i){ return i * 20;})\n\t  .attr(\"width\", 10)\n\t  .attr(\"height\", 10)\n\t  .style(\"fill\", function(d, i){ return colorscale(i);})\n\t  ;\n\t//Create text next to squares\n\tlegend.selectAll('text')\n\t  .data(LegendOptions)\n\t  .enter()\n\t  .append(\"text\")\n\t  .attr(\"x\", w - 52)\n\t  .attr(\"y\", function(d, i){ return i * 20 + 9;})\n\t  .attr(\"font-size\", \"11px\")\n\t  .attr(\"fill\", \"#737373\")\n\t  .text(function(d) { return d; })\n\t  ;\n</script>","x":430,"y":1280,"wires":[["55e88e66.7dd11"]]},{"id":"55e88e66.7dd11","type":"http response","z":"fd8b5730.ad96f8","name":"/radachart","x":700,"y":1280,"wires":[]}]
```````````````````````````````````````````````````

Function(My Professional IoT Skills)
```````````````````````````````````````````````````
<!DOCTYPE html>
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8"/>
  <title>Radar chart</title>
    <script src="http://d3js.org/d3.v3.min.js"></script>
	<script src="RadarChart.js"></script>
	<style>
		body {
		  overflow: hidden;
		  margin: 0;
		  font-size: 14px;
		  font-family: "Helvetica Neue", Helvetica;
		}

		#chart {
		  position: absolute;
		  top: 50px;
		  left: 100px;
		}	
	</style>
  </head>
  <body>
    <div id="body">
	  <div id="chart"></div>
    </div>
	
    <script type="text/javascript" src="script.js"></script>

  </body>
</html>

<script>
    var RadarChart = {
  draw: function(id, d, options){
  var cfg = {
	 radius: 5,
	 w: 600,
	 h: 600,
	 factor: 1,
	 factorLegend: .85,
	 levels: 3,
	 maxValue: 0,
	 radians: 2 * Math.PI,
	 opacityArea: 0.5,
	 ToRight: 5,
	 TranslateX: 80,
	 TranslateY: 30,
	 ExtraWidthX: 100,
	 ExtraWidthY: 100,
	 color: d3.scale.category10()
	};
	
	if('undefined' !== typeof options){
	  for(var i in options){
		if('undefined' !== typeof options[i]){
		  cfg[i] = options[i];
		}
	  }
	}
	cfg.maxValue = Math.max(cfg.maxValue, d3.max(d, function(i){return d3.max(i.map(function(o){return o.value;}))}));
	var allAxis = (d[0].map(function(i, j){return i.axis}));
	var total = allAxis.length;
	var radius = cfg.factor*Math.min(cfg.w/2, cfg.h/2);
	var Format = d3.format('%');
	d3.select(id).select("svg").remove();
	
	var g = d3.select(id)
			.append("svg")
			.attr("width", cfg.w+cfg.ExtraWidthX)
			.attr("height", cfg.h+cfg.ExtraWidthY)
			.append("g")
			.attr("transform", "translate(" + cfg.TranslateX + "," + cfg.TranslateY + ")");
			;

	var tooltip;
	
	//Circular segments
	for(var j=0; j<cfg.levels-1; j++){
	  var levelFactor = cfg.factor*radius*((j+1)/cfg.levels);
	  g.selectAll(".levels")
	   .data(allAxis)
	   .enter()
	   .append("svg:line")
	   .attr("x1", function(d, i){return levelFactor*(1-cfg.factor*Math.sin(i*cfg.radians/total));})
	   .attr("y1", function(d, i){return levelFactor*(1-cfg.factor*Math.cos(i*cfg.radians/total));})
	   .attr("x2", function(d, i){return levelFactor*(1-cfg.factor*Math.sin((i+1)*cfg.radians/total));})
	   .attr("y2", function(d, i){return levelFactor*(1-cfg.factor*Math.cos((i+1)*cfg.radians/total));})
	   .attr("class", "line")
	   .style("stroke", "grey")
	   .style("stroke-opacity", "0.75")
	   .style("stroke-width", "0.3px")
	   .attr("transform", "translate(" + (cfg.w/2-levelFactor) + ", " + (cfg.h/2-levelFactor) + ")");
	}

	//Text indicating at what % each level is
	for(var j=0; j<cfg.levels; j++){
	  var levelFactor = cfg.factor*radius*((j+1)/cfg.levels);
	  g.selectAll(".levels")
	   .data([1]) //dummy data
	   .enter()
	   .append("svg:text")
	   .attr("x", function(d){return levelFactor*(1-cfg.factor*Math.sin(0));})
	   .attr("y", function(d){return levelFactor*(1-cfg.factor*Math.cos(0));})
	   .attr("class", "legend")
	   .style("font-family", "sans-serif")
	   .style("font-size", "10px")
	   .attr("transform", "translate(" + (cfg.w/2-levelFactor + cfg.ToRight) + ", " + (cfg.h/2-levelFactor) + ")")
	   .attr("fill", "#737373")
	   .text(Format((j+1)*cfg.maxValue/cfg.levels));
	}
	
	series = 0;

	var axis = g.selectAll(".axis")
			.data(allAxis)
			.enter()
			.append("g")
			.attr("class", "axis");

	axis.append("line")
		.attr("x1", cfg.w/2)
		.attr("y1", cfg.h/2)
		.attr("x2", function(d, i){return cfg.w/2*(1-cfg.factor*Math.sin(i*cfg.radians/total));})
		.attr("y2", function(d, i){return cfg.h/2*(1-cfg.factor*Math.cos(i*cfg.radians/total));})
		.attr("class", "line")
		.style("stroke", "grey")
		.style("stroke-width", "1px");

	axis.append("text")
		.attr("class", "legend")
		.text(function(d){return d})
		.style("font-family", "sans-serif")
		.style("font-size", "11px")
		.attr("text-anchor", "middle")
		.attr("dy", "1.5em")
		.attr("transform", function(d, i){return "translate(0, -10)"})
		.attr("x", function(d, i){return cfg.w/2*(1-cfg.factorLegend*Math.sin(i*cfg.radians/total))-60*Math.sin(i*cfg.radians/total);})
		.attr("y", function(d, i){return cfg.h/2*(1-Math.cos(i*cfg.radians/total))-20*Math.cos(i*cfg.radians/total);});

 
	d.forEach(function(y, x){
	  dataValues = [];
	  g.selectAll(".nodes")
		.data(y, function(j, i){
		  dataValues.push([
			cfg.w/2*(1-(parseFloat(Math.max(j.value, 0))/cfg.maxValue)*cfg.factor*Math.sin(i*cfg.radians/total)), 
			cfg.h/2*(1-(parseFloat(Math.max(j.value, 0))/cfg.maxValue)*cfg.factor*Math.cos(i*cfg.radians/total))
		  ]);
		});
	  dataValues.push(dataValues[0]);
	  g.selectAll(".area")
					 .data([dataValues])
					 .enter()
					 .append("polygon")
					 .attr("class", "radar-chart-serie"+series)
					 .style("stroke-width", "2px")
					 .style("stroke", cfg.color(series))
					 .attr("points",function(d) {
						 var str="";
						 for(var pti=0;pti<d.length;pti++){
							 str=str+d[pti][0]+","+d[pti][1]+" ";
						 }
						 return str;
					  })
					 .style("fill", function(j, i){return cfg.color(series)})
					 .style("fill-opacity", cfg.opacityArea)
					 .on('mouseover', function (d){
										z = "polygon."+d3.select(this).attr("class");
										g.selectAll("polygon")
										 .transition(200)
										 .style("fill-opacity", 0.1); 
										g.selectAll(z)
										 .transition(200)
										 .style("fill-opacity", .7);
									  })
					 .on('mouseout', function(){
										g.selectAll("polygon")
										 .transition(200)
										 .style("fill-opacity", cfg.opacityArea);
					 });
	  series++;
	});
	series=0;


	d.forEach(function(y, x){
	  g.selectAll(".nodes")
		.data(y).enter()
		.append("svg:circle")
		.attr("class", "radar-chart-serie"+series)
		.attr('r', cfg.radius)
		.attr("alt", function(j){return Math.max(j.value, 0)})
		.attr("cx", function(j, i){
		  dataValues.push([
			cfg.w/2*(1-(parseFloat(Math.max(j.value, 0))/cfg.maxValue)*cfg.factor*Math.sin(i*cfg.radians/total)), 
			cfg.h/2*(1-(parseFloat(Math.max(j.value, 0))/cfg.maxValue)*cfg.factor*Math.cos(i*cfg.radians/total))
		]);
		return cfg.w/2*(1-(Math.max(j.value, 0)/cfg.maxValue)*cfg.factor*Math.sin(i*cfg.radians/total));
		})
		.attr("cy", function(j, i){
		  return cfg.h/2*(1-(Math.max(j.value, 0)/cfg.maxValue)*cfg.factor*Math.cos(i*cfg.radians/total));
		})
		.attr("data-id", function(j){return j.axis})
		.style("fill", cfg.color(series)).style("fill-opacity", .9)
		.on('mouseover', function (d){
					newX =  parseFloat(d3.select(this).attr('cx')) - 10;
					newY =  parseFloat(d3.select(this).attr('cy')) - 5;
					
					tooltip
						.attr('x', newX)
						.attr('y', newY)
						.text(Format(d.value))
						.transition(200)
						.style('opacity', 1);
						
					z = "polygon."+d3.select(this).attr("class");
					g.selectAll("polygon")
						.transition(200)
						.style("fill-opacity", 0.1); 
					g.selectAll(z)
						.transition(200)
						.style("fill-opacity", .7);
				  })
		.on('mouseout', function(){
					tooltip
						.transition(200)
						.style('opacity', 0);
					g.selectAll("polygon")
						.transition(200)
						.style("fill-opacity", cfg.opacityArea);
				  })
		.append("svg:title")
		.text(function(j){return Math.max(j.value, 0)});

	  series++;
	});
	//Tooltip
	tooltip = g.append('text')
			   .style('opacity', 0)
			   .style('font-family', 'sans-serif')
			   .style('font-size', '13px');
  }
};
</script>

<script>
var w = 500,
	h = 500;

var colorscale = d3.scale.category10();

//Legend titles
var LegendOptions = ['Personal Goal','Now'];

//Data
var d = [
		  [ //Goal(Future) 
		    //Software Skills
			{axis:"Embedded C",value:1.0},
			{axis:"Python",value:1.0},
			{axis:"JavaScript&HTML&CSS",value:0.60},
			{axis:"Node.js",value:0.59},
			{axis:"Node-RED",value:1.00},
			{axis:"DB:NoSQL",value:0.88},
			{axis:"Data Structure&Algorithm",value:0.86},
			//Hardware Skills
			{axis:"Linux Embedded",value:0.80},
			{axis:"Sensor & Electronics",value:1.0},
			{axis:"Cloud Computing",value:0.90},
			{axis:"IoT Protocols: MQTT,CoaP",value:1.00},
			{axis:"wireless communication: LoRA,ZigBee,Beacon",value:0.90},
			//Data Science Skills
			{axis:"Spark & Hadoop",value:0.80},
			{axis:"Statistics",value:0.80},
			{axis:"Machine Learning",value:0.70},
			{axis:"R",value:0.90},
			{axis:"GitHub",value:0.90},
			//{axis:"--",value:0.00},
			//{axis:"--",value:0.00},
			//{axis:"--",value:0.00},
			//{axis:"--",value:0.00},
			//{axis:"--",value:0.00}
		  ],[//Now
			//Software Skills
			{axis:"Embedded C",value:0.9},
			{axis:"Python",value:0.70},
			{axis:"JavaScript&HTML&CSS",value:0.30},
			{axis:"Node.js",value:0.35},
			{axis:"Node-RED",value:0.90},
			{axis:"DB:NoSQL",value:0.20},
			{axis:"Data Structure&Algorithm",value:0.46},
			//Hardware Skills
			{axis:"Linux Embedded",value:0.70},
			{axis:"Sensor & Electronics",value:1.0},
			{axis:"Cloud Computing",value:0.50},
			{axis:"IoT Protocols: MQTT,CoaP",value:0.74},
			{axis:"wireless communication: LoRA,ZigBee,Beacon",value:0.40},
			//Data Science Skills
			{axis:"Spark & Hadoop",value:0.30},
			{axis:"Statistics",value:0.5},
			{axis:"Machine Learning",value:0.44},
			{axis:"R",value:0.80},
			{axis:"GitHub",value:0.80},
			//{axis:"--",value:0.00},
			//{axis:"--",value:0.00},
			//{axis:"--",value:0.00},
			//{axis:"--",value:0.00},
			//{axis:"--",value:0.00},
			//{axis:"--",value:0.00}
		  ]
		];

//Options for the Radar chart, other than default
var mycfg = {
  w: w,
  h: h,
  maxValue: 0.6,
  levels: 6,
  ExtraWidthX: 300
}

//Call function to draw the Radar chart
//Will expect that data is in %'s
RadarChart.draw("#chart", d, mycfg);

////////////////////////////////////////////
/////////// Initiate legend ////////////////
////////////////////////////////////////////

var svg = d3.select('#body')
	.selectAll('svg')
	.append('svg')
	.attr("width", w+300)
	.attr("height", h)

//Create the title for the legend
var text = svg.append("text")
	.attr("class", "title")
	.attr('transform', 'translate(90,0)') 
	.attr("x", w - 70)
	.attr("y", 10)
	.attr("font-size", "12px")
	.attr("fill", "#404040")
	.text("My IoT Technology & Data Science Skills(2016)");
		
//Initiate Legend	
var legend = svg.append("g")
	.attr("class", "legend")
	.attr("height", 100)
	.attr("width", 200)
	.attr('transform', 'translate(90,20)') 
	;
	//Create colour squares
	legend.selectAll('rect')
	  .data(LegendOptions)
	  .enter()
	  .append("rect")
	  .attr("x", w - 65)
	  .attr("y", function(d, i){ return i * 20;})
	  .attr("width", 10)
	  .attr("height", 10)
	  .style("fill", function(d, i){ return colorscale(i);})
	  ;
	//Create text next to squares
	legend.selectAll('text')
	  .data(LegendOptions)
	  .enter()
	  .append("text")
	  .attr("x", w - 52)
	  .attr("y", function(d, i){ return i * 20 + 9;})
	  .attr("font-size", "11px")
	  .attr("fill", "#737373")
	  .text(function(d) { return d; })
	  ;
</script>
```````````````````````````````````````````````````


