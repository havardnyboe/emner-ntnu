---
title: Forelensing 7
author: TDT4102
date: \today
geometry: margin=25mm
---

## arv av klasser

- bruk `statick_cast<>()` til å oversette mellom datatyper (klasser)
  - kan bare oversette fra `child` til `parent`, ikke motsatt
- kopierer kun medlemsvariabler arvet fra `parent`

## virtuelle funksjoner

- keyword - `virtual` 
- fungerer kun med referanser
- "Pure `virtual` function" kan ikke kalles slik som en vanlig funksjon

## abstrakt klasse

- har minst en pure virtual function
- kan ikke lage en instanse av denne klassen, kan bare arve fra den

## friend

- keyword - `friend`
- gir tilgang til `private` eller `protected` medlems-variabler og funksjoner
- nyttig til operator overloading
- kan spesifisere enkelt funksjoner som skal være `friend`
- må deklareres innen for klassen

## constructor

- `child` må bruke bruke konstruktører til `parent`
- kan definere flere konstruktører for samme objekt

## `std::pair`

- en `struct` som inneholder to felt som kan ha ulike datatyper
- nyttig i feks histogram

## `auto`

- finn ut data type automatisk
- bruk i feks for-loop med flere datatyper, ref `std::pair`

## `std::map` & `std::unordered_map`

- 