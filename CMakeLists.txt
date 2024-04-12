cmake_minimum_required(VERSION 3.27)
project(bank_in_c C)

set(CMAKE_C_STANDARD 11)

add_executable(bank_in_c main.c
        balance.h
        balance.c
        transfer.h
        transfer.c
        login.h
        login.c)
