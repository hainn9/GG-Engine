#ifndef LOG_H
#define LOG_H

#include <memory>

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace GGEngine {

    class GGE_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

}

// Engine log
#define GGE_CORE_TRACE(...)  ::GGEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GGE_CORE_INFO(...)   ::GGEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GGE_CORE_WARN(...)   ::GGEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GGE_CORE_ERROR(...)  ::GGEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GGE_CORE_FATAL(...)  ::GGEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// App log
#define GGE_TRACE(...)  ::GGEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GGE_INFO(...)   ::GGEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define GGE_WARN(...)   ::GGEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GGE_ERROR(...)  ::GGEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define GGE_FATAL(...)  ::GGEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)

#endif // LOG_H
