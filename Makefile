all: armv7 arm64v8 x86 x86_64 linux

armv7:
	scons platfrom=android_armv7 target=release

arm64v8:
	scons platfrom=android_arm64v8 target=release

x86:
	scons platfrom=android_x86 target=release

x86_64:
	scons platfrom=android_x86_64 target=release

linux:
	scons platfrom=linux target=release

