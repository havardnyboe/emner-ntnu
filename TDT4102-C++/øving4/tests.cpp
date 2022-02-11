#include "std_lib_facilities.h"
#include "uitilities.h"

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    std::cout << "v0: " << v0
              << " increment: " << increment
              << " iterations: " << iterations
              << " result: " << result << std::endl;
}

void testCallByValueReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    std::cout << "v0: " << v0
              << " increment: " << increment
              << " iterations: " << iterations;
    incrementByValueNumTimesRef(v0, increment, iterations);
    std::cout << " result: " << v0 << std::endl;
}
void testString() {
    std::string grades;
    grades = randomizeString(8, 'A', 'F');
    std::cout << "Grades: " << grades << std::endl;
}

void testGradeCount() {
    std::string grades;
    std::vector<pair<char, int>> gradeCount{};
    grades = randomizeString(8, 'A', 'F');

    for (char i{'A'}; i <= 'F'; ++i) {
        gradeCount.push_back(std::make_pair(i, countChar(grades, i)));
    }
    std::cout << "Grades: " << grades << std::endl;
    std::cout << "GradeCount: ";
    for (auto &grade : gradeCount) {
        std::cout << grade.first << ": " << grade.second << " ";
    }
    std::cout << std::endl;

    std::cout << "Average: " << averageGrade(grades) << std::endl;
}