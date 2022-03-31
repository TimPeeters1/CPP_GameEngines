#include "GameManager.h"

#include <SceneTree.hpp>

using namespace godot;

void GameManager::_register_methods() {
    register_method("_ready", &GameManager::_ready);
    register_method("onEndGameTimeout", &GameManager::onEndGameTimeout);

    register_property<GameManager, int>("playerStartHealth", &GameManager::playerStartHealth, (int) 5);
    register_property<GameManager, float>("gameOverTimeout", &GameManager::gameOverTimeout, (float) 3);
}

GameManager::GameManager() {
}

GameManager::~GameManager() {
    
}

void GameManager::_init(){

}

void GameManager::_ready(){
    isGameOver = false;
    currentPlayerHealth = playerStartHealth;

    ScoreText = static_cast<Label*>(get_node("UI/PlayerScore"));
    ScoreText->set_text("Score: " + String::num_int64(currentGameScore));

    HealthText = static_cast<Label*>(get_node("UI/PlayerHealth"));
    HealthText->set_text("PlayerHealth: " + String::num_int64(currentPlayerHealth) + "/" + String::num_int64(playerStartHealth));

    GameOverText = static_cast<Label*>(get_node("UI/GameOver"));
    GameOverText->set_visible(false);
}

void GameManager::addToScore(int scoreToAdd){
    currentGameScore += scoreToAdd;
    ScoreText->set_text("Score: " + String::num_int64(currentGameScore));
}

void GameManager::deduceHealth(int healthToRemove)
{
    if(!isGameOver){
        int newHealth = currentPlayerHealth - healthToRemove;

        if(newHealth <= 0){
            currentPlayerHealth = newHealth;
            endGame();
        }else{
            currentPlayerHealth = newHealth;
        }

        HealthText->set_text("PlayerHealth: " + String::num_int64(currentPlayerHealth) + "/" + String::num_int64(playerStartHealth));
    }
}

void GameManager::endGame()
{
    isGameOver = true;
    GameOverText->set_visible(true);

    gameTimeout = Timer::_new();
    gameTimeout->set_wait_time(gameOverTimeout);   
    gameTimeout->set_one_shot(true);
    gameTimeout->connect("timeout", this, "onEndGameTimeout");
    add_child(gameTimeout);

    gameTimeout->start();
}

void GameManager::onEndGameTimeout()
{
    gameTimeout->free();
    get_tree()->change_scene("res://GameScenes/MainMenu.tscn");
}
