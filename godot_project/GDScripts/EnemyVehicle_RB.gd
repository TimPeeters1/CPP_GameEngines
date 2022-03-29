extends RigidBody

export var max_speed = 10;
export var acceleration = 0.1;
export var gravity = 30;

export var time_before_destroy = 3;

var directional_force = Vector3()
var velocity = Vector3(0,0,0)

var GameManager = null;

var addforceTimer = Timer.new();
var killTimer = Timer.new();

var hasDied = false;

func _ready():
	addforceTimer.wait_time = rand_range(1, 3);
	
	addforceTimer.set_one_shot(true);
	addforceTimer.connect("timeout", self, "on_add_force_sideways");
	add_child(addforceTimer);
	addforceTimer.start();
	
	#Should be replaced by signal later.
	GameManager = get_node("/root/Main/GameManager");

	#random deviation on max_speed
	max_speed += rand_range(0, max_speed * 0.1);

func on_add_force_sideways():
	apply_central_impulse(Vector3.RIGHT * rand_range(-10 , 10))
	
func _physics_process(delta):
	var forceVector = -Vector3.FORWARD * acceleration;
	add_force(forceVector, transform.origin);
	
func _integrate_forces(state):
	linear_velocity =  linear_velocity.normalized() * max_speed;

func on_hit_player():
	GameManager.addToScore(1);
	hasDied = true;
	
	killTimer.wait_time = time_before_destroy;
	killTimer.set_one_shot(true);
	add_child(killTimer);
	killTimer.start();
	
	yield(killTimer,"timeout");
	queue_free();
	
func on_hit_enemykillzone():
	if !hasDied:
		GameManager.deduceHealth(1);
		queue_free();
