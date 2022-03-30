#ifndef PLAYERCOLLISION_H
#define PLAYERCOLLISION_H

#include <Godot.hpp>
#include <Area.hpp>

namespace godot {

    class PlayerCollision : public Area {
        GODOT_CLASS(PlayerCollision, Area)

    private:
        float time_passed;

    public:
        static void _register_methods();

        PlayerCollision();
        ~PlayerCollision();

        void _init();

        void _ready();

        void on_body_entered(Node body);
    };

}

#endif

