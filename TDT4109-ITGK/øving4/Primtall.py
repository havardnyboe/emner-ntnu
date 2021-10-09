#!/usr/bin/env python
# coding: utf-8

# <nav class="navbar navbar-default">
#   <div class="container-fluid">
#     <div class="navbar-header">
#       <a class="navbar-brand" href="_Oving4.ipynb">Øving 4</a>
#     </div>
#     <ul class="nav navbar-nav">
#     <li><a href="Grunnleggende%20om%20funksjoner.ipynb">Grunnleggende om funksjoner</a></li>
#     <li><a href="Varierte%20funksjoner.ipynb">Varierte funksjoner</a></li>
#     <li><a href="Lokale%20variabler.ipynb">Lokale variabler</a></li>
#     <li><a href="Globale%20variabler.ipynb">Globale variabler</a></li>
#     <li><a href="Euklids%20algoritme.ipynb">Euklids algoritme</a></li>
#     <li class="active"><a href="Primtall.ipynb">Primtall</a></li>
#     <li><a href="Multiplikasjon.ipynb">Multiplikasjon</a></li>
#         <li><a href="Den%20store%20sporreundersokelsen.ipynb">Den store spørreundersøkelsen</a></li>
#     <li><a href="Arbeidsdager.ipynb">Arbeidsdager</a></li>
#     <li><a href="Sekantmetoden.ipynb">Sekantmetoden</a></li>
#     <li><a href="Not%20quite%20Blackjack.ipynb">Not quite Blackjack</a></li>
#         <li><a href="Funksjoner%20og%20Jupyter%20widgets.ipynb">Funksjoner og Jupyter widgets</a></li>
#     </ul>
#   </div>
# </nav>
# 
# # Primtall
# 
# **Læringsmål:**
# - Løkker
# 
# **Starting Out with Python:**
# - Kap. 4.2-4.3

# ## a)

# Skriv funksjonen `divisable(a, b)` som returnerer `True` dersom `a` er delelig med `b` og `False` ellers.
# 
# ***Skriv koden i kodeblokken under***

# In[3]:


def divisable(a, b):
    if a % b == 0:
        return True
    else:
        return False


# Sjekk at funksjonen din fungerer med testkoden under. Output fra denne burde være:
# ```
# True
# False
# ```
# 
# (Husk å trykke `ctrl + enter` i kodeblokken med funksjonen din før du kjører testkoden)

# In[4]:


# TESTKODE FOR divisable
print(divisable(10,5))
print(divisable(10,3))


# #### Hint

# En modulo-operasjon (% i python) blir brukt i informatikk og i matematikk til å finne resten av et opprinnelig heltall etter en divisjon med et annet tall.
# 
# Eksempel på en modulo-operasjon: 5%2 = 1

# ## b)

# Lag funksjonen `isPrime` som tar inn et tall `a`. Funksjonen skal ha en for-løkke som itererer fra *b = 2,3,...,a-1* og bruke funksjonen fra forrige oppgave for å sjekke om `a` er delelig med `b`. Om de er delelige avslutter du og returnerer `False`. Ellers skal du returnere `True`.
# 
# ***Skriv koden i kodeblokken under***

# In[5]:


def isPrime(a):
    for i in range(2, a):
        if divisable(a, i):
            return False
    return True


# Sjekk at funksjonen din fungerer med testkoden under. Output fra denne burde være:
# ```
# True
# False
# ```
# 
# Test gjerne også med andre verdier

# In[6]:


# TESTKODE FOR isPrime
print(isPrime(11))
print(isPrime(15))


# ## c)

# Algoritmen skal nå gjøres raskere ved hjelp av 2 små inngrep som beskrevet nedenfor. Kall den nye funksjonen for isPrime2 og ta utgangspunkt i koden du skrev i b).
# 
# - Du skal nå bare iterere deg gjennom oddetall. Men du må fortsatt sjekke om a er delelig med 2.
# - Istedenfor å gå helt til $i=a−1$, skal du nå avslutte når $i>round(\sqrt{a}+0.5)$
# 
# ***Skriv koden din i kodeblokken under og sjekk at den fungerer***

# In[7]:


def isPrime2(a):
    for i in range(2, round(a**(1/2))+(1/2)):
        if i % 2 != 0:
            if divisable(a, i):
                return False
            return True

print(isPrime(11))
print(isPrime(15))

