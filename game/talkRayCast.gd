extends RayCast2D

func _process(_delta):
	is_ray_colliding();

# RayCastにオブジェクトが衝突しているか確認
func is_ray_colliding():
	if(is_colliding()):
		var body:Area2D = get_collider(); 
		body.get_parent().isXButtonView();
