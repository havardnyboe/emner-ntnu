#include "functions.h"
#include "std_lib_facilities.h"

int main() {

    bool keepRunning{true};
    int menuPane{0};

    while (keepRunning) {
        std::cout << std::endl
                  << "------------\n"
                  << "Velg Funksjon:\n\n"
                  << "0) Avslutt\n"
                  << "1) Summer to tall\n"
                  << "2) Summer fler tall\n"
                  << "3) Konverter fra NOK til EUR\n\n"
                  << "Angi valg (0-3): ";
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
        default:
            std::cout << "Ikke en gyldig menu, velg på nytt.";
            break;
        }
    }
}