extends Node

#gamescore
var currentGameScore = 0;

#gamehealth
export var playerStartHealth = 5;
var currentPlayerHealth = 0;

#UI
var ScoreText = null;
var HealthText = null;
var GameOverText = null;

#GameOver
var isGameOver = false;
export var gameOverTimeout = 5;
var gameTimeout = Timer.new();

func _ready():
	currentPlayerHealth = playerStartHealth;
	
	
	ScoreText = get_node("UI/PlayerScore");
	ScoreText.text = "Score: " + str(currentGameScore);
	
	HealthText = get_node("UI/PlayerHealth");
	HealthText.text = "PlayerHealth: " + str(currentPlayerHealth) + "/" + str(playerStartHealth);
	
	GameOverText = get_node("UI/GameOver");
	GameOverText.visible = false;
		
func addToScore(score):
	currentGameScore += score;
	ScoreText.text = "Score: " + str(currentGameScore)

func deduceHealth(healthToRemove):
	if(!isGameOver):
		var newHealth = currentPlayerHealth - healthToRemove;
		
		if(newHealth <= 0):
			currentPlayerHealth = newHealth;
			endGame();
		else:
			currentPlayerHealth = newHealth;
	
		HealthText.text = "PlayerHealth: " + str(currentPlayerHealth) + "/" + str(playerStartHealth);
		
func endGame():
		isGameOver = true;
		GameOverText.visible = true;	
		
		#Needs garbage collection!
		gameTimeout.wait_time = gameOverTimeout;
		gameTimeout.one_shot = true;
		gameTimeout.connect("timeout", self,"_on_timer_timeout") 
		self.add_child(gameTimeout);
		gameTimeout.start();
		
		yield(gameTimeout, "timeout");
		

func _on_timer_timeout():
		gameTimeout.queue_free();
		get_tree().change_scene("res://GameScenes/MainMenu.tscn")
	
