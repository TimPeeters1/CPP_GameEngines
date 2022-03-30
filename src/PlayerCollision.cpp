#include "PlayerCollision.h"
#include "EnemyVehicle.h"

using namespace godot;

void PlayerCollision::_register_methods() {
    register_method("_ready", &PlayerCollision::_ready);
    register_method("on_body_entered", &PlayerCollision::on_body_entered);
}

PlayerCollision::PlayerCollision() {
}

PlayerCollision::~PlayerCollision() {
    // add your cleanup here
}

void PlayerCollision::_init() {
    
}

void PlayerCollision::_ready() {
    connect("body_entered", this, "on_body_entered");
}

void PlayerCollision::on_body_entered(Variant body)
{
    if(cast_to<EnemyVehicle>(body)){
        EnemyVehicle* enemyObject = cast_to<EnemyVehicle>(body);
        enemyObject->onHitPlayer();
    }
}