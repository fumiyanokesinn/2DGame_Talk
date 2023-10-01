extends CharacterBody2D

const SHADER_RESOURCE:Shader = preload("res://src/shader/character/test_npc.gdshader")

func _physics_process(_delta:float)-> void:
	$AnimatedWalk.play("Weight"); 

func isXButtonView(flg:bool)->void:
	$XButton.visible = flg;
	if(flg):
		# シェーダーリソースを持つ新しいShaderMaterialを作成
		var shader_material : ShaderMaterial = ShaderMaterial.new();
		shader_material.shader = SHADER_RESOURCE;
		# スプライトなどのオブジェクトに材質を割り当てる
		$AnimatedWalk.material = shader_material;
	else :
		$AnimatedWalk.material = null
