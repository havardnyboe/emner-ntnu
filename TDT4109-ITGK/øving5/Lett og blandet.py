#!/usr/bin/env python
# coding: utf-8

# <nav class="navbar navbar-default">
#   <div class="container-fluid">
#     <div class="navbar-header">
#       <a class="navbar-brand" href="_Oving5.ipynb">Øving 5</a>
#     </div>
#     <ul class="nav navbar-nav">
#       <li ><a href="Generelt%20om%20lister.ipynb">Generelt om lister</a></li>
#     <li class="active"><a href="Lett%20og%20blandet.ipynb">Lett og blandet</a></li>
#     <li ><a href="Kodeforstaelse.ipynb">Kodeforståelse</a></li>
#     <li><a href="Vektorer.ipynb">Vektorer</a></li>
#     <li ><a href="Lister%20og%20lokker.ipynb">Lister og løkker</a></li>
#     <li ><a href="Teoridelen%20paa%20eksamen.ipynb">Teoridelen på eksamen</a></li>
#     <li><a href="Gangetabell%20og%20lister.ipynb">Gangetabell og lister</a></li>
#     <li ><a href="Lotto.ipynb">Lotto</a></li>
#     <li ><a href="Tannfeen.ipynb">Tannfeen</a></li>
#         <li><a href="Chattebot.ipynb">Chattebot</a></li>
#     <li ><a href="Matriseaddisjon.ipynb">Matriseaddisjon</a></li>
#     </ul>
#   </div>
# </nav>
# 
# 
# # Lett og blandet om lister
# 
# **Læringsmål:**
# 
# * Lister
# 
# **Starting Out with Python:**
# 
# * Kap. 7.1-7.3
# 
# Les om innebygde funksjoner i Python [her](https://docs.python.org/3/library/functions.html), og mer om lister i Python [her](https://docs.python.org/3/tutorial/datastructures.html). Merk at kun noen av disse er pensum, og det vil bli utdelt et nokså utfyllende "formelark" på eksamen.
# 
# 

# ### a)

# Lag en funksjon **is_six_at_edge()**, som tar inn en liste med heltall som parameter og returnerer **True** dersom **6** er det første eller det siste elementet i listen. Funksjonen returnerer ellers **False**.
# NB! Funksjonen skal også returnere True hvis lista starter **og** slutter på 6. 
# 
# Eksempel på kjøring:
# ```python
# print(is_six_at_edge([1,2,3,4,5,6]))
# True
# >>>  
# print(is_six_at_edge([1,2,3,4,5,6,7]))
# False
# ```
# ***Skriv koden din i boksen under.***

# In[5]:


def is_six_at_edge(liste):
    if liste[0] == 6 or liste[-1] == 6:
        return True
    return False

print(is_six_at_edge([1,2,3,4,5,6]))
print(is_six_at_edge([1,2,3,4,5,6,7]))


# #### Sum og lengde av en liste

# sum(listen) returnerer den totale summen av alle elementene i listen, for eksempel sum([1,2,3,4]) = 1+2+3+4 = 10.
# 
# len(listen) returnerer antall elementer i listen, for eksempel len([1,2,3,4])=4.

# ### b)

# Bruk den innebygde funksjonen [sum()](https://docs.python.org/3/library/functions.html#sum), samt len() for å lage en funksjon average() som tar inn en liste med tall som parameter og returnerer gjennomsnittsverdien til tallene i listen.
# 
# Eksempel på kjøring:
# ```python
# print(average([1,3,5,7,9,11]))
# 6```
# 
# ***Skriv koden din i boksen under.***

# In[8]:


def average(liste):
    return sum(liste)/len(liste)

print(average([1,3,5,7,9,11]))


# ### c)

# Bruk den innebygde metoden [**.sort()**](https://docs.python.org/3/howto/sorting.html) for å lage en funksjon **median()** som tar inn en liste og finner medianen av listen og returnerer den. Husk at medianen er det midterste elementet i en sortert rekkefølge av listens elementer.  
# *NB! Du kan anta at det er et oddetall antall elementer i listen!*
# 
# Eksempel på kjøring:
# ```python
# print(median([1,2,4,5,7,9,10]))
# 5
# >>>  
# print(median([1,4,2,5,3]))
# 3
# ```
# ***Skriv koden din i boksen under.***

# In[12]:


def median(liste):
    liste.sort()
    return liste[len(liste)//2]

print(median([1,2,4,5,7,9,10]))
print(median([1,4,2,5,3]))


# #### Hint

# Ved å skrive **my_list.sort()** sorterer du elementene i listen **my_list**
