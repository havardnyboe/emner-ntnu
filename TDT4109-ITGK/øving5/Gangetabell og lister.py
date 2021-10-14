#!/usr/bin/env python
# coding: utf-8

# <nav class="navbar navbar-default">
#   <div class="container-fluid">
#     <div class="navbar-header">
#       <a class="navbar-brand" href="_Oving5.ipynb">Øving 5</a>
#     </div>
#     <ul class="nav navbar-nav">
#       <li ><a href="Generelt%20om%20lister.ipynb">Generelt om lister</a></li>
#     <li ><a href="Lett%20og%20blandet.ipynb">Lett og blandet</a></li>
#     <li ><a href="Kodeforstaelse.ipynb">Kodeforståelse</a></li>
#     <li ><a href="Vektorer.ipynb">Vektorer</a></li>
#     <li ><a href="Lister%20og%20lokker.ipynb">Lister og løkker</a></li>
#     <li ><a href="Teoridelen%20paa%20eksamen.ipynb">Teoridelen på eksamen</a></li>
#     <li class="active"><a href="Gangetabell%20og%20lister.ipynb">Gangetabell og lister</a></li>
#     <li ><a href="Lotto.ipynb">Lotto</a></li>
#     <li ><a href="Tannfeen.ipynb">Tannfeen</a></li>
#         <li><a href="Chattebot.ipynb">Chattebot</a></li>
#     <li ><a href="Matriseaddisjon.ipynb">Matriseaddisjon</a></li>
#     </ul>
#   </div>
# </nav>
# 
# # Gangetabell og lister
# 
# **Læringsmål:**
# 
# * Løkker
# * Lister
# 
# **Starting Out with Python:**
# 
# * Kap. 7: Lists and Tuples
# 
# 

# ### a)

# Lag en funksjon separate(numbers, threshold) som tar inn to argumenter:
# 
# * numbers: en liste med heltall
# * threshold: et heltall
# Funksjonen skal returnere to lister: den første listen skal inneholde alle elementer fra **numbers** som er mindre enn **threshold**, og den andre listen skal inneholde alle elementer fra **numbers** som er større enn eller lik **threshold**.
# 
#  
# En matrise er et rektangulært sett av elementer ordnet i rader og kolonner. Radene er de horisontale linjene, og kolonnene er de vertikale linjene.
# 
# I Python representerer vi dette med lister som inneholder lister.  Elementet øverst til venstre i eksempelet under (med verdi 1) er i rad 1, kolonne 1.

# In[1]:


matrise = [
[1, 2, 3],
[4, 5, 6],
[7, 8, 9]]


# Elementene i matrisen kan hentes ut på følgende måte: **matrise[radnr][kolnr]**. 
# 
# *Husk at radnummer og kolonnenummer er null-indeksert (begynner på 0) i Python i motsetning til matematisk notasjon der de er 1-indeksert!*
# 
# ***Skriv koden din i boksen under.***

# In[3]:


def separate(numbers, threshold):
    a = []
    b = []
    for n in numbers:
        if n < threshold:
            a.append(n)
        else:
            b.append(n)
    return a, b
    
print(separate([0,1,2,3,4,5,6,7,8,9], 6))


# ### b)

# Lag en funksjon **multiplication_table(n)** som tar inn et heltall n som parameter og returnerer gangetabellen fra 1 til n som en matrise med n rader og n kolonner.
# 
# ***Skriv koden din i boksen under.***

# In[4]:


def multiplication_table(n):
    return [[i * j for j in range(1, n + 1)] for i in range(1, n + 1)]


# Har du implementert funksjon riktig skal koden under printe følgende matrise:
# 
# 
# ```
# [[1, 2, 3, 4],
#  [2, 4, 6, 8],
#  [3, 6, 9, 12],
#  [4, 8, 12, 16]]
#  ```

# In[5]:


print(multiplication_table(4))


# #### Hint

# Man kan legge til elementer (som også kan være lister) på slutten av en liste med **liste.append(element)**.
