#include "Emoji.h"

// crate a abstract class Face which inherits from Emoji and has a pure virtual function draw()
class Face : public Emoji {
  protected:
    Point center;
    int radius;

  public:
    virtual void draw(AnimationWindow &) = 0;
    virtual Face(Point, int);
    virtual ~Face(){}; // destruktør
};
