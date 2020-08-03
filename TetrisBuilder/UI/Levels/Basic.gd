extends Control

# Called when the node enters the scene tree for the first time.
func _ready():
	for button in $MarginContainer/VBoxContainer/GridContainer.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])

func _on_Button_pressed(scene_to_load):
	_show_all()
	$MarginContainer.hide()
	_start_game(scene_to_load)

func _process(delta):
	_update_all()
	_check_turns()
	_check_end()

func _show_all():
	$MarginContainer.show()
	$Zero/Camera2D/GameUI.show()
	$Zero.show()
	$Zero/Camera2D/Turns.show()

func _hide_all():
	$Zero.hide()
	$Zero/Camera2D/GameUI.hide()
	$Zero/Camera2D/Turns.hide()
	$MarginContainer.hide()

func _start_game(scene_to_load):
	$Zero._create_level(scene_to_load)
	$Zero/Camera2D/GameUI._ready()
	$Zero/Camera2D/GameUI.animated_blocks = $Zero.get_count_of_remaining_blocks()

func _update_all():
	var blocks = $Zero.get_count_of_remaining_blocks() #сколько осталось (инт)
	var failed = $Zero.get_count_fallen_blocks() #сколько выпало за сцену
	var score = $Zero.get_score_now() #очки
	$Zero/Camera2D/GameUI.update_health($Zero/Camera2D/GameUI.player_max_health - failed)
	$Zero/Camera2D/GameUI.update_score(score)
	$Zero/Camera2D/GameUI.update_blocks(blocks)
	
func _check_turns():
	if $Zero/Camera2D/Turns.condition == '1' :
		$Zero.turn_kinematic_left()
		$Zero/Camera2D/Turns.condition = '0'
	if $Zero/Camera2D/Turns.condition == '2' :
		$Zero.turn_kinematic_right()
		$Zero/Camera2D/Turns.condition = '0'

func _check_end():
	if $Zero.is_game_end():
		if round($Zero/Camera2D/GameUI.animated_health) <= 0:
			_hide_all()
			$LoseScene.show()
		else:
			_hide_all()
			$WinScene.show()


