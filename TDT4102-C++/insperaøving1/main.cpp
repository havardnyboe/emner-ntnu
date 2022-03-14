#include "ContractDataBase.h"
#include "InsuranceContract.h"
#include "Utilities.h"
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------'

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    ContractDataBase db{};
    db.loadContracts("DataBase.txt");
    InsuranceContract contract{"Jonas Lie", InsuranceType::Car, 1000, 1242, ""};
    // You can test your code under here

    // cout << contract << endl;

    // cout << db.addContract("Leif Juster", InsuranceType::Contents, 10000) << endl;

    // db.saveContracts("DataBase.txt");

    cout << toGreek("Hei, jeg er Leif Juster") << endl;

    vector<vector<string>> svadaVec = loadSvada();

    return 0;
}

//------------------------------------------------------------------------------
