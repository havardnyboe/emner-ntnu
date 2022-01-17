// Lecture 3, Example 1 - Bart Iver van Blokland

#include "std_lib_facilities.h"

int main() {
    vector<int> numberList;
    cout << "The number list initially contains " << numberList.size() << " elements." << endl;

    numberList.push_back(4);
    numberList.push_back(2);
    cout << "The number list now contains " << numberList.size() << " element." << endl;
    cout << "The element at index 0 is: " << numberList.at(0) << endl;

    numberList.at(0) = 7;
    cout << "The element at index 0 is: " << numberList.at(0) << endl;


    // Iterating through a vector
    for(int i = 0; i < numberList.size(); i++) {
        numberList.at(i) += 10;
    }

    // Printing out the contents of a vector
    cout << "The vector numberList contains: [";
    for(int i = 0; i < numberList.size(); i++) {
        cout << numberList.at(i);
        if(i < numberList.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;


    return 0;
}
