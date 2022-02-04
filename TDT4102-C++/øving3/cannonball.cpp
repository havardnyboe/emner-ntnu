#include "cannonball.h"
#include "std_lib_facilities.h"
#include "utilities.h"

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
double getVelocityX(double theta, double absVelocity) { return absVelocity * std::cos(degToRad(theta)); }
double getVelocityY(double theta, double absVelocity) { return absVelocity * std::sin(degToRad(theta)); }

std::array<double, 2> getVelocityVector(double theta, double absVelocity) {
    return std::array<double, 2>{getVelocityX(theta, absVelocity),
                                 getVelocityY(theta, absVelocity)};
}

double getDistanceTraveled(double velocityX, double velocityY) {
    return velocityX * flightTime(velocityY);
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}

// opg 4 e)

// bool checkIfDistanceToTargetIsCorrect() {
//     double error = targetPractice(0, 0, 0);
//     if (error == 0)
//         return true;
// }
/*
    får advarsel om at funksjonen ikke returnerer en verdi for alle utfall,
    eks når error ikke er lik 0.
*/

void playTargetPractice() {
    int distanceToTarget = randomWithLimits(100, 1000);
    int maxTries{10};
    bool hasWon{false};

    for (int i{1}; i <= maxTries; ++i) {
        double absVel = getUserInputAbsVelocity();
        double theta = getUserInputTheta();
        double distanceBetweenTargetAndBall = targetPractice(distanceToTarget, getVelocityX(theta, absVel), getVelocityY(theta, absVel));

        clearTerminal();
        if (std::abs(distanceBetweenTargetAndBall) <= 5) {
            hasWon = true;
        } else if (distanceBetweenTargetAndBall < 0) {
            std::cout
                << "Skuddet var for langt." << std::endl;
        } else {
            std::cout << "Skuddet var for kort." << std::endl;
        }

        std::cout << "Kulen landet "
                  << std::abs(distanceBetweenTargetAndBall)
                  << "m unna blinken."
                  << std::endl
                  << "Kulen brukte ";
        printTime(flightTime(getVelocityY(theta, absVel)));
        std::cout << std::endl
                  << "Du har "
                  << maxTries - i
                  << " skudd igjen."
                  << std::endl;

        if (hasWon) {
            std::cout << "Gratulerer du vant!" << std::endl;
            break;
        }
        if (maxTries - i == 0) {
            std::cout << "Du tapte! Prøv igjen!" << std::endl;
        }
    }
}