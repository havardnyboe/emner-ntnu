#include "AnimationWindow.h"
#include "Graph.h"
#include "functions.h"
#include "pythagoras.h"
#include "std_lib_facilities.h"

int main() {

    pythagoras();

    bool keepRunning{true};
    int menuPane{0};

    while (keepRunning) {
        std::cout << std::endl
                  << "------------\n"
                  << "Velg Funksjon:\n\n"
                  << "0) Avslutt\n"
                  << "1) Summer to tall\n"
                  << "2) Summer fler tall\n"
                  << "3) Konverter fra NOK til EUR\n"
                  << "4) Lag en n * m gangetabell\n"
                  << "5) Regn ut andregrads likning\n"
                  << "6) Pythagoras grafisk demo\n"
                  << std::endl
                  << "Angi valg (0-6): ";
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
            printOutTimesTable();
            break;
        case 5:
            solveQuadraticEquation();
            break;
        case 6:
            pythagoras();
            break;
        default:
            std::cout << "Ikke en gyldig menu, velg på nytt.";
            break;
        }
    }
}