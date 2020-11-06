extends Control

var is_rewarded_video_loaded = false

func _on_PlayButton_pressed():
	get_parent().replace_scene(load("res://scenes/Levels.tscn").instance())

func _on_SettingsButton_pressed():
	get_parent().replace_scene(load("res://scenes/Settings.tscn").instance())

func _on_SupportUsButton_pressed():
	if (is_rewarded_video_loaded):
		$AdMob.show_rewarded_video()

func _on_AdMob_rewarded(currency, ammount):
	is_rewarded_video_loaded = false
	$AdMob.load_rewarded_video()

func _on_AdMob_rewarded_video_loaded():
	is_rewarded_video_loaded = true
