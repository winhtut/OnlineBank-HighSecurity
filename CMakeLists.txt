cmake_minimum_required(VERSION 3.21)
project(OnlineBankPj C)

set(CMAKE_C_STANDARD 11)

add_executable(OnlineBankPj main.c onlineBank.h user_setting.h)
