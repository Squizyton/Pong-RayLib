#pragma once
#include "GameObject.h"
#include "ParticleManager.h"

class GameManager : public GameObject
{
public:
    int playerOneScore;
    int playerTwoScore;
    ParticleManager* particleManager;


    Sound scorePointFX;
    GameManager(ParticleManager* particle_manager);

    void draw() override;
    void update() override;
    void scorePoint(int player_number);
    void CreateExplosionEffect(Vector2 position, int amountOfParticles,int xDirection);
    void on_destroy() override;
};
