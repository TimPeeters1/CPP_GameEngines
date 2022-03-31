#ifndef ENEMYVEHICLE_H
#define ENEMYVEHICLE_H

#include <Godot.hpp>
#include <Input.hpp>

#include <Spatial.hpp>
#include <Vector3.hpp>
#include <Rigidbody.hpp>

#include <Timer.hpp>
#include <RandomNumberGenerator.hpp>

#include "GameManager.h"

namespace godot
{
    class EnemyVehicle : public RigidBody
    {
        GODOT_CLASS(EnemyVehicle, RigidBody)

    private:
        float max_speed = 30;
        float acceleration = (float)0.1;
        float side_impulse_force = 20;

        float time_before_destroy = (float)3;

        Vector3 velocity = Vector3();

        Timer *addForceTimer = Timer::_new();
        Timer *killTimer = Timer::_new();

        GameManager *gameManager;
        RandomNumberGenerator *randomGenerator = RandomNumberGenerator::_new();
        ;

        bool hasDied = false;

    public:
        static void _register_methods();

        EnemyVehicle();
        ~EnemyVehicle();

        void _init();

        void _ready();

        void _physics_process(float delta);

        void _integrate_forces(float delta);

        void onAddForceSideways();

        void onHitPlayer();

        void onHitKillzone(bool deducePlayerHealth);

        void onDeathTimeout();
    };

}
#endif