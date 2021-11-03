---
title: Questions
author: Håvard Nybøe
date: \today
geometry: margin=25mm
---


1. Man kan få en tre-dimensjonell context ved å bytte ut `2d` med `webgl` eks: 
```js 
    let ctx = document.getContext('webgl')
```
2. 
```js
    ctx.beginPath()
    ctx.arc(100,100,50,0,2*Math.PI) // tegner en bue på x=100, y=100, r=50, 
                                    // starter med vinkel 0, slutter med vinkel 2*Math.PI
    ctx.fillStyle = 'blue'          // velger farge        
    ctx.fill()                      // fyller den blå
    ctx.stroke()                    // tegner den
```
3. 
```js
    const countries = ['Norway', 'Sweden', 'Denmark', 'New Zealand'];
    const countriesStartingWithN = countries.filter(country => country.startsWith('N'));
```