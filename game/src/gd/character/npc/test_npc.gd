extends CharacterBody2D

var SHADER_RESOURCE:Shader = load("res://src/shader/character/out_line.gdshader")

func _physics_process(_delta:float)-> void:
	$AnimatedWalk.play("Weight"); 

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
