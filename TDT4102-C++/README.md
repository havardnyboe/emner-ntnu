# TDT4102 - Prosedyre- og objektorientert programmering

# Øvinger

- [x] [Øving 0](øving0)
- [x] [Øving 1](øving1)
- [x] [Øving 2](øving2)
- [x] [Øving 3](øving3)
- [x] [Øving 4](øving4)
- [x] [Øving 5](øving5)
- [ ] [Øving 6](øving6)
- [ ] [Øving 7](øving7)
- [ ] [Øving 8](øving8)


# Notater

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