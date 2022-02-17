---
title: Forelesning 8 - Pointers and References
author: TDT4102
date: \today
geometry: margin=25mm
---

## memory

- Når et program starter får det en `stack`
- Når det trenger mer minne kan den allokere `heaps`
- operativsystemet refererer til minneadresser
- minneadresser er bare tall

## pointers

- deklareres med f.eks. 
```c++ 
    int* ptrToInt
```
- deallocating form the `heap` bruk `delete` for å frigjøre minne etter bruk