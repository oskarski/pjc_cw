cmake_minimum_required(VERSION 3.17)
project(pjc_cw)

set(CMAKE_CXX_STANDARD 20)

add_executable(pjc_cw main.cpp)
add_executable(pjc_cw_project project/project.cpp project/BoardConfig.cpp project/InputReader.cpp project/BoardCellVector.cpp project/Board.cpp project/BoardCell.cpp project/ScoreRepository.cpp)