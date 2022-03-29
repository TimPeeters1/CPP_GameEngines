extends Area

func _ready():
	 connect("body_entered", self, "_on_killzone_body_entered")

func _on_killzone_body_entered(body):
	if body.has_method("on_hit_enemykillzone"):
		body.on_hit_enemykillzone();
