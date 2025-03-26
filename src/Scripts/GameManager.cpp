#include "GameManager.h"
#include <string>


GameManager::GameManager(ParticleManager* particle_manager)
{
    playerOneScore = 0;
    playerTwoScore = 0;
    particleManager = particle_manager;
    scorePointFX = LoadSound("src/assets/sounds/Explosion.wav");
}


void GameManager::draw()
{
    //Player ane score
    DrawText(std::to_string(playerOneScore).c_str(), 200, 10, 50, BLACK);
    DrawText(std::to_string(playerTwoScore).c_str(), GetScreenWidth() - 200, 10, 50, BLACK);
}

void GameManager::update()
{
    
}

void GameManager::scorePoint(const int player_number)
{

    PlaySound(scorePointFX);
    
    switch (player_number)
    {
    case 1:
        playerOneScore++;
        break;
    case 2:
        playerTwoScore++;
        break;
    default: ;
    }
}

void GameManager::CreateExplosionEffect(Vector2 position, int amountOfParticles,int xDirection)
{
    particleManager->ExplosionEffect(position, amountOfParticles, xDirection);
}

void GameManager::on_destroy()
{
    UnloadSound(scorePointFX);
    GameObject::on_destroy();
}

