#include "AnimationWindow.h"
#include "Emoji.h"

// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main() {

    const Point tl{100, 100};
    const string win_label{"Emoji factory"};
    AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

    // Initialiser emojiene
    vector<unique_ptr<Emoji>> emoji;
    emoji.push_back(make_unique<SmileyFace>(Point{100, 100}, emojiRadius));
    emoji.push_back(make_unique<SadFace>(Point{250, 100}, emojiRadius));
    emoji.push_back(make_unique<AngryFace>(Point{400, 100}, emojiRadius));
    emoji.push_back(make_unique<WinkFace>(Point{550, 100}, emojiRadius));
    emoji.push_back(make_unique<SurprisedFace>(Point{700, 100}, emojiRadius));

    // Tegn emojiene til vinduet
    for (const auto &e : emoji) {
        e->draw(win);
    }

    win.wait_for_close();
}
