extends Control

const MARGIN_X:int = 125
const MIN_MARGIN_X = 0
const MAX_MARGIN_X = 1000

var marginLeft:int = 0

func _process(_delta:float)-> void:

	if(Input.is_action_just_pressed("Circle_Move_Left")):
		# Aキーを押下した場合、サークルを左に移動
		if(marginLeft>MIN_MARGIN_X):
			marginLeft-=MARGIN_X;
		$MarginCircle.add_theme_constant_override("margin_left",marginLeft);
	if(Input.is_action_just_pressed("Circle_Move_Right")):
		# Dキーを押下した場合、サークルを右に移動
		if(marginLeft<MAX_MARGIN_X):
			marginLeft+=MARGIN_X;
		$MarginCircle.add_theme_constant_override("margin_left",marginLeft);
