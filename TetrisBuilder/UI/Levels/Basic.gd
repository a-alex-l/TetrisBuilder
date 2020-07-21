extends Control

# Called when the node enters the scene tree for the first time.
func _ready():
	for button in $MarginContainer/VBoxContainer/GridContainer.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])

func _on_Button_pressed(scene_to_load):
	$MarginContainer.hide()
	$GUI2.show()
	$Zero.show()
	$GUI.show()
	$Zero._create_level(scene_to_load)
	$GUI2._ready()
	$GUI2.animated_blocks = $Zero.get_count_of_remaining_blocks()
	
func _process(delta):
	var blocks = $Zero.get_count_of_remaining_blocks() #сколько осталось (инт)
	var failed = $Zero.get_count_fallen_blocks() #сколько выпало за сцену
	var score = $Zero.get_score_now() #очки
	$GUI2.update_health($GUI2.player_max_health - failed)
	print($Zero.get_score_now())
	$GUI2.update_score(score)
	$GUI2.update_blocks(blocks)
	if $GUI.condition == '1' :
		$Zero.turn_kinematic_left()
		$GUI.condition = '0'
	if $GUI.condition == '2' :
		$Zero.turn_kinematic_right()
		$GUI.condition = '0'
	if round($GUI2.animated_health) == 0:
		$Zero.hide()
		$GUI2.hide()
		$GUI.hide()
		$LoseScene.show()
		
		

