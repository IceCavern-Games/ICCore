#pragma once

#include <memory>

#include <spdlog/spdlog.h>

namespace ICCore {
    class Logger {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetAppLogger() { return _appLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return _coreLogger; }

    private:
        static std::shared_ptr<spdlog::logger> _appLogger;
        static std::shared_ptr<spdlog::logger> _coreLogger;
    };
} // namespace IC

// App Log Macros
#define IC_APP_TRACE(...) ::ICCore::Logger::GetAppLogger()->trace(__VA_ARGS__)
#define IC_APP_INFO(...) ::ICCore::Logger::GetAppLogger()->info(__VA_ARGS__)
#define IC_APP_WARN(...) ::ICCore::Logger::GetAppLogger()->warn(__VA_ARGS__)
#define IC_APP_ERROR(...) ::ICCore::Logger::GetAppLogger()->error(__VA_ARGS__)
#define IC_APP_FATAL(...) ::ICCore::Logger::GetAppLogger()->fatal(__VA_ARGS__)

// Core Log Macros
#define IC_CORE_TRACE(...) ::ICCore::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define IC_CORE_INFO(...) ::ICCore::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define IC_CORE_WARN(...) ::ICCore::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define IC_CORE_ERROR(...) ::ICCore::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define IC_CORE_FATAL(...) ::ICCore::Logger::GetCoreLogger()->fatal(__VA_ARGS__)