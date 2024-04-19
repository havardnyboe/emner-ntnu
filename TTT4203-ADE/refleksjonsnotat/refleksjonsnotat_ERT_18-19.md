---
title: Refleksjonsnotat ERT 18-19
author: Håvard Solberg Nybøe
date: \today
geometry: margin=30mm
colorlinks: true
graphics: true
---

Hensikten med **refleksjonsnotatet** og den påfølgende **oppfølgingssamtalen** er å reflektere over egen læring og få god veiledning fra læringsassistentene. Det blir ikke satt karakter.

## Hva har du lært denne uka?

Denne uken har jeg lært om klokkesignaler og hvordan D-vippen bruker denne til å sette verdier. Jeg har også lært om kondensatorer og spoler og hva disse kan brukes til.

## Tre på topp fra ERT-18

1. At er system er synkront betyr at det er synkronisert ved hjelp av et klokkesignal. Sammenliknet med et kombinatorisk system er et synkront system avhengig av tilstanden til kretsen før klokkesignalet, mens det kombinatoriske systemet kun avhenger av den nåværende tilstanden. Fordelen med et synkront system er at det gir forutsigbarhet og konsistens i kretsen og at det tillater sekvensiell logikk.
2. Trekantsymbolet ved inngangen hvor klokken kobles til representerer en buffer eller en forsterker. Dette symbolet indikerer at inngangen er følsom for signalets overgang, enten det er en stigende eller synkende kant. For at utgangen Q skal bli lik inngangen D må det komme en klokkepuls. Ved den stigende kanten av klokkepulsen, vil verdien på D-inngangen bli overført til Q-utgangen. Hensikten clock enable og reset er å gi mer kontroll over operasjonene til D-vippen. Clock enable gjør det mulig å bestemme når D-vippen skal reagere på klokkesignalet, og reset gjør det mulig å sette Q-utgangen feks 0 uavhengig av D-inngangen og klokkesignalet.
3. Når en teller oppnår sin maksimale utgangsverdi, vil den vanligvis "rulle over" til sin minimale verdi. Dette kalles også for en “overflow”-tilstand. En teller kan være enten synkron, kombinatorisk, eller en kombinasjon avhengig av hvordan den er laget. For eksempel i en synkron teller er alle flip-flops klokket sammen, mens i en asynkron teller er utgangen fra en flip-flop brukt som klokkeinngang til den neste. I blandet modus kan noen deler av systemet være synkrone, mens andre deler er kombinatoriske.

## Tre på topp fra ERT-19

1. Når kondensatorer kobles i serie, reduseres den totale kapasitansen. Dette skyldes at det effektive området mellom kondensatorens plater reduseres. Når kondensatorer kobles i parallell, øker den totale kapasitansen fordi det effektive området mellom platene øker. Ved likespenning oppfører kondensatoren seg som en åpen krets. Ved vekslende spenning lades og utlades kondensatoren i takt med spenningen. Når en motstand er koblet i serie med en kondensator dannes en RC-krets. Da vil ladningen av kondensatoren og strømmen gjennom kretsen være en funksjon av tid. Strømmen i kretsen blir bestemt av resistansen som er koplet i serie med kondensatoren.
2. Når en spole kobles i serie øker den totale induktansen. Når spoler kobles i parallell, reduseres den totale induktansen. Ved likespenning vil en spole ha null motstand og motstanden øker med økende frekvens. Ved vekslende spenning vil spolen motsette seg endringer i strømmen gjennom den. Når en motstand er koblet i serie med en spole dannes en RL-krets. Da vil strømmen gjennom kretsen være en funksjon av tid. Strømmen i kretsen blir bestemt av resistansen som er koplet i serie med spolen.
3. Ved oppladning og utladning av en kondensator varierer strøm og spenning. Strømmen i en kondensator er gitt av hvor raskt spenningen varierer ganger kapasitansen. For en spole, når strømmen i en spole blir forsøkt endret, vil magnetfeltet i spolen endre seg og dette setter opp en motspenning som hindrer strømmen i å øke så raskt som den normalt ville ha gjort. Tiden det tar for en kondensator eller en spole å lade opp eller utlade er avhengig av størrelsen på komponentene (kapasitans for kondensatorer og induktans for spoler) og motstanden i kretsen.
