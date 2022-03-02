#pragma once
#include "std_lib_facilities.h"

enum class InsuranceType
{
    Car,
    Contents,
    Travel
};

class InsuranceContract
{
    string holderName;
    InsuranceType insType;
    int value;
    int id;
    string insuranceText;

public:
    InsuranceContract(string holderName, InsuranceType insType, int value, int id, string insText = "Text missing!");

    int getId() { return id; }
    int getValue() { return value; }
    string getHolder() { return holderName; }
    InsuranceType getInsuranceType() { return insType; }
    string getInsuranceText() { return insuranceText; }

    // Defaultconstructor, not relevant for the assignment.
    InsuranceContract() { InsuranceContract("", InsuranceType::Car, -1, -1, ""); } 
};

//Used in ContractDataBase::loadContracts(). 
const map<string, InsuranceType> stringToInsuranceType{
            {"Car", InsuranceType::Car}, {"Contents", InsuranceType::Contents}, {"Travel", InsuranceType::Travel}};

string insuranceTypeToString(InsuranceType t);

ostream &operator<<(ostream &os, InsuranceContract obj);
