# MadStudio 项目文档

## 项目概述

MadStudio 是一个基于 Qt 6 的桌面应用程序，使用 C++ 和 CMake 构建系统开发。该项目目前处于开发初期阶段，主要包含一个主窗口和一个自定义的流式布局（FlowLayout）组件。

### 主要技术栈
- **编程语言**: C++
- **GUI 框架**: Qt 6.9+ (Core, Widgets)
- **构建系统**: CMake 3.19+
- **IDE 配置**: CLion/Qt Creator (支持 .idea 目录)

### 项目架构
```
MadStudio/
├── main.cpp                    # 应用程序入口点
├── studiomainwindow.h/cpp      # 主窗口类定义和实现
├── studiomainwindow.ui         # Qt Designer UI 文件
├── madwidgets/                 # 自定义组件库
│   ├── flowlayout.h/cpp        # 流式布局实现
│   ├── CMakeLists.txt          # madwidgets 子模块构建配置
│   └── madwidgets.pri          # qmake 包含文件（备用）
├── resource/                   # 资源文件
│   ├── app.qrc                 # Qt 资源集合文件
│   ├── app.rc                  # Windows 资源文件
│   └── logo.ico                # 应用图标
└── CMakeLists.txt              # 主项目构建配置
```

## 构建和运行

### 前置要求
- CMake 3.19 或更高版本
- Qt 6.9 或更高版本（需包含 Core 和 Widgets 模块）
- 支持 C++17 或更高版本的编译器（MinGW 或 MSVC）

### 构建步骤

1. **创建构建目录**（推荐在项目根目录外）：
   ```bash
   mkdir build
   cd build
   ```

2. **配置 CMake**：
   ```bash
   # MinGW 编译器
   cmake -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="C:/Path/To/Qt/6.x.x/mingw_64" ..

   # 或 MSVC 编译器
   cmake -G "Visual Studio 17 2022" -A x64 -DCMAKE_PREFIX_PATH="C:/Path/To/Qt/6.x.x/msvc2019_64" ..
   ```

3. **编译项目**：
   ```bash
   cmake --build . --config Debug
   # 或 Release 版本
   cmake --build . --config Release
   ```

4. **运行应用程序**：
   ```bash
   # Windows
   cd Debug
   MadStudio.exe

   # 或 Release
   cd Release
   MadStudio.exe
   ```

### 构建输出
- 构建产物位于 `build/` 目录下
- Windows 平台会生成 `MadStudio.exe` 可执行文件
- 支持部署脚本自动生成（通过 `qt_generate_deploy_app_script`）

## 开发约定

### 代码风格
- 使用 Qt 的命名约定：类名使用 PascalCase（如 `MadStudioMainWindow`），成员变量使用 camelCase
- 头文件使用 `#ifndef` 宏进行包含保护
- 使用 Qt 的智能指针和对象模型进行内存管理
- 自定义组件命名空间：`Mad`（如 `Mad::FlowLayout`）

### 文件组织
- 每个类对应一个 `.h` 头文件和一个 `.cpp` 实现文件
- UI 文件使用 Qt Designer（`.ui` 格式）
- 资源文件统一放在 `resource/` 目录
- 自定义组件库放在 `madwidgets/` 子目录，作为静态库编译

### 模块化设计
- `madwidgets` 是一个独立的静态库模块，可以被其他项目复用
- 主程序通过 `add_subdirectory(madwidgets)` 引入自定义组件
- 使用 `target_include_directories` 确保头文件路径正确

### Git 工作流
- 使用 `.gitignore` 排除构建产物和临时文件
- 构建目录 `build/`、`debug/`、`release/` 被忽略
- IDE 配置文件（`.qtc_clangd`、`.vscode`）被忽略

## 当前功能

### 已实现
- 基本的应用程序框架（QApplication + QMainWindow）
- 主窗口 UI（包含菜单栏：文件、编辑、视图、设置）
- 自定义 FlowLayout 组件（基础框架已搭建，待完善）
- 资源系统集成（图标、应用图标）

### 待开发
- FlowLayout 的完整实现（布局算法、子项管理）
- 菜单功能实现（打开、关闭等操作）
- 主窗口内容布局和功能
- 设置对话框
- 应用程序配置持久化

## 开发注意事项

1. **Qt 版本兼容性**: 项目要求 Qt 6.5+，确保开发环境满足要求
2. **编译器选择**: 项目支持 MinGW 和 MSVC 两种编译器，根据需要选择
3. **资源管理**: 使用 Qt 的资源系统（`.qrc`）管理图标和其他资源
4. **UI 设计**: 可以使用 Qt Designer 修改 `.ui` 文件，或在代码中动态创建 UI
5. **模块复用**: `madwidgets` 库设计为可复用，添加新组件时遵循现有模式

## 调试和测试

- 使用 Qt Creator 或 CLion 进行调试
- 日志输出使用 `qDebug()`、`qWarning()` 等 Qt 日志函数
- 当前项目暂无单元测试框架，建议后续添加 Qt Test

## 常见问题

### CMake 找不到 Qt
确保设置 `CMAKE_PREFIX_PATH` 指向 Qt 安装目录，或设置 `Qt6_DIR` 环境变量。

### 编译错误
检查 Qt 版本是否为 6.5+，编译器是否支持 C++17。

### 运行时缺少 DLL
使用 `windeployqt` 工具部署 Qt 依赖，或使用 CMake 生成的部署脚本。
