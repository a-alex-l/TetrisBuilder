extends Control

func _on_MenuButton_pressed():
	get_parent().replace_scene(load("res://scenes/MenuWindow.tscn").instance())

func _on_LevelButton_pressed(level_number):
	var game_interface_scene = load("res://scenes/GameInterface.tscn").instance()
	game_interface_scene.level_number = int(level_number)
	get_parent().replace_scene(game_interface_scene)
