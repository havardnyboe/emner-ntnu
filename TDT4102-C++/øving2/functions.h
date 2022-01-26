#include <iostream>
#include <math.h>
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
void sumOfIntegersAndPrint() {
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
void sumOfIntegersLoopAndPrint() {
    int input{1}, sum{0};
    while (input) {
        std::cout << "Skriv inn et heltall (0 for å avslutte): ";
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
double inputDouble(std::string prompt = "Skriv inn et tall: ") {
    double i{0};
    std::cout << prompt;
    std::cin >> i;
    return i;
}

// e)
double NOKtoEURAndPrint() {
    double exchangeRate{9.75},
        inputInNOK{inputDouble()},
        outputInEUR{0};

    if (inputInNOK < 0) {
        std::cout << "Kan ikke bruke negative tall";
        inputInNOK = inputDouble();
    }

    outputInEUR = inputInNOK / exchangeRate;
    std::cout.precision(3);
    std::cout << inputInNOK << "NOK = " << outputInEUR << "EUR" << std::endl;
    return outputInEUR;
}

// f)
/*
    Man må bruke inputDouble framfor inputInteger for å kunne bruke desimaler.

    Returntypen er double fordi funskjonen bruker og regner med flyttall.
*/

/* OPPGAVE 3 - Menysystem */

// b)
void printOutTimesTable() {
    int width = inputInteger();
    int height = inputInteger();
    clear();
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            std::cout << i * j << '\t';
        }
        std::cout << std::endl;
    }
}

/* OPPGAVE 4 */

// a)
double discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}

// b)
void printRealRoots(double a, double b, double c) {
    double discriminantValue = discriminant(a, b, c);
    if (discriminantValue < 0) {
        std::cout << "Ingen reelle løsninger" << std::endl;
    } else if (discriminantValue == 0) {
        double root = -b / (2 * a);
        std::cout << "En reell løsning: " << root << std::endl;
    } else {
        double root1 = (-b + sqrt(discriminantValue)) / (2 * a);
        double root2 = (-b - sqrt(discriminantValue)) / (2 * a);
        std::cout << "To reelle løsninger: " << root1 << " og " << root2 << std::endl;
    }
}

void solveQuadraticEquation() {
    double a = inputDouble("Skriv inn a: "),
           b = inputDouble("Skriv inn b: "),
           c = inputDouble("Skriv inn c: ");
    printRealRoots(a, b, c);
}

/* OPPGAVE 6 - Renter med bruk av løkker */

// a)
int calculateBalance(int deposit, int interest, int years) {
    vector<int> balance{deposit};
    for (int i = 0; i < years; i++) {
        double bal = deposit * pow((1 + std::static_cast<double>(interest) / 100), years);
        balance.push_back(bal);
    }
}
