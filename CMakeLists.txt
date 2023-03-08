cmake_minimum_required(VERSION 3.16)

project(QmlThemeDemo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(QmlThemeDemo
    main.cpp
)

set(resource_files
    "main.qml"

    "Themes/Light.qml"
    "Themes/Dark.qml"
    "Themes/OneDark.qml"
    "Themes/ThemeBase.qml"
    "Themes/ThemeManager.qml"
    "Themes/qmldir"
)

qt_add_resources(QmlThemeDemo "QmlThemeDemo"
    PREFIX
        "/"
    FILES
        ${resource_files}
)

set_target_properties(QmlThemeDemo PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(QmlThemeDemo
    PRIVATE Qt6::Quick)

install(TARGETS QmlThemeDemo
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
