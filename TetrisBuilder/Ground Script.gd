extends KinematicBody2D

var data = preload("res://bin/GroundMove.gdns").new()

func _ready():
	print(data.hello())
