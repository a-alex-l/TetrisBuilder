extends KinematicBody2D

var data = preload("res://bin/BlockMove.gdns").new()

func _init():
	data._init()

func _ready():
	data.hello()

func _input(event):
	data._input(event)

func _physics_process(delta):
	data._physics_process(delta)
