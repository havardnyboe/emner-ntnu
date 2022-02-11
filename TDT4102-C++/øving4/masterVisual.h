#pragma once
#include "AnimationWindow.h"
#include "GUI.h"

using namespace Graph_lib;

constexpr int winW = 500; // velg vindu bredde
constexpr int winH = 500; // velg vindu hoyde

constexpr int padY = winH / 10;      // velg x skalering
constexpr int padX = winW / 10;      // velg y skalering
constexpr int radCircle = padX / 10; // velg sirkel radius

constexpr int btnW = padX;
constexpr int btnH = padY;
constexpr Point upperLeftCornerBtn = Point{winW - padX - btnW, padY};

constexpr int inBoxW = winW - 3 * padX - btnW;
constexpr int inBoxH = padY;
constexpr Point upperLeftCornerInBox = Point{padX, padY};

struct Guess {
    const string code;
    char startLetter = 'a';
};

struct Feedback {
    const int correctPosition = 0;
    const int correctCharacter = 0;
};

// Her defineres klassen MastermindWindow, som arver fra klassen AnimationWindow.
// Det betyr at alle medlemsvariable og medlemsfunksjoner i AnimationWindow, også er en
// del av MastermindWindow. Du kan lese mer om klasser i kapittel 9.4 og om arv
// i kapittel 14.3 i læreboka.
class MastermindWindow : public AnimationWindow {
  public:
    MastermindWindow(int x, int y, int w, int h, int size, const string &title);

    static void cb_guess(Fl_Widget *widget, Address pw) {
        (void)widget;
        reference_to<MastermindWindow>(pw).newGuess();
    }

    vector<Guess> guesses;
    vector<Feedback> feedbacks;

    void setCodeHidden(bool hidden);

    string getInput(unsigned int n, char lower, char upper);

  private:
    string wait_for_guess();
    void newGuess() { button_pressed = true; }
    void drawCodeHider();
    bool button_pressed = false;
    bool code_hidden = true;
    Fl_Button guessBtn;
    Fl_Input guess;
    int size = 0;
};

void addGuess(MastermindWindow &mwin, const string code, const char startLetter);
void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter);
