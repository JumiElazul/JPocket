#include "logger.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>
#include <string>

namespace JPocket
{

    bool logger::initialized = false;
    std::shared_ptr<spdlog::logger> logger::_logger = nullptr;

    void logger::init()
    {
        if (!initialized)
        {
            // Construct color pattern
            std::string pattern;
            pattern = "%^";
            // Show name of the logger
            pattern += "[%n]";
            // Show the log level of the message
            pattern += " [%l]";
            // Show the time of the log message
            pattern += " [%T]";
            // Show the information about the log message, such as time, source file, line number, etc.
            pattern += " [%s, %!, ln %#]";
            // Show log message
            pattern += " %v ";
            // End the color pattern
            pattern += "%$";
            spdlog::set_pattern(pattern);

            _logger = spdlog::stdout_color_mt("JUMI");
            _logger->set_level(spdlog::level::trace);

            initialized = true;
        }
    }

    std::shared_ptr<spdlog::logger>& logger::get_logger()
    {
        return _logger;
    }

}
