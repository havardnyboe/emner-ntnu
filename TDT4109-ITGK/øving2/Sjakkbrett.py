#!/usr/bin/env python
# coding: utf-8

# <nav class="navbar navbar-default">
#   <div class="container-fluid">
#     <div class="navbar-header">
#       <a class="navbar-brand" href="_Oving2.ipynb">Øving 2</a>
#     </div>
#     <ul class="nav navbar-nav">
#     <li><a href="Ulike%20typer%20if-setninger.ipynb">Ulike typer if-setninger</a></li>
#     <li><a href="Sammenligning%20av%20strenger.ipynb">Sammenligning av strenger</a></li>
#     <li><a href="Logiske%20operatorer%20og%20logiske%20uttrykk.ipynb">Logiske operatorer og logiske uttrykk</a></li>
#     <li><a href="Forbrytelse%20og%20straff.ipynb">Forbrytelse og straff</a></li>
#     <li><a href="Aarstider.ipynb">Årstider</a></li>
#         <li ><a href="Tekstbasert%20spill.ipynb">Tekstbasert spill</a></li>
#     <li class="active"><a href="Sjakkbrett.ipynb">Sjakkbrett</a></li>
#     <li><a href="Billettpriser%20og%20rabatter.ipynb">Billettpriser og rabatter</a></li>
#     <li><a href="Skatteetaten.ipynb">Skatteetaten</a></li>
#     <li><a href="Epletigging.ipynb">Datamaskinen som tigget epler</a></li>
#     <li><a href="Andregradsligning.ipynb">Andregradsligning</a></li>
#     </ul>
#   </div>
# </nav>
# 
# # Sjakkbrett
# 
# **Læringsmål:**
# 
# * Betingelser
# * Logiske uttrykk
# * Nøstede if-setninger
# 
# **Starting Out with Python:**
# 
# * Kap. 2.7
# * Kap. 3.2-3.3
# * Kap. 3.5
#  
# Posisjoner på et sjakkbrett kan identifiseres med en bokstav og et tall. Bokstaven identifiserer kolonnen (kalt "linjen" i sjakk), og tallet identifiserer raden.
# 
# 
# ![img](./../../Resources/Images/chessboard.png)
# 

# ### a)

# **I denne oppgaven skal du lage et program som tar inn en posisjon fra brukeren, og bruker if-setninger til å finne ut hvilken farge ruten for denne posisjonen har.**
# 
# Ta utgangspunkt i de tre kodelinjene under, som hjelper deg litt på vei. Disse viser hvordan man kan bruke indeksering av en strengvariabel (her kalt `pos`) for å finne enkelttegn.
# 
# Indeks 0 er det første tegnet i strengen, når `pos = 'a5'` vil dermed `pos[0]` være `'a'` og `pos[1]` være `'5'`.
# 
# I din kode må du
# 
# * bytte ut kodelinjen `posisjon = 'a5'` med en kodelinje som i stedet ber bruker om å taste inn posisjonen
# * legge til mer kode under kodelinjen `tall = ...` for å ta en beslutning om den innskrevne posisjonen er hvit eller svart rute.
# 
# Eksempel på kjøring:
# 
#   
# ```python
# Posisjon: a5  
# Svart  
# ```
#   
# ```
# Posisjon: d3  
# Hvit  
# ```
#   
# ```
# Posisjon: f6
# Svart
# ```

# In[32]:


pos = input("Posisjon: ")

parBokstaver = ['b', 'd', 'f', 'h']
oddeBokstaver = ['a', 'c', 'e', 'g']
    
if (len(pos) != 2):
    print("Feil input. Du må skrive akkurat to tegn")
elif not(pos[0] in parBokstaver + oddeBokstaver) or (int(pos[1]) < 1) or (int(pos[1]) > 8):
    print("""Feil input.
Første tegn må være en bokstav A-H eller a-h
Andre tegn må være et tall 1-8
    """)
elif (pos[0].lower() in parBokstaver and int(pos[1]) % 2 == 0) or (pos[0].lower() in oddeBokstaver and int(pos[1]) % 2 != 0):
    print("Svart")
else:
    print("Hvit")


# #### Hint

# Modulo (`%`)

# ## b) Valgfri ekstraoppgave

# Denne trenger du ikke ha fått til for å få godkjent deloppgaven.
# 
# **Utvid programmet så det også håndterer mulig feil input fra bruker, på følgende måte**:
# 
# * Hvis brukeren skriver inn en streng med en annen lengde enn 2 tegn (enten kortere eller lenger), skal programmet svare `"Feil input. Du må skrive akkurat to tegn"` og så avslutte.
# * Hvis innskrevet tekst er 2 tegn lang men ikke tilsvarer en sjakkrute, skal programmet svare som vist under. Dette skal altså skje hvis første tegn noe annet enn en bokstav A-H eller a-h, eller andre tegn er noe annet enn et tall 1-8.
# 
#   
# ```
# Posisjon: A9
# Feil input.
# Første tegn må være en bokstav A-H eller a-h
# Andre tegn må være et tall 1-8
# ```
# 
# Hvis lengden er to tegn, med bokstav og tall innen lovlige verdiområder, skal programmet gi samme resultat som i kjøringene i oppgave a
