cmake_minimum_required(VERSION 3.15)
project(vigenere_cipher)

set(CMAKE_CXX_STANDARD 20)

add_executable(vigenere_cipher main.cpp vigenere.cpp vigenere.h)