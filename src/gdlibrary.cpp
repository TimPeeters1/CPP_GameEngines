#include "EnemyVehicle.h"
#include "GameManager.h"
#include "gdexample.h"
#include "Killzone.h"
#include "MainMenu.h"
#include "PlayerCollision.h"
#include "PlayerVehicle.h"
#include "SpawnArea.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options * o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options * o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle) {
    godot::Godot::nativescript_init(handle);

     godot::register_class<godot::EnemyVehicle>();
     godot::register_class<godot::GameManager>();
     godot::register_class<godot::GDExample>();
     godot::register_class<godot::Killzone>();
     godot::register_class<godot::MainMenu>();
     godot::register_class<godot::PlayerCollision>();
     godot::register_class<godot::PlayerVehicle>();
     godot::register_class<godot::SpawnArea>();

 }