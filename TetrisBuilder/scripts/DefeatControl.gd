extends Control

func _on_MenuButton_pressed():
	get_parent().replace_scene(load("res://scenes/MenuWindow.tscn").instance())
