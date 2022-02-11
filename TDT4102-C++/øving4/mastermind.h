#include <iostream>
#pragma once

constexpr int SIZE{4};
constexpr int LETTERS{6};

int checkCharactersAndPosition(std::string code, std::string guess);
int checkCharacters(std::string code, std::string guess);

void playMastermind();
void playMastermindVisual();
