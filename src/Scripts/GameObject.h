#pragma once
#include <raylib.h>

class GameObject
{
public:
    //Constructor
    GameObject();
    //Variables

    //Current player number. Determines the control scheme
    int playerNumber;

    //Rectangle
    Rectangle* rectangle;
    //Position of the current rectangle
    Vector2 position;
    //Velocity
    Vector2 velocity;

    Color paddleColor;


    //The Draw
    virtual void draw();

    //Update
    virtual void update();
    virtual void on_destroy();
};
