# besvarelse oppgave 4 på eksamen 2022
# kommentert ut kode er original-svar som er skrevet feil

def les_meteoritter(filnavn):
    meteoritter = []
    
    with open(filnavn, "r") as fil:
        for i, linje in enumerate(fil.read().split("\n")):
            if i != 0: # ignorerer første linje
                meteoritt = linje.split(",")
                
                if len(meteoritt) > 7: # spesialtilfelle for jernmeteoritt
                    meteoritt.pop(3) # fjerner ekstra felt fra split
                    meteoritt[2] = "Iron" # setter klassen til Iron
                    
                meteoritt[3] = float(meteoritt[3]) # masse til flyttall
                meteoritt[4] = int(meteoritt[4]) # nedslagsår til heltall
                
                meteoritter.append(meteoritt) # legger til meteoritten
            
    return meteoritter

def sorter_masse(nedslag, kolonne):
    sortert = {}
    kolonne_indeks = ["name","id","class","mass","year","latitude","longitude"]
    
    for m in nedslag:
        key = m[kolonne_indeks.index(kolonne)]
        
        if not sortert.get(key):
            sortert[key] = 0 # setter til null hvis den ikke finnes
            
        sortert[key] += m[kolonne_indeks.index("mass")] # legger til massen
        
    return sortert

def lagre_sorterte_nedslag(sortert):
    with open("meteorer.txt", "w") as fil:
        # fil.writelines(sortert)
        for key, val in sortert.items():
            fil.write(str(key) + "," + str(val) + "\n")
                
def hent_sorterte_nedslag():
    sortert = {}
    with open("meteorer.txt", "r") as fil:
        # for linje in fil.read().split("\n"):
        for linje in fil.read().strip().split("\n"):
            data = linje.split(",")
            print(data)
            # sortert[data[0]] = int(data[1])
            sortert[data[0]] = float(data[1])
            
    return sortert


def main():
    meteoritter = les_meteoritter("meteoritter.csv")
    print(meteoritter, "\n")
    sortert = sorter_masse(meteoritter, "year")
    print(sortert, "\n")
    lagre_sorterte_nedslag(sortert)
    sortert2 = hent_sorterte_nedslag()
    print(sortert, sortert2, "\n")

    meteoritter = les_meteoritter("meteoritter.csv")
    sortert = sorter_masse(meteoritter, "year")

    aar = []
    storst = 0
    for item in sortert.items():
        if item[1] > storst:
            # storst = items[1]
            storst = item[1]
            aar = [item[0]]
        elif item[1] == storst:
            aar.append(item[0])

    for a in aar:
        print(f"I {a} var den totale nedslagsmassen {storst}")

if __name__ == "__main__":
    main()