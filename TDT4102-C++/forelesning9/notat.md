---
title: Forelesning 9 - Memory
author: TDT4102
date: \today
geometry: margin=25mm
---

## stack vs. heap

- stack:
  - mindre plass i minnet (1-8 MB)
  - minne allokeres og deallokeres dynamisk
    - deallokeres i slutten av skopet
- heap:
  - kan bruke hele minnet
  - må allokere og deallokere minne manuelt
  - `new` allokoerer minne i heap
  - `delete` deallokerer minne i heap
  - bedre metode:
    - `unique_ptr` er en smart pointer som deallokerer minne automatisk
  
## destructor

- motsatte av en konstruktør (constructor)
- kalles når objektet blir slettet

## how to avoid C-pointers 101

- bruk `unique_ptr` for unike pekere
- eller `shared_ptr` for pereke som skal deles mellom objekter

## memory ownership

- `unique_ptr`:
  - en peker som peker til et objekt
  - objektet blir slettet når pekeren blir slettet
  - pekeren blir slettet når objektet blir slettet
- `shared_ptr`:
  - en peker som peker til et objekt
  - objektet blir slettet når det ikke er flere pekere til objektet
  - pekeren blir slettet når objektet blir slettet
