cmake_minimum_required(VERSION 3.20)
project(Projekt)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

add_executable(Projekt main.cpp StartMenu.cpp StartMenu.h Pokemon.cpp Pokemon.h Game.cpp Game.h Trainer.cpp Trainer.h Battle.cpp Battle.h)
