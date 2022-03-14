#pragma once
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji {
  public:
    virtual void draw(AnimationWindow &) = 0;
    virtual ~Emoji(){}; // destruktør
};
