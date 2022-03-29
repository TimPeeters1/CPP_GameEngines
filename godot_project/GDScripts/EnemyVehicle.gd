extends KinematicBody

export var max_speed = 10;
export var acceleration = 0.1;
export var gravity = 30;

var directional_force = Vector3()
var velocity = Vector3(0,0,0)

var GameManager = null;

var addforceTimer = Timer.new();

func _ready():
	addforceTimer.wait_time = rand_range(0, 1);
	
	addforceTimer.set_one_shot(true);
	addforceTimer.connect("timeout", self, "on_add_force_sideways");
	add_child(addforceTimer);
	addforceTimer.start();
	
	#Should be replaced by signal later.
	GameManager = get_node("/root/Main/GameManager");

func on_add_force_sideways():
	velocity.x += rand_range(-50, 50);
	
	addforceTimer.wait_time = rand_range(2, 5);
	addforceTimer.start();
	
func _physics_process(delta):
	if !is_on_floor():
		velocity.y -= gravity * delta;
	else:
		velocity += -get_global_transform().basis.z * max_speed;
		
	velocity = move_and_slide(velocity, Vector3.UP)
	
	if velocity.length() > max_speed:
		velocity = velocity.normalized() * max_speed
	

func on_hit_player():
	GameManager.addToScore(1);
	queue_free()
	
func on_hit_enemykillzone():
	GameManager.deduceHealth(1);
	queue_free()
