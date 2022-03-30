#include "SpawnArea.h"

#include <ResourceLoader.hpp>
#include <Vector3.hpp>
#include <Spatial.hpp>

#include <String.hpp>

using namespace godot;

void SpawnArea::_register_methods() {
   register_method("_ready", &SpawnArea::_ready);
   register_method("onSpawnEnemy", &SpawnArea::onSpawnEnemy);

   register_property<SpawnArea, float>("spawnExtents", &SpawnArea::spawnExtents, (float) 10);
   register_property<SpawnArea, float>("minSpawnTime", &SpawnArea::minSpawnTime, (float) 2);
   register_property<SpawnArea, float>("maxSpawnTime", &SpawnArea::maxSpawnTime, (float) 5);
}

SpawnArea::SpawnArea() {
}

SpawnArea::~SpawnArea() {
   
}

void SpawnArea::_init() {

}

void SpawnArea::_ready()
{
    gameManager = cast_to<GameManager>(get_node("/root/Main/GameManager"));
    randomGenerator->randomize();

    spawnTimer = Timer::_new();
    spawnTimer->set_one_shot(true);
    spawnTimer->connect("timeout", this, "onSpawnEnemy");
    add_child(spawnTimer);

    startNewTimer();
}

void SpawnArea::onSpawnEnemy()
{
    if(!gameManager->isGameOver){
        ResourceLoader* reLo = ResourceLoader::get_singleton();
        Ref<PackedScene> res = reLo->load(enemyToSpawn);
        Spatial* instancedEnemy = static_cast<Spatial*>(res->instance());
       
        Vector3 transformDeviation = Vector3(0,0, randomGenerator->randf_range(-spawnExtents, spawnExtents));
        instancedEnemy->set_translation(transformDeviation);
        instancedEnemy->set_rotation(get_rotation());
        
        add_child(instancedEnemy);

        startNewTimer();
    }
}

void SpawnArea::startNewTimer()
{
    float newSpawnTime = randomGenerator->randf_range(minSpawnTime, maxSpawnTime);
    spawnTimer->set_wait_time(newSpawnTime); 
    spawnTimer->start();
}
