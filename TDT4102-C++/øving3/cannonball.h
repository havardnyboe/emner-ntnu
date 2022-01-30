#pragma once
#include "std_lib_facilities.h"

double acclY();
double velY(double initVelocity, double time);

// Rengner ut posisjon i x -og y-retning
double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);

double flightTime(double initVelocity);

void printTime(double seconds);

double getUserInputTheta();

double getUserInputAbsVelocity();

double degToRad(double deg);

// Returnerer farten i x- og y-retning
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

std::array<double, 2> getVelocityVector(double theta, double absVelocity);

double getDistanceTraveled(double velocityX, double velocityY);