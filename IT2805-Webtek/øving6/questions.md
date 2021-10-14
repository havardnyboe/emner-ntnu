# Questions

1. Fordi JavaScript ikke regner med desimaltall slik vi gjør, men heller med binæretall.
   I konverteringen mellom tallsystemene skjer det en avrunningsfeil og regnestykke blir derfor ikke helt riktig.
   Det blir det samme som at $0.3 + 0.3 + 0.3 = 0.9$ mens ${1\over3} + {1\over3} + {1\over3} = 1$
1. `method` stributtet bestemmer hvordan skjemaet skal sende data.  
   `GET` sender form dataen som URL variabler, og `POST` sender dataen via en HTML post transaction og viser ikke dataen i URL-en.
1. Skjema dataen dukker opp i URL-en når method er get for at man skal kunne bruke URL-en til å hente og bruke dataen.
1. Fordi enkelte nettlesere støtter ikke alltid JavaScript eller HTML5 og skjemaet vil derfor ikke fungere i de nettleserene.
1. Man skal bruke `textarea` i stedet for `input` hvis brukeren skal skrive inn mye teskt for eksempel hvis de skal skrive en beskrivelse.
