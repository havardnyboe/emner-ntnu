#include "std_lib_facilities.h"

void writeInputToFile(string filename) {
    std::ofstream outfile;
    outfile.open(filename);
    std::string input;
    cout << "Write a word and press enter. Type 'quit' to quit.\n";
    while (cin >> input) {
        if (input == "quit")
            break;
        outfile << input << '\n';
    }
}

int main() {
    writeInputToFile("opg1a.txt");
    return 0;
}
