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

***

* CV Smaple (It's NOT Me)

![CVFormat.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/05_RadaChart_Web/CVFormat.png)

```````````````````````````````````````````````````
[{"id":"a6269323.4372b","type":"http in","z":"5d085b60.4df384","name":"/resume","url":"/resume","method":"get","swaggerDoc":"","x":211.27975463867188,"y":359.8412570953369,"wires":[["cb8724a1.91a1a8"]]},{"id":"cb8724a1.91a1a8","type":"template","z":"5d085b60.4df384","name":"My Resume","field":"payload","fieldType":"msg","format":"handlebars","syntax":"mustache","template":"<!DOCTYPE html>\n<html>\n<head>\n<title>Haesung Lee - Curriculum Vitae</title>\n\n<meta name=\"viewport\" content=\"width=device-width\"/>\n<meta name=\"description\" content=\"The Curriculum Vitae of Joe Bloggs.\"/>\n<meta charset=\"UTF-8\"> \n\n<link type=\"text/css\" rel=\"stylesheet\" href=\"style.css\">\n<link href='http://fonts.googleapis.com/css?family=Rokkitt:400,700|Lato:400,300' rel='stylesheet' type='text/css'>\n\n<!--[if lt IE 9]>\n<script src=\"//html5shiv.googlecode.com/svn/trunk/html5.js\"></script>\n<![endif]-->\n</head>\n<style type=\"text/css\">\nhtml,body,div,span,object,iframe,h1,h2,h3,h4,h5,h6,p,blockquote,pre,abbr,address,cite,code,del,dfn,em,img,ins,kbd,q,samp,small,strong,sub,sup,var,b,i,dl,dt,dd,ol,ul,li,fieldset,form,label,legend,table,caption,tbody,tfoot,thead,tr,th,td,article,aside,canvas,details,figcaption,figure,footer,header,hgroup,menu,nav,section,summary,time,mark,audio,video {\nborder:0;\nfont:inherit;\nfont-size:100%;\nmargin:0;\npadding:0;\nvertical-align:baseline;\n}\n\narticle,aside,details,figcaption,figure,footer,header,hgroup,menu,nav,section {\ndisplay:block;\n}\n\nhtml, body {background: #181818; font-family: 'Lato', helvetica, arial, sans-serif; font-size: 16px; color: #222;}\n\n.clear {clear: both;}\n\np {\n\tfont-size: 1em;\n\tline-height: 1.4em;\n\tmargin-bottom: 20px;\n\tcolor: #444;\n}\n\n#cv {\n\twidth: 90%;\n\tmax-width: 800px;\n\tbackground: #f3f3f3;\n\tmargin: 30px auto;\n}\n\n.mainDetails {\n\tpadding: 25px 35px;\n\tborder-bottom: 2px solid #cf8a05;\n\tbackground: #ededed;\n}\n\n#name h1 {\n\tfont-size: 2.5em;\n\tfont-weight: 700;\n\tfont-family: 'Rokkitt', Helvetica, Arial, sans-serif;\n\tmargin-bottom: -6px;\n}\n\n#name h2 {\n\tfont-size: 2em;\n\tmargin-left: 2px;\n\tfont-family: 'Rokkitt', Helvetica, Arial, sans-serif;\n}\n\n#mainArea {\n\tpadding: 0 40px;\n}\n\n#headshot {\n\twidth: 12.5%;\n\tfloat: left;\n\tmargin-right: 30px;\n}\n\n#headshot img {\n\twidth: 100%;\n\theight: auto;\n\t-webkit-border-radius: 50px;\n\tborder-radius: 50px;\n}\n\n#name {\n\tfloat: left;\n}\n\n#contactDetails {\n\tfloat: right;\n}\n\n#contactDetails ul {\n\tlist-style-type: none;\n\tfont-size: 0.9em;\n\tmargin-top: 2px;\n}\n\n#contactDetails ul li {\n\tmargin-bottom: 3px;\n\tcolor: #444;\n}\n\n#contactDetails ul li a, a[href^=tel] {\n\tcolor: #444; \n\ttext-decoration: none;\n\t-webkit-transition: all .3s ease-in;\n\t-moz-transition: all .3s ease-in;\n\t-o-transition: all .3s ease-in;\n\t-ms-transition: all .3s ease-in;\n\ttransition: all .3s ease-in;\n}\n\n#contactDetails ul li a:hover { \n\tcolor: #cf8a05;\n}\n\n\nsection {\n\tborder-top: 1px solid #dedede;\n\tpadding: 20px 0 0;\n}\n\nsection:first-child {\n\tborder-top: 0;\n}\n\nsection:last-child {\n\tpadding: 20px 0 10px;\n}\n\n.sectionTitle {\n\tfloat: left;\n\twidth: 25%;\n}\n\n.sectionContent {\n\tfloat: right;\n\twidth: 72.5%;\n}\n\n.sectionTitle h1 {\n\tfont-family: 'Rokkitt', Helvetica, Arial, sans-serif;\n\tfont-style: italic;\n\tfont-size: 1.5em;\n\tcolor: #cf8a05;\n}\n\n.sectionContent h2 {\n\tfont-family: 'Rokkitt', Helvetica, Arial, sans-serif;\n\tfont-size: 1.5em;\n\tmargin-bottom: -2px;\n}\n\n.subDetails {\n\tfont-size: 0.8em;\n\tfont-style: italic;\n\tmargin-bottom: 3px;\n}\n\n.keySkills {\n\tlist-style-type: none;\n\t-moz-column-count:3;\n\t-webkit-column-count:3;\n\tcolumn-count:3;\n\tmargin-bottom: 20px;\n\tfont-size: 1em;\n\tcolor: #444;\n}\n\n.keySkills ul li {\n\tmargin-bottom: 3px;\n}\n\n@media all and (min-width: 602px) and (max-width: 800px) {\n\t#headshot {\n\t\tdisplay: none;\n\t}\n\t\n\t.keySkills {\n\t-moz-column-count:2;\n\t-webkit-column-count:2;\n\tcolumn-count:2;\n\t}\n}\n\n@media all and (max-width: 601px) {\n\t#cv {\n\t\twidth: 95%;\n\t\tmargin: 10px auto;\n\t\tmin-width: 280px;\n\t}\n\t\n\t#headshot {\n\t\tdisplay: none;\n\t}\n\t\n\t#name, #contactDetails {\n\t\tfloat: none;\n\t\twidth: 100%;\n\t\ttext-align: center;\n\t}\n\t\n\t.sectionTitle, .sectionContent {\n\t\tfloat: none;\n\t\twidth: 100%;\n\t}\n\t\n\t.sectionTitle {\n\t\tmargin-left: -2px;\n\t\tfont-size: 1.25em;\n\t}\n\t\n\t.keySkills {\n\t\t-moz-column-count:2;\n\t\t-webkit-column-count:2;\n\t\tcolumn-count:2;\n\t}\n}\n\n@media all and (max-width: 480px) {\n\t.mainDetails {\n\t\tpadding: 15px 15px;\n\t}\n\t\n\tsection {\n\t\tpadding: 15px 0 0;\n\t}\n\t\n\t#mainArea {\n\t\tpadding: 0 25px;\n\t}\n\n\t\n\t.keySkills {\n\t-moz-column-count:1;\n\t-webkit-column-count:1;\n\tcolumn-count:1;\n\t}\n\t\n\t#name h1 {\n\t\tline-height: .8em;\n\t\tmargin-bottom: 4px;\n\t}\n}\n\n@media print {\n    #cv {\n        width: 100%;\n    }\n}\n\n@-webkit-keyframes reset {\n\t0% {\n\t\topacity: 0;\n\t}\n\t100% {\n\t\topacity: 0;\n\t}\n}\n\n@-webkit-keyframes fade-in {\n\t0% {\n\t\topacity: 0;\n\t}\n\t40% {\n\t\topacity: 0;\n\t}\n\t100% {\n\t\topacity: 1;\n\t}\n}\n\n@-moz-keyframes reset {\n\t0% {\n\t\topacity: 0;\n\t}\n\t100% {\n\t\topacity: 0;\n\t}\n}\n\n@-moz-keyframes fade-in {\n\t0% {\n\t\topacity: 0;\n\t}\n\t40% {\n\t\topacity: 0;\n\t}\n\t100% {\n\t\topacity: 1;\n\t}\n}\n\n@keyframes reset {\n\t0% {\n\t\topacity: 0;\n\t}\n\t100% {\n\t\topacity: 0;\n\t}\n}\n\n@keyframes fade-in {\n\t0% {\n\t\topacity: 0;\n\t}\n\t40% {\n\t\topacity: 0;\n\t}\n\t100% {\n\t\topacity: 1;\n\t}\n}\n\n.instaFade {\n    -webkit-animation-name: reset, fade-in;\n    -webkit-animation-duration: 1.5s;\n    -webkit-animation-timing-function: ease-in;\n\t\n\t-moz-animation-name: reset, fade-in;\n    -moz-animation-duration: 1.5s;\n    -moz-animation-timing-function: ease-in;\n\t\n\tanimation-name: reset, fade-in;\n    animation-duration: 1.5s;\n    animation-timing-function: ease-in;\n}\n\n.quickFade {\n    -webkit-animation-name: reset, fade-in;\n    -webkit-animation-duration: 2.5s;\n    -webkit-animation-timing-function: ease-in;\n\t\n\t-moz-animation-name: reset, fade-in;\n    -moz-animation-duration: 2.5s;\n    -moz-animation-timing-function: ease-in;\n\t\n\tanimation-name: reset, fade-in;\n    animation-duration: 2.5s;\n    animation-timing-function: ease-in;\n}\n \n.delayOne {\n\t-webkit-animation-delay: 0, .5s;\n\t-moz-animation-delay: 0, .5s;\n\tanimation-delay: 0, .5s;\n}\n\n.delayTwo {\n\t-webkit-animation-delay: 0, 1s;\n\t-moz-animation-delay: 0, 1s;\n\tanimation-delay: 0, 1s;\n}\n\n.delayThree {\n\t-webkit-animation-delay: 0, 1.5s;\n\t-moz-animation-delay: 0, 1.5s;\n\tanimation-delay: 0, 1.5s;\n}\n\n.delayFour {\n\t-webkit-animation-delay: 0, 2s;\n\t-moz-animation-delay: 0, 2s;\n\tanimation-delay: 0, 2s;\n}\n\n.delayFive {\n\t-webkit-animation-delay: 0, 2.5s;\n\t-moz-animation-delay: 0, 2.5s;\n\tanimation-delay: 0, 2.5s;\n}    \n</style>\n\n<body id=\"top\">\n<div id=\"cv\" class=\"instaFade\">\n\t<div class=\"mainDetails\">\n\t\t<div id=\"headshot\" class=\"quickFade\">\n\t\t\t<img src=\"headshot.jpg\" alt=\"Alan Smith\" />\n\t\t</div>\n\t\t\n\t\t<div id=\"name\">\n\t\t\t<h1 class=\"quickFade delayTwo\">Haesung Lee Bloggs</h1>\n\t\t\t<h2 class=\"quickFade delayThree\">Haesung Lee Title</h2>\n\t\t</div>\n\t\t\n\t\t<div id=\"contactDetails\" class=\"quickFade delayFour\">\n\t\t\t<ul>\n\t\t\t\t<li>e: <a href=\"mailto:achasma@gmail.com\" target=\"_blank\">joe@bloggs.com</a></li>\n\t\t\t\t<li>w: <a href=\"http://www.bloggs.com\">www.bloggs.com</a></li>\n\t\t\t\t<li>m: 01234567890</li>\n\t\t\t</ul>\n\t\t</div>\n\t\t<div class=\"clear\"></div>\n\t</div>\n\t\n\t<div id=\"mainArea\" class=\"quickFade delayFive\">\n\t\t<section>\n\t\t\t<article>\n\t\t\t\t<div class=\"sectionTitle\">\n\t\t\t\t\t<h1>Personal Profile</h1>\n\t\t\t\t</div>\n\t\t\t\t\n\t\t\t\t<div class=\"sectionContent\">\n\t\t\t\t\t<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer dolor metus, interdum at scelerisque in, porta at lacus. Maecenas dapibus luctus cursus. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec ultricies massa et erat luctus hendrerit. Curabitur non consequat enim. Vestibulum bibendum mattis dignissim. Proin id sapien quis libero interdum porttitor.</p>\n\t\t\t\t</div>\n\t\t\t</article>\n\t\t\t<div class=\"clear\"></div>\n\t\t</section>\n\t\t\n\t\t\n\t\t<section>\n\t\t\t<div class=\"sectionTitle\">\n\t\t\t\t<h1>Work Experience</h1>\n\t\t\t</div>\n\t\t\t\n\t\t\t<div class=\"sectionContent\">\n\t\t\t\t<article>\n\t\t\t\t\t<h2>Job Title at Company</h2>\n\t\t\t\t\t<p class=\"subDetails\">April 2011 - Present</p>\n\t\t\t\t\t<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec ultricies massa et erat luctus hendrerit. Curabitur non consequat enim. Vestibulum bibendum mattis dignissim. Proin id sapien quis libero interdum porttitor.</p>\n\t\t\t\t</article>\n\t\t\t\t\n\t\t\t\t<article>\n\t\t\t\t\t<h2>Job Title at Company</h2>\n\t\t\t\t\t<p class=\"subDetails\">Janruary 2007 - March 2011</p>\n\t\t\t\t\t<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec ultricies massa et erat luctus hendrerit. Curabitur non consequat enim. Vestibulum bibendum mattis dignissim. Proin id sapien quis libero interdum porttitor.</p>\n\t\t\t\t</article>\n\t\t\t\t\n\t\t\t\t<article>\n\t\t\t\t\t<h2>Job Title at Company</h2>\n\t\t\t\t\t<p class=\"subDetails\">October 2004 - December 2006</p>\n\t\t\t\t\t<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec ultricies massa et erat luctus hendrerit. Curabitur non consequat enim. Vestibulum bibendum mattis dignissim. Proin id sapien quis libero interdum porttitor.</p>\n\t\t\t\t</article>\n\t\t\t</div>\n\t\t\t<div class=\"clear\"></div>\n\t\t</section>\n\t\t\n\t\t\n\t\t<section>\n\t\t\t<div class=\"sectionTitle\">\n\t\t\t\t<h1>Key Skills</h1>\n\t\t\t</div>\n\t\t\t\n\t\t\t<div class=\"sectionContent\">\n\t\t\t\t<ul class=\"keySkills\">\n\t\t\t\t\t<li>A Key Skill</li>\n\t\t\t\t\t<li>A Key Skill</li>\n\t\t\t\t\t<li>A Key Skill</li>\n\t\t\t\t\t<li>A Key Skill</li>\n\t\t\t\t\t<li>A Key Skill</li>\n\t\t\t\t\t<li>A Key Skill</li>\n\t\t\t\t\t<li>A Key Skill</li>\n\t\t\t\t\t<li>A Key Skill</li>\n\t\t\t\t</ul>\n\t\t\t</div>\n\t\t\t<div class=\"clear\"></div>\n\t\t</section>\n\t\t\n\t\t\n\t\t<section>\n\t\t\t<div class=\"sectionTitle\">\n\t\t\t\t<h1>Education</h1>\n\t\t\t</div>\n\t\t\t\n\t\t\t<div class=\"sectionContent\">\n\t\t\t\t<article>\n\t\t\t\t\t<h2>College/University</h2>\n\t\t\t\t\t<p class=\"subDetails\">Qualification</p>\n\t\t\t\t\t<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec ultricies massa et erat luctus hendrerit. Curabitur non consequat enim.</p>\n\t\t\t\t</article>\n\t\t\t\t\n\t\t\t\t<article>\n\t\t\t\t\t<h2>College/University</h2>\n\t\t\t\t\t<p class=\"subDetails\">Qualification</p>\n\t\t\t\t\t<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec ultricies massa et erat luctus hendrerit. Curabitur non consequat enim.</p>\n\t\t\t\t</article>\n\t\t\t</div>\n\t\t\t<div class=\"clear\"></div>\n\t\t</section>\n\t\t\n\t</div>\n</div>\n<script type=\"text/javascript\">\nvar gaJsHost = ((\"https:\" == document.location.protocol) ? \"https://ssl.\" : \"http://www.\");\ndocument.write(unescape(\"%3Cscript src='\" + gaJsHost + \"google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E\"));\n</script>\n<script type=\"text/javascript\">\nvar pageTracker = _gat._getTracker(\"UA-3753241-1\");\npageTracker._initData();\npageTracker._trackPageview();\n</script>\n</body>\n</html>","x":421.2797546386719,"y":359.8412570953369,"wires":[["37683c2d.e44784"]]},{"id":"37683c2d.e44784","type":"http response","z":"5d085b60.4df384","name":"/resume","x":631.2797546386719,"y":359.84125232696533,"wires":[]}]
```````````````````````````````````````````````````

* Function
```````````````````````````````````````````````````
<!DOCTYPE html>
<html>
<head>
<title>Haesung Lee - Curriculum Vitae</title>

<meta name="viewport" content="width=device-width"/>
<meta name="description" content="The Curriculum Vitae of Joe Bloggs."/>
<meta charset="UTF-8"> 

<link type="text/css" rel="stylesheet" href="style.css">
<link href='http://fonts.googleapis.com/css?family=Rokkitt:400,700|Lato:400,300' rel='stylesheet' type='text/css'>

<!--[if lt IE 9]>
<script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script>
<![endif]-->
</head>
<style type="text/css">
html,body,div,span,object,iframe,h1,h2,h3,h4,h5,h6,p,blockquote,pre,abbr,address,cite,code,del,dfn,em,img,ins,kbd,q,samp,small,strong,sub,sup,var,b,i,dl,dt,dd,ol,ul,li,fieldset,form,label,legend,table,caption,tbody,tfoot,thead,tr,th,td,article,aside,canvas,details,figcaption,figure,footer,header,hgroup,menu,nav,section,summary,time,mark,audio,video {
border:0;
font:inherit;
font-size:100%;
margin:0;
padding:0;
vertical-align:baseline;
}

article,aside,details,figcaption,figure,footer,header,hgroup,menu,nav,section {
display:block;
}

html, body {background: #181818; font-family: 'Lato', helvetica, arial, sans-serif; font-size: 16px; color: #222;}

.clear {clear: both;}

p {
	font-size: 1em;
	line-height: 1.4em;
	margin-bottom: 20px;
	color: #444;
}

#cv {
	width: 90%;
	max-width: 800px;
	background: #f3f3f3;
	margin: 30px auto;
}

.mainDetails {
	padding: 25px 35px;
	border-bottom: 2px solid #cf8a05;
	background: #ededed;
}

#name h1 {
	font-size: 2.5em;
	font-weight: 700;
	font-family: 'Rokkitt', Helvetica, Arial, sans-serif;
	margin-bottom: -6px;
}

#name h2 {
	font-size: 2em;
	margin-left: 2px;
	font-family: 'Rokkitt', Helvetica, Arial, sans-serif;
}

#mainArea {
	padding: 0 40px;
}

#headshot {
	width: 12.5%;
	float: left;
	margin-right: 30px;
}

#headshot img {
	width: 100%;
	height: auto;
	-webkit-border-radius: 50px;
	border-radius: 50px;
}

#name {
	float: left;
}

#contactDetails {
	float: right;
}

#contactDetails ul {
	list-style-type: none;
	font-size: 0.9em;
	margin-top: 2px;
}

#contactDetails ul li {
	margin-bottom: 3px;
	color: #444;
}

#contactDetails ul li a, a[href^=tel] {
	color: #444; 
	text-decoration: none;
	-webkit-transition: all .3s ease-in;
	-moz-transition: all .3s ease-in;
	-o-transition: all .3s ease-in;
	-ms-transition: all .3s ease-in;
	transition: all .3s ease-in;
}

#contactDetails ul li a:hover { 
	color: #cf8a05;
}


section {
	border-top: 1px solid #dedede;
	padding: 20px 0 0;
}

section:first-child {
	border-top: 0;
}

section:last-child {
	padding: 20px 0 10px;
}

.sectionTitle {
	float: left;
	width: 25%;
}

.sectionContent {
	float: right;
	width: 72.5%;
}

.sectionTitle h1 {
	font-family: 'Rokkitt', Helvetica, Arial, sans-serif;
	font-style: italic;
	font-size: 1.5em;
	color: #cf8a05;
}

.sectionContent h2 {
	font-family: 'Rokkitt', Helvetica, Arial, sans-serif;
	font-size: 1.5em;
	margin-bottom: -2px;
}

.subDetails {
	font-size: 0.8em;
	font-style: italic;
	margin-bottom: 3px;
}

.keySkills {
	list-style-type: none;
	-moz-column-count:3;
	-webkit-column-count:3;
	column-count:3;
	margin-bottom: 20px;
	font-size: 1em;
	color: #444;
}

.keySkills ul li {
	margin-bottom: 3px;
}

@media all and (min-width: 602px) and (max-width: 800px) {
	#headshot {
		display: none;
	}
	
	.keySkills {
	-moz-column-count:2;
	-webkit-column-count:2;
	column-count:2;
	}
}

@media all and (max-width: 601px) {
	#cv {
		width: 95%;
		margin: 10px auto;
		min-width: 280px;
	}
	
	#headshot {
		display: none;
	}
	
	#name, #contactDetails {
		float: none;
		width: 100%;
		text-align: center;
	}
	
	.sectionTitle, .sectionContent {
		float: none;
		width: 100%;
	}
	
	.sectionTitle {
		margin-left: -2px;
		font-size: 1.25em;
	}
	
	.keySkills {
		-moz-column-count:2;
		-webkit-column-count:2;
		column-count:2;
	}
}

@media all and (max-width: 480px) {
	.mainDetails {
		padding: 15px 15px;
	}
	
	section {
		padding: 15px 0 0;
	}
	
	#mainArea {
		padding: 0 25px;
	}

	
	.keySkills {
	-moz-column-count:1;
	-webkit-column-count:1;
	column-count:1;
	}
	
	#name h1 {
		line-height: .8em;
		margin-bottom: 4px;
	}
}

@media print {
    #cv {
        width: 100%;
    }
}

@-webkit-keyframes reset {
	0% {
		opacity: 0;
	}
	100% {
		opacity: 0;
	}
}

@-webkit-keyframes fade-in {
	0% {
		opacity: 0;
	}
	40% {
		opacity: 0;
	}
	100% {
		opacity: 1;
	}
}

@-moz-keyframes reset {
	0% {
		opacity: 0;
	}
	100% {
		opacity: 0;
	}
}

@-moz-keyframes fade-in {
	0% {
		opacity: 0;
	}
	40% {
		opacity: 0;
	}
	100% {
		opacity: 1;
	}
}

@keyframes reset {
	0% {
		opacity: 0;
	}
	100% {
		opacity: 0;
	}
}

@keyframes fade-in {
	0% {
		opacity: 0;
	}
	40% {
		opacity: 0;
	}
	100% {
		opacity: 1;
	}
}

.instaFade {
    -webkit-animation-name: reset, fade-in;
    -webkit-animation-duration: 1.5s;
    -webkit-animation-timing-function: ease-in;
	
	-moz-animation-name: reset, fade-in;
    -moz-animation-duration: 1.5s;
    -moz-animation-timing-function: ease-in;
	
	animation-name: reset, fade-in;
    animation-duration: 1.5s;
    animation-timing-function: ease-in;
}

.quickFade {
    -webkit-animation-name: reset, fade-in;
    -webkit-animation-duration: 2.5s;
    -webkit-animation-timing-function: ease-in;
	
	-moz-animation-name: reset, fade-in;
    -moz-animation-duration: 2.5s;
    -moz-animation-timing-function: ease-in;
	
	animation-name: reset, fade-in;
    animation-duration: 2.5s;
    animation-timing-function: ease-in;
}
 
.delayOne {
	-webkit-animation-delay: 0, .5s;
	-moz-animation-delay: 0, .5s;
	animation-delay: 0, .5s;
}

.delayTwo {
	-webkit-animation-delay: 0, 1s;
	-moz-animation-delay: 0, 1s;
	animation-delay: 0, 1s;
}

.delayThree {
	-webkit-animation-delay: 0, 1.5s;
	-moz-animation-delay: 0, 1.5s;
	animation-delay: 0, 1.5s;
}

.delayFour {
	-webkit-animation-delay: 0, 2s;
	-moz-animation-delay: 0, 2s;
	animation-delay: 0, 2s;
}

.delayFive {
	-webkit-animation-delay: 0, 2.5s;
	-moz-animation-delay: 0, 2.5s;
	animation-delay: 0, 2.5s;
}    
</style>

<body id="top">
<div id="cv" class="instaFade">
	<div class="mainDetails">
		<div id="headshot" class="quickFade">
			<img src="headshot.jpg" alt="Alan Smith" />
		</div>
		
		<div id="name">
			<h1 class="quickFade delayTwo">Haesung Lee Bloggs</h1>
			<h2 class="quickFade delayThree">Haesung Lee Title</h2>
		</div>
		
		<div id="contactDetails" class="quickFade delayFour">
			<ul>
				<li>e: <a href="mailto:achasma@gmail.com" target="_blank">joe@bloggs.com</a></li>
				<li>w: <a href="http://www.bloggs.com">www.bloggs.com</a></li>
				<li>m: 01234567890</li>
			</ul>
		</div>
		<div class="clear"></div>
	</div>
	
	<div id="mainArea" class="quickFade delayFive">
		<section>
			<article>
				<div class="sectionTitle">
					<h1>Personal Profile</h1>
				</div>
				
				<div class="sectionContent">
					<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer dolor metus, interdum at scelerisque in, porta at lacus. Maecenas dapibus luctus cursus. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec ultricies massa et erat luctus hendrerit. Curabitur non consequat enim. Vestibulum bibendum mattis dignissim. Proin id sapien quis libero interdum porttitor.</p>
				</div>
			</article>
			<div class="clear"></div>
		</section>
		
		
		<section>
			<div class="sectionTitle">
				<h1>Work Experience</h1>
			</div>
			
			<div class="sectionContent">
				<article>
					<h2>Job Title at Company</h2>
					<p class="subDetails">April 2011 - Present</p>
					<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec ultricies massa et erat luctus hendrerit. Curabitur non consequat enim. Vestibulum bibendum mattis dignissim. Proin id sapien quis libero interdum porttitor.</p>
				</article>
				
				<article>
					<h2>Job Title at Company</h2>
					<p class="subDetails">Janruary 2007 - March 2011</p>
					<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec ultricies massa et erat luctus hendrerit. Curabitur non consequat enim. Vestibulum bibendum mattis dignissim. Proin id sapien quis libero interdum porttitor.</p>
				</article>
				
				<article>
					<h2>Job Title at Company</h2>
					<p class="subDetails">October 2004 - December 2006</p>
					<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec ultricies massa et erat luctus hendrerit. Curabitur non consequat enim. Vestibulum bibendum mattis dignissim. Proin id sapien quis libero interdum porttitor.</p>
				</article>
			</div>
			<div class="clear"></div>
		</section>
		
		
		<section>
			<div class="sectionTitle">
				<h1>Key Skills</h1>
			</div>
			
			<div class="sectionContent">
				<ul class="keySkills">
					<li>A Key Skill</li>
					<li>A Key Skill</li>
					<li>A Key Skill</li>
					<li>A Key Skill</li>
					<li>A Key Skill</li>
					<li>A Key Skill</li>
					<li>A Key Skill</li>
					<li>A Key Skill</li>
				</ul>
			</div>
			<div class="clear"></div>
		</section>
		
		
		<section>
			<div class="sectionTitle">
				<h1>Education</h1>
			</div>
			
			<div class="sectionContent">
				<article>
					<h2>College/University</h2>
					<p class="subDetails">Qualification</p>
					<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec ultricies massa et erat luctus hendrerit. Curabitur non consequat enim.</p>
				</article>
				
				<article>
					<h2>College/University</h2>
					<p class="subDetails">Qualification</p>
					<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec ultricies massa et erat luctus hendrerit. Curabitur non consequat enim.</p>
				</article>
			</div>
			<div class="clear"></div>
		</section>
		
	</div>
</div>
<script type="text/javascript">
var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");
document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));
</script>
<script type="text/javascript">
var pageTracker = _gat._getTracker("UA-3753241-1");
pageTracker._initData();
pageTracker._trackPageview();
</script>
</body>
</html>
```````````````````````````````````````````````````
