#ifndef MAINMENU_H
#define MAINMENU_H

#include <Godot.hpp>
#include <Node.hpp>
#include <BaseButton.hpp>

namespace godot
{
    class MainMenu : public Control
    {
        GODOT_CLASS(MainMenu, Control)

    private:
      BaseButton* startButton;
      BaseButton* quitButton;

    public:
        static void _register_methods();

        MainMenu();
        ~MainMenu();

        void _init();

        void _ready();

        void onStartGame();

        void onQuitGame();
    };

}
#endif