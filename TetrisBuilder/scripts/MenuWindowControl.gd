extends Control

var AdMob
var AdMobDict = Dictionary()

var GodotAds

func _init():
	return
	GodotAds = Engine.get_singleton("GodotAds")
	GodotAds.init(get_instance_id())
	AdMob = GodotAds.get_singleton("AdMob")
	AdMobDict["BannerAd"] = false
	AdMobDict["InterstitialAd"] = false
	AdMobDict["RewardedVideoAd"] = true
	AdMobDict["BannerGravity"] = "BOTTOM"
	AdMobDict["BannerAdId"] = "your banner ad id"
	AdMobDict["InterstitialAdId"] = "your interstitial ad id"
	AdMobDict["RewardedVideoAdId"] = "rewarded video ad id"


func _on_PlayButton_pressed():
	get_parent().replace_scene(load("res://scenes/Levels.tscn").instance())

func _on_SettingsButton_pressed():
	get_parent().replace_scene(load("res://scenes/Settings.tscn").instance())

func _on_SupportUsButton_pressed():
	return
	if (AdMob.is_rewarded_video_loaded()):
		AdMob.show_rewarded_video()
