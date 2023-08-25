---
title: fuzzy search
categories: 
tags: 
date: 2023-08-21
---

## fuzzysort

- [fuzzysort](https://github.com/farzher/fuzzysort)

common usage:

```js
const mystuff = [{file:'Monitor.cpp'}, {file:'MeshRenderer.cpp'}]
const results = fuzzysort.go('mr', mystuff, {key:'file'})
// [{score:-18, obj:{file:'MeshRenderer.cpp'}}, {score:-6009, obj:{file:'Monitor.cpp'}}]
```

![fuzzysort](https://camo.githubusercontent.com/304845af3f126233b14638053ee89b7b303e2f348b1bd21cf4acade2b03c4ae1/68747470733a2f2f692e696d6775722e636f6d2f5448625130386e2e676966)