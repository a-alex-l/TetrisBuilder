#!python
import os, subprocess

opts = Variables([], ARGUMENTS)

# Gets the standard flags CC, CCX, etc.
env = DefaultEnvironment()

# Define our options
opts.Add(EnumVariable('target', "Compilation target", 'debug', ['d', 'debug', 'r', 'release']))
opts.Add(EnumVariable('platform', "Compilation platform", '', ['', 'windows', 'x11', 'linux', 'osx', 'android_armv7', 'android_arm64v8', 'android_x86_64']))
opts.Add(EnumVariable('p', "Compilation target, alias for 'platform'", '', ['', 'windows', 'x11', 'linux', 'osx']))
opts.Add(BoolVariable('use_llvm', "Use the LLVM / Clang compiler", 'no'))
opts.Add(PathVariable('target_path', 'The path where the lib is installed.', 'TetrisBuilder/bin/'))
opts.Add(PathVariable('target_name', 'The library name.', 'libgdexample', PathVariable.PathAccept))

# Local dependency paths, adapt them to your setup
godot_headers_path = "godot-cpp/godot_headers/"
cpp_bindings_path = "godot-cpp/"
cpp_library = "libgodot-cpp"

# Updates the environment with the option variables.
opts.Update(env)

# Process some arguments
if env['use_llvm']:
    env['CC'] = 'clang'
    env['CXX'] = 'clang++'

if env['p'] != '':
    env['platform'] = env['p']

if env['platform'] == '':
    print("No valid target platform selected.")
    quit();

# For the reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# Check our platform specifics
if env['platform'] in ('x11', 'linux'):
    env['target_path'] += 'x11/'
    cpp_library += '.linux'
    env.Append(CCFLAGS=['-fPIC'])
    env.Append(CXXFLAGS=['-std=c++17'])
    if env['target'] in ('debug', 'd'):
        cpp_library += '.debug.64.a'
        env.Append(CCFLAGS=['-g3', '-Og'])
    else:
        cpp_library += '.release.64.a'
        env.Append(CCFLAGS=['-g', '-O3'])

else:
    #Find location of 'armv7a-linux-androideabi29-clang++'
    #env['CC'] = '/home/alex/android/android-ndk-r21d/toolchains/llvm/prebuilt/linux-x86_64/bin/armv7a-linux-androideabi29-clang'
    env['CXX'] = '/home/alex/android/android-ndk-r21d/toolchains/llvm/prebuilt/linux-x86_64/bin/'
    env['target_path'] += 'android/'
    env.Append(CXXFLAGS=['-std=c++14'])

    if env['target'] in ('debug', 'd'):
        cpp_library += '.android.debug'
        env.Append(CCFLAGS=['-g3', '-Og'])
    else:
        cpp_library += '.android.release'
        env.Append(CCFLAGS=['-g', '-O3'])

    if env['platform'] in ('android_armv7'):
        env['target_path'] += 'armv7/'
        cpp_library += '.armv7.a'
        env['CXX'] += 'armv7a-linux-androideabi30-clang++'
    elif env['platform'] in ('android_arm64v8'):
        env['target_path'] += 'arm64v8/'
        cpp_library += '.arm64v8.a'
        env['CXX'] += 'aarch64-linux-android30-clang++'
    elif env['platform'] in ('android_x86_64'):
        env['target_path'] += 'x86_64/'
        cpp_library += '.x86_64.a'
        env['CXX'] += 'x86_64-linux-android30-clang++'

print(cpp_library)

# make sure our binding library is properly includes
env.Append(CPPPATH=['.', godot_headers_path, cpp_bindings_path + 'include/', cpp_bindings_path + 'include/core/', cpp_bindings_path + 'include/gen/'])
env.Append(LIBPATH=[cpp_bindings_path + 'bin/'])
env.Append(LIBS=[cpp_library])

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=['src/'])
sources = Glob('src/*.cpp')

library = env.SharedLibrary(target=env['target_path'] + env['target_name'] , source=sources)

Default(library)

# Generates help for the -h scons option.
Help(opts.GenerateHelpText(env))
