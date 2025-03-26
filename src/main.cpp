#include <raylib.h>

#include "Scripts/Game.h"

int main(void)
{
    auto game = Game();
    
    if (game.Init())
    {
        game.GameLoop();
    }
    return 0;
}
