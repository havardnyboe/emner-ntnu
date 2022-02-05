#include "std_lib_facilities.h"
#include "uitilities.h"

void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}

// void swapNumbers(int &a, int &b) {
// }

void createStudent(Student &student) {
    std::cout << "Studentens alder: ";
    std::cin >> student.age;
    std::cout << "Studentens navn: ";
    std::cin >> student.name;
    std::cout << "Studentens studieprogram: ";
    std::cin >> student.studyProgram;
}

void printStudent(const Student &student) {
    std::cout << "Navn:\t\t" << student.name
              << "\nStudieprogram:\t" << student.studyProgram
              << "\nAlder:\t\t" << student.age << std::endl;
}

void isInProgram(const Student &student, const std::string &program) {
    if (student.studyProgram == program) {
        std::cout << "Studenten er i studieprogrammet " << program << std::endl;
    } else {
        std::cout << "Studenten er ikke i studieprogrammet " << program << std::endl;
    }
}
std::string randomizeString(int length, char upperBound, char lowerBound) {
    std::string randomString;
    for (int i = 0; i < length; i++) {
        randomString += (rand() % (upperBound - lowerBound + 1)) + lowerBound;
    }
    return randomString;
}