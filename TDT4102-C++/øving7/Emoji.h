#pragma once
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji {
  public:
    virtual void draw(AnimationWindow &) = 0;
    virtual ~Emoji(){}; // destruktør
};

class Face : public Emoji {
  protected:
    Point center;
    int radius;

  public:
    Face(Point c, int r) : center{c}, radius{r} {};
    virtual void draw(AnimationWindow &win);
    virtual ~Face(){}; // destruktør
};

class EmptyFace : public Face {
  public:
    EmptyFace(Point c, int r) : Face{c, r} {};
    virtual void draw(AnimationWindow &win);
    virtual ~EmptyFace(){}; // destruktør
};

class SmileyFace : public EmptyFace {
  public:
    SmileyFace(Point c, int r) : EmptyFace{c, r} {};
    virtual void draw(AnimationWindow &win);
    virtual ~SmileyFace(){}; // destruktør
};

class SadFace : public EmptyFace {
  public:
    SadFace(Point c, int r) : EmptyFace{c, r} {};
    virtual void draw(AnimationWindow &win);
    virtual ~SadFace(){}; // destruktør
};

class AngryFace : public EmptyFace {
  public:
    AngryFace(Point c, int r) : EmptyFace{c, r} {};
    virtual void draw(AnimationWindow &win);
    virtual ~AngryFace(){}; // destruktør
};

class WinkFace : public EmptyFace {
  public:
    WinkFace(Point c, int r) : EmptyFace{c, r} {};
    virtual void draw(AnimationWindow &win);
    virtual ~WinkFace(){}; // destruktør
};

class SurprisedFace : public EmptyFace {
  public:
    SurprisedFace(Point c, int r) : EmptyFace{c, r} {};
    virtual void draw(AnimationWindow &win);
    virtual ~SurprisedFace(){}; // destruktør
};