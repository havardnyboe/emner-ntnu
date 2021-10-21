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
#     <li class="active"><a href="Innebygde%20funksjoner.ipynb">Innebygde funksjoner og lister</a></li>
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
# # Innebygde funksjoner og lister
# 
# **Læringsmål:**
# 
# * Lister
# * Innebygde funksjoner
# 
# **Starting Out with Python:**
# 
# * Kap. 7: Lists and Tuples
#  
# 
# I denne oppgaven skal vi bruke innebygde funksjoner i Python til å behandle lister. 
# 
# Du finner informasjon og nyttige metoder [her](https://docs.python.org/3/tutorial/datastructures.html). (bruk disse!)

# ### a)

# Opprett en liste random_numbers bestående av 100 tilfeldige heltall fra 1 til og med 10.
# 
# **Eksempel på slik liste:**
# >```python
# [9, 7, 4, 3, 2, 3, 9, 4, 4, 1, 1, 3, 4, 9, 5, 5, 3, 4, 7, 8, 9, 4, 6, 6, 1, 6, 5, 7, 2, 5, 7, 1, 9, 4, 9, 6, 1, 1, 1, 5, 6, 5, 9, 10, 5, 7, 4, 4, 10, 4, 4, 8, 1, 5, 4, 9, 5, 5, 2, 8, 10, 8, 1, 5, 10, 8, 3, 3, 7, 7, 6, 3, 3, 3, 4, 9, 4, 8, 4, 6, 1, 10, 3, 6, 5, 7, 10, 9, 9, 1, 10, 3, 2, 3, 6, 9, 8, 3, 2, 5]
# ```
# 
# ***Skriv koden din i kodeblokken under:***

# In[1]:


from random import randint

a = []
for i in range(100):
    a.append(randint(1,10))
    
print(a)


# ### b)

# Skriv kode for å finne antall forekomster av tallet **2** i listen.
# 
# **Eksempel på kjøring for listen i a):**
# 
# >```
# Number of 2s: 5
# ```
# 
# ***Skriv koden din i kodeblokken under:***

# In[2]:


numer_of_twos = a.count(2)

print(numer_of_twos)


# ### c)

# Skriv ut summen av alle tallene i listen.
# 
# **Eksempel på kjøring for listen i a):**
# >```python
# Sum of numbers: 529
# ```
# 
# ***Skriv koden din i kodeblokken under:***

# In[3]:


s = sum(a)

print(s)


# ### d)

# Sorter listen i stigende rekkefølge.
# 
# **Eksempel på kjøring for listen i a):**
# >```python
# Numbers sorted: [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10]
# ```
# 
# ***Skriv koden din i kodeblokken under:***

# In[4]:


a.sort()
print(a)


# ### e)

# Skriv ut typetallet. (Det tallet det er flest forekomster av i listen)
# 
# **Eksempel på kjøring for listen i a):**
# >```python
# There are most of number: 4
# ```
# 
# ***Skriv koden din i kodeblokken under:***

# In[5]:


def most_common(lst):
    return max(set(lst), key=lst.count)

print(most_common(a))


# ### f)

# Skriv ut listen baklengs.
# 
# **Eksempel på kjøring for listen i a):**
# >```python
# Numbers reversed: [10, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
# ```
# 
# ***Skriv koden din i kodeblokken under:***

# In[6]:


a.reverse()
print(a)

