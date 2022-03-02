#include "std_lib_facilities.h"

int foo() {
    int total{0};
    if (total % 2 == 0) {
        int total{1};
    } else {
        int total{2};
    }
    return total;
}

void swqp(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

enum class Byer { Kristiansand,
                  Bergen,
                  Trondheim = 42,
                  Krikenes
};

int a = func(1);

bool func(bool b) {
    if (b) {
        return func(!b);
    }
    return 10;
}

class Person {
  private:
    string name;

  public:
    Person(string name);
};

Person::Person(string name) {
    name = name;
}

int main() {

    cout << foo() << endl;

    char c1 = 'x';
    char c2 = 'y';
    swap(c1, c2);
    cout << (c2 > c1) << endl;

    int a = static_cast<int>(Byer::Kristiansand);
    int b = static_cast<int>(Byer::Bergen);
    int c = a + b;
    c += static_cast<int>(Byer::Trondheim);
    int d = c + static_cast<int>(Byer::Krikenes);
    cout << d << endl;
}
