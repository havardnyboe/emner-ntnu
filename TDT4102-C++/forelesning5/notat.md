---
title: Forelesning 5
author: TDT4102
date: \today
geometry: margin=25mm
---

## inkludering av filer

- Ikke inkluder `.cpp` men heller header filer `.h`

## `c++std::vector` vs. `c++std::array`

- `c++std::vector` dynamic length
- `c++std::array` fixed length

## enumirations `enum`

- begrensinger av verdier
- istedet for `true`eller `false`
- god kombinasjon med switch cases
```c++
    enum class CoffeeType {
        DARK, CAPPUCCINO, ESPRESSO
    };

    void prepareCoffee(CoffeeType coffeeType) {
        switch(coffeeType) {
            case CoffeeType::DARK:
                prepareDarkCoffee();
                break;
            case CoffeeType::CAPPUCCINO:
                prepareDarkCoffee();
                break;
            case CoffeeType::ESPRESSO:
                prepareDarkCoffee();
                break;
        }
    }
```

\newpage
## error behandling

- **assert**
  - stopper programmet med en gang hvis utsagn er `false`
  
- **exceptions**
  - `throw` "kaster" feilmelding ut
  - `try` tester ut en funksjon
  - `catch` "fanger" feilmeldingen som ble kastet
```c++
    void func() {
        if (!statement) {
            throw error;
        }
    }

    try{
        func();
    } catch(error) {
        /* behandle error*/
    }
```

## scope

- definerer hvor variabler er definert i koden
- lages med `{}`
```c++
    { // starten på scope

    } // slutten på scope
```
