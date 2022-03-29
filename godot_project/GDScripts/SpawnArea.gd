extends Spatial

#Enemy Vehicle 
var newEnemy = preload("res://GameplayScenes/EnemyVehicle.tscn")

var timer = null;
var timer_interval;

export var spawnExtents = 10;
export var minSpawnTime = 2;
export var maxSpawnTime = 5;

var GameManager = null;

func _ready():
	#Should be replaced by signal later.
	GameManager = get_node("/root/Main/GameManager");
	
	timer = Timer.new();
	timer.set_one_shot(true);
	timer.connect("timeout", self, "on_timeout_complete");
	add_child(timer);
	
	start_new_timer();
	
func on_timeout_complete():
	if(!GameManager.isGameOver):
		var instance = newEnemy.instance();
		var transformDeviation = Vector3(0, 0, rand_range(-spawnExtents, spawnExtents));
		instance.transform.origin = transformDeviation;
		instance.rotation = self.rotation;
		add_child(instance)	;
	
		start_new_timer();


func start_new_timer():
	var randSpawnTime = rand_range(minSpawnTime, maxSpawnTime);
	timer.set_wait_time(randSpawnTime);
	timer.start();
