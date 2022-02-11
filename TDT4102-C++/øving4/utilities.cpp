#include "std_lib_facilities.h"
#include "uitilities.h"

void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i{0}; i < numTimes; ++i) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes) {
    for (int i{0}; i < numTimes; ++i) {
        startValue += increment;
    }
}

void swapNumbers(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void createStudent(Student &student) {
    std::cout << "Studentens navn: ";
    std::cin >> student.name;
    std::cout << "Studentens alder: ";
    std::cin >> student.age;
    std::cout << "Studentens studieprogram: ";
    std::cin >> student.studyProgram;
}

void printStudent(const Student &student) {
    std::cout << "Navn:\t\t" << student.name
              << "\nAlder:\t\t" << student.age
              << "\nStudieprogram:\t" << student.studyProgram
              << std::endl;
}

void isInProgram(const Student &student, const std::string &program) {
    if (student.studyProgram == program) {
        std::cout << "Studenten er i studieprogrammet " << program << std::endl;
    } else {
        std::cout << "Studenten er ikke i studieprogrammet " << program << std::endl;
    }
}

std::string randomizeString(int length, char lowerBound, char upperBound) {
    std::string randomString;
    for (int i{0}; i < length; ++i) {
        randomString += rand() % (upperBound - lowerBound + 1) + lowerBound;
    }
    return randomString;
}

std::string readInputToString(int length, char lowerBound, char upperBound) {
    std::string input;
    for (int i{0}; i < length; ++i) {
        char c;
        std::cout << "Skriv inn et tegn: ";
        std::cin >> c;
        c = std::toupper(c);
        if (c >= lowerBound && c <= upperBound) {
            input += c;
        } else {
            std::cout << "Ugyldig tegn: " << c << std::endl;
            --i;
        }
    }
    return input;
}

int countChar(const std::string &str, char ch) {
    int count{0};
    for (char c : str) {
        if (c == ch) {
            ++count;
        }
    }
    return count;
}

double averageGrade(const std::string &str) {
    double sum{0};
    std::map<char, int> gradeToNum{{'A', 5}, {'B', 4}, {'C', 3}, {'D', 2}, {'E', 1}, {'F', 0}};
    for (char c : str) {
        sum += gradeToNum.at(c);
    }
    return sum / str.length();
}