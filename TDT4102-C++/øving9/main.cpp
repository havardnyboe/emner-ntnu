#include "Car.h"

int main() {
    unique_ptr<Car> car = make_unique<Car>(5);
    Person p1("Ola", "ola@example.com", move(car));
    Person p2("Kari", "kari@example.com");

    cout << p1 << endl;
    cout << p2 << endl;
}