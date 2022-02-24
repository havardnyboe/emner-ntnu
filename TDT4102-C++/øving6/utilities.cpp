#include "utilities.h"

string CourseCatalog::getCourse(string courseCode) {
    for (auto &elem : courses) {
        if (elem.first == courseCode) {
            return elem.second;
        }
    }
    return "";
}

void CourseCatalog::loadCourses(string filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Fant ikke filen " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string courseCode, courseName;
        getline(ss, courseCode, ',');
        getline(ss, courseName);
        addCourse(courseCode, courseName);
    }
}

void CourseCatalog::saveCourses(string filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Fant ikke filen " << filename << endl;
        return;
    }
    for (auto &elem : courses) {
        file << elem.first << "," << elem.second << endl;
    }
}

ostream &operator<<(ostream &os, const CourseCatalog &catalog) {
    for (auto &elem : catalog.courses) {
        os << elem.first << " - " << elem.second << endl;
    }
    return os;
}

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

string inputTxtFileName() {
    string filename;
    cout << "Skriv inn filnavn: ";
    cin >> filename;
    return "txt/" + filename + ".txt";
}

ifstream openFile(string filename) {
    ifstream infile(filename);
    if (!infile) {
        cout << "File " << filename << " could not be opened.\n";
        exit(1);
    }
    return infile;
}

vector<Temps> readTemps(string filename) {
    ifstream infile(filename);
    if (!infile) {
        cout << "File " << filename << " could not be opened.\n";
        exit(1);
    }
    vector<Temps> temps;
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        Temps t;
        ss >> t.max >> t.min;
        temps.push_back(t);
    }
    return temps;
}

void tempStats(vector<Temps> temps) {
    int minDay = 0;
    int maxDay = 0;
    double minTemp = temps.at(0).min;
    double maxTemp = temps.at(0).max;
    for (int i = 0; i < temps.size(); i++) {
        if (temps.at(i).min < minTemp) {
            minTemp = temps.at(i).min;
            minDay = i;
        }
        if (temps.at(i).max > maxTemp) {
            maxTemp = temps.at(i).max;
            maxDay = i;
        }
    }
    cout << "Dag " << minDay << " hadde den laveste temperaturen på " << minTemp << " grader." << endl;
    cout << "Dag " << maxDay << " hadde den høyeste temperaturen på " << maxTemp << " grader." << endl;
}

void writeInputToFile(string filename) {
    ofstream outfile(filename, ios_base::app);
    string input;
    cout << "Write a word and press enter. Type 'quit' to quit.\n";
    while (cin >> input) {
        if (input == "quit")
            break;
        outfile << input << '\n';
    }
}

void readFileAndAddLineNumbers(string filename) {
    ifstream infile = openFile(filename);
    ofstream outfile("txt/output.txt");
    string line;
    int line_number = 1;
    while (getline(infile, line)) {
        outfile << line_number << ": " << line << '\n';
        ++line_number;
    }
}

void countCharactersInFile(string filename) {
    ifstream infile = openFile(filename);
    string line;
    array<pair<char, int>, 26> letterCount;
    for (char c = 'a'; c <= 'z'; c++) {
        letterCount.at(c - 'a') = pair<char, int>{c, 0};
    }
    while (getline(infile, line)) {
        for (char c : line) {
            if (tolower(c) >= 'a' && c <= 'z') {
                letterCount.at(tolower(c) - 'a').second++;
            }
        }
    }
    for (auto &p : letterCount) {
        cout << p.first << ": " << p.second << '\n';
    }
}
