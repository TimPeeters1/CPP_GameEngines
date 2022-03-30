#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <Godot.hpp>
#include <Node.hpp>

#include <Label.hpp>
#include <Timer.hpp>

namespace godot
{
    class GameManager : public Node {
       GODOT_CLASS(GameManager, Node)

    private:
        //GameScore
          int currentGameScore = 0;
        
        //PlayerHealth
        int playerStartHealth = 5;
        int currentPlayerHealth = 0;

        //UI Elements
        Label* ScoreText;
        Label* HealthText;
        Label* GameOverText;

        //GameOver timeout
        float gameOverTimeout = 5;
        Timer* gameTimeout;

    public:
        static void _register_methods();

        GameManager();
        ~GameManager();

        void _init();

        void _ready();

        void addToScore(int scoreToAdd);

        void deduceHealth(int healthToRemove);

        void endGame();

        void onEndGameTimeout();

        bool isGameOver = false;
    };

}
#endif