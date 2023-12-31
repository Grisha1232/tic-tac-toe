cmake_minimum_required(VERSION 3.2)

project(tic-tac-toe)

set(CMAKE_CXX_STANDARD 20)
set(CMALE_CXX_STANDARD_REQUIERED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(tic-tac-toe
    main.cpp
)

add_library(Windows Windows/tic-tac-toeWindow.cpp Windows/tic-tac-toeWindow.h)
add_library(Logic Logic/Game.cpp Logic/Game.h)

target_link_libraries(tic-tac-toe PRIVATE Windows)
target_link_libraries(Windows PRIVATE Logic)

target_link_libraries(tic-tac-toe PRIVATE Qt6::Widgets)
target_link_libraries(Logic PRIVATE Qt6::Widgets)
target_link_libraries(Windows PRIVATE Qt6::Widgets)

set_target_properties(tic-tac-toe PROPERTIES
	WIN32_EXECUTABLE ON
	MACOSX_BUNDLE ON
)
