// main.cpp
#include "Logger.h"
#include <iostream>
#include <string>

using namespace std;

int test_looger() {
    // 设置日志级别
    Log::setLogLevel(LogLevel::DEBUG);

    // 启用文件日志
    Log::enableFileLogging("app.log");

    // 原有的字符串日志方式（仍然支持）
    Log::i("MAIN", "Application started");

    // 新的参数化日志方式
    int userId = 12345;
    std::string userName = "Bob";
    double balance = 1234.56;

    // 使用 printf 风格的格式化（兼容性更好）
    Log::i("USER", "User login: ID=%d, Name=%s", userId, userName.c_str());
    Log::d("ACCOUNT", "User %s balance: %.2f", userName.c_str(), balance);

    // 记录程序运行中的变量
    for (int i = 0; i < 5; i++) {
        Log::v("LOOP", "Processing item %d of %d", i + 1, 5);

        if (i == 2) {
            Log::w("LOOP",
                   "Warning: Processing item %d took longer than expected",
                   i + 1);
        }
    }

    // 错误日志示例
    int errorCode = 404;
    std::string errorMsg = "File not found";
    Log::e("ERROR", "Error occurred: Code=%d, Message=%s", errorCode,
           errorMsg.c_str());

    // 混合使用不同类型的参数
    bool isConnected = true;
    float temperature = 25.7f;
    Log::i("SYSTEM", "Status: Connected=%s, Temperature=%.1f°C",
           isConnected ? "true" : "false", temperature);

    Log::i("MAIN", "Application finished");

    return 0;
}

int main() {

    constexpr const char *TAG = "BOOT";

    Log::d(TAG, "Hello, Cmake + clang + ninja on Windows!");

    test_looger();

    return 0;
}