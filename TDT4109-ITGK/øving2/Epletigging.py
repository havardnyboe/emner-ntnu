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
#     <li><a href="Sjakkbrett.ipynb">Sjakkbrett</a></li>
#     <li><a href="Billettpriser%20og%20rabatter.ipynb">Billettpriser og rabatter</a></li>
#     <li><a href="Skatteetaten.ipynb">Skatteetaten</a></li>
#     <li class="active"><a href="Epletigging.ipynb">Datamaskinen som tigget epler</a></li>
#     <li><a href="Andregradsligning.ipynb">Andregradsligning</a></li>
#     </ul>
#   </div>
# </nav>
# 
# # Datamaskinen som tigget epler - Debugging
# 
# **Læringsmål:**
# 
# * Feilretting
# * Betingelser
# 
# **Starting Out with Python:**
# 
# * Kap. 3: Decision Structures and Boolean Logic
# 
# I denne oppgaven får du utdelt en kodesnutt som inneholder feil. Det er både konkrete feil i koden (python-syntaks) og logiske feil (brukeren kan gi input som får programmet til å gi betydningsløse svar). 
# 
# Din oppgave er å rette opp i syntaks-feilene, og håndtere de logiske feilene på en fornuftig måte. 
# 
# 

# ### a)

# Programmet spør brukeren hvor mange epler han har, og hvor mange han er villig til å gi bort. Basert på disse svarene er det tre mulige utfall, som vist under:
# 
#   
# ```python
# Dette er et program for å teste din sjenerøsitet.
# Hvor mange epler har du? 0
# Æsj, det sier du bare for å slippe å gi noe!
# ```
#   
# ```python
# Dette er et program for å teste din sjenerøsitet.
# Hvor mange epler har du? 5
# Hvor mange kan du gi til meg? 2
# Du beholder det meste for deg selv...
# Du har nå 3 epler igjen.
# ```
#   
# ```python
# Dette er et program for å teste din sjenerøsitet.
# Hvor mange epler har du? 7
# Hvor mange kan du gi til meg? 5
# Takk, det var snilt!
# Du har nå 2 epler igjen. 
# ```
# 
# Koden som skal kjøre programmet er som vist under. **Finn syntaksfeilene og rett opp i dem slik at koden kjører som vist i eksempelteksten.**

# In[9]:


print("Dette er et program for å teste din sjenerøsitet.")
har_epler = int(input("Hvor mange epler har du? "))
if har_epler == 0:
    print("Æsj, det sier du bare for å slippe å gi noe!")
else:
    gir_epler = int(input("Hvor mange kan du gi til meg? "))
    if gir_epler < har_epler / 2:
        print("Du beholder det meste for deg selv...")
    else:
        print("Takk, det var snilt!")
    if har_epler - gir_epler == 1:
        print("Du har nå", har_epler - gir_epler, "eple igjen.")
    elif har_epler - gir_epler < 0:
        print(f"Du har nå 0 epler igjen. Gi meg de {abs(har_epler-gir_epler)} du skylder meg neste gang vi møtes.")
    else:
        print("Du har nå", har_epler - gir_epler, "epler igjen.")


# ### b)

# Utskriften av siste print-setning vil bli grammatisk feil hvis brukeren har igjen 1 eple, siden det skrives «epler». Utvid programmet slik at det skriver:
# 
#   
# ```python
# Du har nå 1 eple igjen.
# ```
# 
# hvis det ble akkurat ett, ellers epler i flertall som det står nå.

# ### c)

# Hvis brukeren skriver inn et større tall for hvor mange epler man kan gi bort enn hva man faktisk hadde, kommer siste linje ut med et negativt tall.
# 
# Utvid programmet ytterligere slik at hvis brukeren f.eks. har 7 epler men vil gi bort 9, avslutter programmet med
# 
#   
# ```python
# Du har nå 0 epler igjen. Gi meg de 2 du skylder meg neste gang vi møtes.
# ```
