extends CharacterBody2D

# 方向一覧
const DIRECTION_LEFT :String= "LEFT"
const DIRECTION_RIGHT :String = "RIGHT"
const DIRECTION_FRONT :String = "FRONT"
const DIRECTION_BACK:String = "BACK"

# RayCastの方向
const ROTATION_LEFT :int = 180
const ROTATION_RIGHT :int = 0
const ROTATION_FRONT :int = 90
const ROTATION_BACK :int = 270

# 停止時
const STOPPING :Vector2= Vector2(0.0,0.0)

# 速度
@export var SPEED :float = 4000.0

var direction:String = DIRECTION_BACK # キャラの方向
var isConversation:bool = false # 会話フラグ

func _physics_process(delta:float)->void: 
	if(!BalloonManager.isChat):
		playerMove(delta);
	
	stopping();

#　キャラクターの移動を制御
func playerMove(delta):
	velocity = Vector2(0.0,0.0);
	
	# 右移動
	if(Input.is_action_pressed("Move_Right")&&
	!Input.is_action_pressed("Move_Left")&&
	!Input.is_action_pressed("Move_Up")&&
	!Input.is_action_pressed("Move_Down")):
		direction = DIRECTION_RIGHT;
		velocity.x = 1 *SPEED;
		$AnimatedWalk.play("RightRun");
		$TalkRayCast.rotation_degrees = $TalkRayCast.ROTATION_RIGHT;
	# 左移動
	if(Input.is_action_pressed("Move_Left")&&
	!Input.is_action_pressed("Move_Right")&&
	!Input.is_action_pressed("Move_Up")&&
	!Input.is_action_pressed("Move_Down")):
		direction = DIRECTION_LEFT;
		velocity.x = -1 *SPEED;
		$AnimatedWalk.play("LeftRun");
		$TalkRayCast.rotation_degrees = $TalkRayCast.ROTATION_LEFT;
	# 上移動
	if(Input.is_action_pressed("Move_Up")&&
	!Input.is_action_pressed("Move_Down")&&
	!Input.is_action_pressed("Move_Left")&&
	!Input.is_action_pressed("Move_Right")):
		direction = DIRECTION_FRONT;
		velocity.y = -1 *SPEED;
		$AnimatedWalk.play("BackRun");
		$TalkRayCast.rotation_degrees = $TalkRayCast.ROTATION_BACK;
	# 下移動
	if(Input.is_action_pressed("Move_Down")&&
	!Input.is_action_pressed("Move_Up")&&
	!Input.is_action_pressed("Move_Left")&&
	!Input.is_action_pressed("Move_Right")):
		direction = DIRECTION_BACK;
		velocity.y = 1 *SPEED;
		$AnimatedWalk.play("FrontRun");
		$TalkRayCast.rotation_degrees = $TalkRayCast.ROTATION_FRONT;
	
	# 斜め左下移動
	if(Input.is_action_pressed("Move_Down")&&
	Input.is_action_pressed("Move_Left")&&
	!Input.is_action_pressed("Move_Up")&&
	!Input.is_action_pressed("Move_Right")):
		velocity.y = 1 *SPEED;
		velocity.x = -1 *SPEED;
		if(direction == DIRECTION_BACK):
			$AnimatedWalk.play("FrontRun");
			$TalkRayCast.rotation_degrees = $TalkRayCast.ROTATION_FRONT;
		else :
			$AnimatedWalk.play("LeftRun");
			$TalkRayCast.rotation_degrees = $TalkRayCast.ROTATION_LEFT;
	# 斜め右下移動
	if(Input.is_action_pressed("Move_Down")&&
	Input.is_action_pressed("Move_Right")&&
	!Input.is_action_pressed("Move_Up")&&
	!Input.is_action_pressed("Move_Left")):
		velocity.y = 1 *SPEED;
		velocity.x = 1 *SPEED;
		if(direction == DIRECTION_BACK):
			$AnimatedWalk.play("FrontRun");
			$TalkRayCast.rotation_degrees = $TalkRayCast.ROTATION_FRONT;
		else :
			$AnimatedWalk.play("RightRun");
			$TalkRayCast.rotation_degrees = $TalkRayCast.ROTATION_RIGHT;
	# 斜め左上移動
	if(Input.is_action_pressed("Move_Up")&&
	Input.is_action_pressed("Move_Left")&&
	!Input.is_action_pressed("Move_Down")&&
	!Input.is_action_pressed("Move_Right")):
		velocity.y = -1 *SPEED;
		velocity.x = -1 *SPEED;
		if(direction == DIRECTION_FRONT):
			$AnimatedWalk.play("BackRun");
			$TalkRayCast.rotation_degrees = $TalkRayCast.ROTATION_BACK;
		else :
			$AnimatedWalk.play("LeftRun");
			$TalkRayCast.rotation_degrees = $TalkRayCast.ROTATION_LEFT;
	# 斜め右上移動
	if(Input.is_action_pressed("Move_Up")&&
	Input.is_action_pressed("Move_Right")&&
	!Input.is_action_pressed("Move_Down")&&
	!Input.is_action_pressed("Move_Left")):
		velocity.y = -1 *SPEED;
		velocity.x = 1 *SPEED;
		if(direction == DIRECTION_FRONT):
			$AnimatedWalk.play("BackRun");
			$TalkRayCast.rotation_degrees = $TalkRayCast.ROTATION_BACK;
		else :
			$AnimatedWalk.play("RightRun");
			$TalkRayCast.rotation_degrees = $TalkRayCast.ROTATION_RIGHT;
	
	velocity = velocity *delta;
	move_and_slide();

#　停止時または会話時のアニメーション
func stopping()->void:
	if(velocity == STOPPING || BalloonManager.isChat):
		if(direction == DIRECTION_LEFT):
			$AnimatedWalk.play("LeftWeight");
		if(direction == DIRECTION_RIGHT):
			$AnimatedWalk.play("RightWeight");
		if(direction == DIRECTION_BACK):
			$AnimatedWalk.play("FrontWeight");
		if(direction == DIRECTION_FRONT):
			$AnimatedWalk.play("BackWeight");
