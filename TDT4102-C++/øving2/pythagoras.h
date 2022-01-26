#include "AnimationWindow.h"
#include "Graph.h"
#include <iostream>

/* OPPGVE 5 - Pythagoras */

void pythagoras() {

    using namespace Graph_lib;
    using namespace TDT4102;

    int windowWidth{650},
        windowHeight{600};

    Point trianglePoint1{250, 200},
        trianglePoint2{250, 400},
        trianglePoint3{400, 400};

    Point squareAPoint1{250, 400},
        squareAPoint2{250, 550},
        squareAPoint3{400, 550},
        squareAPoint4{400, 400};

    Point squareBPoint1{250, 200},
        squareBPoint2{50, 200},
        squareBPoint3{50, 400},
        squareBPoint4{250, 400};

    Point squareCPoint1{250, 200},
        squareCPoint2{400, 400},
        squareCPoint3{600, 250},
        squareCPoint4{450, 50};

    AnimationWindow window{100, 100, windowWidth, windowHeight, "Pythagoras"};

    window.draw_triangle(trianglePoint1, trianglePoint2, trianglePoint3, Color::black);
    window.draw_quad(squareAPoint1, squareAPoint2, squareAPoint3, squareAPoint4, Color::red);
    window.draw_quad(squareBPoint1, squareBPoint2, squareBPoint3, squareBPoint4, Color::green);
    window.draw_quad(squareCPoint1, squareCPoint2, squareCPoint3, squareCPoint4, Color::blue);

    window.wait_for_close();
}