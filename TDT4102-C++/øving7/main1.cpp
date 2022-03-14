#include "std_lib_facilities.h"
#include "Emoji.h"


class Animal {
  protected:
    string name;
    int age;

  public:
    Animal(string n, int a) : name(n), age(a) {}
    virtual ~Animal() {}
    virtual string toString() {
        return "Animal: " + name + " " + to_string(age);
    }
};

class Cat : public Animal {
  public:
    Cat(string n, int a) : Animal(n, a) {}
    string toString() {
        return "Cat: " + name + " " + to_string(age);
    }
};

class Dog : public Animal {
  public:
    Dog(string n, int a) : Animal(n, a) {}
    string toString() {
        return "Dog: " + name + " " + to_string(age);
    }
};

void testAnimal() {
    Animal animal("Bob", 11);
    Cat cat("Rob", 21);
    Dog dog("John", 34);
    cout << animal.toString() << endl;
    cout << cat.toString() << endl;
    cout << dog.toString() << endl;
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(make_unique<Cat>("Sivert", 13));
    animals.emplace_back(make_unique<Dog>("Sivert", 13));
    animals.emplace_back(make_unique<Cat>("Sivert", 13));
    for (auto &a : animals) {
        cout << a->toString() << endl;
    }
}

int main() {
    testAnimal();
}
