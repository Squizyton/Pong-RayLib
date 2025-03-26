#include "ParticleManager.h"

#include <iostream>
#include <raymath.h>

#include "Utilties.h"

void ParticleManager::Init()
{

    //Initilize all the particles
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        particlePool[i].position = Vector2Zero();
        particlePool[i].color = *Utilties::GenerateRandomColor();
        particlePool[i].alpha = 1.0f;
        particlePool[i].size = (float)GetRandomValue(1, 15 )/20.0f;
        particlePool[i].rotation = (float)GetRandomValue(0, 360);
        particlePool[i].active = false;
        particlePool[i].speed = GetRandomValue(1,5);
    }

    //Get the texture
    texture = LoadTexture("src/assets/textures/particle.png");
}

void ParticleManager::draw()
{
    DrawParticles();
}

void ParticleManager::update()
{
    UpdateParticles();
}

void ParticleManager::UpdateParticles()
{
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        if (particlePool[i].active)
        {
            Particle* particle = &particlePool[i];

            particle->position = Vector2Add(particle->position,particle->direction);
            particle->alpha -= 0.005f;
            
            if (particle->alpha <= 0)particle->active = false;

            particle->rotation += 2.0f;
        }
    }
}

void ParticleManager::DrawParticles()
{
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        if (particlePool[i].active)
        {
           
            
            //Source
            particlePool[i].source.width = (float)texture.width;
            particlePool[i].source.height = (float)texture.height;

            
            //Dest
            particlePool[i].dest.x = particlePool[i].position.x;
            particlePool[i].dest.y = particlePool[i].position.y;
            particlePool[i].dest.width = particlePool[i].size * texture.width;
            particlePool[i].dest.height = particlePool[i].size * texture.height;
            
            //Origin
            //Aka The Pivot point
            particlePool[i].origin.x = (texture.width*particlePool[i].size/2.0f);
            particlePool[i].origin.y = (texture.height*particlePool[i].size/2.0f);

            
            DrawTexturePro(texture,
                particlePool[i].source, ///We are setting the rectangle here
                particlePool[i].dest,
                particlePool[i].origin,
                particlePool[i].rotation, // Rotation
                Fade(particlePool[i].color, particlePool[i].alpha) // Color
                );
            
        }
    }
}

void ParticleManager::ExplosionEffect(Vector2 explosion_position, int amount,int xDirection)
{
    
    //Get a random point
    int randomStartingPointInArray = (int)(GetRandomValue(0, MAX_PARTICLES - amount));

    //Start the for loop in that array
    for (int i = 0; i < amount; i++)
    {
        int randomIndex = GetRandomValue(0, MAX_PARTICLES);
        
        if (!particlePool[randomIndex].active)
        {
            particlePool[randomIndex].position = explosion_position ;

            //Add an offset to the Y
            particlePool[randomIndex].position.y = particlePool[randomIndex].position.y +  Utilties::GetRandomFloat(-20.f, 20.f);
            particlePool[randomIndex].position.x = particlePool[randomIndex].position.x +  (Utilties::GetRandomFloat(0, 20.f) * static_cast<float>(xDirection));
            
            
            particlePool[randomIndex].active = true;
            particlePool[randomIndex].alpha = 1.0f;
            particlePool[randomIndex].direction.x = xDirection * particlePool[i].speed - Utilties::GetRandomFloat(-1.f, 1.f) ;
            particlePool[randomIndex].direction.y = (static_cast<float>(Utilties::GetRandomFloat(-1, 1)) -Utilties::GetRandomFloat(-1.f, 1.f) ) * particlePool[i].speed;
        }
    }
}
