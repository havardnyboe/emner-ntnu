def sjekk(tall):
    if tall % 2 == 0:
        return "par"
    elif tall % 2 == 1:
        return "odde"
    else:
        return "des"

print(sjekk(3))
print(sjekk(3.0))
print(sjekk(3.1))
print(sjekk(4))
print(sjekk(4.2))