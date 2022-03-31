#include "Killzone.h"

#include "EnemyVehicle.h"
#include "PlayerVehicle.h"

using namespace godot;

void Killzone::_register_methods() {
    register_method("_ready", &Killzone::_ready);
    register_method("on_body_entered", &Killzone::on_body_entered);

    register_property<Killzone, bool>("deduceHealth", &Killzone::deduceHealth, false);
}

Killzone::Killzone() {
}

Killzone::~Killzone() {

}

void Killzone::_init() {

}

void Killzone::_ready()
{
    connect("body_entered", this, "on_body_entered");
}

void Killzone::on_body_entered(Variant body)
{
     if(cast_to<EnemyVehicle>(body)){
        EnemyVehicle* enemyObject = cast_to<EnemyVehicle>(body);
        enemyObject->onHitKillzone(deduceHealth);
    }
    if(cast_to<PlayerVehicle>(body)){
        GameManager* gameManager = cast_to<GameManager>(get_node("/root/Main/GameManager"));
        gameManager->endGame();
        cast_to<PlayerVehicle>(body)->queue_free();
    }
}
