#include "Game.h"

#include <iostream>
#include <memory>
#include <ostream>
#include <vector>

#include "Paddle.h"
#include "raylib.h"
#include "Ball.h"


//All the game objects
std::vector<GameObject*> gameObjects;

//Background Texture
Texture2D backgroundTexture;


bool Game::Init()
{
    //Create the window
    InitWindow(screenWidth, screenHeight, "Pong Game");
    SetTargetFPS(60); //Set game to 60 FPS
    InitAudioDevice();

    // playerTwo = new Paddle({50, 100},RED);


    //Initialize Objects
    ParticleManager* particle_manager = new ParticleManager();
    GameManager* game_manager = new GameManager(particle_manager);
    ball* ball = new class ball(game_manager);
    Paddle* player_one = new Paddle({20, 30},BLACK, ball, 1);
    Paddle* player_two = new Paddle({static_cast<float>(GetScreenWidth() - 20), 30},RED, ball, 2);


    particle_manager->Init();


    player_one->SetGameManager(game_manager);
    player_two->SetGameManager(game_manager);


    //Push on Entity System
    gameObjects.push_back(particle_manager);
    gameObjects.push_back(game_manager);
    gameObjects.push_back(player_one);
    gameObjects.push_back(player_two);
    gameObjects.push_back(ball);



    //Load THe Background texture
    backgroundTexture = LoadTexture("src/assets/textures/pongBackground.png");


    return true;
}

void Game::GameLoop()
{
    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }
    End();
}


void Game::Update()
{
    switch (gameState)
    {
    case title:
        if (IsKeyPressed(KEY_SPACE))
        {
            gameState = game;
        }
        break;
    case game:
        for (GameObject* gameObject : gameObjects)
        {
            gameObject->update();
        }
        break;
    case gameOver:
        break;
    default: ;
    }
}


void Game::Draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    switch (gameState)
    {
    case title:
        DrawText("WELCOME TO PONG", 20, 20, 40, DARKGREEN);
        DrawText("Press Space To Start The Game", 130, 220, 25, DARKGREEN);
        break;
    case game:
        DrawTexture(backgroundTexture, 0, 0,WHITE);
        for (GameObject* gameObject : gameObjects)
        {
            gameObject->draw();
        }
        break;
    case gameOver:
        break;
    }
    EndDrawing();
}


void Game::End()
{
    //Free the memory
    for (int i = 0; i < gameObjects.size(); i++)
    {
        std::cout << "Freeing GameObject: " << gameObjects[i] << '\n';
        gameObjects[i]->on_destroy();
        free(gameObjects[i]);
    }

    CloseAudioDevice();
    CloseWindow();
}
