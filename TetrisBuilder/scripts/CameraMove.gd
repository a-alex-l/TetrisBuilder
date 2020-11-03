extends Camera2D

func move(speed):
	position += speed
	get_parent().get_child(1).set_position(
		get_parent().get_child(1).get_position() + speed)


func _input(event):
	if (event is InputEventScreenDrag):
		if (!get_parent().get_child(0).current_block.dragging):
			move(-event.speed * scale / 25)


func _on_ScaleButton_pressed(scale_in):
	get_parent().get_child(1).rect_scale *= scale_in
	zoom *= scale_in
	scale *= scale_in
