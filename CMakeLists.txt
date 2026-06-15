cmake_minimum_required(VERSION 3.16)

project(StudentAdventure)

set(CMAKE_CXX_STANDARD 20)

# Wyszukiwanie biblioteki SFML 3 w systemie
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

# Wskazanie folderu z plikami nagłówkowymi (.h)
include_directories(include)

# Definicja pliku wykonywalnego i lista wszystkich plików źródłowych (.cpp)
add_executable(game
    src/main.cpp
    src/Character.cpp
    src/Student.cpp
    src/Lecturer.cpp
    src/ECTS.cpp
    src/Coffee.cpp
    src/Platform.cpp
    src/Game.cpp
)

# Linkowanie modułów SFML do pliku wykonywalnego gry
target_link_libraries(game PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)
include_directories(include)