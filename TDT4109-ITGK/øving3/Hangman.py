#!/usr/bin/env python
# coding: utf-8

# <nav class="navbar navbar-default">
#   <div class="container-fluid">
#     <div class="navbar-header">
#       <a class="navbar-brand" href="_Oving3.ipynb">Øving 3</a>
#     </div>
#     <ul class="nav navbar-nav">
#       <li ><a href="Intro%20til%20lokker.ipynb">Intro til løkker</a></li>
#     <li ><a href="Mer%20om%20lokker.ipynb">Mer om løkker</a></li>
#     <li><a href="Nostede%20lokker.ipynb">Intro til nøstede løkker</a></li>
#     <li ><a href="Kodeforstaelse.ipynb">Kodeforståelse</a></li>
#     <li ><a href="Gjett%20tallet.ipynb">Gjett tallet</a></li>
#         <li ><a href="Tekstbasert%20spill%202.ipynb">Tekstbasert spill 2</a></li>
#     <li ><a href="Geometrisk%20rekke.ipynb">Geometrisk rekke</a></li>
#     <li ><a href="Fibonacci.ipynb">Fibonacci</a></li>
#     <li><a href="Alternerende%20sum.ipynb">Alternerende sum</a></li>
#     <li class="active"><a href="Hangman.ipynb">Hangman</a></li>
#     <li ><a href="Doble%20lokker.ipynb">Doble løkker</a></li>
#     </ul>
#   </div>
# </nav>
# 
# **Læringsmål:**
# 
# * Betingelser
# * While-løkker
# 
# **Starting Out with Python:**
# 
# * Kap. 3.4 
# * Kap. 4.2
# 
# Kapittel fire introduserer repetisjonsstrukturer. Dette er en mye brukt programmeringsteknikk som brukes når et program skal utføre den samme oppgaven mange ganger etter hverandre. I denne oppgaven bruker vi en enkel while-løkke for å lage et hangman-spill i Python. 
# 
# Lag et program som tar inn et ord (tekststreng) og antall liv (heltall) fra en bruker, og lar en annen (eller samme) bruker gjette på bokstaver i ordet. 

# **a)** Start med å hente inn data fra bruker. Lagre dette i to variabler "hemmelig_ord" og "antall_liv".
# 
# ***Skriv koden din her.***

# In[1]:


hemmelig_ord = input("Hemmelig ord: ")
antall_liv = int(input("Antall liv: "))


# **b)** Under har vi laget en while-løkke som kjører evig. Din oppgave er å fylle inn manglende logikk inne i løkken. Ting som må gjøres er:
# 
# * Hent inn en bokstav fra bruker
# * Sjekk om denne er i det hemmelige ordet 
#   * Trekk fra et liv dersom brukeren tipper feil
#  * Hvis brukeren ikke har flere liv skal løkken avsluttes (HINT: bruk "break" for å avslutte en løkke) 
# 
# PS: Husk å skrive ut resultatet til brukeren. **Du kan bruke variablene du laget i oppgave a uten å skrive dem på nytt** 
# 
# Eksempel på kjøring av kode:
# 
# ```python
# Skriv inn det hemmelige ordet: hemmelig
# Hvor mange forsøk får brukeren? 2
# Gjett på én bokstav i ordet: f
# Bokstaven f er ikke i ordet.
# Du har  1 liv igjen, prøv på nytt.
# Gjett på én bokstav i ordet: h
# Stemmer, bokstaven er i ordet
# Gjett på én bokstav i ordet: e
# Stemmer, bokstaven er i ordet
# Gjett på én bokstav i ordet: r
# Bokstaven r er ikke i ordet.
# Du har ingen liv igjen.
# ```

# In[14]:


hemmelig_ord_tmp = input("Hemmelig ord: ")
hemmelig_ord = []
for i in hemmelig_ord_tmp:
    hemmelig_ord.append(i)
    
antall_liv = int(input("Antall liv: "))

losnings_ord = []
for i in hemmelig_ord:
    losnings_ord.append('*')

while True:
    bokstav = input("Bokstav: ")
    if bokstav in hemmelig_ord:
        losnings_ord[hemmelig_ord.index(bokstav)] = bokstav
        hemmelig_ord[hemmelig_ord.index(bokstav)] = '~' # legger til ~ for å unngå bug der man ikke kan ha to like bokstaver
    else:
        antall_liv -= 1
    if antall_liv == 0:
        print("Du er tom for liv, prøv igjen")
        break
    elif ''.join(losnings_ord) == hemmelig_ord_tmp:
        print(f"Gratulerer du fant løsningsordet {hemmelig_ord_tmp}")
        break
    else:
        print(antall_liv)
        print(''.join(losnings_ord))


# **d)** **FRIVILLIG vanskeligere oppgave**: Fyll inn logikk for å fullføre spillet. Ting som kan implementeres er:
# 
# * Avslutt løkken hvis brukeren har gjettet alle bokstavene i løsningsordet.
# * For hvert gjett, print ut maskert løsningsord med stjerner for hver bokstav som fortsatt ikke er gjettet. `(Eks.: lø*ning*ord)`
# 
# Du kan fortsette i samme kodefelt som oppgave b.
