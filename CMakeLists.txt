cmake_minimum_required(VERSION 3.16)

project(QmlThemeDemo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 获取添加.cpp与.h文件
file(GLOB_RECURSE CPP_FILES *.cpp *.h)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appQmlThemeDemo
    ${CPP_FILES}
    ./Resource.qrc
)
file(GLOB_RECURSE QmlFiles *.qml)

foreach(element ${QmlFiles})
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" qmlfile ${element})
    list(APPEND QMLFiles ${qmlfile})
endforeach(element)
# 去重
list(REMOVE_DUPLICATES QMLFiles)

# 获取添加.qml文件
file(GLOB_RECURSE ImgFiles *.png *.svg *.jpg)
# 将QmlFiles列表中各元素的绝对路径更改为相对路径
foreach(element ${ImgFiles})
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" imgfile ${element})
    list(APPEND IMGFiles ${imgfile})
endforeach(element)
# 去重
list(REMOVE_DUPLICATES IMGFiles)

qt_add_qml_module(appQmlThemeDemo
    URI QmlThemeDemo
    VERSION 1.0
    QML_FILES
        ${QMLFiles}
    RESOURCES
        ${IMGFiles}
)
# 无效
list(APPEND QML_DIRS "qrc:/")
set(QML_IMPORT_PATH "${QML_DIRS}" CACHE STRING "")

set_target_properties(appQmlThemeDemo PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQmlThemeDemo
    PRIVATE Qt6::Quick)

install(TARGETS appQmlThemeDemo
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
