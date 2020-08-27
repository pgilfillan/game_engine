# OpenGL Based Game Engine

What is intended to be a simple game engine written primarily with OpenGL, potentially with a
rendering abstraction layer in the future. Mostly being written for the purpose of learning, 
in particular learning more about rendering techniques, engine architecture and designing 
systems with many components. I'm not expecting to develop a meaningful game with it.

Barely anything apart from a basic rendering skeleton done yet.

## Building

* git clone --recurse-submodules https://github.com/pgilfillan/game_engine.git
* mkdir game_engine/build
* cd game_engine/build
* cmake ..
* cmake --build .

Then run `build/Debug/main.exe`
