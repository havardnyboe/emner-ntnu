---
title: Refleksjonsnotat ERT 8-9
author: Håvard Solberg Nybøe
date: \today
geometry: margin=30mm
colorlinks: true
graphics: true
---

Hensikten med **refleksjonsnotatet** og den påfølgende **oppfølgingssamtalen** er å reflektere over egen læring og få god veiledning fra læringsassistentene. Det blir ikke satt karakter.

## Hva har du lært denne uka?

Denne uka har jeg lært om binær-addisjon og toerkomplement. Jeg har også lært om

## Tre på topp fra ERT-8

1. Binær-addisjon fungerer på samme måte som desimal-addisjon og har samme regneregler. Eneste forskjellen er at på grunn av at vi bruker to-tallsystemet vil tallene ha færre siffer, men til gjengjeld være lengre. Men dette har ingen praktisk betydning for regneoperasjonene. Man er til en viss grad begrenset av antall bits man regner med. Hvis addereren feks ikke har plass til mer enn 8 bits, vil det være umulig å regne med tall større enn 255.

1. Toerkomplement er en metode for å representere negative tall i binærsystemet. Det funger ved at man ført bruker det tilsvarende positive tallet, og så inverterer alle bitene og legger til 1. Den første biten vil da i praksis representere fortegnet, 1 for negativt og 0 for positivt, og man kan regne ut resten av tallet som om det var positivt. Toerkomplement er praktisk å bruke fordi det gjør det enkelt å utføre regneoperasjoner på negative tall og unngår situasjonen hvor 0 har to representasjoner, en positiv og en negativ. Dette hadde vært tilfelle hvis man bare brukte første bit som fortegn. Man vet hvor mange bits man skal regne med fordi første bit alltid representerer fortegnet, og antall bits vil derfor være $\lfloor \log_2 n \rfloor + 1$, der $n$ er desimaltallet man skal representere i toerkomplement.

1. Vanlige binære adderere er laget for å kun addere spenninger som enten er logisk høy eller lav. Det er mulig å lage en adderer som kan addere basert på ulike spenningsnivåer, og dette kan være nyttig hvis man ønsker å minimere antall transistorer man skal bruke. Hvis en adderes tar inn tre 1-ere, vil summen bli 1 og den vil "miste" en 1-er fra mente.

## Tre på topp fra ERT-9

1. Superposisjonsprinsippet kan være nyttig for lineære kretser. Det tillater oss å analysere kretsens respons ved å vurdere strøm og spenning fra hver spenningskilde hver for seg. Superposisjonsprinsippet er vanligvis ikke brukbart i kretser med dioder eller andre ikke-lineære komponenter. Bidraget til en spennings- eller strømkilde refererer til den effekten den har på en elektrisk krets. Det er hvordan hver kilde påvirker kretsens oppførsel individuelt. Superposisjonsprinsippet gjelder for kretser med både spennings- og strømkilder samtidig, forutsatt at kretsen er lineær.

1. Å nullstille en spenningskilde betyr å sette spenningen den leverer til 0 volt, altså å skru den av eller koble den fra kretsen. Dette kan være nødvendig for å simulere ulike kretsscenarier eller for å analysere kretsens oppførsel under forskjellige forhold. Når en spenningskilde er avskrudd, tilsvarer det en åpen krets, der det ikke går strøm gjennom kilden og det heller ikke ligger noen spenning over den.

1. Å nullstille en strømkilde betyr å redusere strømmen den leverer til 0 ampere, altså å skru den av eller bryte kretsen den er koblet til. Dette kan være nødvendig for å simulere ulike kretssituasjoner eller for å analysere kretsens respons under forskjellige forhold. Når en strømkilde er avskrudd, tilsvarer det en krets med en åpen krets, der det ikke går strøm fra kilden. Selv om strømkilden er av, kan det fortsatt være spenning over den avhengig av kretsens konfigurasjon og andre komponenter.

## Legg ved bilde av kretsene dine fra uken her

Ingen kretser denne uken.

## Hvor langt (hvilken oppgave) kom du i løpet av fredagen?

Oppgave 5
