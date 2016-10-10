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

* CV 4 Smaples For CV(resume)

![4samples_NodeRED.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/05_RadaChart_Web/4samples_NodeRED.png)
![4samples.png](https://github.com/leehaesung/NodeRED/blob/master/02_CodeFiles/05_RadaChart_Web/4samples.png)

```````````````````````````````````````````````````
[{"id":"3535e027.f689c","type":"http in","z":"1e24f9f9.947116","name":"/resume01","url":"/resume01","method":"get","swaggerDoc":"","x":248.57142639160156,"y":188.57142639160156,"wires":[["7e655a00.694dc8"]]},{"id":"7e655a00.694dc8","type":"template","z":"1e24f9f9.947116","name":"My Resume","field":"payload","fieldType":"msg","format":"handlebars","syntax":"mustache","template":"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\n<html>\n<head>\n\n\t<title>Haesung Lee | Web Progrmaer   | achasma@gmail.com</title>\n\t<meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\" />\n\n\t<meta name=\"keywords\" content=\"\" />\n\t<meta name=\"description\" content=\"\" />\n\n\t<link rel=\"stylesheet\" type=\"text/css\" href=\"http://yui.yahooapis.com/2.7.0/build/reset-fonts-grids/reset-fonts-grids.css\" media=\"all\" /> \n\t<link rel=\"stylesheet\" type=\"text/css\" href=\"resume.css\" media=\"all\" />\n\n</head>\n\n<style type=\"text/css\">\n/*\n---------------------------------------------------------------------------------\n\tSTRIPPED DOWN RESUME TEMPLATE\n    html resume\n\n    v0.9: 5/28/09\n\n    design and code by: thingsthatarebrown.com \n                        (matt brown)\n---------------------------------------------------------------------------------\n*/\n.msg { padding: 10px; background: #222; position: relative; }\n.msg h1 { color: #fff;  }\n.msg a { margin-left: 20px; background: #408814; color: white; padding: 4px 8px; text-decoration: none; }\n.msg a:hover { background: #266400; }\n\n/* //-- yui-grids style overrides -- */\nbody { font-family: Georgia; color: #444; }\n#inner { padding: 10px 80px; margin: 80px auto; background: #f5f5f5; border: solid #666; border-width: 8px 0 2px 0; }\n.yui-gf { margin-bottom: 2em; padding-bottom: 2em; border-bottom: 1px solid #ccc; }\n\n/* //-- header, body, footer -- */\n#hd { margin: 2.5em 0 3em 0; padding-bottom: 1.5em; border-bottom: 1px solid #ccc }\n#hd h2 { text-transform: uppercase; letter-spacing: 2px; }\n#bd, #ft { margin-bottom: 2em; }\n\n/* //-- footer -- */\n#ft { padding: 1em 0 5em 0; font-size: 92%; border-top: 1px solid #ccc; text-align: center; }\n#ft p { margin-bottom: 0; text-align: center;   }\n\n/* //-- core typography and style -- */\n#hd h1 { font-size: 48px; text-transform: uppercase; letter-spacing: 3px; }\nh2 { font-size: 152% }\nh3, h4 { font-size: 122%; }\nh1, h2, h3, h4 { color: #333; }\np { font-size: 100%; line-height: 18px; padding-right: 3em; }\na { color: #990003 }\na:hover { text-decoration: none; }\nstrong { font-weight: bold; }\nli { line-height: 24px; border-bottom: 1px solid #ccc; }\np.enlarge { font-size: 144%; padding-right: 6.5em; line-height: 24px; }\np.enlarge span { color: #000 }\n.contact-info { margin-top: 7px; }\n.first h2 { font-style: italic; }\n.last { border-bottom: 0 }\n\n\n/* //-- section styles -- */\n\na#pdf { display: block; float: left; background: #666; color: white; padding: 6px 50px 6px 12px; margin-bottom: 6px; text-decoration: none;  }\na#pdf:hover { background: #222; }\n\n.job { position: relative; margin-bottom: 1em; padding-bottom: 1em; border-bottom: 1px solid #ccc; }\n.job h4 { position: absolute; top: 0.35em; right: 0 }\n.job p { margin: 0.75em 0 3em 0; }\n\n.last { border: none; }\n.skills-list {  }\n.skills-list ul { margin: 0; }\n.skills-list li { margin: 3px 0; padding: 3px 0; }\n.skills-list li span { font-size: 152%; display: block; margin-bottom: -2px; padding: 0 }\n.talent { width: 32%; float: left }\n.talent h2 { margin-bottom: 6px; }\n\n#srt-ttab { margin-bottom: 100px; text-align: center;  }\n#srt-ttab img.last { margin-top: 20px }\n\n/* --// override to force 1/8th width grids -- */\n.yui-gf .yui-u{width:80.2%;}\n.yui-gf div.first{width:12.3%;}\n</style>\n\n<body>\n\n<div id=\"doc2\" class=\"yui-t7\">\n\t<div id=\"inner\">\n\t\n\t\t<div id=\"hd\">\n\t\t\t<div class=\"yui-gc\">\n\t\t\t\t<div class=\"yui-u first\">\n\t\t\t\t\t<h1>Haesung Lee</h1>\n\t\t\t\t\t<h2>Web Developer</h2>\n\t\t\t\t</div>\n\n\t\t\t\t<div class=\"yui-u\">\n\t\t\t\t\t<div class=\"contact-info\">\n\t\t\t\t\t\t<h3><a id=\"pdf\" href=\"#\">Download PDF</a></h3>\n\t\t\t\t\t\t<h3><a href=\"mailto:name@yourdomain.com\">achasma@gmail.com</a></h3>\n\t\t\t\t\t\t<h3>+61432399841</h3>\n\t\t\t\t\t</div><!--// .contact-info -->\n\t\t\t\t</div>\n\t\t\t</div><!--// .yui-gc -->\n\t\t</div><!--// hd -->\n\n\t\t<div id=\"bd\">\n\t\t\t<div id=\"yui-main\">\n\t\t\t\t<div class=\"yui-b\">\n\n\t\t\t\t\t<div class=\"yui-gf\">\n\t\t\t\t\t\t<div class=\"yui-u first\">\n\t\t\t\t\t\t\t<h2>Profile</h2>\n\t\t\t\t\t\t</div>\n\t\t\t\t\t\t<div class=\"yui-u\">\n\t\t\t\t\t\t\t<p class=\"enlarge\">\n\t\t\t\t\t\t\t\tProgressively evolve cross-platform ideas before impactful infomediaries. Energistically visualize tactical initiatives before cross-media catalysts for change. \n\t\t\t\t\t\t\t</p>\n\t\t\t\t\t\t</div>\n\t\t\t\t\t</div><!--// .yui-gf -->\n\n\t\t\t\t\t<div class=\"yui-gf\">\n\t\t\t\t\t\t<div class=\"yui-u first\">\n\t\t\t\t\t\t\t<h2>Skills</h2>\n\t\t\t\t\t\t</div>\n\t\t\t\t\t\t<div class=\"yui-u\">\n\n\t\t\t\t\t\t\t\t<div class=\"talent\">\n\t\t\t\t\t\t\t\t\t<h2>Web Design</h2>\n\t\t\t\t\t\t\t\t\t<p>Assertively exploit wireless initiatives rather than synergistic core competencies.\t</p>\n\t\t\t\t\t\t\t\t</div>\n\n\t\t\t\t\t\t\t\t<div class=\"talent\">\n\t\t\t\t\t\t\t\t\t<h2>Interface Design</h2>\n\t\t\t\t\t\t\t\t\t<p>Credibly streamline mission-critical value with multifunctional functionalities.\t </p>\n\t\t\t\t\t\t\t\t</div>\n\n\t\t\t\t\t\t\t\t<div class=\"talent\">\n\t\t\t\t\t\t\t\t\t<h2>Project Direction</h2>\n\t\t\t\t\t\t\t\t\t<p>Proven ability to lead and manage a wide variety of design and development projects in team and independent situations.</p>\n\t\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t</div>\n\t\t\t\t\t</div><!--// .yui-gf -->\n\n\t\t\t\t\t<div class=\"yui-gf\">\n\t\t\t\t\t\t<div class=\"yui-u first\">\n\t\t\t\t\t\t\t<h2>Technical</h2>\n\t\t\t\t\t\t</div>\n\t\t\t\t\t\t<div class=\"yui-u\">\n\t\t\t\t\t\t\t<ul class=\"talent\">\n\t\t\t\t\t\t\t\t<li>XHTML</li>\n\t\t\t\t\t\t\t\t<li>CSS</li>\n\t\t\t\t\t\t\t\t<li class=\"last\">Javascript</li>\n\t\t\t\t\t\t\t</ul>\n\n\t\t\t\t\t\t\t<ul class=\"talent\">\n\t\t\t\t\t\t\t\t<li>Jquery</li>\n\t\t\t\t\t\t\t\t<li>PHP</li>\n\t\t\t\t\t\t\t\t<li class=\"last\">CVS / Subversion</li>\n\t\t\t\t\t\t\t</ul>\n\n\t\t\t\t\t\t\t<ul class=\"talent\">\n\t\t\t\t\t\t\t\t<li>OS X</li>\n\t\t\t\t\t\t\t\t<li>Windows XP/Vista</li>\n\t\t\t\t\t\t\t\t<li class=\"last\">Linux</li>\n\t\t\t\t\t\t\t</ul>\n\t\t\t\t\t\t</div>\n\t\t\t\t\t</div><!--// .yui-gf-->\n\n\t\t\t\t\t<div class=\"yui-gf\">\n\t\n\t\t\t\t\t\t<div class=\"yui-u first\">\n\t\t\t\t\t\t\t<h2>Experience</h2>\n\t\t\t\t\t\t</div><!--// .yui-u -->\n\n\t\t\t\t\t\t<div class=\"yui-u\">\n\n\t\t\t\t\t\t\t<div class=\"job\">\n\t\t\t\t\t\t\t\t<h2>Facebook</h2>\n\t\t\t\t\t\t\t\t<h3>Senior Interface Designer</h3>\n\t\t\t\t\t\t\t\t<h4>2005-2007</h4>\n\t\t\t\t\t\t\t\t<p>Intrinsicly enable optimal core competencies through corporate relationships. Phosfluorescently implement worldwide vortals and client-focused imperatives. Conveniently initiate virtual paradigms and top-line convergence. </p>\n\t\t\t\t\t\t\t</div>\n\n\t\t\t\t\t\t\t<div class=\"job\">\n\t\t\t\t\t\t\t\t<h2>Apple Inc.</h2>\n\t\t\t\t\t\t\t\t<h3>Senior Interface Designer</h3>\n\t\t\t\t\t\t\t\t<h4>2005-2007</h4>\n\t\t\t\t\t\t\t\t<p>Progressively reconceptualize multifunctional \"outside the box\" thinking through inexpensive methods of empowerment. Compellingly morph extensive niche markets with mission-critical ideas. Phosfluorescently deliver bricks-and-clicks strategic theme areas rather than scalable benefits. </p>\n\t\t\t\t\t\t\t</div>\n\n\t\t\t\t\t\t\t<div class=\"job\">\n\t\t\t\t\t\t\t\t<h2>Microsoft</h2>\n\t\t\t\t\t\t\t\t<h3>Principal and Creative Lead</h3>\n\t\t\t\t\t\t\t\t<h4>2004-2005</h4>\n\t\t\t\t\t\t\t\t<p>Intrinsicly transform flexible manufactured products without excellent intellectual capital. Energistically evisculate orthogonal architectures through covalent action items. Assertively incentivize sticky platforms without synergistic materials. </p>\n\t\t\t\t\t\t\t</div>\n\n\n\t\t\t\t\t\t\t<div class=\"job last\">\n\t\t\t\t\t\t\t\t<h2>International Business Machines (IBM)</h2>\n\t\t\t\t\t\t\t\t<h3>Lead Web Designer</h3>\n\t\t\t\t\t\t\t\t<h4>2001-2004</h4>\n\t\t\t\t\t\t\t\t<p>Globally re-engineer cross-media schemas through viral methods of empowerment. Proactively grow long-term high-impact human capital and highly efficient innovation. Intrinsicly iterate excellent e-tailers with timely e-markets.</p>\n\t\t\t\t\t\t\t</div>\n\n\t\t\t\t\t\t</div><!--// .yui-u -->\n\t\t\t\t\t</div><!--// .yui-gf -->\n\n\n\t\t\t\t\t<div class=\"yui-gf last\">\n\t\t\t\t\t\t<div class=\"yui-u first\">\n\t\t\t\t\t\t\t<h2>Education</h2>\n\t\t\t\t\t\t</div>\n\t\t\t\t\t\t<div class=\"yui-u\">\n\t\t\t\t\t\t\t<h2>Indiana University - Bloomington, Indiana</h2>\n\t\t\t\t\t\t\t<h3>Dual Major, Economics and English &mdash; <strong>4.0 GPA</strong> </h3>\n\t\t\t\t\t\t</div>\n\t\t\t\t\t</div><!--// .yui-gf -->\n\n\n\t\t\t\t</div><!--// .yui-b -->\n\t\t\t</div><!--// yui-main -->\n\t\t</div><!--// bd -->\n\n\t\t<div id=\"ft\">\n\t\t\t<p>Jonathan Doe &mdash; <a href=\"mailto:name@yourdomain.com\">name@yourdomain.com</a> &mdash; (313) - 867-5309</p>\n\t\t</div><!--// footer -->\n\n\t</div><!-- // inner -->\n\n\n</div><!--// doc -->\n\n\n</body>\n</html>\n\n","x":458.57142639160156,"y":188.57142639160156,"wires":[["fd9d105c.372b3"]]},{"id":"fd9d105c.372b3","type":"http response","z":"1e24f9f9.947116","name":"/resume01","x":678.5714263916016,"y":188.57142162322998,"wires":[]},{"id":"95b97019.ae68","type":"http in","z":"1e24f9f9.947116","name":"/resume02","url":"/resume02","method":"get","swaggerDoc":"","x":245.85635375976562,"y":255.8441619873047,"wires":[["4f3104e5.48aa1c"]]},{"id":"4f3104e5.48aa1c","type":"template","z":"1e24f9f9.947116","name":"My Resume","field":"payload","fieldType":"msg","format":"handlebars","syntax":"mustache","template":"\n<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\n<html xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n\t<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\" />\n\t<title>Resume | Haesung Lee</title>\n\t<meta name=\"robots\" content=\"noindex, nofollow\" />\n\t<style type=\"text/css\" media=\"all\">\n\t\thtml{\n\t\t\tbackground-color:#444;\n\t\t\tbackground: url(/posts/backgrounds/images/20.gif);\n\t\t\tpadding:0 1em;\n\t\t\t}\n\t\tbody {\n\t\t\tbackground-color:#FFF;\n\t\t\tfont-family:Arial, Helvetica, sans-serif;\n\t\t\tpadding:2em;\n\t\t\tmargin:1em auto;\n\t\t\tborder:2px solid #000;\n\t\t\tmax-width: 50em;\n\t\t\t}\n\t\t#address{\n\t\t\tfloat:right;\n\t\t\tpadding-top:2.5em;\n\t\t\t}\n\t\t#contact{\n\t\t\ttext-align:right;\n\t\t\t}\n\t\t.date {\n\t\t\tfloat:left;\n\t\t\tfont-size:1em;\n\t\t\tmargin:0 0 0 -16em;\n\t\t\ttext-align:right;\n\t\t\t}\n\t\tabbr, acronym{\n\t\t\tborder-bottom:1px dotted #333;\n\t\t\tcursor:help;\n\t\t\t}\t\n\t\taddress{\n\t\t\tfont-style:italic;\n\t\t\tcolor:#333;\n\t\t\tfont-size:.9em;\n\t\t\t}\n\t\t.content{\n\t\t\twidth:32em;\n\t\t\tmargin:0 0 0 16em;\n\t\t\t}\t\n\t\t.section{\n\t\t\tmargin: 0;\n\t\t\tpadding:1em 0;\n\t\t\t}\n\t\tul{\n\t\t\tpadding-left:.5em;\n\t\t\tmargin-left:.5em;\n\t\t\t}\n\t\th1{\n\t\t\tmargin:0 0 .1em 0;\n\t\t\tpadding:1em 0 0 0;\n\t\t\tfont-size:1.75em;\n\t\t\tborder-bottom:3px double #000;\n\t\t\t}\n\t\th2 {\n\t\t\tfont-size:1.3em;\n\t\t\tfont-variant: small-caps;\n\t\t\tletter-spacing: .06em;\n\t\t\tborder-bottom:1px solid #000;\n\t\t\t}\n\t\t.section h3 {\n\t\t\tfont-size:1em;\n\t\t\tfont-variant: small-caps;\n\t\t\tmargin-bottom:0;\n\t\t\twidth:14em;\n\t\t\t}\n\t</style>\n\t<style type=\"text/css\" media=\"print\">\n\t\tbody {\n\t\t\tbackground-color:#FFF;\n\t\t\tborder-width:0 0 0 0;\n\t\t\tmargin:0;\n\t\t\twidth:100%\n\t\t\t}\n\t</style>\n</head>\n<body>\n\t<div id=\"address\">335 Name Street, Unit #, Town, Province, N2H 3Y6</div>\n\t<h1>Haesung Lee</h1>\n\t<div id=\"contact\">3A, Your Major, <abbr title=\"University of Waterloo\">UW</abbr>, 1-519-500-8252, <a href=\"mailto:YOUREMAILADDRESS@uwaterloo.ca\">emailaddress@uwaterloo.ca</a></div>\n\t\n\t<div class=\"section\">\n\t\t<h2>Summary of Qualifications</h2>\n\t\t\t<ul>\n\t\t\t\t<li>Bullet one Bullet one</li>\n\t\t\t\t<li>Bullet two Bullet two</li>\n\t\t\t\t<li>Bullet three Bullet three</li>\n\t\t\t\t<li>Bullet four Bullet four</li>\n\t\t\t\t<li>Bullet five Bullet Five</li>\n\t\t\t</ul>\n\t</div>\n\t\n\t<div class=\"section\">\n\t\t<h2>Work Experience</h2>\n\t\t<div class=\"content\">\n\t\t\t<span class=\"date\">Start &raquo; End Year</span>\n\t\t\t<h3>Job Title One</h3>\n\t\t\t<address>Company Name, Address, City Province</address>\n\t\t\t<ul>\n\t\t\t\t<li>Bullet one Bullet one</li>\n\t\t\t\t<li>Bullet two Bullet two</li>\n\t\t\t\t<li>Bullet three Bullet three</li>\n\t\t\t\t<li>Bullet four Bullet four</li>\n\t\t\t</ul>\n\t\t\t\n\t\t\t<span class=\"date\">Start &raquo; End Year</span>\n\t\t\t<h3>Job Title Two</h3>\n\t\t\t<address>Company Name, Address, City Province</address>\n\t\t\t<ul>\n\t\t\t\t<li>Bullet one Bullet one</li>\n\t\t\t\t<li>Bullet two Bullet two</li>\n\t\t\t\t<li>Bullet three Bullet three</li>\n\t\t\t\t<li>Bullet four Bullet four</li>\n\t\t\t</ul>\n\t\t\t\n\t\t\t<span class=\"date\">Start &raquo; End Year</span>\n\t\t\t<h3>Job Title Three</h3>\n\t\t\t<address>Company Name, Address, City Province</address>\n\t\t</div>\n\t</div>\n\t\n\t<div class=\"section\">\n\t\t<h2>Volunteer Experience</h2>\n\t\t<div class=\"content\">\n\t\t\t<span class=\"date\">Start &raquo; End Year</span>\n\t\t\t<h3>Volunteer Job Title</h3>\n\t\t\t<address>Company Name, Address, City Province</address>\n\t\t\t<ul>\n\t\t\t\t<li>Bullet one Bullet one</li>\n\t\t\t\t<li>Bullet two Bullet two</li>\n\t\t\t\t<li>Bullet three Bullet three</li>\n\t\t\t</ul>\n\t\t</div>\n\t</div>\n\t\n\t<div class=\"section\">\n\t\t<h2>Education</h2>\n\t\t\t<ul>\n\t\t\t\t<li>Candidate for Bachelor of Major, University, Province,  StartYear - Present</li>\n\t\t\t\t<li>OSSD, Highschool, Town, Province, StartYear-EndYear</li>\n\t\t\t</ul>\n\t</div>\n\t\n\t<div class=\"section\">\n\t\t<h2>Academic Awards</h2>\n\t\t\t<ul>\n\t\t\t\t<li>Year, Year, Name of award/Scholarship</li>\n\t\t\t</ul>\n\t</div>\n\t\n</body>\n</html>\n\n","x":455.8563537597656,"y":255.8441619873047,"wires":[["25e59f4e.288ad"]]},{"id":"25e59f4e.288ad","type":"http response","z":"1e24f9f9.947116","name":"/resume02","x":675.8563537597656,"y":255.8441572189331,"wires":[]},{"id":"532b4d05.6fcaf4","type":"http in","z":"1e24f9f9.947116","name":"/resume03","url":"/resume03","method":"get","swaggerDoc":"","x":244.4277801513672,"y":317.2727355957031,"wires":[["c6a63049.d94b3"]]},{"id":"c6a63049.d94b3","type":"template","z":"1e24f9f9.947116","name":"My Resume","field":"payload","fieldType":"msg","format":"handlebars","syntax":"mustache","template":"\n<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\n<html xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n\t<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\" />\n\t<title>Resume | Haesung Lee</title>\n\t<meta name=\"robots\" content=\"noindex, nofollow\" />\n\t<style type=\"text/css\" media=\"all\">\n\t\thtml{\n\t\t\tbackground-color:#FFF;\n\t\t\tpadding:0 1em;\n\t\t\t}\n\t\tbody {\n\t\t\tbackground-color:#FFF;\n\t\t\tfont-family:Georgia, \"Times New Roman\", Times, serif;\n\t\t\tpadding:1em;\n\t\t\tborder:solid #AAA 1px;\n\t\t\tmargin:1em auto;\n\t\t\tmax-width: 50em;\n\t\t\t}\n\t\t#address{\n\t\t\theight:5em;\n\t\t\twidth:48em;\n\t\t\ttext-align:center;\n\t\t\t}\n\t\t#address div{\n\t\t\twidth:14em;\n\t\t\tfloat:left;\n\t\t\tpadding:0 .5em 0 1.5em;\n\t\t\t}\n\t\t#address h3{\n\t\t\tborder-bottom: none;\n\t\t\tmargin-top: 0;\n\t\t\t}\t\n\t\t.date {\n\t\t\tfloat:right;\n\t\t\tfont-size:.8em;\n\t\t\tmargin-top:.4em;\n\t\t\ttext-align:right;\n\t\t\t}\n\t\tabbr, acronym{\n\t\t\tborder-bottom:1px dotted #333;\n\t\t\tcursor:help;\n\t\t\t}\t\n\t\taddress{\n\t\t\tfont-style:italic;\n\t\t\tcolor:#333;\n\t\t\tfont-size:.9em;\n\t\t\t}\n\t\t\t\n\t\t\n\t\th1{\n\t\t\tfont-size:1.75em;\n\t\t\ttext-align:center;\n\t\t\tpadding:.5em 0;\n\t\t\t}\n\t\th2 {\n\t\t\tclear:both;\n\t\t\tfont-size: 1.4em;\n\t\t\tfont-weight:bold;\n\t\t\tmargin-top:2em;\n\t\t\tfont-variant: small-caps;\n\t\t\tpadding-left:.25em;\n\t\t\tbackground-color:#EEE;\n\t\t\tborder-bottom: 1px solid #999;\n\t\t\tletter-spacing: .06em;\n\t\t\t}\n\t\th3 {margin: 1em 0 0 0;}\n\t</style>\n\t<style type=\"text/css\" media=\"print\">\n\t\tbody {\n\t\t\tbackground-color:#FFF;\n\t\t\tborder-width:0 0 0 0;\n\t\t\tmargin:0;\n\t\t\twidth:100%\n\t\t\t}\n\t</style>\n</head>\n<body>\n\t<h1>Haesung Lee</h1>\n\t<div id=\"address\">\n\t\t<div>\n\t\t\t<h3>Local Address</h3>\n\t\t\t335 Name Street, Unit #<br>\n\t\t\tTown, Province, N2H 3Y6<br>\n\t\t\t1-519-500-8252\n\t\t</div>\n\t\t<div id=\"first\">\n\t\t\t<h3>Credentials</h3>\n\t\t\t3A, Your Major, <abbr title=\"University of Waterloo\">UW</abbr><br />\n\t\t\t<a href=\"mailto:YOUREMAILADDRESS@uwaterloo.ca\">emailaddress@uwaterloo.ca</a><br />\n\t\t\t<a href=\"http://www.YOURWEBSITE.ca\">www.yourwebsite.ca</a>\n\t\t</div>\n\t\t<div>\n\t\t\t<h3>Permanent Address</h3>\n\t\t\t62 6th Avenue <br>\n\t\t\tTown, Ontario, N4N 2V6<br>\n\t\t\t1-519-500-4833\n\t\t</div>\n\t</div>\n\t\n\t<h2>Summary of Qualifications</h2>\n\t<ul>\n\t\t<li>Bullet one Bullet one</li>\n\t\t<li>Bullet two Bullet two</li>\n\t\t<li>Bullet three Bullet three</li>\n\t\t<li>Bullet four Bullet four</li>\n\t\t<li>Bullet five Bullet Five</li>\n\t</ul>\n\t\n\t\n\t<h2>Work Experience</h2>\n\t<span class=\"date\">Start &raquo; End Year</span>\n\t<h3>Job Title One</h3>\n\t<address>Company Name, Address, City Province</address>\n\t<ul>\n\t\t<li>Bullet one Bullet one</li>\n\t\t<li>Bullet two Bullet two</li>\n\t\t<li>Bullet three Bullet three</li>\n\t\t<li>Bullet four Bullet four</li>\n\t</ul>\n\t\n\t<span class=\"date\">Start &raquo; End Year</span>\n\t<h3>Job Title Two</h3>\n\t<address>Company Name, Address, City Province</address>\n\t<ul>\n\t\t<li>Bullet one Bullet one</li>\n\t\t<li>Bullet two Bullet two</li>\n\t\t<li>Bullet three Bullet three</li>\n\t\t<li>Bullet four Bullet four</li>\n\t</ul>\n\t\n\t<span class=\"date\">Start &raquo; End Year</span>\n\t<h3>Job Title Three</h3>\n\t<address>Company Name, Address, City Province</address>\n\t\n\t\n\t<h2>Interest / Volunteer</h2>\n\t<span class=\"date\">Start &raquo; End Year</span>\n\t<h3>Volunteer Job Title</h3>\n\t<address>Company Name, Address, City Province</address>\n\t<ul>\n\t\t<li>Bullet one Bullet one</li>\n\t\t<li>Bullet two Bullet two</li>\n\t\t<li>Bullet three Bullet three</li>\n\t</ul>\n\t\n\t\n\t<h2>Education</h2>\n\t<ul>\n\t\t<li>Candidate for Bachelor of Major, University, Province,  StartYear - Present</li>\n\t\t<li>OSSD, Highschool, Town, Province, StartYear-EndYear</li>\n\t</ul>\n\t\n\t\n\t<h2>Academic Awards</h2>\n\t<ul>\n\t\t<li>Year, Year, Name of award/Scholarship</li>\n\t</ul>\n\t\n\t\n</body>\n</html>\n\n","x":454.4277801513672,"y":317.2727355957031,"wires":[["3bee8e95.66fe52"]]},{"id":"3bee8e95.66fe52","type":"http response","z":"1e24f9f9.947116","name":"/resume03","x":674.4277801513672,"y":317.27273082733154,"wires":[]},{"id":"bbe1f37d.c9f55","type":"http in","z":"1e24f9f9.947116","name":"/resume04","url":"/resume04","method":"get","swaggerDoc":"","x":242.99920654296875,"y":374.41558837890625,"wires":[["b646b09b.aa0fd"]]},{"id":"b646b09b.aa0fd","type":"template","z":"1e24f9f9.947116","name":"My Resume","field":"payload","fieldType":"msg","format":"handlebars","syntax":"mustache","template":"\n<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\n<html xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n\t<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\" />\n\t<title>Resume | Haesung Lee</title>\n\t<meta name=\"robots\" content=\"noindex, nofollow\" />\n\t<style type=\"text/css\" media=\"all\">\n\t\thtml{\n\t\t\tbackground-color:#EEE;\n\t\t\tpadding:0 1em;\n\t\t\t}\n\t\tbody {\n\t\t\tbackground-color:#FFF;\n\t\t\tfont-family:\"Trebuchet MS\", Helvetica, Arial;\n\t\t\tpadding:1em;\n\t\t\tborder:solid #AAA;\n\t\t\tborder-width:1px 3px 3px 1px;\n\t\t\tmargin:1em auto;\n\t\t\tmax-width: 50em;\n\t\t\t}\n\t\t#address{\n\t\t\theight:5em;\n\t\t\twidth:47em;\n\t\t\tmargin:1em 0 1em 0;\n\t\t\t}\n\t\t#address div{\n\t\t\twidth:13em;\n\t\t\tfloat:left;\n\t\t\tpadding:0 .5em 0 1.5em;\n\t\t\tborder-left:1px solid #CCC;\n\t\t\t}\n\t\t#address div#first{\n\t\t\tborder-left:none;\n\t\t\t}\n\t\t#address h3{\n\t\t\tborder-bottom: none;\n\t\t\tmargin-top: 0;\n\t\t\t}\t\n\t\t.date {\n\t\t\tfloat:right;\n\t\t\tfont-size:.8em;\n\t\t\tmargin-top:.4em;\n\t\t\ttext-align:right;\n\t\t\t}\n\t\tabbr, acronym{\n\t\t\tborder-bottom:1px dotted #333;\n\t\t\tcursor:help;\n\t\t\t}\t\n\t\taddress{\n\t\t\tfont-style:italic;\n\t\t\tcolor:#333;\n\t\t\tfont-size:.9em;\n\t\t\t}\n\t\t\t\n\t\t\n\t\th1{\n\t\t\tfont-size:1.5em;\n\t\t\tfont-family: Helvetica, Verdana, Arial, sans-serif;\n\t\t\t}\n\t\th2 {\n\t\t\tclear:both;\n\t\t\tfont-size: 1.4em;\n\t\t\tfont-weight:bold;\n\t\t\tmargin-top:2em;\n\t\t\tfont-variant: small-caps;\n\t\t\tpadding-left:.25em;\n\t\t\tbackground-color:#EEE;\n\t\t\tborder-bottom: 1px solid #999;\n\t\t\tletter-spacing: .06em;\n\t\t\t}\n\t\th3 {margin: 1em 0 0 0;}\n\t</style>\n\t<style type=\"text/css\" media=\"print\">\n\t\tbody {\n\t\t\tbackground-color:#FFF;\n\t\t\tborder-width:0 0 0 0;\n\t\t\tmargin:0;\n\t\t\twidth:100%\n\t\t\t}\n\t</style>\n</head>\n<body>\n\t<h1>Haesung Lee</h1>\n\t<div id=\"address\">\n\t\t<div id=\"first\">\n\t\t\t<h3>Credentials</h3>\n\t\t\t3A, Your Major, <abbr title=\"University of Waterloo\">UW</abbr><br />\n\t\t\t<a href=\"mailto:YOUREMAILADDRESS@uwaterloo.ca\">emailaddress@uwaterloo.ca</a><br />\n\t\t\t<a href=\"http://www.YOURWEBSITE.ca\">www.yourwebsite.ca</a>\n\t\t</div>\n\t\t<div>\n\t\t\t<h3>Local Address</h3>\n\t\t\t335 Name Street, Unit #<br>\n\t\t\tTown, Province, N2H 3Y6<br>\n\t\t\t1-519-500-1111\n\t\t</div>\n\t\t<div>\n\t\t\t<h3>Permanent Address</h3>\n\t\t\t62 6th Avenue <br>\n\t\t\tTown, Ontario, N4N 2V6<br>\n\t\t\t1-519-500-1111\n\t\t</div>\n\t</div>\n\t\n\t<h2>Summary of Qualifications</h2>\n\t<ul>\n\t\t<li>Bullet one Bullet one</li>\n\t\t<li>Bullet two Bullet two</li>\n\t\t<li>Bullet three Bullet three</li>\n\t\t<li>Bullet four Bullet four</li>\n\t\t<li>Bullet five Bullet Five</li>\n\t</ul>\n\t\n\t\n\t<h2>Work Experience</h2>\n\t<span class=\"date\">Start &raquo; End Year</span>\n\t<h3>Job Title One</h3>\n\t<address>Company Name, Address, City Province</address>\n\t<ul>\n\t\t<li>Bullet one Bullet one</li>\n\t\t<li>Bullet two Bullet two</li>\n\t\t<li>Bullet three Bullet three</li>\n\t\t<li>Bullet four Bullet four</li>\n\t</ul>\n\t\n\t<span class=\"date\">Start &raquo; End Year</span>\n\t<h3>Job Title Two</h3>\n\t<address>Company Name, Address, City Province</address>\n\t<ul>\n\t\t<li>Bullet one Bullet one</li>\n\t\t<li>Bullet two Bullet two</li>\n\t\t<li>Bullet three Bullet three</li>\n\t\t<li>Bullet four Bullet four</li>\n\t</ul>\n\t\n\t<span class=\"date\">Start &raquo; End Year</span>\n\t<h3>Job Title Three</h3>\n\t<address>Company Name, Address, City Province</address>\n\t\n\t\n\t<h2>Interest / Volunteer</h2>\n\t<span class=\"date\">Start &raquo; End Year</span>\n\t<h3>Volunteer Job Title</h3>\n\t<address>Company Name, Address, City Province</address>\n\t<ul>\n\t\t<li>Bullet one Bullet one</li>\n\t\t<li>Bullet two Bullet two</li>\n\t\t<li>Bullet three Bullet three</li>\n\t</ul>\n\t\n\t\n\t<h2>Education</h2>\n\t<ul>\n\t\t<li>Candidate for Bachelor of Major, University, Province,  StartYear - Present</li>\n\t\t<li>OSSD, Highschool, Town, Province, StartYear-EndYear</li>\n\t</ul>\n\t\n\t\n\t<h2>Academic Awards</h2>\n\t<ul>\n\t\t<li>Year, Year, Name of award/Scholarship</li>\n\t</ul>\n\t\n\t\n</body>\n</html>\n\n","x":452.99920654296875,"y":374.41558837890625,"wires":[["b0c6c0b8.3d62b"]]},{"id":"b0c6c0b8.3d62b","type":"http response","z":"1e24f9f9.947116","name":"/resume04","x":672.9992065429688,"y":374.41558361053467,"wires":[]},{"id":"42fd859f.de723c","type":"comment","z":"1e24f9f9.947116","name":"Sample","info":"","x":207.85714285714283,"y":74.28571428571428,"wires":[]}]
```````````````````````````````````````````````````
