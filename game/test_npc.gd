extends CharacterBody2D

func _physics_process(_delta:float)-> void:
	$AnimatedWalk.play("Weight"); 


func _on_talk_area_body_entered(_body):
	$XButton.visible = true;


func _on_talk_area_body_exited(_body):
	$XButton.visible = false;
