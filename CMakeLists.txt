cmake_minimum_required(VERSION 3.19)
project(snake)

set(CMAKE_CXX_STANDARD 14)

set( SFML_STATIC_LIBRARIES TRUE )

set ( SFML_DIR "C:/Users/korzonki/Documents/kajetan/SFML-2.5.1/")

add_compile_options(-Wall -Wextra -g)

find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

add_executable(${PROJECT_NAME}  main.cpp Snake.cpp Game.cpp EventHandler.cpp View.cpp Map.cpp menus/Menu.cpp menus/StartMenu.cpp menus/EndMenu.cpp menus/GameplayMenu.cpp menus/MainMenu.cpp)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)