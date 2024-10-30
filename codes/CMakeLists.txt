cmake_minimum_required(VERSION 3.16)
project(HiveGame)

# 设置 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)

# 添加项目的源文件
add_executable(HiveGame
        src/main.cpp
        src/Board.cpp
        src/Insect.cpp
        src/QueenBee.cpp
        src/Position.cpp
        src/Game.h
        src/PlayerControl.cpp
        src/Player.cpp
        src/HumanPlayer.h
        src/HumanPlayer.cpp
        src/RobotPlayer.h
        src/RobotPlayer.cpp
        src/Game.cpp
)

# 设置 SFML 的包含和库路径
set(SFML_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/libs/SFML/include")
set(SFML_LIBRARY_DIR "${PROJECT_SOURCE_DIR}/libs/SFML/lib")

# 包含 SFML 的头文件目录
include_directories(${SFML_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src)

# 链接 SFML 的静态库
target_link_libraries(HiveGame
        "${SFML_LIBRARY_DIR}/libsfml-graphics.a"
        "${SFML_LIBRARY_DIR}/libsfml-window.a"
        "${SFML_LIBRARY_DIR}/libsfml-system.a"
)