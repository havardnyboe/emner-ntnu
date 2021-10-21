#!/usr/bin/env python
# coding: utf-8

# <nav class="navbar navbar-default">
#   <div class="container-fluid">
#     <div class="navbar-header">
#       <a class="navbar-brand" href="_Oving6.ipynb">Øving 6</a>
#     </div>
#     <ul class="nav navbar-nav">
#     <li ><a href="Aksessering.ipynb">Aksessering av karakter</a></li>
#     <li ><a href="Strenger%20og%20konkatinering.ipynb">Konkatinering</a></li>
#     <li class="active"><a href="Slicing.ipynb">Slicing</a></li>
#     <li ><a href="Tekstbehandling.ipynb">Tekstbehandling</a></li>
#     <li ><a href="Strenghandtering.ipynb">Strenghåndtering</a></li>
#     <li ><a href="Innebygde%20funksjoner.ipynb">Innebygde funksjoner og lister</a></li>
#     <li><a href="Fjesboka.ipynb">Fjesboka</a></li>
#     <li ><a href="Akkorder%20og%20toner.ipynb">Akkorder og toner</a></li>
#     <li ><a href="Ideel%20gasslov.ipynb">Ideel Gasslov</a></li>
#     <li><a href="Sammenhengende%20tallrekke.ipynb">Sammenhengende Tallrekke</a></li>
#     <li ><a href="Sortering.ipynb">Sortering</a></li>
#     <li ><a href="Strengmanipulasjon.ipynb">Strengmanipulasjon</a></li>
#     <li ><a href="Kryptering.ipynb">Kryptering</a></li>
#     <li ><a href="Litt%20sjakk.ipynb">Litt Sjakk</a></li>
#     </ul>
#   </div>
# </nav>
# 
# # Slicing av strenger
# 
# **Læringsmål:**
# 
# * Strenger
# * Funksjoner
# * Lister
# 
# **Starting Out with Python:**
# 
# * Kap. 8.2

# ### Kort om slicing

# Slicing kan brukes til å velge ut en del av en streng. Formatet for dette er:  
# string[start : slutt : steg]
# 
# * Den nye strengen vil starte på karakteren start-indeksen tilsvarer, fortsette med karakteren indikert av indeksen (start+steg), så ta neste karakter indikert av indeksen (start+steg+steg), osv., helt til, men ikke med, karakteren end-indeksen tilsvarer. (Se eksempeler på kjøring)
# * Om start ikke er spesifisert, antas indeks 0
# ' Om slutt ikke er spesifisert, antas indeks len(string)
# * Om steg ikke er spesifisert antas steg = 1
# 
# **Eksempel:**

# In[1]:


streng = "One ring to rule them all"
print(streng[:3])       #Samme som streng[0:3]
print(streng[12:16])    
print(streng[12:])      #Samme som streng[12:len(streng)] og streng[12:25]
print(streng[1::9])     


# ### a)

# Skriv en funksjon som tar inn en streng som argument, og returnerer en ny streng bestående av hver fjerde karakter i argumentet.
# 
# **Eksempel:**
# 
# ```python
# #streng = "I Was Told There’d Be Cake"
# -> Islh’ek
# ```
# 
# ***Skriv koden din i kodeblokken under***

# In[10]:


streng = "I Was Told There’d Be Cake"
out = ""
for i in range(len(streng)):
    if i % 4 == 0:
        out += streng[i]
    
print(out)


# ### b)

# Skriv en funksjon som tar inn en liste med strenger, itererer gjennom denne, og returnerer en ny streng bestående av de to siste karakterene i strengene i listen.
# 
# **Eksempel:**
# ```python
# #liste = ["banan","propan","Westerosi"]
# -> anansi
# ```
# 
# ***Skriv koden din i kodeblokken under***

# In[12]:


liste = ["banan","propan","Westerosi"]

def last_to_char(liste):
    out = ""
    for s in liste:
        out += s[-2] + s[-1]
    return out

print(last_to_char(liste))


# ### c)

# Under følger tre kodesnutter, der to inneholder en feil hver, og den siste er rett. Hvilken kode er korrekt? Finn feilen i de to andre.

# In[19]:


#Kodesnutt 1
streng = "I Want Cake"
streng[7:] = "Cupcake"
print(streng)
 
#Kodesnutt 2
streng = "I Want Cake"
streng = streng[-4:100:]
print(streng)
 
#Kodesnutt 3
streng = "I Want Cake"
streng = streng[]
print(streng)


# Dobbeltklikk på teksten under og skriv svaret ditt i boksen.

# **Ditt svar:** 1 og 3 er feil, 2 er riktig. 
# - feil på 1: man kan ikke legge til en streng i en streng
# - feil på 3: `streng = streng[]` mangler en index å kalle i stengen
