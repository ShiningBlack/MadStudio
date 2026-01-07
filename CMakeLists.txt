cmake_minimum_required(VERSION 3.19)
project(MadStudio LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(MadStudio
    WIN32 MACOSX_BUNDLE
    main.cpp
    studiomainwindow.cpp
    studiomainwindow.h
    studiomainwindow.ui
    demowindow.cpp
    demowindow.h
    demowindow.ui
    pages/flowlayoutpage.cpp
    pages/flowlayoutpage.h
    pages/flowlayoutpage.ui
    pages/cardpage.cpp
    pages/cardpage.h
    pages/cardpage.ui
    pages/toastpage.cpp
    pages/toastpage.h
    pages/toastpage.ui
    pages/searchboxpage.cpp
    pages/searchboxpage.h
    pages/searchboxpage.ui
    pages/buttonpage.cpp
    pages/buttonpage.h
    pages/buttonpage.ui
    resource/app.qrc
    resource/app.rc
    IFLOW.md
)

# 包含 madwidgets 源码
add_subdirectory(madwidgets)

target_link_libraries(MadStudio
    PRIVATE
        Qt::Core
        Qt::Widgets
        madwidgets
)
target_link_libraries(MadStudio PRIVATE Qt6::Core)

include(GNUInstallDirs)

install(TARGETS MadStudio
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET MadStudio
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
