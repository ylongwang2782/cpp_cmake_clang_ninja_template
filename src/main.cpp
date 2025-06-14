// main.cpp
#include "Logger.h"
#include <iostream>

using namespace std;

int test_logger() {
    // 测试基本日志功能
    Log::v("TestTag", "This is a verbose message");
    Log::d("TestTag", "This is a debug message");
    Log::i("TestTag", "This is an info message");
    Log::w("TestTag", "This is a warning message");
    Log::e("TestTag", "This is an error message");

    std::cout << "\n--- Testing log level filtering ---\n";

    // 设置日志级别为INFO，应该只显示INFO、WARN、ERROR
    Log::setLogLevel(LogLevel::INFO);
    Log::v("FilterTest", "This verbose should not appear");
    Log::d("FilterTest", "This debug should not appear");
    Log::i("FilterTest", "This info should appear");
    Log::w("FilterTest", "This warning should appear");
    Log::e("FilterTest", "This error should appear");

    std::cout << "\n--- Testing file logging ---\n";

    // 启用文件日志
    Log::enableFileLogging("test.log");
    Log::i("FileTest", "This message should appear in both console and file");
    Log::w("FileTest", "This warning should also be logged to file");

    // 禁用文件日志
    Log::disableFileLogging();
    Log::i("FileTest", "This message should only appear in console");

    std::cout << "\n--- Testing SyncMsg example ---\n";

    // 重置日志级别为VERBOSE以显示所有消息
    Log::setLogLevel(LogLevel::VERBOSE);
    Log::d("SyncMsg", "process");

    return 0;
}

int main() {

    constexpr const char *TAG = "BOOT";

    Log::d(TAG, "Hello, Cmake + clang + ninja on Windows!");

    test_logger();

    return 0;
}
