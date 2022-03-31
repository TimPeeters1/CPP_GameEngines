#ifndef KILLZONE_H
#define KILLZONE_H

#include <Godot.hpp>
#include <Area.hpp>

namespace godot {

    class Killzone : public Area {
        GODOT_CLASS(Killzone, Area)

    private:
        //Deduce health when EnemyVehicle hits the body.
        bool deduceHealth = false;

    public:
        static void _register_methods();

        Killzone();
        ~Killzone();

        void _init();

        void _ready();

        void on_body_entered(Variant body);

    };

}

#endif

