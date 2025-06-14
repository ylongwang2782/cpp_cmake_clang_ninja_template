#pragma once
#include <fstream>
#include <mutex>
#include <string>

enum class LogLevel { VERBOSE = 0, DEBUG = 1, INFO = 2, WARN = 3, ERROR = 4 };

class Logger {
  public:
    static Logger &getInstance();

    void setLogLevel(LogLevel level);
    void enableFileLogging(const std::string &filename);
    void disableFileLogging();

    void log(LogLevel level, const std::string &tag,
             const std::string &message);

    // 便捷方法
    void v(const std::string &tag, const std::string &message);
    void d(const std::string &tag, const std::string &message);
    void i(const std::string &tag, const std::string &message);
    void w(const std::string &tag, const std::string &message);
    void e(const std::string &tag, const std::string &message);

  private:
    Logger() = default;
    ~Logger();
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    std::string getCurrentTimestamp();
    std::string levelToString(LogLevel level);

    LogLevel currentLogLevel = LogLevel::VERBOSE;
    std::ofstream logFile;
    bool fileLoggingEnabled = false;
    std::mutex logMutex;
};

// 全局便捷访问
class Log {
  public:
    static void v(const std::string &tag, const std::string &message);
    static void d(const std::string &tag, const std::string &message);
    static void i(const std::string &tag, const std::string &message);
    static void w(const std::string &tag, const std::string &message);
    static void e(const std::string &tag, const std::string &message);

    static void setLogLevel(LogLevel level);
    static void enableFileLogging(const std::string &filename);
    static void disableFileLogging();
};