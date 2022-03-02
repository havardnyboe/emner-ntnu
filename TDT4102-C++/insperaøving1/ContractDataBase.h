#pragma once
#include "std_lib_facilities.h"
#include "InsuranceContract.h"

class ContractDataBase
{
public:
    ContractDataBase() {}                                          
    vector<InsuranceContract> getDataBase() { return contracts; } // Can be used for debugging purposes.
    InsuranceContract getContract(int id);
    int numberOfInsuranceType(InsuranceType type);
    int addContract(string holderName, InsuranceType insType, int value);
    void saveContracts(string filename);

    //Function for loading contracts to the database from a file. Already implemented.
    void loadContracts(string filename); 

private:
    vector<InsuranceContract> contracts;
};
