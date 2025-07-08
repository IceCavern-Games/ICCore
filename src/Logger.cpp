#include "Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace ICCore {
    std::shared_ptr<spdlog::logger> Logger::_appLogger;
    std::shared_ptr<spdlog::logger> Logger::_coreLogger;

    void Logger::Init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        _coreLogger = spdlog::stdout_color_mt("IC");
        _coreLogger->set_level(spdlog::level::trace);

        _appLogger = spdlog::stdout_color_mt("ICApp");
        _appLogger->set_level(spdlog::level::trace);
    }
}