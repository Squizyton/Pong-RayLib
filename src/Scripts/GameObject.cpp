#include "GameObject.h"


void GameObject::update()
{
    
}

void GameObject::on_destroy()
{
}

GameObject::GameObject()
= default;

void GameObject::draw()
{
    DrawRectangleRec(*rectangle,paddleColor);
}

