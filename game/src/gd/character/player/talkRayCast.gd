extends RayCast2D

# RayCastの方向
const ROTATION_LEFT :int = 180
const ROTATION_RIGHT :int = 0
const ROTATION_FRONT :int = 90
const ROTATION_BACK :int = 270

var area:Area2D 

func _process(_delta):
	is_ray_colliding();

# RayCastにオブジェクトが衝突しているか確認
func is_ray_colliding()->bool:
	if(is_colliding()):
		# 衝突している場合
		if(area!=get_collider()&&area!=null):
			# 衝突先が変更したら既存のXButtonを非表示
			area.get_parent().isXButtonView(false);
		# 衝突先のXButtonを表示
		area = get_collider(); 
		area.get_parent().isXButtonView(true);
		return true
	else:
		if(area!=null):
			# 衝突していない場合
			area.get_parent().isXButtonView(false);
		return false
