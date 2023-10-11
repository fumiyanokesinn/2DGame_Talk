extends Node

# 既に会話しているか
var isChat:bool = false

## Show the example balloon
func show_dialogue_balloon(resource: DialogueResource,node: Node, title: String = "", extra_game_states: Array = []) -> void:
	if(!isChat):
#		会話していない場合,会話を実行
		isChat = true;
		var BalloonScene:Resource = load("res://src/tscn/dialogue/dialogue_ballon.tscn");
		
#		バルーンノードを追加
		var balloon: Node2D = (BalloonScene).instantiate();
		node.add_child(balloon);
		print(node.position);
		balloon.position.y = -150;
		print(balloon.position);
		balloon.start(resource, title, extra_game_states);
