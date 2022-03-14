#include "Emoji.h"

void Face::draw(AnimationWindow &win) {
    win.draw_circle(center, radius, Color::yellow);
    win.draw_arc(center, radius * 2, radius * 2, 0, 360);
};

void EmptyFace::draw(AnimationWindow &win) {
    Face::draw(win);
    win.draw_circle(Point{center.x - 20, center.y - 10}, radius / 5.5, Color::green);
    win.draw_circle(Point{center.x + 20, center.y - 10}, radius / 5.5, Color::green);
};

void SmileyFace::draw(AnimationWindow &win) {
    EmptyFace::draw(win);
    win.draw_arc(Point{center.x, center.y + 10}, radius * 1.2, radius, 180, 360);
};

void SadFace::draw(AnimationWindow &win) {
    EmptyFace::draw(win);
    win.draw_arc(Point{center.x, center.y + 30}, radius * 1.2, radius, 0, 180);
};

void AngryFace::draw(AnimationWindow &win) {
    Face::draw(win);
    win.draw_circle(Point{center.x - 20, center.y - 10}, radius / 5.5, Color::red);
    win.draw_circle(Point{center.x + 20, center.y - 10}, radius / 5.5, Color::red);
    win.draw_line(Point{center.x - 30, center.y - 25}, Point{center.x - 10, center.y - 20});
    win.draw_line(Point{center.x + 30, center.y - 25}, Point{center.x + 10, center.y - 20});
    win.draw_arc(Point{center.x, center.y + 30}, radius * 1.2, radius, 0, 180);
};

void WinkFace::draw(AnimationWindow &win) {
    Face::draw(win);
    win.draw_circle(Point{center.x - 20, center.y - 10}, radius / 5.5, Color::green);
    win.draw_arc(Point{center.x + 15, center.y - 7}, radius / 2.75, radius / 2.75, 0, 180);
    win.draw_arc(Point{center.x, center.y + 10}, radius * 1.2, radius, 180, 360);
};

void SurprisedFace::draw(AnimationWindow &win) {
    EmptyFace::draw(win);
    win.draw_arc(Point{center.x, center.y + 20}, radius / 2, radius / 2, 0, 360);
};