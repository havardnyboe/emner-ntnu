#pragma once
#include "std_lib_facilities.h"

struct Temps {
    double min;
    double max;
};

class CourseCatalog {
    map<string, string> courses;

  public:
    void addCourse(string courseCode, string courseName) {
        courses.insert({courseCode, courseName});
    }
    void updateCourseName(string courseCode, string newCourseName) {
        courses[courseCode] = newCourseName;
    }
    void removeCourse(string courseCode) {
        courses.erase(courseCode);
    }
    void printCourses() {
        for (auto &elem : courses) {
            cout << elem.first << " - " << elem.second << endl;
        }
    }
    void loadCourses(string filename);
    void saveCourses(string filename);

    string getCourse(string courseCode);

    friend ostream &operator<<(ostream &, const CourseCatalog &);
};

// istream &operator>>(istream &is, Temps &t) {
//     is >> t.min >> t.max;
//     return is;
// }

string inputTxtFileName();

ifstream openFile(string filename);

vector<Temps> readTemps(string filename);

void tempStats(vector<Temps> temps);

void clearScreen();
void writeInputToFile(string filename);
void readFileAndAddLineNumbers(string filename);
void countCharactersInFile(string filename);