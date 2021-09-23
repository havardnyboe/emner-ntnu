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
#     <li ><a href="Geometrisk%20rekke.ipynb">Geometrisk rekke</a></li>
#         <li ><a href="Tekstbasert%20spill%202.ipynb">Tekstbasert spill 2</a></li>
#     <li ><a href="Fibonacci.ipynb">Fibonacci</a></li>
#     <li class="active"><a href="Alternerende%20sum.ipynb">Alternerende sum</a></li>
#     <li ><a href="Hangman.ipynb">Hangman</a></li>
#     <li ><a href="Doble%20lokker.ipynb">Doble løkker</a></li>
#     </ul>
#   </div>
# </nav>
# 
# # Alternerende sum
# 
# **Læringsmål:**
# 
# * Løkker
# 
# **Starting Out with Python:**
# 
# * Kap. 4.2-4.3
# 
# I denne oppgaven skal du ved hjelp av løkker summere sammen tall, basert på brukerinput. 

# **a)** Skriv et program som leser inn et heltall n fra bruker og legger sammen tallserien under.
# 
# **$1^{2}-2^{2}+3^{2}-4^{2}+5^{2}-\cdot \cdot \cdot \pm n^{2}$**
# 
# Legg merke til at alle partallene har negativt fortegn og alle oddetallene har positivt fortegn. Husk at navnet på variabelen din ***ikke*** kan være **sum**, ettersom dette er navnet på en funksjon i python. Husk også at range() bare går til et tall og ikke til og med.
# 
# Eksempel på kjøring:
# ```python
# n = 7
# Summen av tallserien er 28
# ```
# 
# ***Skriv koden din her:***

# In[ ]:


def sum_n(n):
    s = 0
    for i in range(n+1):
        if i % 2 == 0:
            s -= i**2
        else:
            s += i**2
    return f"Sum: {s}"

n = int(input("n: "))
print(sum_n(n))


# **b)** Skriv et nytt program slik at det avslutter iterasjonen **før** summen av tallene er større enn det positive heltallet k. Dette vil si at resultatet som skal skrives ut er summen på siste ledd før summen går over tallet k.
# 
# Hold styr på hvor mange ledd fra tallserien som er brukt i summen og skriv dette ut sammen med resultatet.
# 
# Eksempel på kjøring:
# 
# ```python
# k = 6
# Summen av tallene før summen blir større enn k er -10. Antall iterasjoner: 4
# ```
# ```python
# k = 12
# Summen av tallene før summen blir større enn k er -10. Antall iterasjoner: 4
# ```
# ```python
# k = 15
# Summen av tallene før summen blir større enn k er -21. Antall iterasjoner: 6
# ```
# 
# ***Skriv koden din her:***

# In[15]:


def sum_n():
    s = [0, 0]
    for i in range(int(10e99)):
        if s[1] > k:
            return f"Sum: {s[0]}, Ant. iterasjoner: {i-2}"
        s[0] = s[1]
        if i % 2 == 0:
            s[1] = s[1] - i**2
        else:
            s[1] = s[1] + i**2
    return f"Sum: {s[1]}, Ant. iterasjoner: {i-2}"

k = int(input("k: "))
print(sum_n())

