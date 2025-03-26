#include "Paddle.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <raymath.h>

#include "Ball.h"
#include "Utilties.h"


Paddle::Paddle(Vector2 position, Color color,class ball* ballRef ,int playerNumber)
{
    this->position = position;
    this->paddleColor = color;
    this->playerNumber = playerNumber;


    speed = 10;
    ball = ballRef;
    //Creates a new Rectangle
    rectangle = new Rectangle 
    {
        position.x,
        position.y,
        10,
        100
    };

    onCollideFX = LoadSound("src/assets/sounds/boin.wav");
}

void Paddle::update()
{
  move();
    checkBallCollision();
}

void Paddle::move()
{
    //Movement
    switch (playerNumber)
    {
    case 1:

        if (IsKeyDown(KEY_W))
            yVelocity = -1 * speed;
        if (IsKeyDown(KEY_S))
            yVelocity = 1 * speed;


        if (IsKeyDown(KEY_D))
            xVelocity = 1 * speed;
        if (IsKeyDown(KEY_A))
            xVelocity = -1 * speed;
        if (IsKeyReleased(KEY_W))
            yVelocity = 0;
        if (IsKeyReleased(KEY_S))
            yVelocity = 0;
        

        


        
        break;
    case 2:

       
        if (IsKeyDown(KEY_UP))
            yVelocity = -1 * speed;
        if (IsKeyDown(KEY_DOWN))
            yVelocity = 1 * speed;
        if (IsKeyReleased(KEY_UP))
            yVelocity = 0;
        if (IsKeyReleased(KEY_DOWN))
            yVelocity = 0;
     
        

        break;
    
    default: ;
    }

    
    this->position.y += static_cast<float>(yVelocity);
    rectangle->y += yVelocity;

    
    //Collision Check with  walls
    rectangle->y = std::min(rectangle->y, GetScreenHeight() - rectangle->height);
    rectangle->y = std::max<float>(rectangle->y, 0);
}


void Paddle::checkBallCollision()
{
    if (CheckCollisionRecs(*rectangle,*ball->rectangle))
    {

        //If ball hits a certain part of the rectangle

        float pitch = 1.0f;

        
        //Top third of paddle
        if (ball->position.y < rectangle->height/3 + rectangle->y)
        {
            pitch+= Utilties::GetRandomFloat(0.f,2.f);
            ball->velocity.y = -1 * ball->speed;
        }
        //Bottom third of rectangle
        else if (ball->position.y > (rectangle->height/3) * 2 + rectangle->y)
        {
            pitch -= Utilties::GetRandomFloat(0.f,1.f);
            ball->velocity.y = 1 * ball->speed;
        }
            //Middle
        else ball->velocity.y = 0;

        ball->radius -= .1f;
        ball->rectangle->width = ball->radius;
        ball->rectangle->height = ball->radius;

        
        paddleColor = *Utilties::GenerateRandomColor();
        
        
        
        SetSoundPitch(onCollideFX,pitch);
        PlaySound(onCollideFX);
        
        //Reverse the velocity
        ball->velocity.x *= -1;
        ball->velocity.x += (ball->velocity.x * .05f);
        gameManager->CreateExplosionEffect(ball->position,5,ball->velocity.x / 10.f);
    }
}

void Paddle::SetGameManager(GameManager* gameManager)
{
    this->gameManager = gameManager;
}
