extends CharacterBody2D

# 方向一覧
const DIRECTION_LEFT :String= "LEFT"
const DIRECTION_RIGHT :String = "RIGHT"
const DIRECTION_FRONT :String = "FRONT"
const DIRECTION_BACK:String = "BACK"

# 停止時
const STOPPING :Vector2= Vector2(0.0,0.0)

# 速度
const SPEED :float = 6000.0

var direction:String = DIRECTION_BACK

func _physics_process(delta:float)->void: 
	playerMove(delta);

#　キャラクターの移動を制御
func playerMove(delta):
	velocity = Vector2(0.0,0.0);
	
	if(Input.is_action_pressed("Move_Right")&&
	!Input.is_action_pressed("Move_Left")&&
	!Input.is_action_pressed("Move_Up")&&
	!Input.is_action_pressed("Move_Down")):
		direction = DIRECTION_RIGHT;
		velocity.x = 1 *SPEED;
		$AnimatedWalk.play("RightRun");
	
	if(Input.is_action_pressed("Move_Left")&&
	!Input.is_action_pressed("Move_Right")&&
	!Input.is_action_pressed("Move_Up")&&
	!Input.is_action_pressed("Move_Down")):
		direction = DIRECTION_LEFT;
		velocity.x = -1 *SPEED;
		$AnimatedWalk.play("LeftRun");
	
	if(Input.is_action_pressed("Move_Up")&&
	!Input.is_action_pressed("Move_Down")&&
	!Input.is_action_pressed("Move_Left")&&
	!Input.is_action_pressed("Move_Right")):
		direction = DIRECTION_FRONT;
		velocity.y = -1 *SPEED;
		$AnimatedWalk.play("BackRun");
	
	if(Input.is_action_pressed("Move_Down")&&
	!Input.is_action_pressed("Move_Up")&&
	!Input.is_action_pressed("Move_Left")&&
	!Input.is_action_pressed("Move_Right")):
		direction = DIRECTION_BACK;
		velocity.y = 1 *SPEED;
		$AnimatedWalk.play("FrontRun");
	
#	斜め移動
	if(Input.is_action_pressed("Move_Down")&&
	Input.is_action_pressed("Move_Left")&&
	!Input.is_action_pressed("Move_Up")&&
	!Input.is_action_pressed("Move_Right")):
		velocity.y = 1 *SPEED;
		velocity.x = -1 *SPEED;
		if(direction == DIRECTION_BACK):
			$AnimatedWalk.play("FrontRun");
		else :
			$AnimatedWalk.play("LeftRun");
	
	if(Input.is_action_pressed("Move_Down")&&
	Input.is_action_pressed("Move_Right")&&
	!Input.is_action_pressed("Move_Up")&&
	!Input.is_action_pressed("Move_Left")):
		velocity.y = 1 *SPEED;
		velocity.x = 1 *SPEED;
		if(direction == DIRECTION_BACK):
			$AnimatedWalk.play("FrontRun");
		else :
			$AnimatedWalk.play("RightRun");
	
	if(Input.is_action_pressed("Move_Up")&&
	Input.is_action_pressed("Move_Left")&&
	!Input.is_action_pressed("Move_Down")&&
	!Input.is_action_pressed("Move_Right")):
		velocity.y = -1 *SPEED;
		velocity.x = -1 *SPEED;
		if(direction == DIRECTION_FRONT):
			$AnimatedWalk.play("BackRun");
		else :
			$AnimatedWalk.play("LeftRun");
	
	if(Input.is_action_pressed("Move_Up")&&
	Input.is_action_pressed("Move_Right")&&
	!Input.is_action_pressed("Move_Down")&&
	!Input.is_action_pressed("Move_Left")):
		velocity.y = -1 *SPEED;
		velocity.x = 1 *SPEED;
		if(direction == DIRECTION_FRONT):
			$AnimatedWalk.play("BackRun");
		else :
			$AnimatedWalk.play("RightRun");
	
#	停止時のアニメーション
	if(velocity == STOPPING):
		if(direction == DIRECTION_LEFT):
			$AnimatedWalk.play("LeftWeight");
		if(direction == DIRECTION_RIGHT):
			$AnimatedWalk.play("RightWeight");
		if(direction == DIRECTION_BACK):
			$AnimatedWalk.play("FrontWeight");
		if(direction == DIRECTION_FRONT):
			$AnimatedWalk.play("BackWeight");
	
	velocity = velocity *delta;
	move_and_slide();
