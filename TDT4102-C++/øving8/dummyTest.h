#pragma once
#include <iostream>

class Dummy {
  public:
    int *num;
    Dummy() {
        num = new int{0};
    }
    Dummy(const Dummy &d) {
        num = new int{*d.num};
    }
    ~Dummy() {
        delete num;
    }
    Dummy operator=(const Dummy d) {
        *num = *d.num;
        return *this;
    }
};

void dummyTest();