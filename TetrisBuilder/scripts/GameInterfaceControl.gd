extends Control

var level_number = 0

func _on_LeftTurnButton_pressed():
	$Zero.current_block.turn_block_left()

func _on_RightTurnButton_pressed():
	$Zero.current_block.turn_block_right()

func _on_Pause_pressed():
	$Zero.paused = true
	
	$Zero.paused = false
	
func block_fell(fallen_blocks):
	if   (fallen_blocks == 0):
		$Interface/LeftSide/Heart3.hide()
	elif (fallen_blocks == 1):
		$Interface/LeftSide/Heart2.hide()
	else:
		$Interface/LeftSide/Heart1.hide()
		$Zero.paused = true
		yield(get_tree().create_timer(10), "Watch on loose")
		$Zero.paused = false

func update_remaining_blocks(remaining_blocks):
	$Interface/RightSide/CountRemainBlock.text = str(remaining_blocks)

