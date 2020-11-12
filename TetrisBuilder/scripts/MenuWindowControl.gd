extends Control

func _on_PlayButton_pressed():
	get_parent().replace_scene(load("res://scenes/Levels.tscn").instance())

func _on_SettingsButton_pressed():
	get_parent().replace_scene(load("res://scenes/Settings.tscn").instance())

func _on_SupportUsButton_pressed():
	pass
