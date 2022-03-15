#include "dummyTest.h"

void dummyTest() {
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c = a;
    std::cout << "a: " << *a.num << "\n";
    std::cout << "b: " << *b.num << "\n";
    std::cout << "c: " << *c.num << "\n";

    *b.num = 3;
    *c.num = 5;

    std::cout << "a: " << *a.num << "\n";
    std::cout << "b: " << *b.num << "\n";
    std::cout << "c: " << *c.num << "\n";

    std::cout << "\nb) Feilmeldingen betyr at når programmet prøver å slette perekene b og c som peker til a vil det feile fordi a ikke eksisterer lenger.\n";
    std::cout << "\nc) b er ikke lenger 5 men 3 fordi den ikke lenger en en peker til a\n\n";
}