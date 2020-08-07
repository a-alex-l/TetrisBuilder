extends MarginContainer
var condition = '0'

# Called when the node enters the scene tree for the first time.
func _ready():
	for button in $HBoxContainer.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.move])

func _on_Button_pressed(move):
	condition = String(move)
