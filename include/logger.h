#ifndef JUMI_JPOCKET_LOGGER_H
#define JUMI_JPOCKET_LOGGER_H

#define SPDLOG_LEVEL_NAMES { "TRACE   ", "DEBUG   ", "INFO    ", "WARN    ", "ERROR   ", "CRITICAL", "OFF     " }
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>

#define JUMI_TRACE(...)    SPDLOG_LOGGER_TRACE(logger::get_logger(), __VA_ARGS__)
#define JUMI_DEBUG(...)    SPDLOG_LOGGER_DEBUG(logger::get_logger(), __VA_ARGS__)
#define JUMI_INFO(...)     SPDLOG_LOGGER_INFO(logger::get_logger(), __VA_ARGS__)
#define JUMI_WARN(...)     SPDLOG_LOGGER_WARN(logger::get_logger(), __VA_ARGS__)
#define JUMI_ERROR(...)    SPDLOG_LOGGER_ERROR(logger::get_logger(), __VA_ARGS__)
#define JUMI_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(logger::get_logger(), __VA_ARGS__)

#ifdef NDEBUG
    #define JUMI_TRACE(...)
    #define JUMI_DEBUG(...)
    #define JUMI_INFO(...)
    #define JUMI_WARN(...)
    #define JUMI_ERROR(...)
    #define JUMI_CRITICAL(...)
#endif

namespace JPocket
{

    class logger
    {
    public:
        static void init();
        static std::shared_ptr<spdlog::logger>& get_logger();

    private:
        static bool initialized;

        static std::shared_ptr<spdlog::logger> _logger;
    };

}

#endif


