extends Control

func _on_MenuButton_pressed():
	get_tree().paused = false
	get_parent().replace_scene(load("res://scenes/MenuWindow.tscn").instance())


func _on_PlayButton_pressed():
	get_tree().paused = false
	get_parent().get_child(1).queue_free()
