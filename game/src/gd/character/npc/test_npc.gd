extends CharacterBody2D

var START_DIALOGUE_FILE:DialogueResource = load("res://dialogue/start.dialogue")
const START_DIALOGUE:String = "start"

var SHADER_RESOURCE:Shader = load("res://src/shader/character/out_line.gdshader")

func _physics_process(_delta:float)-> void:
	$AnimatedWalk.play("Weight"); 
	if($XButton.visible):
		if(Input.is_action_just_pressed("Talk_Action")):
#			$DialogueBallon.visible = true;
			chat(START_DIALOGUE_FILE,get_name());

# チャットボタンを表示する
func isXButtonView(flg:bool)->void:
	$XButton.visible = flg;
	if(flg):
		# シェーダーリソースを持つ新しいShaderMaterialを作成
		var outLine : ShaderMaterial = ShaderMaterial.new();
		outLine.shader = SHADER_RESOURCE;
		# スプライトなどのオブジェクトに材質を割り当てる
		$AnimatedWalk.material = outLine;
	else :
		$AnimatedWalk.material = null

# 会話を行う
func chat(fileName:DialogueResource,chatName:String)->void:
	BalloonManager.show_dialogue_balloon(fileName,get_node("."),chatName);
