extends RigidBody

const MovementSpeed = 20;

func _process(delta):
	if Input.is_action_pressed("Player_Right"):
		add_force(Vector3(-MovementSpeed,0,0), transform.origin)
		
	if Input.is_action_pressed("Player_Left"):
		add_force(Vector3(MovementSpeed,0,0), transform.origin)
