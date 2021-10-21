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
#     <li ><a href="Slicing.ipynb">Slicing</a></li>
#     <li ><a href="Tekstbehandling.ipynb">Tekstbehandling</a></li>
#     <li ><a href="Strenghandtering.ipynb">Strenghåndtering</a></li>
#     <li ><a href="Innebygde%20funksjoner.ipynb">Innebygde funksjoner og lister</a></li>
#     <li ><a href="Fjesboka.ipynb">Fjesboka</a></li>
#     <li ><a href="Akkorder%20og%20toner.ipynb">Akkorder og toner</a></li>
#     <li ><a href="Ideel%20gasslov.ipynb">Ideel Gasslov</a></li>
#     <li class="active"><a href="Sammenhengende%20tallrekke.ipynb">Sammenhengende Tallrekke</a></li>
#     <li ><a href="Sortering.ipynb">Sortering</a></li>
#     <li ><a href="Strengmanipulasjon.ipynb">Strengmanipulasjon</a></li>
#     <li ><a href="Kryptering.ipynb">Kryptering</a></li>
#     <li ><a href="Litt%20sjakk.ipynb">Litt Sjakk</a></li>
#     </ul>
#   </div>
# </nav>
# 
# # Sammenhengende tallrekke
# 
# **Læringsmål:**
# 
# * Lister
# 
# **Starting Out with Python:**
# 
# * Kap. 7: Lists and Tuples
# 
# I denne oppgaven skal du sammenligne lister med tall. (Eksempel på kjøring av hver deloppgave er samlet i kodeblokk nederst på siden.)
# 
#  

# **a)** Lag en funksjon `randList(size, lower_bound, upper_bpund)` som tar inn tre heltall, `size`, `lower_bound` og `upper_bound`. Denne skal returnere en liste med tilfeldige tall i intervallet mellom `lower_bound` og `upper_bound`. Hvor mange tall listen skal inneholde er angitt av `size`.
# 
# ***Skriv funksjonen din i kodeblokken under og test at den fungerer***

# In[1]:


import random as r

def randList(size, lower_bound, upper_bound):
    a = []
    for i in range(size):
        a.append(r.randint(lower_bound, upper_bound))
    return a


# **b)** Skriv en funksjon `compareLists(list1, list2)` som sammenligner 2 lister og returnerer en liste med alle tall som var med i begge listene. Kopier skal ikke taes med. Ikke bruk innebygde funksjoner.
# 
# ***Skriv funksjonen din i kodeblokken under og test at den fungerer***

# In[26]:


def compareLists(list1, list2):
    a = {}
    for e in list1:
        if e in list2:
            a.add(e)
    return list(a)


# **c)** Skriv en ny funksjon `multiCompList(lists)` som kan sammenligne et vilkårlig antall lister.  
# Hint: `lists` er en liste av lister. Ikke bruk innebygde funksjoner, men ta gjerne i bruk funksjoner du har laget tidligere i oppgaven.
# 
# ***Skriv funksjonen din i kodeblokken under og test at den fungerer***

# In[33]:


def multiCompList(lists):
    return [e for e in lists[0] if e in lists[1] and e in lists[2]]


# **d)** Skriv en funksjon `longestEven(list)` som finner lengste sammenhengende rekke med partall i en liste. Metoden skal returnere indeksen til det første partallet i rekken og antallet partall i rekken.
# 
# ***Skriv funksjonen din i kodeblokken under***

# In[50]:


def longestEven(list):
    evens = [x for x in list if x % 2 == 0]
    return [evens.index(max(evens)), len(evens)]


# **Test av alle funksjonene:**

# In[51]:


def main():
    print(randList(10,2,7))
    a = [1,2,3]
    b = [4,3,1]
    print(compareLists(a,b))
    c = [7,2,1]
    d = [a,b,c]
    print(multiCompList(d))
    liste = [4,3,3,6,2,6,8,3,4,3,3]
    print(longestEven(liste))
 
main()


# **Eksempel på riktig utskrift:**
# >```python
# [5, 6, 7, 4, 7, 3, 2, 4, 3, 2] # Merk at denne vil variere!
# [1, 3]
# [1]
# (3, 4)
# ```
