extends CharacterBody2D

func _physics_process(_delta:float)-> void:
	$AnimatedWalk.play("Weight"); 

func isXButtonView()->void:
	$XButton.visible = true;
