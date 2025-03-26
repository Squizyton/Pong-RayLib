#pragma once
#include <raylib.h>

#include "GameObject.h"

#define MAX_PARTICLES 2500

typedef struct Particle
{
    Vector2 position;
    Vector2 direction;
    Rectangle source;
    Rectangle dest;
    Vector2 origin;
    Color color;
    float alpha;
    float size;
    float rotation;
    float speed;
    bool active;
};

class ParticleManager : public GameObject
{
public:
    Particle particlePool[MAX_PARTICLES] = {};
    float gravity = 3.0f;
    Texture2D texture;
    
    void Init();
    void UpdateParticles();
    void update() override;
    void draw() override;
    void DrawParticles();
    
    //Types of Effects
    void ExplosionEffect(Vector2 explosion_position,int amount,int xDirection); 
};
