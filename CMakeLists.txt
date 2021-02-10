cmake_minimum_required(VERSION 3.17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(GAME)


include_directories(/usr/local/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# add_compile_options(-Wall -Wextra -pedantic -Werror -m64 -std=c++17)
add_executable(main 
	src/main.cpp
	src/Game.cpp
	src/TextureManager.cpp
	src/Player.cpp
	src/GameObject.cpp
	src/Enemy.cpp
	src/Vector.cpp
	src/InputHandler.cpp
	src/MenuState.cpp
	src/PlayState.cpp
	src/GameStateMachine.cpp)




#finding the libraries 
find_library(SDL2 SDL2 REQUIRED)
find_library(SDL2main SDL2main REQUIRED)
find_library(SDL2_image SDL2_image REQUIRED)
find_library(SDL2_ttf SDL2_ttf)

#Making it output to bin/Deubg or bin/Release Depending on which config we are using
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin/debug RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin/release)
target_compile_options(main PUBLIC -Wall -Wextra -pedantic -Werror -m64 -std=c++17)
target_link_libraries(main ${SDL2} ${SDL2main} ${SDL2_image} ${SDL2_ttf})