# 🧱 cpp_cmake_clang_template

[![CMake Presets](https://img.shields.io/badge/CMake-Presets-blue.svg)](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html)
[![Build with Clang++](https://img.shields.io/badge/build-clang%2B%2B-orange.svg)](https://clang.llvm.org/)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](./LICENSE)
[![Platform: Windows](https://img.shields.io/badge/platform-Windows-blue)](#)
[![VSCode Ready](https://img.shields.io/badge/Editor-VSCode-007ACC.svg?logo=visual-studio-code)](https://code.visualstudio.com/)


一个用于在 **Windows 上使用 Clang++ + CMake + Ninja** 快速搭建 C++ 工程的模板项目，适配 VSCode，支持调试与预设构建，适合作为个人项目或教学示范的起点工程。

---

## ✨ 特性 Features

- ⚙️ 使用 CMake 管理构建流程
- 🧠 支持 Clang++ 编译器 + Ninja 构建系统
- 🖥️ 内置 VSCode 配置，支持一键构建和调试
- 📋 支持 CMake Presets（推荐构建方式）
- 🐞 支持断点调试（基于 LLDB）
- ✅ 项目结构清晰、模块化、可拓展

---

## 📁 项目结构

```

cpp\_cmake\_clang\_template/
├── CMakeLists.txt             # 顶层构建文件
├── src/
│   └── main.cpp               # 示例程序
├── include/                   # 可选头文件目录
├── build/                     # 构建输出目录（由 preset 自动生成）
├── .vscode/
│   ├── launch.json            # 调试配置（使用 LLDB）
│   └── tasks.json             # 构建任务
├── CMakePresets.json          # 构建预设管理推荐入口
└── README.md

````

---

## 🚀 快速开始（推荐使用 CMake Presets）

### 🔧 环境要求

- ✅ [LLVM/Clang](https://releases.llvm.org/)（推荐通过 Scoop 安装：`scoop install llvm`）
- ✅ [CMake ≥ 3.23](https://cmake.org/)
- ✅ [Ninja](https://ninja-build.org/)
- ✅ [VSCode](https://code.visualstudio.com/)
  - 插件：`CMake Tools`、`CodeLLDB`、`C/C++`

### 📦 编译与运行

```bash
# 初始化 Debug 构建
cmake --preset debug

# 构建
cmake --build --preset debug

# 运行可执行程序（或在 VSCode 中调试）
./build/debug/main.exe
````

---

## 🖥️ VSCode 使用说明

### ✅ 快捷键

* `Ctrl+Shift+B` — 执行构建任务
* `F5` — 启动调试（断点、单步、查看变量）

### ⚙️ 预配置说明

* `launch.json` 使用 `CodeLLDB` 调试 clang++ 编译出的可执行文件
* `tasks.json` 自动调用 `cmake --build` 构建项目
* 可在 `.vscode/settings.json` 设置默认 preset：

```json
{
  "cmake.preferredConfigurePreset": "debug",
  "cmake.preferredBuildPreset": "debug"
}
```

---

## ⚙️ CMake Presets 配置（节选）

```json
{
  "version": 3,
  "configurePresets": [
    {
      "name": "debug",
      "inherits": "base-clang",
      "binaryDir": "${sourceDir}/build/debug",
      "cacheVariables": {
        "CMAKE_BUILD_TYPE": "Debug"
      }
    },
    {
      "name": "release",
      "inherits": "base-clang",
      "binaryDir": "${sourceDir}/build/release",
      "cacheVariables": {
        "CMAKE_BUILD_TYPE": "Release"
      }
    }
  ],
  "buildPresets": [
    { "name": "debug", "configurePreset": "debug" },
    { "name": "release", "configurePreset": "release" }
  ]
}
```

---

## ✅ 示例输出

```bash
$ ./build/debug/main.exe
Hello, Clang + CMake on Windows!
```

---

## ❓常见问题 FAQ

### Q: VSCode 无法命中断点？

A:

* 确认构建类型为 `Debug`
* 确认 `clang++` 与 `lldb` 来自相同 LLVM 版本
* 检查是否正确配置 VSCode 调试器（使用 CodeLLDB）

### Q: 是否支持 Windows + MSVC 调试器？

A: 本项目以 Clang++ + LLDB 为核心。如需切换至 `clang-cl` + `cppvsdbg`，请另行配置。

---

## 📜 License

[MIT License](LICENSE) © 2025 YourName

---

## 🙋‍♂️ 贡献或建议

欢迎 issue / PR / 提问，共同完善本模板 🎉

```

---

如果你还希望我为这份 `README.md`：

- 添加徽章（badge）
- 添加 GitHub Actions 构建状态
- 自动识别是否安装 Clang/Ninja/CMake 的检查脚本

我可以继续帮你扩展。

是否需要我将这份 README 输出为 Markdown 文件或直接写入你的工程目录？
```
