extends MarginContainer

onready var number_label_HP = $HBoxContainer/Bars/Bar/Count/Background/Number
onready var bar_HP = $HBoxContainer/Bars/Bar/TextureProgress
onready var number_label_Score = $HBoxContainer/Bars/EnergyBar/Count/Background/Number
onready var bar_Score = $HBoxContainer/Bars/EnergyBar/TextureProgress
onready var blocks = $HBoxContainer/Counters/BombCounter/Background/Number
onready var tween = $Tween

var animated_health = 0
var animated_score = 0
var animated_blocks = 0
var player_max_health = 5
var player_max_score = 1000


func _ready():
	bar_HP.max_value = player_max_health
	bar_Score.max_value = player_max_score
	update_health(player_max_health)
	update_score(player_max_score)

func update_health(new_value):
	tween.interpolate_property(self, "animated_health", animated_health, new_value, 0.6, Tween.TRANS_LINEAR, Tween.EASE_IN)
	if not tween.is_active():
		tween.start()

func update_score(new_value):
	tween.interpolate_property(self, "animated_score", animated_score, new_value, 0.6, Tween.TRANS_LINEAR, Tween.EASE_IN)
	if not tween.is_active():
		tween.start()

func update_blocks(new_value):
	animated_blocks = round(new_value)
	blocks.text = str(animated_blocks)

func _process(delta):
	var round_value_HP = round(animated_health)
	number_label_HP.text = str(round_value_HP)
	bar_HP.value = round_value_HP
	var round_value_score = round(animated_score)
	number_label_Score.text = str(round_value_score)
	bar_Score.value = round_value_score
	blocks.text = str(animated_blocks)
