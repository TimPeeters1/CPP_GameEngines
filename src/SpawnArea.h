#ifndef SPAWNAREA_H
#define SPAWNAREA_H

#include <Godot.hpp>
#include <Sprite.hpp>

#include <Spatial.hpp>
#include <RandomNumberGenerator.hpp>
#include <PackedScene.hpp>

#include "GameManager.h"

namespace godot {

    class SpawnArea : public Spatial {
        GODOT_CLASS(SpawnArea, Spatial)

    private:
        float spawnExtents = 10;
        float minSpawnTime = 2;
        float maxSpawnTime = 2;

        GameManager* gameManager;

        Timer* spawnTimer;
        RandomNumberGenerator* randomGenerator = RandomNumberGenerator::_new();

        String enemyToSpawn = "res://GameplayScenes/EnemyVehicle.tscn";
    public:
        static void _register_methods();

        SpawnArea();
        ~SpawnArea();

        void _init();

        void _ready();

        void onSpawnEnemy();

        void startNewTimer();
    };

}
#endif