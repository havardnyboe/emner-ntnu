

def alfa(streng, tall):
    if tall == 0:
        return min(streng)
    return max(streng)

print(alfa("manus", 0))
print(alfa("manus", 1))
print(alfa("manus", 0.5))