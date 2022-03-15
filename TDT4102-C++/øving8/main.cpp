#include "dummyTest.h"
#include "utilities.h"

int main() {

    Matrix a(4, 6);
    Matrix b(5);

    bool running{true};
    int choice{0};
    while (running) {
        std::cout << std::endl
                  << "--------------" << std::endl
                  << "Velg en funksjon:" << std::endl
                  << std::endl
                  << "0: Avslutt" << std::endl
                  << "1: Generer Fibonacci" << std::endl
                  << "2: Skriv ut en matrise" << std::endl
                  << "3: Legg til en verdi i en matrise" << std::endl
                  << "4: Dummy test" << std::endl
                  << "5: Kopiering- og tilordningtest" << std::endl
                  << "6: Operatoroverlasting" << std::endl
                  << std::endl
                  << "Angi valg: ";
        std::cin >> choice;
        clearScreen();
        switch (choice) {
        case 0:
            running = false;
            break;
        case 1:
            createFibonacci();
            break;
        case 2: {
            std::string input;
            std::cout << "Hvilken matrise vil du skrive ut? (a, b): ";
            std::cin >> input;
            if (input == "a") {
                std::cout << a << std::endl;
            } else if (input == "b") {
                std::cout << b << std::endl;
            } else {
                std::cout << "Ugyldig input" << std::endl;
            }
            break;
        }
        case 3: {
            std::string input;
            std::cout << "Hvilken matrise vil du legge til verdi i? (a, b): ";
            std::cin >> input;
            if (input == "a") {
                addValueToMatrix(a);
            } else if (input == "b") {
                addValueToMatrix(b);
            } else {
                std::cout << "Ugyldig input" << std::endl;
            }
            break;
        }
        case 4:
            dummyTest();
            break;
        case 5: {
            Matrix c{a};
            Matrix d = b;

            std::cout << "a:\n"
                      << a << std::endl;
            std::cout << "b:\n"
                      << b << std::endl;
            std::cout << "c:\n"
                      << c << std::endl;
            std::cout << "d:\n"
                      << d << std::endl;
            break;
        }
        case 6: {
            Matrix a(2, 2), b(2, 2), c(2, 2);
            a.set(0, 0, 1);
            a.set(0, 1, 2);
            a.set(1, 0, 3);
            a.set(1, 1, 4);
            b.set(0, 0, 4);
            b.set(0, 1, 3);
            b.set(1, 0, 2);
            b.set(1, 1, 1);
            c.set(0, 0, 1);
            c.set(0, 1, 3);
            c.set(1, 0, 1.5);
            c.set(1, 1, 2);

            std::cout << "a:\n"
                      << a << std::endl
                      << "b:\n"
                      << b << std::endl
                      << "c:\n"
                      << c << std::endl;
            std::cout << "a += b + c:\n"
                      << a + b + c;
            break;
        }
        default:
            std::cout << "Ugyldig valg" << std::endl;
            break;
        }
    }
    return 0;
}
