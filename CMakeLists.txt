cmake_minimum_required(VERSION 3.6)
project(crazy_eights)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp card.h player.h deck.h card_imp.cpp player_imp.cpp deck_imp.cpp)
add_executable(crazy_eights ${SOURCE_FILES})