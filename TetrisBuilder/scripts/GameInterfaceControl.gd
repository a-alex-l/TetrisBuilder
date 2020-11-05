extends Control

var level_number = 0

func _on_LeftTurnButton_pressed():
	$Zero.current_block.turn_block_left()

func _on_RightTurnButton_pressed():
	$Zero.current_block.turn_block_right()

func _on_Pause_pressed():
	
	var scene = load("res://scenes/Pause.tscn").instance()
	scene.set_position($Camera.get_global_position())
	scene.rect_scale = $Camera.scale
	get_tree().paused = true
	get_parent().add_small_scene(scene)
	
func block_fell(fallen_blocks):
	if   (fallen_blocks == 1):
		$Interface/LeftSide/Heart3.hide()
	elif (fallen_blocks == 2):
		$Interface/LeftSide/Heart2.hide()
	else:
		$Interface/LeftSide/Heart1.hide()
		game_end("res://scenes/Defeat.tscn")

func update_remaining_blocks(remaining_blocks):
	$Interface/RightSide/CountRemainBlock.text = str(remaining_blocks)

func game_end(file_path):
	var scene = load(file_path).instance()
	for child in get_children():
		child.queue_free()
	get_parent().add_small_scene(scene)
