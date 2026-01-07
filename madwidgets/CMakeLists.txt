cmake_minimum_required(VERSION 3.19)
project(madwidgets LANGUAGES CXX)

set(MADWIDGETS_SOURCES
    flowlayout.cpp
    cardwidget.cpp
    toastmanager.cpp
    modernsearchbox.cpp
    modernbutton.cpp
)

set(MADWIDGETS_HEADERS
    flowlayout.h
    cardwidget.h
    toastmanager.h
    modernsearchbox.h
    modernbutton.h
)

# 可选：如果你希望编译成独立静态库（取消注释以下内容）
add_library(madwidgets STATIC
    ${MADWIDGETS_SOURCES}
    ${MADWIDGETS_HEADERS}
)

target_link_libraries(madwidgets
    PUBLIC
    Qt::Core
    Qt::Widgets
    Qt::Gui
)

target_include_directories(madwidgets PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
