#include "std_lib_facilities.h"
#include "tests.h"
#include "uitilities.h"

int main() {

    bool keepRunning{true};
    int menuPane{0};

    srand(time(nullptr));

    while (keepRunning) {
        std::cout << std::endl
                  << "--------------\n"
                  << "Velg Funksjon:\n\n"
                  << "0) Avslutt\n"
                  << "1) Test call by value\n"
                  << "2) Test call by value reference\n"
                  << "3) Lag en student\n"
                  << "4) Skriv ut studenten\n"
                  << "5) Sjekk om en student er i et studieprogram\n"
                  << std::endl
                  << "Angi valg (0-8): ";
        std::cin >> menuPane;

        clear(); // renser terminalen

        Student student;
        std::string program;
        switch (menuPane) {
        case 0:
            keepRunning = false;
            break;
        case 1:
            testCallByValue();
            break;
        case 2:
            testCallByValueReference();
            break;
        case 3:
            createStudent(student);
            clear();
            printStudent(student);
            break;
        case 4:
            printStudent(student);
            break;
        case 5:
            std::cout << "Studieprogram: ";
            std::cin >> program;
            isInProgram(student, program);
            break;
        default:
            std::cout << "Ikke en gyldig menu, velg på nytt.";
            break;
        }
    }
}
