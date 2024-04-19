---
title: Refleksjonsnotat ERT 4-5
author: Håvard Solberg Nybøe
date: \today
geometry: margin=30mm
colorlinks: true
graphics: true
---

Hensikten med **refleksjonsnotatet** og den påfølgende **oppfølgingssamtalen** er å reflektere over egen læring og få god veiledning fra læringsassistentene. Det blir ikke satt karakter.

## Hva har du lært denne uka?

Denne uka har jeg lært om NMOS og PMOS transistorer og hvordan de fungerer, og settes sammen til å lage grunnleggende logiske porter.
Jeg har også lært om grunnleggende logikk og boolsk algebra.

## Tre på topp fra ERT-4

1. Kretssymbolet til en NMOS-transistor ser slik ut:

\includegraphics[width=0.2\textwidth]{../img/uke4/NMOS.png}

For at en NMOS-transistor skal lede strøm må det gå en spenning i tilkoblingspunkt G. Det går strøm gjennom alle tilkoblingspunktene i en NMOS-transistor, men det er bare strømmen fra D som går videre til S, G styrer hvor mye strøm som går fra D til S. Jeg ville koblet opp en NMOS-transistor ved å koble D til en spenningskilde, S til jord og G til en variabel spenningskilde, for eksempel via et potentiometer. Dette fordi jeg da kan styre hvor mye strøm som går fra D til S ved å justere spenningen på G.

2. Kretssymbolet til en PMOS-transistor ser slik ut:

\includegraphics[width=0.2\textwidth]{../img/uke4/PMOS.png}

For at en PMOS-transistor skal lede strøm må det som i NMOS-transistoren gå en spenning i tilkoblingspunktet G. Forskjellen mellom en PMOS og en NMOS transistor er at PMOS transistoren gir motstatt verdi av strømmen som kommer inn. Altså hvis det for eksempel kommer 10mA inn i D, vil S gi ut -10mA.

3. Totempælen er en sammenkobling av en NMOS og en PMOS transistor og ser slik ut:

\includegraphics[width=0.2\textwidth]{../img/uke4/totempæl.png}

Så lenge totempælen har en spenning i $V_DD$ og er koblet til jord vil den lede strøm, når spenningen i $v_A$ er lav. Når spenningen i $v_A$ er høy vil totempælen ikke lede strøm.

## Tre på topp fra ERT-5

1. Logiske porter er grunnleggende logiske kretser som tar inn en eller flere logiske verdier og gir ut en logisk verdi. De mest grunnleggende logiske portene er OG, ELLER og IKKE. OG tar inn to logiske verdier og gir ut en logisk verdi som er sann hvis begge de logiske verdiene som kommer inn er sanne. ELLER tar inn to logiske verdier og gir ut en logisk verdi som er sann hvis en eller begge de logiske verdiene som kommer inn er sanne. IKKE tar inn en logisk verdi og gir ut en logisk verdi som er sann hvis den logiske verdien som kommer inn er usann, og usann hvis den logiske verdien som kommer inn er sann. Portene kan brukes til å lage logiske kretser og elektroniske komponenter.

1. En sannehetstabell er en tabell som viser alle mulige kombinasjoner av logiske verdier som kan komme inn i en logisk port, og hva den logiske porten vil gi ut for hver kombinasjon. For eksempel vil en sannehetstabell for en ELLER-port se slik ut:

| A   | B   | A ELLER B |
| --- | --- | --------- |
| 0   | 0   | 0         |
| 0   | 1   | 1         |
| 1   | 0   | 1         |
| 1   | 1   | 1         |

3. En inverter er en logisk port (IKKE-porten), som tar inn en logisk verdi og gir ut den inverse logiske verdien. For eksempel vil en inverter gi ut 1 hvis den får inn 0, og 0 hvis den får inn 1.

## Legg ved bilde av kretsene dine fra uken her

\includegraphics[width=\textwidth]{../img/uke4/krets1.jpeg}

## Hvor langt (hvilken oppgave) kom du i løpet av fredagen?

Oppgave 4

## Hva lurer jeg på?

Ikke noe spesielt denne uka.
