cmake_minimum_required(VERSION 3.12)
project(whist)

set(CMAKE_CXX_STANDARD 14)

add_executable(whist main.cpp Card.cpp Card.h Deck.cpp Deck.h Player.cpp Player.h Dealer.cpp Dealer.h)