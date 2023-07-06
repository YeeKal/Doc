---
title: markdown advanced tutorial
categories: note
tags: tool
date: 2023-01-10
---
## useful tools

- [List_of_LaTeX_mathematical_symbols](https://oeis.org/wiki/List_of_LaTeX_mathematical_symbols)


## block

<font color=#4cd137>██████</font>
<font color=#4cd137>░</font>

░░░░░░░░
░

- [unicode block](https://www.compart.com/en/unicode/block/U+2580)

## use html

```html
<font face="宋体">宋体</font>
<font face="楷书">楷书</font>
<font face="草书">草书</font>
<font face="隶书">隶书</font>
<font face="行书">行书</font>
<font face="黑体">黑体</font>
<font face="仿宋">仿宋</font>
<font face="篆书">篆书</font>
<font face="仿宋_GB2312">仿宋_GB2312</font>
<font face="微软雅黑">微软雅黑</font>
<font face="Times New Roman">Times New Roman</font>
```


<font color='Tomato'>Convex combination, Convex hull </font>

<font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>haha</font>


## Hide-show content

<details>
<summary>title of the content (*not* support **markdown** syntax ~~hmm~~)</summary>
content body (support **markdown** syntax ~~hmm~~)
```json
{
  support: "codeblock to"
}
​```

</details>


## Combining italic, bold, superscript, subscript, and/or strikethrough

italic-bold -> __*“ ssss”*__

superscript -> Starwars<sup>TM</sup>

superscript-italic -> Starwars<sup>*tm*</sup>

subscript -> F<sub>x</sub>

subscript-bold -> Limit<sub>**min**</sub>

italic-bold-strikethrough -> ~~__*“ ssss”*__~~

## Quote long sentence

> hjhfjsdfjkdsf
>> jdfjdkkjdkg

## inline svg

<svg fill="none" viewBox="0 0 800 400" width="800" height="400" xmlns="http://www.w3.org/2000/svg">
	<foreignObject width="100%" height="100%">
		<div xmlns="http://www.w3.org/1999/xhtml">
			<style>
				@keyframes rotate {
					0% {
						transform: rotate(3deg);
					}
					100% {
						transform: rotate(-3deg);
					}
				}
				@keyframes gradientBackground {
					0% {
						background-position: 0% 50%;
					}
					50% {
						background-position: 100% 50%;
					}
					100% {
						background-position: 0% 50%;
					}
				}
				@keyframes fadeIn {
					0% {
						opacity: 0;
					}
					66% {
						opacity: 0;
					}
					100% {
						opacity: 1;
					}
				}
				.container {
					font-family:
						system-ui,
						-apple-system,
						'Segoe UI',
						Roboto,
						Helvetica,
						Arial,
						sans-serif,
						'Apple Color Emoji',
						'Segoe UI Emoji';
					display: flex;
					flex-direction: column;
					align-items: center;
					justify-content: center;
					margin: 0;
					width: 100%;
					height: 400px;
					background: linear-gradient(-45deg, #fc5c7d, #6a82fb, #05dfd7);
					background-size: 600% 400%;
					animation: gradientBackground 10s ease infinite;
					border-radius: 10px;
					color: white;
					text-align: center;
				}
				h1 {
					font-size: 50px;
					line-height: 1.3;
					letter-spacing: 5px;
					text-transform: uppercase;
					text-shadow:
						0 1px 0 #efefef,
						0 2px 0 #efefef,
						0 3px 0 #efefef,
						0 4px 0 #efefef,
						0 12px 5px rgba(0, 0, 0, 0.1);
					animation: rotate ease-in-out 1s infinite alternate;
				}
				p {
					font-size: 20px;
					text-shadow: 0 1px 0 #efefef;
					animation: 5s ease 0s normal forwards 1 fadeIn;
				}
			</style>
			<div class="container">
				<h1>Made with HTML &amp; CSS<br/>not an animated GIF</h1>
				<p>Click to see the source</p>
			</div>
		</div>
	</foreignObject>
</svg>

## script and iframe

Using `<script>` tag
<script src="https://gist.github.com/DrSensor/2b45a6eb516b6b8084a4866d10699113.js"></script>

---
Using `<iframe>` tag
<iframe src="https://codesandbox.io/embed/6zk98l6w0k" style="width:100%; height:500px; border:0; border-radius: 4px; overflow:hidden;" sandbox="allow-modals allow-forms allow-popups allow-scripts allow-same-origin"></iframe>

## footnotes

Here is a simple footnote[^1]. With some additional text after it. head[^head]


## file tree

# Code & components for pages

'''
./src/* 
  ├─ src/assets - # Minified images, fonts, icon files
  ├─ src/components - # Individual smaller components
  ├─ src/fragments - # Larger chunks of a page composed of multiple components
  ├─ src/layouts - # Page layouts used for different types of pages composed of components and fragments
  ├─ src/page - # Custom pages or pages composed of layouts with hardcoded data components, fragments, & layouts
  ├─ src/pages/* - # Next.js file based routing
  │  ├─ _app.js - # next.js app entry point
  │  ├─ _document.js - # next.js document wrapper
  │  ├─ global.css - #  Global CSS styles
  │  └─ Everything else... - # File based routing
  └─ src/utils - # Utility functions used in various places
'''

[![CI](https://github.com/fastify/fastify/workflows/ci/badge.svg)](https://github.com/fastify/fastify/actions/workflows/ci.yml)
[![Package Manager CI](https://github.com/fastify/fastify/workflows/package-manager-ci/badge.svg)](https://github.com/fastify/fastify/actions/workflows/package-manager-ci.yml)
[![Web SIte](https://github.com/fastify/fastify/workflows/website/badge.svg)](https://github.com/fastify/fastify/actions/workflows/website.yml)
[![Known Vulnerabilities](https://snyk.io/test/github/fastify/fastify/badge.svg)](https://snyk.io/test/github/fastify/fastify)
[![Coverage Status](https://coveralls.io/repos/github/fastify/fastify/badge.svg?branch=main)](https://coveralls.io/github/fastify/fastify?branch=main)
[![js-standard-style](https://img.shields.io/badge/code%20style-standard-brightgreen.svg?style=flat)](https://standardjs.com/)
[![CI](https://github.com/fastify/fastify/workflows/ci/badge.svg)](https://github.com/fastify/fastify/actions/workflows/ci.yml)

## footnotes

[^1]: My reference.
[^head]: jkajf

## Snippets for Markdown

```json
{
	"head":{
		"prefix": "head",
		"body": [
			"---",
			"title: $1",
			"categories: $2",
			"tags: $3",
			"date: $CURRENT_YEAR-$CURRENT_MONTH-$CURRENT_DATE",
			"---"
		],
		"description": " head "
	},
	"date":{
		"prefix": "date",
		"body": [
			"$CURRENT_YEAR-$CURRENT_MONTH-$CURRENT_DATE"
		],
		"description": "date"
	},
	"latex inline": {
		"prefix": "lai",
		"body": [
			"\\$$1\\$"
		],
		"description": "```latex inline```"
	},
	"latex outline": {
		"prefix": "lao",
		"body": [
			"\\$\\$$1\\$\\$"
		],
		"description": "```latex inline```"
	},
	"```python": {
		"prefix": "```py",
		"body": [
			"```python\n$1\n```"
		],
		"description": "```python```"
	},
	
	"`cp": {
		"prefix": "```cpp",
		"body": [
			"```cpp\n$1\n```"
		],
		"description": "```cpp```"
	},

  
	"ftr": {
		"prefix": "fontred",
		"body": [
			"<font color=#e84118>$1</font>", "$2"
		],
		"description": "<font color=red></font>"
	},
  
	"ftb": {
		"prefix": "fontblue",
		"body": [
			"<font color=#00a8ff>$1</font>", "$2"
		],
		"description": "<font color=blue></font>"
	},
  
	"ftg": {
		"prefix": "fontgreen",
		"body": [
			"<font color=#4cd137>$1</font>", "$2"
		],
		"description": "<font color=green></font>"
	},
		"latex-align": {
		"prefix": "align",
		"body": [
			"$$\\begin{aligned}",
			"$1",
			"\\end{alined}$$"
		],
		"description": "latex-align"
	},
	"color": {
		"prefix": "color",
		"body": [
			"<font color='Tomato'>$1</font>"
		],
		"description": "font color"
	},
		"note": {
		"prefix": "note",
		"body": [
			"<font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>$1</font>"
		],
		"description": "green background"
	}

}
```