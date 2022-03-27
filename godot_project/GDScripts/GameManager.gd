extends Node


var currentGameScore = 0;
var ScoreText = null;

func _ready():
	ScoreText = get_node("UI/Label");
	ScoreText.text = "Score: " + str(currentGameScore);
		
func addToScore(var score):
	currentGameScore += score;
	ScoreText.text = "Score: " + str(currentGameScore)
