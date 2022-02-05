#pragma once

void clear();

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes);

struct Student {
    std::string name;
    std::string studyProgram;
    int age;
};

void createStudent(Student &student);
void printStudent(const Student &student);
void isInProgram(const Student &student, const std::string &program);