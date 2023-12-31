#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For the reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["extension/src/"])
sources = (
    Glob("extension/src/*.cpp")
    + Glob("extension/src/character/*.cpp")
    + Glob("extension/src/UI/*.cpp")
)

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "game/bin/libgdsummator.{}.{}.framework/libgdsummator.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    # This line
    env["LINKFLAGS"] = "-static-libgcc -static-libstdc++ -static -pthread"
    library = env.SharedLibrary(
        "game/bin/libgdsummator{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
