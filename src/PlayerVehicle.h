#ifndef PLAYERVEHICLE_H
#define PLAYERVEHICLE_H

#include <Godot.hpp>
#include <Input.hpp>
#include <Spatial.hpp>
#include <Vector3.hpp>
#include <KinematicBody.hpp>
#include <Math.hpp>

namespace godot {

    class PlayerVehicle : public KinematicBody {
        GODOT_CLASS(PlayerVehicle, KinematicBody)

    private:
      float movementSpeed = 5;
      
      float friction = (float)0.1;
      float acceleration = (float)0.1;
      float gravity = (float)30;

      float input_dir = 0;

      Vector3 velocity = Vector3();

    public:
        static void _register_methods();

        PlayerVehicle();
        ~PlayerVehicle();

        void _init();

        void _physics_process(float delta);
        
        void get_input();
    };

}
#endif