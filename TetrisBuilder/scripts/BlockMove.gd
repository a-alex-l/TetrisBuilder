extends KinematicBody2D

var dragging = false
var collision_now = false

var camera

func _ready():
	camera = get_parent().get_parent().get_child(2)

func _input(event):
	if (event is InputEventScreenTouch):
		if (!dragging && ((event.position * camera.scale) +
					camera.position - position).length() < 150):
			dragging = true
		else:
			if (dragging):
				dragging = false
				if (collision_now):
					get_parent().make_new_block()


	if (event is InputEventScreenDrag):
		if (dragging):
			var move_vector = ((event.position * camera.scale) +
					camera.position - position) * 20
			move_and_slide(move_vector,
				Vector2(0, 0), false, 4, PI/4, false)
			collision_now = is_on_floor() || is_on_wall() || is_on_ceiling()

func turn_block_left():
	rotate(-PI/2)
	
func turn_block_right():
	rotate(PI/2)
