#include "AnimationWindow.h"
#include "Graph.h"
#include "functions.h"
#include "pythagoras.h"
// #include "std_lib_facilities.h"
#include <iostream>

int main() {

    bool keepRunning{true};
    int menuPane{0};

    while (keepRunning) {
        std::cout << std::endl
                  << "--------------\n"
                  << "Velg Funksjon:\n\n"
                  << "0) Avslutt\n"
                  << "1) Summer to tall\n"
                  << "2) Summer fler tall\n"
                  << "3) Konverter fra NOK til EUR\n"
                  << "4) Gjør om sekunder til lesbar tid\n"
                  << "5) Lag en n * m gangetabell\n"
                  << "6) Regn ut andregrads likning\n"
                  << "7) Pythagoras grafisk demo\n"
                  << "8) Rente utregning\n"
                  << std::endl
                  << "Angi valg (0-8): ";
        std::cin >> menuPane;

        clear(); // renser terminalen

        switch (menuPane) {
        case 0:
            keepRunning = false;
            break;
        case 1:
            inputIntegersAndPrintSum();
            break;
        case 2:
            sumOfIntegersLoopAndPrint();
            break;
        case 3:
            NOKtoEURAndPrint();
            break;
        case 4:
            printHumanReadableTime(inputInteger("Skrv inn tid i sekunder: "));
            break;
        case 5:
            printOutTimesTable();
            break;
        case 6:
            solveQuadraticEquation();
            break;
        case 7:
            pythagoras();
            break;
        case 8:
            printBalance(calculateBalance(
                inputInteger("Skriv inn en startsaldo: "),
                inputDouble("Skriv inn en rentesats (i %): "),
                inputInteger("Skriv inn antall år: ")));
            break;
        default:
            std::cout << "Ikke en gyldig menu, velg på nytt.";
            break;
        }
    }
}