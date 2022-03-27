extends Area

func _ready():
	 connect("body_entered", self, "_on_Area_body_entered")
	
func _on_Area_body_entered(body):
	if body.has_method("on_hit_player"):
		body.on_hit_player();
