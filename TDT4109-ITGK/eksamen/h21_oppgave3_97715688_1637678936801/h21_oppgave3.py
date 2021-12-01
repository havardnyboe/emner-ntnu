# Denne koden er til hjelp for deg, slik at du slipper å skrive alt selv.
# Oppgaveteksten som er her er ikke garantert å være helt korrekt, du står
# selv ansvarlig for å sjekke den korrekte oppgaveteksten i Inspera.

'''
Du skal nå lage et program for en dagligvarebutikk. Programmet holder styr på lager, håndterer oppdatering av
lager og salg. Dataen lagres i fil når butikken stenger, og leses fra fil når butikken åpnes. Butikken kan
også generere middagsforslag til en gitt pris. Oppgaven baserer seg på strukturene matvarer og beholdning.
Du kan alltid anta at du har fått til tidligere oppgaver, og bruke disse i koden din.

'matvarer' er en todimensjonal liste med følgende struktur:
[[navn, pris, rett],[navn2, pris2, rett2], ...]
Hver innerliste inneholder en string 'navn', et heltall 'pris' og en string 'rett' for en matvare.
'''
matvarer = [['laks', 59, 'middag'], ['kjøttdeig', 25, 'middag'],
            ['ris', 15, 'middag'], ['ost', 99, 'frokost'], ['bønner', 7, 'middag'],
            ['soyasaus', 33, 'middag'],['banan', 4, 'mellommåltid']]
'''
'beholdning' er en dictionary med følgende struktur:
{navn:antall, navn2:antall2, ...}
Hver nøkkel er en string 'navn', og hver verdi er et heltall 'antall' som beskriver hvor mange av
den spesifikke varen som er på lager.
Du kan anta at alle varer som finnes i beholdning også finnes som en vare i matvarer. Andre
eventuelle antagelser må skrives i din besvarelse.
'''
beholdning = {'laks': 6, 'kjøttdeig': 14, 'ris': 15, 'ost': 9, 'bønner': 6, 'soyasaus': 0, 'banan': 1}

'''
Tallene i eksemplene til oppgavene forutsetter at man har fått til tidligere oppgaver.
'''


# Oppgave 3.1 - finn_pris(matvarer, let_etter)
'''
Vi trenger å finne prisen på matvarene i butikken.
Skriv funksjonen finn_pris(matvarer, let_etter):
- Du skal finne prisen til en bestemt matvare, gitt av parameteret 'let_etter' i den todimensjonale listen 'matvarer'.
- Hvis let_etter ikke finnes i matvarer skal funksjonen returnere 0, ellers skal prisen på matvaren returneres.
Parametre:
- 'matvarer' er den todimensjonale listen som beskrevet i starten av oppgave 3.
- 'let_etter' er en streng som inneholder matvaren som det letes etter.

Eksempel:
>>> print(finn_pris(matvarer, 'ost'))
99
>>> print(finn_pris(matvarer, 'finnesikke'))
0
'''
# SKRIV KODEN DIN HER:
def finn_pris(matvarer, let_etter):
    for matvare in matvarer:
        if matvare[0] == let_etter:
            return matvare[1]
    return 0




# print(finn_pris(matvarer, 'ost'))
# print(finn_pris(matvarer, 'finnesikke'))
# print(finn_pris(matvarer, 'laks'))
# print(finn_pris(matvarer, 'lakks'))
# print(finn_pris(matvarer, 'middag'))

# Oppgave 3.2 - oppdater_matvare(beholdning, matvare, antall)
'''
Butikken har behov for å kunne oppdatere en og en vare i beholdningen.
Skriv funksjonen oppdater_matvare(beholdning, matvare, antall):
- hvis 'antall' har en negativ verdi skal beholdningen gå med med tilsvarende mengde.
- du kan anta at alle matvarer man får inn som parametre allerede eksisterer.
- du kan anta at du ikke får en oppdatering som gir en negativ beholdning av en matvare.
- returner den oppdaterte beholdningen.
Parametre:
- dictionaryen 'beholdning' som beskrevet i starten av oppgave 3.
- en streng 'matvare'.
- heltallet 'antall'.

Eksempel på kjøring:
>>> print(beholdning['kjøttdeig'])
14
>>> oppdater_matvare(beholdning, 'kjøttdeig', -1)
>>> print(beholdning['kjøttdeig'])
13
'''
# SKRIV KODEN DIN HER:

def oppdater_matvare(beholdning, matvare, antall):
    beholdning[matvare] += antall
    return beholdning



    
# print(beholdning['kjøttdeig'])
# oppdater_matvare(beholdning, 'kjøttdeig', -1)
# print(beholdning['kjøttdeig'])


# oppgave 3.3 - oppdater_beholdning(beholdning, endringer)
'''
Butikken får påfyll av ulike matvarer når det skjer en leveranse. Da må beholdningen oppdateres.
På samme måte må beholdningen reduseres når noen kjøper noe i butikken.
Skriv funksjonen oppdater_beholdning(beholdning, endringer):
- legg til/trekk fra endringer til beholdningen.
- returner den oppdaterte beholdningen.
Parametre:
- 'beholdning' er som tidligere.
- 'endringer' er en todimensjonal liste med matvarer og antall på format: [[navn,antall],[navn2,antall2], ...]

Eksempel:
>>> print(beholdning)
{'laks': 6, 'kjøttdeig': 13, 'ris': 15, 'ost': 9, 'bønner': 6, 'soyasaus': 0, 'banan': 1}
>>> beholdning = oppdater_beholdning(beholdning, [['ost',2], ['kjøttdeig',-4], ['bønner',-1]])
>>> print(beholdning)
{'laks': 6, 'kjøttdeig': 9, 'ris': 15, 'ost': 11, 'bønner': 5, 'soyasaus': 0, 'banan': 1}
'''
# SKRIV KODEN DIN HER:

def oppdater_beholdning(beholdning, endringer):
    for endring in endringer:
        beholdning[endring[0]] += endring[1]
    return beholdning



# print(beholdning)
# beholdning = oppdater_beholdning(beholdning, [['ost', 2], ['kjøttdeig', -4] ,['bønner', -1]])
# print(beholdning)


# oppgave 3.4 vis_priser(beholdning, matvarer, tekst)
'''
Butikken trenger å vite hvilke varer som er i sortimentet!
Skriv funksjonen vis_priser(beholdning, matvarer, tekst):
- finn hvilke matvarer som er i 'tekst', fjern unødvendige tegn og ord som ikke er matvarer.
- returner en liste av tupler der hvert tuppel inneholder navn på vare og pris på den varen.
- du kan anta at 'tekst' er i lower-case.
Parametre:
- 'beholdning' og 'matvarer' er lik tidligere.
- 'tekst' er en string med matvarer og eventuelle andre ord, der ordene er skilt ved mellomrom.
    Teksten kan inneholde '.' og ','. F.eks: 'bønner og kjøttdeig, med banan.'

Eksempel:
>>> print(vis_priser(beholdning, matvarer, 'bønner med soyasaus, og ris'))
[('bønner', 7), ('soyasaus', 33), ('ris', 15)]
'''
# SKRIV KODEN DIN HER:

def vis_priser(beholdning, matvarer, tekst):
    liste = []
    for matvare in matvarer:
        if matvare[0] in tekst:
            liste.append((matvare[0], matvare[1]))
    return liste


# print('Test av vis_priser():')
# print(vis_priser(beholdning, matvarer, 'bønner med soyasaus, og ris'))


# oppgave 3.5 - salg(matvarer, beholdning, handleliste)
'''
Butikken er opptatt av glade kunder! Derfor ønsker butikken å gi kundene mulighet til
å levere en handleliste. Dette er en liste med alle matvarene kunden ønsker.
Hvis kunden ønsker å handle flere av samme vare så vil matvaren gjentas (som ['ost', 'ost', 'banan'])
Butikken skal selge matvarer helt til det er tomt for dem. Hvis kunden ønsker to ost, men det finnes
kun en, så skal én ost selges.
Funksjonen salg(matvarer, beholdning, handleliste) skal gjøre følgende ting:
- Skrive ut alle matvarer som selges, og hvilken pris de selges for.
- Oppdatere beholdning for å reflektere salget som er gjennomført.
- Skrive ut sluttsummen for alle matvarer som ble solgt.
- Returner et tuppel bestående av alle matvarer som ble solgt.
Parametre:
- matvarer og beholdning er som tidligere.
- handleliste er en liste med matvarer. Du kan anta at alle matvarene finnes i både matvarer og beholdning.

Eksempel:
>>> print(salg(matvarer, beholdning,['ost','banan','banan', 'kjøttdeig', 'kjøttdeig']))
ost 99
banan 4
kjøttdeig 25
kjøttdeig 25
Totalsum: 153
('ost', 'banan', 'kjøttdeig', 'kjøttdeig')
'''
# SKRIV KODEN DIN HER:

def salg(matvarer, beholdning, handleliste):
    for matvare in handleliste:
        if matvare in matvarer:
            print(matvare, matvarer[matvare])
            beholdning[matvare] -= 1
    # print('Totalsum:', sum(matvarer.values()))
    return tuple(handleliste)

# print('Test av salg:')
# print(salg(matvarer, beholdning,['ost','banan','banan', 'kjøttdeig', 'kjøttdeig']))


# oppgave 3.6 - skriv_beholdning(beholdning), les_beholdning()
'''
Når butikken stenger må varebeholdningen lagres til fil, og så må varebeholdningen leses inn fra fil igjen når butikken åpner.
Skriv funksjonene skriv_beholdning(beholdning) og les_beholdning().
skriv_beholdning(beholdning) skal:
- lagre innholdet i dictionaryen 'beholdning' på et passende format.
- hvis filen finnes fra før, skal denne skrives over.
Parametre skriv_beholdning(beholdning):
- 'beholdning' er som tidligere.
les_beholdning() skal:
- lese den samme filen, opprette den samme dictionaryen, og returnere den.
Du velger selv format og struktur på filen, men det kan jo være enkelt å ta utgangspunkt
i den samme folderen som programmet kjøres fra. NB! Husk at eventuelle moduler må importeres.
Filen trenger ikke være lesbar for mennesker, det du måles på er at det fungerer.
'''
# SKRIV KODEN DIN HER

def skriv_beholdning(beholdning):
    with open('beholdning.csv', 'w') as f:
        for matvare in beholdning:
            f.write(matvare + ';' + str(beholdning[matvare]) + '\n')

def les_beholdning():
    with open('beholdning.csv', 'r') as f:
        beholdning = {}
        for line in f:
            matvare, antall = line.strip().split(';')
            beholdning[matvare] = int(antall)
    return beholdning


# print('Beholdning før skriving og lesing:\n', beholdning)
# skriv_beholdning(beholdning)
# beholdning = les_beholdning()
# print('Beholdning etter skriving og lesing:\n', beholdning)


# oppgave 3.7 - tilfeldig_middag(matvarer, budsjett)
'''
Noen ganger trenger kunder litt inspirasjon for å lage seg en middag. Lag en
funksjon tilfeldig_middag(matvarer, budsjett) som skal generere en tilfeldig
middag med forskjellige matvarer av retten 'middag' innenfor gitt budsjett.
Funksjonen trenger ikke ta hensyn til om matvaren er på lager, den skal kun
gi inspirasjon til middagsretter.
Parametre:
- 'matvarer' er som tidligere.
- 'budsjett' er et heltall.
tilfeldig_middag(matvarer, budsjett) skal:
- velge tilfeldige matvarer i kategorien 'middag' som man har nok penger til å kjøpe, duplikat av matvarer er ikke lov.
- holde styr på hvor mye de tilfeldige varene koster.
- returnere en liste med tilfeldige middagsvarer som koster tilsammen maks 'budsjett' når det ikke lenger finnes varer som kan legges til.

Eksempel på kjøring:
>>> tilfeldig_middag(matvarer, 70)
['laks', 'bønner']
>>> tilfeldig_middag(matvarer, 50)
['ris', 'bønner', 'kjøttdeig']
>>> tilfeldig_middag(matvarer, 20)
['ris']
'''
# SKRIV KODEN DIN HER

def tilfeldig_middag(matvarer, budsjett):
    middag = []
    for matvare in matvarer:
        if matvare['kategori'] == 'middag' and matvare['pris'] <= budsjett:
            middag.append(matvare['navn'])
            budsjett -= matvare['pris']
    return middag


print(f'Tilfelding middag 70: {tilfeldig_middag(matvarer, 70)}')
print(f'Tilfelding middag 50: {tilfeldig_middag(matvarer, 50)}')
print(f'Tilfelding middag 20: {tilfeldig_middag(matvarer, 20)}')