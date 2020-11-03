extends Node2D

var ramaining_blocks
var fallen_blocks = 0
var tower_peak = 0

var current_block
var current_block_s_number

var ground
var camera

var random = RandomNumberGenerator.new()
func get_random(r_from, r_to):
	random.randomize()
	return random.randi_range(r_from, r_to)
	
func add_kinematic():
	current_block_s_number = str(get_random(0, 2))
	current_block = load("res://scenes/blocks/Block " +
		current_block_s_number + " KinematicBody.tscn").instance()
	current_block.set_global_position(Vector2(640, tower_peak - 360))
	add_child(current_block)

func change_to_rigid():
	var tmp_rigid = load("res://scenes/blocks/Block " +
		current_block_s_number + " RigidBody.tscn").instance()
	tmp_rigid.set_global_transform(current_block.get_global_transform())
	remove_child(current_block)
	add_child(tmp_rigid)

func make_new_block():
	tower_peak = min(tower_peak, current_block.get_global_position().y)
	change_to_rigid()
	add_kinematic()
	
	ramaining_blocks -= 1
	get_parent().update_remaining_blocks(ramaining_blocks)

func _ready():
	ramaining_blocks = (get_parent().level_number + 1) * 10
	get_parent().update_remaining_blocks(ramaining_blocks)
	
	camera = get_parent().get_child(2)
	
	ground = load("res://scenes/levels/Level " +
		str(get_parent().level_number) + ".tscn").instance()
	ground.set_name("Ground")
	ground.position = Vector2(640, 0)
	add_child(ground)
	
	add_kinematic()
