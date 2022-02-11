#include "masterVisual.h"
#include "mastermind.h"
#include "std_lib_facilities.h"
#include "tests.h"
#include "uitilities.h"

int main() {

    bool keepRunning{true};
    int menuPane{0};

    srand(time(nullptr)); // seed RNG

    Student student{"", 0, ""}; // lager en tom Student

    while (keepRunning) {
        std::cout << std::endl
                  << "--------------\n"
                  << "Velg Funksjon:\n\n"
                  << "0) Avslutt\n"
                  << "1) Test call by value\n"
                  << "2) Test call by value reference\n"
                  << "3) Test swap\n"
                  << "4) Lag en student\n"
                  << "5) Skriv ut studenten\n"
                  << "6) Sjekk om en student er i et studieprogram\n"
                  << "7) testString \n"
                  << "8) readInputToString \n"
                  << "9) testGradeCount \n"
                  << "10) Mastermind \n"
                  << "11) Mastermind visual (funker ikke :( ) \n"
                  << std::endl
                  << "Angi valg (0-11): ";
        std::cin >> menuPane;
        clear(); // renser terminalen

        switch (menuPane) {
        case 0: {
            keepRunning = false;
            break;
        }
        // opg 1
        case 1: {
            testCallByValue();
            break;
        }
        case 2: {
            testCallByValueReference();
            break;
        }
        case 3: {
            int a, b;
            std::cout << "Skriv inn et tall (a): ";
            std::cin >> a;
            std::cout << "Skriv inn et tall (b): ";
            std::cin >> b;
            swapNumbers(a, b);
            std::cout << "a: " << a << " b: " << b << std::endl;
            break;
        }
        // opg 2
        case 4: {
            createStudent(student);
            clear();
            printStudent(student);
            break;
        }
        case 5: {
            printStudent(student);
            break;
        }
        case 6: {
            std::string program;
            std::cout << "Studieprogram: ";
            std::cin >> program;
            isInProgram(student, program);
            break;
        }
        // opg 3
        case 7: {
            testString();
            break;
        }
        case 8: {
            std::cout << readInputToString(10, 'A', 'F') << std::endl;
            break;
        }
        case 9: {
            testGradeCount();
            break;
        }
        // opg 4
        case 10: {
            playMastermind();
            break;
        }
        case 11: {
            playMastermindVisual();
            break;
        }
        default: {
            std::cout << "Ikke en gyldig menu, velg på nytt.";
            break;
        }
        }
    }
}
