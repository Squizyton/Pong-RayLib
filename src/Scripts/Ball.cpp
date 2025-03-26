#include "Ball.h"

#include <iostream>
#include <ostream>

#include "raymath.h"



ball::ball(GameManager* game_manager)
{
    position.x = GetScreenWidth() / 2.f;
    position.y = GetScreenHeight() / 2.f;

    //Create a rectanble for the bounding box
    rectangle = new Rectangle
    {
        position.x, position.y,radius,radius
    };

    this->game_manager = game_manager;
    
    velocity.x = GetRandomValue(-1,1);

    if (velocity.x == 0)
        velocity.x = 1;

    
    velocity.y = GetRandomValue(-1,1);
    
    velocity = Vector2Scale(velocity, speed);

}

void ball::draw()
{
    DrawCircleV(position,radius,PINK);
}

void ball::update()
{
    position = Vector2Add(position,velocity);
    
    //Update where the rectangle collider box is
    rectangle->x = position.x;
    rectangle->y = position.y;

    
    //Check vertical Collision
    if (position.y > GetScreenHeight() - 2.5f || position.y < 0)
        velocity.y *= -1;


    //Check horizontal Collision
    if (position.x > GetScreenWidth() - 2.5f)
    {
        game_manager->scorePoint(1); 
            // std::cout <<"Velocity:" << velocity.x << " " << "Explosion Amount: " << roundf(25 * static_cast<float>(velocity.x / 10)) << "\n";

        //abs(roundf(50 * (velocity.x/10)))
        game_manager->CreateExplosionEffect(position,abs(roundf(50 * (velocity.x/10))),-1);
        restart_ball();
    }

    if (position.x < 0)
    {
        game_manager->scorePoint(2);
        //std::cout << "Velocity:" << velocity.x << " " << "Explosion Amount: " << roundf(25 * (velocity.x / 10)) << "\n";
        game_manager->CreateExplosionEffect(position,abs(roundf(500* (velocity.x /10))),1);
        restart_ball();
    }
}

void ball::restart_ball()
{
    position.x = GetScreenWidth() / 2.f;
    position.y = GetScreenHeight() / 2.f;
    velocity.x = 1.f;
    radius = 15;
   rectangle->width = radius;
   rectangle->height =radius;
    velocity.y = GetRandomValue(-1,1);
    velocity = Vector2Scale(velocity, speed);
}


