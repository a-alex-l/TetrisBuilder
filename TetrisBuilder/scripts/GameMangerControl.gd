extends Control

func replace_scene(new_scene):
	self.get_child(0).queue_free()
	self.add_child(new_scene)
