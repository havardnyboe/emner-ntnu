#include "Car.h"

Car::Car(int seats) {
    this->freeSeats = seats;
}
bool Car::hasFreeSeats() const {
    return freeSeats > 0;
}
int Car::getFreeSeats() const {
    return freeSeats;
}
void Car::reserveFreeSeat() {
    --freeSeats;
}

Person::Person(string name, string email, unique_ptr<Car> car) {
    this->name = name;
    this->email = email;
    this->car = move(car);
}
string Person::getName() const {
    return name;
}
string Person::getEmail() const {
    return email;
}
void Person::setEmail(string email) {
    this->email = email;
}
bool Person::hasAvailableSeats() const {
    return car ? car->hasFreeSeats() : false;
}
ostream &operator<<(ostream &os, const Person &p) {
    os << p.name << " (" << p.email << ")";
    if (p.car) {
        os << " has a car with " << p.car->getFreeSeats() << " free seats";
    }
    return os;
}