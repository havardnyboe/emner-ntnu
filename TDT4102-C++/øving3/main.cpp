#include "cannonball.h"
#include "std_lib_facilities.h"
#include "utilities.h"

void testDeviation(double compareOperand, double toOperand, double maxError, std::string name);

int main() {
    //     const double maxError{0.00001};

    //     testDeviation(velY(25.0, 2.5), 0.475, maxError, "velY(25.0, 2.5)");
    //     testDeviation(velY(25.0, 5.0), -24.05, maxError, "velY(25.0, 5.0)");

    //     testDeviation(posX(0.0, 50.0, 2.5), 125.0, maxError, "posX(0.0,50.0,2.5)");
    //     testDeviation(posX(0.0, 50.0, 5.0), 250.0, maxError, "posX(0.0,50.0,5.0)");

    //     testDeviation(posY(0.0, 25.0, 2.5), 31.84, maxError, "posY(0.0, 25.0, 2.5)");
    //     testDeviation(posY(0.0, 25.0, 5.0), 2.375, maxError, "posY(0.0, 25.0, 5.0)");
    // }

    // void testDeviation(double compareOperand, double toOperand, double maxError, std::string name) {
    //     if (std::abs(compareOperand - toOperand) > maxError) {
    //         std::cout << "Test feilet for " << name << ": " << compareOperand << " != " << toOperand << std::endl;
    //     } else {
    //         std::cout << "Testet " << name << ": " << compareOperand << " og " << toOperand << " er tilnærmet like." << std::endl;
    //     }

    // cout << checkIfDistanceToTargetIsCorrect() << endl;

    srand(unsigned(time(nullptr)));

    playTargetPractice();
}