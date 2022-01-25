#include <iostream>

void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

/* OPPGAVE 1 - Funksjoner og "Input/Output" */

//  a)
void inputAndPrintInteger() {
    int i{0};
    clear();
    std::cout << "Skriv inn et heltall: ";
    std::cin >> i;
    std::cout << "Du skrev: " << i << '\n';
}

//  b)
int inputInteger() {
    int i{0};
    std::cout << "Skriv inn et heltall: ";
    std::cin >> i;
    return i;
}

//  c)
void inputIntegersAndPrintSum() {
    int num1 = inputInteger(),
        num2 = inputInteger(),
        sum = num1 + num2;
    std::cout << "Summen av " << num1
              << " og " << num2
              << " er " << sum
              << std::endl;
}

//  d)
/*
    jeg valgte inputInteger fordi det var lettere å bruke returverdien,
    og selv velge når jeg skrev ut til skjermen,
    enn å forholde meg til inputIntegerAndPrintSum
*/

//  e)
bool isOdd(int i) {
    if (i % 2 == 0)
        return false;
    return true;
}

//  f)
void printHumanReadableTime(int s) {
    int hours = s / 3600,
        minutes = (s % 3600) / 60,
        seconds = s % 60;
    std::cout << hours << " time(r), "
              << minutes << " minutt(er) og "
              << seconds << " sekund(er)"
              << std::endl;
}

/* OPPGAVE 2 - Løkker */

// a)
void sumOfIntegers() {
    int numberOfIntegers{0}, sum{0};
    std::cout << "Hvor mange tall vil du legge sammen?: ";
    std::cin >> numberOfIntegers;
    for (int i = 0; i < numberOfIntegers; i++) {
        int tmp{0};
        std::cout << "Skriv inn et heltall: ";
        std::cin >> tmp;
        sum += tmp;
    }
    std::cout << "Summen av tallene er " << sum << std::endl;
}

// b)
void sumOfIntegersLoop() {
    int input{1}, sum{0};
    while (input) {
        std::cout << "Skriv inn et heltall: ";
        std::cin >> input;
        sum += input;
    }
    std::cout << "Summen av tallene er " << sum << std::endl;
}

// c)
/*
    for løkken er best egnet til oppgave a fordi det skal itereres x andtall ganger,
    while løkken er best egnet til oppgave b fordi det skal itereres til en betingelse er sann.
*/

// d)
