#pragma once
#include "GameManager.h"
#include "GameObject.h"

class ball : public GameObject
{
    
public:
    Vector2 velocity;
    float speed = 5;
    float radius = 15;

    GameManager* game_manager;
    
    ball(GameManager* game_manager);
    void draw() override;
    void update() override;
    void restart_ball();
    
};
