---
title: Refleksjonsnotat ERT 16-17
author: Håvard Solberg Nybøe
date: \today
geometry: margin=30mm
colorlinks: true
graphics: true
---

Hensikten med **refleksjonsnotatet** og den påfølgende **oppfølgingssamtalen** er å reflektere over egen læring og få god veiledning fra læringsassistentene. Det blir ikke satt karakter.

## Hva har du lært denne uka?

Denne uken har jeg lært om operasjonsforsterkere (opamp) og hva denne er og gjør. Jeg har også lært om RAM-minneceller og hvordan en adressedekoder virker med disse.

## Tre på topp fra ERT-16

1. Opampens gyldne regler refererer til to viktige egenskaper ved operasjonsforsterkere: ideelle innganger og null strøm inn eller ut. Det er nyttig å vite at det ikke går strøm inn eller ut av opampens innganger fordi det forenkler analyse av kretser og tillater oss å anta at inngangene er i en tilstand av virtuell kortslutning. Dette gjør det lettere å analysere kretser og finne løsninger. Inngangene til en opamp er inverterende inngang (-) og ikke-inverterende inngang (+). Det er nyttig å anta at differansen mellom inngangene er lik 0 i det lineære området fordi det forenkler analysen av kretser og tillater oss å bruke ideelle egenskaper ved opampen for å oppnå ønsket funksjonalitet. Spenningsforskjellen mellom inngangene er ikke alltid null på grunn av drift og små forskjeller i komponenter.

2. En inverterende forsterker produserer en utgangsspenning som er invertert i forhold til inngangssignalet. En ikke-inverterende forsterker produserer en utgangsspenning som er i fase med inngangssignalet. En vanlig inverterende forsterkerkrets bruker en negativ tilbakekobling, mens en ikke-inverterende forsterkerkrets bruker positiv tilbakekobling. Fordelene med en inverterende forsterker inkluderer muligheten til å oppnå både positive og negative forsterkninger, samt lavere inngangsimpedans. Et eksempel på en inverterende forsterkerkrets er en klassisk inverterende forsterker med en enkelt operasjonsforsterker.

3. En addisjonskrets er en krets som legger til eller summerer flere inngangssignaler for å produsere en enkelt utgangsspenning. I denne kretsen blir spenningene på de forskjellige inngangene matet inn i motstander som er koblet sammen på en slik måte at de summerte spenningene blir produsert på utgangen. Addisjonskretsen er nyttig i applikasjoner der flere signaler må kombineres eller summeres, for eksempel i signalbehandling eller instrumentering. Forskjellene og likhetene mellom addisjonskretsen i figur 4 og en annen addisjonskrets kan variere avhengig av konfigurasjonen og formålet med kretsene. Typisk er de begge designet for å legge til flere inngangssignaler, men de kan ha ulike tilpasninger basert på spesifikke krav og applikasjoner.

## Tre på topp fra ERT-17

1. En adressedekoder brukes sammen med en RAM-minnecelle for å velge den riktige minnecellen basert på en gitt adresse. Adressedekoderen tar en adresse som inngang og velger den tilsvarende minnecellen som skal leses fra eller skrives til. En RAM-minnecelle er en minste enhet i minnet som kan lagre en bit med informasjon (0 eller 1). RAM brukes til å midlertidig lagre data og instruksjoner som trengs for øyeblikkelig tilgang av en datamaskin eller annen digital enhet. To invertere koblet sammen danner en minnecelle fordi de danner en flip-flop-konfigurasjon som kan lagre en bit informasjon.

2. En oppslagstabell er en tabell som inneholder inngangs- og utgangsverdier for en kombinatorisk krets. Den gir en direkte sammenheng mellom inngangs- og utgangsverdiene til kretsen. Enkle porter som ELLER- og OG-porter kan lages ved å bruke en oppslagstabell ved å definere sannhetstabellen for porten i tabellen. Fordelen med å implementere kombinatorisk logikk som en paritetsbitgenerator ved bruk av oppslagstabell-metoden er at det gir en enkel og fleksibel måte å designe logiske funksjoner på. Det kan være mer oversiktlig og enklere å endre funksjonaliteten til kretsen ved å endre oppslagstabellen, sammenlignet med å lage kretsen med logiske porter.

3. Svitsj-modellen med motstander er nyttig for å modellere oppførselen til MOSFET-transistorer mer nøyaktig. Motstandene i svitsj-modellen representerer intern motstand og kan påvirke responsen og hastigheten til transistorer i en krets. Motstanden i svitsj-modellen kan påvirke driverens evne til å endre innholdet i minnecellen ved å regulere strømmen som strømmer gjennom transistoren. Hvis vi brukte svitsj-modellen uten motstander, ville driverens evne til å endre innholdet i minnecellen være begrenset, og responsen til kretsen kunne være unøyaktig eller langsom. Motstandene bidrar til å kontrollere strøm- og spenningsnivåer og sikrer riktig funksjon av kretsen.
