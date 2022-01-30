#include "cannonball.h"
#include "std_lib_facilities.h"

double acclY() { return -9.81; } // akselerasjon i y-retning

double velY(double initVelocity, double time) {
    return initVelocity + acclY() * time;
}

double posX(double initPosition, double initVelocity, double time) {
    return initPosition + initVelocity * time;
}

double posY(double initPosition, double initVelocity, double time) {
    return initPosition + initVelocity * time + (acclY() * time * time) / 2;
}

double flightTime(double initVelocity) {
    return (-2 * initVelocity) / acclY();
}

// skriver om sekunder til et lesbart format
void printTime(double seconds) {
    int h = seconds / 3600,
        m = (static_cast<int>(seconds) % 3600) / 60,
        s = static_cast<int>(seconds) % 60;
    std::cout << h << " time(r), "
              << m << " minutt(er) og "
              << s << " sekund(er)"
              << std::endl;
}

double getUserInputTheta() {
    double theta{0};
    std::cout << "Skriv inn en vinkel: ";
    std::cin >> theta;
    return theta;
}

double getUserInputAbsVelocity() {
    double vel{0};
    std::cout << "Skriv inn fart: ";
    std::cin >> vel;
    return std::abs(vel);
}

double degToRad(double deg) { return deg * M_PI / 180; }

// Returnerer henholdsvis farten i x- og y-retning
double getVelocityX(double theta, double absVelocity) { return absVelocity * cos(theta); }
double getVelocityY(double theta, double absVelocity) { return absVelocity * sin(theta); }

std::array<double, 2> getVelocityVector(double theta, double absVelocity) {
    return std::array<double, 2>{getVelocityX(theta, absVelocity),
                                 getVelocityY(theta, absVelocity)};
}

double getDistanceTraveled(double velocityX, double velocityY) {
    return;
}