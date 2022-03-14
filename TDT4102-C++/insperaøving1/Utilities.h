#pragma once
#include "std_lib_facilities.h"

string toGreek(string sentence);

vector<vector<string>> loadSvada();

string svadaGenerator(vector<vector<string>> svadaVec);

//Can be used to test the svadaGenerator()-function.
inline vector<vector<string>> testSvadaGenerationVec{
    {"Gitt", "Under hensyntagen til", "I lys av", "Vedroerende"},
    {"en plutselig", "en uforutsett", "en erstatningsmessig", "en kollektiv"},
    {"fornyelse", "risikovurdering", "forsikringstaker", "egenandel"},
    {"omfattes", "utstedes", "iverksettes", "anvendes"},
    {"fornyelsen", "forsikringsbehovet", "vilkaarene", "oppsigelsen"},
    {"innenfor rammen av", "som en foelge av", "under forutsetning av", "med henblikk paa"},
    {"oppgjoeret.", "husstanden", "aarsakssammenhengen", "betingelsene"}};