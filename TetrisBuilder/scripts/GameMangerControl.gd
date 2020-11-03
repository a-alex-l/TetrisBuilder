extends Control

func replace_scene(new_scene):
	for child in get_children():
		child.queue_free()
	add_child(new_scene)

func add_small_scene(new_scene):
	add_child(new_scene)
