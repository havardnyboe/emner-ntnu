#include "utilities.h"

const map<string, string> capitalsMap{{"Norway", "Oslo"}, {"Sweden", "Stockholm"}, {"Denmark", "Copenhagen"}};
string getCapital(const string &country) {
    return capitalsMap.at(country);
}

int main() {
    bool keepRunning{true};
    int choice;
    CourseCatalog ntnu;
    ntnu.loadCourses("txt/courses.txt");

    while (keepRunning) {
        std::cout << std::endl
                  << "--------------\n"
                  << "Velg Funksjon:\n\n"
                  << "0: Avslutt\n"
                  << "1. Skriv input til fil\n"
                  << "2. Les fil og legg til linenummer\n"
                  << "3. Tell bokstaver i fil\n"
                  << "4. Debuggeroppgave (getCapital)\n"
                  << "5. Legg til emne\n"
                  << "6. Endre emnenavn\n"
                  << "7. Fjern emne\n"
                  << "8. Skriv ut emner\n"
                  << "9. Finn min og max temperatur\n"
                  << std::endl
                  << "Angi valg: ";
        std::cin >> choice;
        clearScreen();

        switch (choice) {
        case 0:
            keepRunning = false;
            ntnu.saveCourses("txt/courses.txt");
            break;
        case 1:
            writeInputToFile(inputTxtFileName());
            break;
        case 2:
            readFileAndAddLineNumbers(inputTxtFileName());
            break;
        case 3:
            countCharactersInFile(inputTxtFileName());
            break;
        case 4:
            cout << "Capitals:\n";
            for (auto &elem : capitalsMap) {
                cout << getCapital(elem.first) << endl;
            }
            std::cout << "\nFeilmeldingen var at operatoren [] var ugyldig for map, endret den til å bruke .at()\n";
            break;
        case 5: {
            string courseName, courseCode;
            std::cout << "Skriv inn emnekode: ";
            std::cin >> courseCode;
            std::cout << "Skriv inn emnenavn: ";
            std::cin >> courseName;
            ntnu.addCourse(courseCode, courseName);
            ntnu.saveCourses("txt/courses.txt");
            std::cout << "Emnet er lagt til.\n";
            break;
        }
        case 6: {
            string courseCode, newCourseName;
            std::cout << "Skriv inn emnekode: ";
            std::cin >> courseCode;
            std::cout << "Skriv inn nytt emnenavn: ";
            std::cin >> newCourseName;
            ntnu.updateCourseName(courseCode, newCourseName);
            ntnu.saveCourses("txt/courses.txt");
            std::cout << "Emnet er oppdatert.\n";
            break;
        }
        case 7: {
            string courseCode;
            std::cout << "Skriv inn kurskode: ";
            std::cin >> courseCode;
            std::cout << "Emnet " << ntnu.getCourse(courseCode) << " er fjernet.\n";
            ntnu.removeCourse(courseCode);
            ntnu.saveCourses("txt/courses.txt");
            break;
        }
        case 8:
            ntnu.printCourses();
            break;
        case 9: {
            vector<Temps> temps = readTemps("txt/temperatures.txt");
            tempStats(temps);
            break;
        }
        default:
            std::cout << "Ugyldig valg.\n";
            break;
        }
    }

    return 0;
}
