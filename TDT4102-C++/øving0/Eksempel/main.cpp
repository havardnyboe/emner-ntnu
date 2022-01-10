// Lecture 1, Example 4 - Bart Iver van Blokland
// I cheated a bit for this series of slides in order to keep things simple
// You need a few more lines than what is shown, but not too many.
// (specifically the drawCircle function and a couple of include statements)

#include "AnimationWindow.h"
#include "std_lib_facilities.h"

void drawCircle(Point location, int radius)
{
    // Creates and opens a window, then draws the circle,
    // and finally ensures the window stays open until the user closes it explicitly
    AnimationWindow window;
    window.draw_circle(location, radius);
    window.wait_for_close();
}

int main()
{
    int xCoordinate = 150;
    int yCoordinate = 100;
    int radius = 100;
    drawCircle({xCoordinate, yCoordinate}, radius);
    return 0;
}