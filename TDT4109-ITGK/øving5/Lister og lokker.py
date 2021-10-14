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
#     <li class="active"><a href="Lister%20og%20lokker.ipynb">Lister og løkker</a></li>
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
# # Lister og løkker
# 
# **Læringsmål:**
# 
# * Lister
# 
# * Løkker
# 
# **Starting Out with Python:**
# 
# * Kap. 7.7

# ### Iterering gjennom en liste

# For å iterere/gå gjennom elementene i en liste brukes løkker, og dette gjøres hovedsakelig på to ulike måter:
# 
# 1) For-løkker, ved å bruke range()-funksjonen og indekser.
# 
# Eksempel:

# In[1]:


liste = [1,2,3,4,5]
lengde = len(liste)   #5
for x in range(lengde):
    print(liste[x])


# 2) For-in-løkker, som henter ut ett og ett element av en liste.

# In[2]:


liste = [1,2,3,4,5]
for x in liste:
    print(x)


# Disse metodene brukes om hverandre, og det er lurt å kunne bruke begge. Begge gir samme output. **Kjør dem selv for å verifisere med ctr + enter**

# ### a)

# Lag en liste **number_list** med alle heltallene fra 0 til og med 99.
# 
# Eksempel på kjøring:
# 
# ```python
# >>>print(number_list)
# [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,..., 99]
# ```
# ***Skriv svaret ditt i boksen under.***

# In[7]:


number_list = []
for i in range(100):
    number_list.append(i)
print(number_list)


# #### Hint

# For å legge til et nytt **element** til en liste (**my_list**) kan du bruke den innebygde funksjonen "append" slik: my_list.append(element).

# ### b) 

# Summer sammen alle tall i listen som er delelig på 3 eller 10. (Summen skal bli 1953)
# 
# ***Skriv svaret ditt i boksen under.***

# In[8]:


s = 0
for i in number_list:
    if i % 3 == 0 or i % 10 == 0:
        s+=i

print(s)


# ### c)

# Bytt plass på alle nabo partall og oddetall i listen. (listen skal nå være: [1, 0, 3, 2, 5, 4, 7, 6, 9, 8,..., 98])
# 
# ***Skriv svaret ditt i boksen under.***

# In[10]:


for i in range(0, 100, 2):
    tmp = number_list[i]
    number_list[i] = number_list[i+1]
    number_list[i+1] = tmp

print(number_list)


# ### d)

# Lag en ny liste **reversed_list** som inneholder elementene i **number_list** i motsatt rekkefølge. (Merk: uten å bruke innebygde funksjoner i Python)
# 
# Dersom du nå printer listen skal du få:
#     
# ```python
# [98, 99, 96, 97, 94, 95, 92, 93, 90, 91, 88, 89, 86, 87, 84, 85, 82, 83, 80, 81, 78, 79, 76, 77, 74, 75, 72, 73, 70, 71, 68, 69, 66, 67, 64, 65, 62, 63, 60, 61, 58, 59, 56, 57, 54, 55, 52, 53, 50, 51, 48, 49, 46, 47, 44, 45, 42, 43, 40, 41, 38, 39, 36, 37, 34, 35, 32, 33, 30, 31, 28, 29, 26, 27, 24, 25, 22, 23, 20, 21, 18, 19, 16, 17, 14, 15, 12, 13, 10, 11, 8, 9, 6, 7, 4, 5, 2, 3, 0, 1]
# ```
# 
# ***Skriv svaret ditt i boksen under.***

# In[11]:


reversed_list = []
for i in range(99, -1, -1):
    reversed_list.append(number_list[i])
    
print(reversed_list)

