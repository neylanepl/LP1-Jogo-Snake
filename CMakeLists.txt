cmake_minimum_required(VERSION 3.5)
project(snake VERSION 0.1 LANGUAGES CXX )

### Executável
# Diretório contendo os .hpp
include_directories( include )

# Cria um executável com nome "snake"
add_executable( snake
                src/Level.cpp
                src/Player.cpp
                src/Snake.cpp 
                src/SnakeGame.cpp
                src/Snaze.cpp)

# The end