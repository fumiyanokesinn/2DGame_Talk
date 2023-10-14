extends Node

# 既に会話しているか
var isChat:bool = false

# 会話バルーンを表示させる
func show_dialogue_balloon(resource: DialogueResource,node: Node, title: String = "", extra_game_states: Array = []) -> void:
	if(!isChat):
#		会話していない場合,会話を実行
		isChat = true;
		var BalloonScene:Resource = load("res://src/tscn/dialogue/dialogue_ballon.tscn");
		
#		バルーンノードを会話したキャラに追加
		var balloon: Node2D = (BalloonScene).instantiate();
		node.add_child(balloon);
		balloon.position.y = -150;
		balloon.start(resource, title, extra_game_states);
