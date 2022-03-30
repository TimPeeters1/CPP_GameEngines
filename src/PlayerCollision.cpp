#include "PlayerCollision.h"

using namespace godot;

void PlayerCollision::_register_methods() {
    register_method("_ready", &PlayerCollision::_ready);
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

void PlayerCollision::on_body_entered(Node body)
{
    if(body.has_method(""))
}