#pragma once

class Game
{
private:
    typedef enum GameState
    {
        title,
        game,
        gameOver,
    } GameState;
    int screenWidth = 800, screenHeight = 600;

GameState gameState = GameState::title;

    
public:



    bool Init();
    void Update();
    void GameLoop();
    void End();
    void Draw();

    
};
