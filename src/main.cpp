#include "models/Game.hpp"
#include "DEFINITIONS.hpp"

int main (int argc, char *argv[]) {
    satisfying_ball::Game app(WINDOW_WIDTH, WINDOW_HEIGHT, "Satisfying Ball");
    app.Run();
    return 0;
}
