def fjern_dup(liste):
    for i in range(len(liste)-1, 0, -1):
        if liste[i] == liste[i-1]:
            liste.pop(i)
    return liste

print(fjern_dup([1,4,3,2]))
print(fjern_dup([1,4,4,3]))
print(fjern_dup([2,2,3,3,3,1,4,1,1,1,1]))