cmake_minimum_required(VERSION 3.16)
project(Freezer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets WebEngineWidgets)

add_executable(freezer-bin
    src/main.cpp
    src/FreezerWindow.cpp
)

target_include_directories(freezer-bin PRIVATE include)

target_link_libraries(freezer-bin
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::WebEngineWidgets
)

install(TARGETS freezer-bin RUNTIME DESTINATION bin)

install(FILES desktop/freezer.desktop
        DESTINATION share/applications)

install(FILES icons/freezer.png
        DESTINATION share/icons/hicolor/512x512/apps)

install(FILES proxy/freezer-wireproxy.conf
        DESTINATION share/freezer)

install(FILES adblock/deezer.txt
        DESTINATION share/freezer)
