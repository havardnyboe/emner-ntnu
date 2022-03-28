#pragma once
#include "std_lib_facilities.h"

class Car {
  private:
    int freeSeats;

  public:
    Car(int seats);
    bool hasFreeSeats() const;
    int getFreeSeats() const;
    void reserveFreeSeat();
};

class Person {
  private:
    string name;
    string email;
    unique_ptr<Car> car;

  public:
    Person(string name, string email, unique_ptr<Car> car = nullptr);
    string getName() const;
    string getEmail() const;
    void setEmail(string email);
    bool hasAvailableSeats() const;
    friend ostream &operator<<(ostream &os, const Person &p);
};