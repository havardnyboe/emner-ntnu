---
title: Forelesning 6 - Objektorientering
author: TDT4102
date: \today
geometry: margin=25mm
---

## Hva er prosedyreorientering

- funksjoner kaller andre funksjoner
- variabler sendes og fordeles gjennom funksjons-parametere og retur-verdier
- funksjonene er et abstraksjonslag

## Hva er objektorientering

- `public` og `private` funksjoner
- `struct` vs. `class`
  - `struct` public by default
  - `class` private by default
- variabler sendes og fordeles gjennom objekter
- objekter er et abstraksjonslag

## inheritance (arving av klasser)

- "kopierer" kode fra en klasse til en annen
  ```c++
    class Ball : public MouseFollower {};
    // Ball klassen arver innhold fra MouseFOllower
  ```
- `protected`
- kan overskrive funksjoner som er arvet fra andre klasser
- brukes til å lage et hierarki av klasser

## Hva er forskjellen (i C++)


|       | Objektorientering           |       | Prosedyreorientering       |
| :---: | --------------------------- | :---: | -------------------------- |
|  (+)  | hiding of state (variables) | (+-)  | state is not hidden        |
|  (+)  | abstraction                 | (+-)  | harder to abstract         |
|  (+)  | reuse through inheritance   | (+-)  | reuse functions explicitly |
|  (-)  | performance                 |  (+)  | performance                |

## operator overload

- definere en spesiell funksjon for en operator for udefinerte datatyper
  - f.eks definere at vektorer (fra matematikken) kan legges sammen og skrives ut til terminalen 