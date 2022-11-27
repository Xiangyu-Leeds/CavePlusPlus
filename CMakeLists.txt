

cmake_minimum_required(VERSION 3.22)
project(CavePlusPlus)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt@5/5.15.5_1")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(CavePlusPlus tom.cpp cave.cpp location.cpp main.cpp move.cpp place.cpp blocks.h cave.h coin.h command.h location.h move.h mushroom.h place.h rock.h thing.h tom.h throw.cpp throw.h bomb.h explode.h explode.cpp)
target_link_libraries(CavePlusPlus
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

