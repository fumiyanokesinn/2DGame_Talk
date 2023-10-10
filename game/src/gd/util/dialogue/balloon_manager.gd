extends Node

## Show the example balloon
func show_dialogue_balloon(resource: DialogueResource,node: Node, title: String = "", extra_game_states: Array = []) -> void:
	var BalloonScene:Resource = load("res://src/tscn/dialogue/dialogue_ballon.tscn")
	
	var balloon: Node2D = (BalloonScene).instantiate()
	node.add_child(balloon)
	balloon.start(resource, title, extra_game_states)
