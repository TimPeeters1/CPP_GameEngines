#include "MainMenu.h"
#include <SceneTree.hpp>

using namespace godot;

void MainMenu::_register_methods() {
    register_method("_ready", &MainMenu::_ready);
    register_method("onStartGame", &MainMenu::onStartGame);
    register_method("onQuitGame", &MainMenu::onQuitGame);
}

MainMenu::MainMenu() {
}

MainMenu::~MainMenu() {

}

void MainMenu::_init() {

}

void MainMenu::_ready(){
    //I know there is a easier way than to hardcode these paths, but oh well..
    startButton = cast_to<BaseButton>(get_node("/root/Menu/VerticalBox/ButtonBox/Start"));
    startButton->connect("pressed", this, "onStartGame");

    quitButton = cast_to<BaseButton>(get_node("/root/Menu/VerticalBox/ButtonBox/Quit"));
    quitButton->connect("pressed", this, "onQuitGame");
}

void MainMenu::onStartGame()
{
    get_tree()->change_scene("res://GameScenes/Main3D.tscn");
}

void MainMenu::onQuitGame()
{
    get_tree()->quit();
}
