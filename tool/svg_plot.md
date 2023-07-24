
## function plot

![graph](imgs/svg-loaders/graph.svg)

- [svggrapher](http://dlippman.imathas.com/svg2/svggrapher.htm)

## pie chart

<div>
<div class="buttons"></div>
<svg width="100" height="100" class="chart">
    <circle r="25" cx="50" cy="50" class="pie"/>
  </svg>
<script>
var total = 158,
    buttons = document.querySelector('.buttons'),
    pie = document.querySelector('.pie'),
    activeClass = 'active';
var continents = {
  asia: 60,
  northAmerica : 5,
  southAmerica: 9,
  oceania: 1,
  africa: 15,
  europe: 12
};
// work out percentage as a result of total
var numberFixer = function(num){
  var result = ((num * total) / 100);
  return result;
}
// create a button for each country
for(property in continents){
  var newEl = document.createElement('button');
  newEl.innerText = property;
  newEl.setAttribute('data-name', property);
  buttons.appendChild(newEl);
}
// when you click a button setPieChart and setActiveClass
  buttons.addEventListener('click', function(e){
    if(e.target != e.currentTarget){
      var el = e.target,
          name = el.getAttribute('data-name');
      setPieChart(name);
      setActiveClass(el);
    }
    e.stopPropagation();
  });
var setPieChart = function(name){
  var number = continents[name],
      fixedNumber = numberFixer(number),
      result = fixedNumber + ' ' + total;
  
  pie.style.strokeDasharray = result;
}
var setActiveClass = function(el) {
  for(var i = 0; i < buttons.children.length; i++) {
    buttons.children[i].classList.remove(activeClass);
    el.classList.add(activeClass);
  }
}
// Set up default settings
setPieChart('asia');
setActiveClass(buttons.children[0]);
</script>
<style>
$primaryColor: #0074d9;
circle {
  fill: #ddd;
  stroke: $primaryColor;
  stroke-width: 50;
  stroke-dasharray: 0 158;
  transition: stroke-dasharray .3s ease;
}
svg {
  margin: 0 auto;
  transform: rotate(-90deg);
  background: #ddd;
  border-radius: 50%;
  display: block;
}
.buttons {
  margin-bottom: 30px;
}
button {
  text-transform: capitalize;
  font-size: 13px;
  cursor: pointer;
  -webkit-appearance: none;
  border: none;
  margin-right: 5px;
  background-color: transparent;
  padding: 5px 10px;
  outline: none;
  border-radius: 2px;
  transition: background-color .1s ease, color .2s ease;
  &:last-of-type {
    margin-right: 0;
  }
  &.active {
    font-weight: 400;
    background-color: $primaryColor;
    color: white;
  }
}
figcaption {
  margin-bottom: 20px;
  font-size: 22px;
  font-weight: bold;
  text-align: center;
}
body {
  display: flex;
  justify-content: center;
  align-items: center;
  flex-direction: column;
  font-family: 'Open Sans', sans-serif;
}
body, html {
  height: 100%;
}
</style>
</div>