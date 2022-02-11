#pragma once

void clear();

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes);
void swapNumbers(int &a, int &b);

struct Student {
    std::string name;
    int age;
    std::string studyProgram;
};

void createStudent(Student &student);
void printStudent(const Student &student);
void isInProgram(const Student &student, const std::string &program);

std::string randomizeString(int length, char lowerBound, char upperBound);
std::string readInputToString(int length, char lowerBound, char upperBound);

int countChar(const std::string &str, char ch);
double averageGrade(const std::string &str);