#ifndef PLAYER_H
#define PLAYER_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include <Input.hpp>
#include <Spatial.hpp>
#include <RigidBody.hpp>


namespace godot {

    class Player : public RigidBody {
        GODOT_CLASS(Player, RigidBody)

    private:
      float MovementSpeed = 20;
    public:
        static void _register_methods();

        Player();
        ~Player();

        void _init();

        void _process(float delta);

        void _input(Variant event);
    };

}
#endif