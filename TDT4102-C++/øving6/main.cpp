#include "std_lib_facilities.h"

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
    ifstream infile(filename);
    ofstream outfile("output.txt");
    string line;
    if (!infile) {
        cout << "File not found.\n";
        return;
    }
    int line_number = 1;
    while (std::getline(infile, line)) {
        outfile << line_number << ": " << line << '\n';
        ++line_number;
    }
}

void countCharactersInFile(string filename) {
    array<map<char, int>, 26> charCount;
    for (char c{'a'}; c <= 'z'; c++) {
        charCount.at(c - 'a').insert({c, 0});
    }
}

int main() {
    writeInputToFile("opg1a.txt");
    readFileAndAddLineNumbers("opg1a.txt");
    return 0;
}
