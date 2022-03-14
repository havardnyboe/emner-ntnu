#include "Utilities.h"

string toGreek(string sentence) {
    // BEGIN: 2a

    // Write your answer to assignment 2a here, between the // BEGIN: 2a
    // and // END: 2a comments. Remove the code that is already there.

    string greekSentence = "";

    for (char c : sentence) {
        if (c != ' ')
            greekSentence += c + 2;
        else
            greekSentence += c;
    }

    return greekSentence;

    // END: 2a
}

vector<vector<string>> loadSvada() {
    // BEGIN: 2b

    // Write your answer to assignment 2b here, between the // BEGIN: 2b
    // and // END: 2b comments. Remove the code that is already there.

    vector<vector<string>> svadaVec{{}};
    ifstream svadaFile("SvadaWords.txt");
    int i = 0;
    string line;
    while (svadaFile.is_open()) {
        getline(svadaFile, line);
        if (line == "") {
            svadaFile.close();
            break;
        } else if (line == "||\r") {
            svadaVec.push_back(vector<string>());
            i++;
        } else {
            svadaVec.at(i).push_back(line);
        }
    }

    // END: 2b
}

string svadaGenerator(vector<vector<string>> svadaVec) {
    // BEGIN: 2c1

    // Write your answer to assignment 2c1 here, between the // BEGIN: 2c1
    // and // END: 2c1 comments. Remove the code that is already there.

    (void)svadaVec;
    return "";

    // END: 2c1
}