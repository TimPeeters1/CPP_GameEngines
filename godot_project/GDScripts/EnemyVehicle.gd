extends KinematicBody


export var movementSpeed = 10;
export var acceleration = 0.1;
export var gravity = 30;

var directional_force = Vector3()
var velocity = Vector3(0,0,0)


func _physics_process(delta):
	velocity += -get_global_transform().basis.z * movementSpeed
	
	velocity.y -= gravity * delta;
	velocity = move_and_slide(velocity, Vector3.UP)
	velocity = velocity.normalized() * min(0, movementSpeed);


