---
title: 使用svg画图
categories:  svg
tags: tool
date: 2022-10-17
---

## reading blocks


<svg width="800" height="600">
  
  <g id="group1" onMouseOver="displayBlock()" onMouseOut="hiddenText()" width=400 height=400>
    <rect id="rect1" x="100" y="100" width="200" height="200" 
    stroke="none" stroke-width="3" fill="green" />
    <text id="text1" x="160" y="200" fill="white">2022-1018</text>
  </g>
</svg>

<script type="text/JavaScript">
function displayBlock() {
  var block_size=12;
  var xmlns = "http://www.w3.org/2000/svg";
  var group=document.getElementById("group1");
  for(var i =0;i<52;i++){
    for(var j=0;j<7;j++){
      var rect1=document.createElementNS(xmlns, "rect");
      rect1.setAttributeNS(null, 'x', (block_size+2)*i);
      rect1.setAttributeNS(null, 'y', (block_size+2)*j);
      rect1.setAttributeNS(null, 'ry', 2);
      rect1.setAttributeNS(null, 'ry', 2);
      rect1.setAttributeNS(null, 'width', block_size);
      rect1.setAttributeNS(null, 'height', block_size);
      rect1.setAttributeNS(null, 'fill', "green");
      rect1.setAttributeNS(null, 'opacity', 0.5);
      group.appendChild(rect1);
    }
  }
}
function showText(){
  document.getElementById("group1").children[1].style.opacity="1.0";
}
function showRootChildrenCount() {
  alert("Total Children: "+document.documentElement.childNodes.length);
}
document.addEventListener('DOMContentLoaded',displayBlock());
windows.onload=function(){
  displayBlock();
}
</script>




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