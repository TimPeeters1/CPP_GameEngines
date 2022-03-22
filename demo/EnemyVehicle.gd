extends RigidBody


func _process(delta):
	add_force(Vector3(0,0,10), transform.origin)
