cmake_minimum_required(VERSION 3.17)
project(kursovay)

set(CMAKE_CXX_STANDARD 14)

add_executable(kursovay main.cpp String.cpp String.h FileCannotOpened.h NoSign.h HashTable.h Dictionary.cpp Dictionary.h WrongKey.h WrongValues.h Exceptions.h)