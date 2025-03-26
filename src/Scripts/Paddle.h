#pragma once
#include "GameManager.h"
#include "GameObject.h"

class ball;

class Paddle : public GameObject
{
public:
    int yVelocity;
    int xVelocity;
    int speed;

    ball* ball;
    GameManager* gameManager;
    Sound onCollideFX;
    
    Paddle(Vector2 position, Color color,class ball* ballRef ,int playerNumber);
    void update() override;
    void move();
    void checkBallCollision();
    void SetGameManager(GameManager* gameManager);
    void on_destroy() override;
};

inline void Paddle::on_destroy()
{
    
    GameObject::on_destroy();
    UnloadSound(onCollideFX);
}  
