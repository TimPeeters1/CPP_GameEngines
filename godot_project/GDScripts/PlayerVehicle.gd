extends KinematicBody

export var movementSpeed = 1;

export var friction = 0.1;
export var acceleration = 0.1;
export var gravity = 30;

var velocity = Vector3(0,0,0)

func get_input():
	var input_direction = 0
	if Input.is_action_pressed("Player_Right"):
		input_direction += movementSpeed
	if Input.is_action_pressed("Player_Left"):
		input_direction -= movementSpeed

	if input_direction != 0:
		# accelerate when there's input
		velocity.x = lerp(velocity.x, input_direction * movementSpeed, acceleration)
	else:
		# slow down when there's no input
		velocity.x = lerp(velocity.x, 0, friction)
		
func _physics_process(delta):
	get_input()
	velocity.y -= gravity * delta;
	velocity = move_and_slide(velocity, Vector3.UP)
