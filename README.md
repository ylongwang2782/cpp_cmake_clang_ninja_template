## 🧱 cpp\_cmake\_clang\_template

一个用于在 **Windows** 上快速搭建 **Clang + CMake + C++** 工程的模板项目，支持 VSCode 快速开发、构建与调试。

### ✨ 特性 Features

* 📦 使用 CMake 构建系统，结构清晰易扩展
* 🧠 支持 Clang 编译器在 Windows 上开发调试
* 🛠️ 预配置 VSCode 的 `tasks.json` 和 `launch.json`，一键编译与调试
* ⚡ 支持 Debug 和 Release 模式
* 📁 项目结构简洁，适合作为 C++ 工程起点

---

### 📁 项目结构 Project Structure

```bash
cpp_cmake_clang_template/
├── CMakeLists.txt          # 顶层CMake配置
├── src/                    # 源码目录
│   └── main.cpp
├── include/                # 头文件目录
├── build/                  # 构建输出目录（建议添加 .gitignore）
├── .vscode/                # VSCode 配置
│   ├── tasks.json
│   └── launch.json
└── README.md               # 项目说明
```

---

### 🚀 快速开始 Quick Start

#### 1️⃣ 准备环境

确保以下工具已安装：

* [Clang](https://releases.llvm.org/)
* [CMake](https://cmake.org/)
* [Ninja](https://ninja-build.org/)（可选，推荐）
* [VSCode](https://code.visualstudio.com/) + [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)

#### 2️⃣ 构建项目

```bash
# 创建构建目录
mkdir build
cd build

# 使用Clang作为编译器进行构建
cmake .. -G "Ninja" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++

# 编译
cmake --build .
```

---

### 🖥️ VSCode 使用说明

#### 配置文件说明：

* `.vscode/tasks.json`：定义了编译任务
* `.vscode/launch.json`：配置了调试器（需使用 clang-cl 或 gdb/lldb）

#### 一键编译运行：

1. 按 `Ctrl+Shift+B` 编译
2. 按 `F5` 调试运行

---

### 🔧 自定义配置

* 支持通过 `-DCMAKE_BUILD_TYPE=Release` 切换到 Release 模式
* 可拓展添加单元测试、第三方库（如 Catch2、fmt、spdlog）

---

### ✅ 示例输出

```bash
$ ./build/main.exe
Hello, Clang + CMake on Windows!
```

---

### 📌 常见问题 FAQ

#### Q: 编译器找不到？

A: 请确认已将 Clang 添加到系统环境变量 `PATH` 中。

#### Q: VSCode 无法识别 clang？

A: 安装 `LLVM` 后配置 `"C_Cpp.default.compilerPath"` 指向 `clang.exe`。

---

### 📜 许可证 License

MIT License © 2025 YourName

---