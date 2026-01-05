# madwidgets/madwidgets.pri
# qmake include file for MadStudio Widgets

# 自动包含头文件路径
INCLUDEPATH += $$PWD

# 添加源文件（注意：pri 文件通常只声明，不强制包含）
HEADERS += \
    $$PWD/flowlayout.h \
    # $$PWD/mybutton.h \

SOURCES += \
    $$PWD/flowlayout.cpp \
    # $$PWD/mybutton.cpp \

# 如果有资源文件、UI 文件等也可加在这里