def sjekk_to(streng):
    out = 1
    if int(streng[0] + streng[1]) > 29:
        out *= 2
    if int(streng[2] + streng[3]) > 18:
        out *= 3
    if int(streng[4] + streng[5]) > 52:
        out *= 5
    return out
    

print(sjekk_to('051033'))
print(sjekk_to('421033'))
print(sjekk_to('052033'))
print(sjekk_to('051099'))
print(sjekk_to('422033'))
print(sjekk_to('421099'))
print(sjekk_to('422099'))