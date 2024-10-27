cmake_minimum_required(VERSION 3.16)
project(HiveGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(HiveGame
        src/main.cpp
        src/Board.cpp
        src/Insect.cpp
        src/QueenBee.cpp
        src/Position.cpp)

include_directories(${PROJECT_SOURCE_DIR}/src)

# 设置 SFML 的路径
set(SFML_PREFIX_PATH "C://SFML-2.6.1")

# 查找 SFML 库
find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)

# 添加项目的源文件
add_executable(HiveGame main.cpp Board.cpp Insect.cpp Position.cpp)


# 将 SFML 链接到你的项目
target_link_libraries(HiveGame sfml-graphics sfml-window sfml-system)
