#include "EnemyVehicle.h"

using namespace godot;

void EnemyVehicle::_register_methods() {
    register_method("_ready", &EnemyVehicle::_ready);
    register_method("_physics_process", &EnemyVehicle::_physics_process);
    register_method("_integrate_forces", &EnemyVehicle::_integrate_forces);
    register_method("onAddForceSideways", &EnemyVehicle::onAddForceSideways);

    register_property<EnemyVehicle, float>("max_speed", &EnemyVehicle::max_speed, (float) 30);
    register_property<EnemyVehicle, float>("acceleration", &EnemyVehicle::acceleration, (float) 0.1);
    register_property<EnemyVehicle, float>("side_impulse_force", &EnemyVehicle::side_impulse_force, 20);
}

EnemyVehicle::EnemyVehicle() {

}

EnemyVehicle::~EnemyVehicle() {
}

void EnemyVehicle::_init(){
    
}

void EnemyVehicle::_ready() {
   
    randomGenerator->randomize();

    addForceTimer = Timer::_new();
    addForceTimer->set_wait_time(2);   
    addForceTimer->set_one_shot(true);
    addForceTimer->connect("timeout", this, "onAddForceSideways");
    add_child(addForceTimer);

    addForceTimer->start();

    velocity = -Vector3::FORWARD * acceleration;
}

void EnemyVehicle::_physics_process(float delta) {
    add_force(velocity, this->get_transform().origin);
}

void EnemyVehicle::_integrate_forces(float delta) {
    set_linear_velocity(get_linear_velocity().normalized() * max_speed);
}

void EnemyVehicle::onAddForceSideways(){
    apply_central_impulse(Vector3::RIGHT * randomGenerator->randf_range(-side_impulse_force, side_impulse_force));
}

void EnemyVehicle::onHitPlayer(){
    Godot::print("OnHitPlayer");
}

void EnemyVehicle::onHitKillzone(){
    Godot::print("OnHitKillzone");
}