---
title: 使用svg画图
categories:  svg
tags: tool
date: 2022-10-17
---



## js event

<svg width="600" height="600">
  <script type="text/JavaScript">
    <![CDATA[
        function hiddenText() {
          document.getElementById("group1").children[1].style.opacity="0.0";
        }
        function showText(){
          document.getElementById("group1").children[1].style.opacity="1.0";
        }
        function showRootChildrenCount() {
          alert("Total Children: "+document.documentElement.childNodes.length);
        }
    ]]>
  </script>
  <g id="group1" onMouseOver="showText()" onMouseOut="hiddenText()">
    <rect id="rect1" x="100" y="100" width="200" height="200" 
    stroke="none" stroke-width="3" fill="green" 
    />
    <text id="text1" x="160" y="200" fill="white" onMouseOver="showColor()">2022-1018</text>
  </g>
</svg>
