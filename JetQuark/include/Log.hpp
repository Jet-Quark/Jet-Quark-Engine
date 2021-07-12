/**
 * Jet Quark, a game engine.
 * Copyright (C) 2021  Mehdi Nasef
 * Copyright (C) 2021  Marta López Rauhut
 * Copyright (C) 2021  Antonio Solana Suárez
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <memory>
#include <utility>
#include <cassert>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#define JTQ_LOG_LEVEL_TRACE      0
#define JTQ_LOG_LEVEL_DEBUG      1
#define JTQ_LOG_LEVEL_INFO       2
#define JTQ_LOG_LEVEL_WARN       3
#define JTQ_LOG_LEVEL_ERROR      4
#define JTQ_LOG_LEVEL_CRITICAL   5
#define JTQ_LOG_LEVEL_OFF        6

#ifndef JTQ_ENG_ACTIVE_LOG_LEVEL
   #define JTQ_ENG_ACTIVE_LOG_LEVEL JTQ_LOG_LEVEL_INFO
#endif

#ifndef JTQ_APP_ACTIVE_LOG_LEVEL
   #define JTQ_APP_ACTIVE_LOG_LEVEL JTQ_LOG_LEVEL_INFO
#endif

namespace JtQ
{

class Logger {
public:

   // LogManager manages Loggers.
   friend class LogManager;

   /**
    * Loggers cannot be copied.
    */
   Logger(const Logger&) = delete;

   /**
    * Log trace information.
    * @param fmt  Format string.
    * @param args Formatting args.
    */
   template<typename FormatString, typename... Args>
   inline void trace(const FormatString& fmt, Args&&... args)
   {
      mSpdLogger_sptr->trace(fmt, std::forward<Args>(args)...);
   }

   /**
    * Log debug information.
    * @param fmt  Format string.
    * @param args Formatting args.
    */
   template<typename FormatString, typename... Args>
   inline void debug(const FormatString& fmt, Args&&... args)
   {
      mSpdLogger_sptr->debug(fmt, std::forward<Args>(args)...);
   }

   /**
    * Log information.
    * @param fmt  Format string.
    * @param args Formatting args.
    */
   template<typename FormatString, typename... Args>
   inline void info(const FormatString& fmt, Args&&... args)
   {
      mSpdLogger_sptr->info(fmt, std::forward<Args>(args)...);
   }

   /**
    * Log warnnings.
    * @param fmt  Format string.
    * @param args Formatting args.
    */
   template<typename FormatString, typename... Args>
   inline void warn(const FormatString& fmt, Args&&... args)
   {
      mSpdLogger_sptr->warn(fmt, std::forward<Args>(args)...);
   }

   /**
    * Log errors.
    * @param fmt  Format string.
    * @param args Formatting args.
    */
   template<typename FormatString, typename... Args>
   inline void error(const FormatString& fmt, Args&&... args)
   {
      mSpdLogger_sptr->error(fmt, std::forward<Args>(args)...);
   }

   /**
    * Log critical information.
    * @param fmt  Format string.
    * @param args Formatting args.
    */
   template<typename FormatString, typename... Args>
   inline void critical(const FormatString& fmt, Args&&... args)
   {
      mSpdLogger_sptr->critical(fmt, std::forward<Args>(args)...);
   }

private:
   // a pointer to a spdlog logger.
   std::shared_ptr<spdlog::logger> mSpdLogger_sptr;

   // Default constructor creates an uninitialized logger.
   Logger() = default;

   // Creates a Logger with the provided name.
   explicit Logger(const char* name);

   // Move constructor for Logger.
   Logger(Logger&& temp) noexcept;

   // Move assignment operator.
   Logger& operator=(Logger&&) noexcept;

   // The destructor is the default since we have a shared ptr to spdlog logger
   ~Logger() = default;
};


class LogManager {
public:

   /**
    * LogManager is a singleton thus, it cannot be copied.
    */
   LogManager(const LogManager&) = delete;

   /**
    * Initializes logging system (LogManager).
    * @param  logFile A log file path to log to a file instead of console.
    * @return         true if initialized correctly, false otherwise.
    */
   static bool init(const char* logFile = nullptr);

   /**
    * Gets the singleton instance of LogManager.
    * @return A reference to singleton Instance of LogManager.
    */
   static inline LogManager& getSingleInstance()
   {
      assert(initialized);
      return singleInstance;
   }

   /**
    * Gets application's Logger.
    * @return A reference to application's Logger.
    */
   static inline Logger& getAppLogger()
   {
      assert(initialized);
      return singleInstance.appLogger;
   }

   /**
    * Gets Jet Quark Engine's Logger.
    * @return A reference to engine's Logger.
    */
   static inline Logger& getJtQLogger()
   {
      assert(initialized);
      return singleInstance.JtQLogger;
   }

private:

   static LogManager singleInstance;
   static bool initialized;

   Logger JtQLogger;
   Logger appLogger;

   // Creates an uninitialized LogManager.
   LogManager() = default;

   // Default since no freeing is required.
   ~LogManager() = default;
};

} // namespace JtQ

///////////////////////////////////////////////////////////////////////////////
// Application logging macros /////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#if JTQ_APP_ACTIVE_LOG_LEVEL == JTQ_LOG_LEVEL_TRACE

   #define JTQ_APP_TRACE(fmt, ...) \
      JtQ::LogManager::getAppLogger().trace(fmt __VA_OPT__(,) __VA_ARGS__)

#else
   #define JTQ_APP_TRACE(fmt, ...)
#endif

#if JTQ_APP_ACTIVE_LOG_LEVEL <= JTQ_LOG_LEVEL_DEBUG

   #define JTQ_APP_DEBUG(fmt, ...) \
      JtQ::LogManager::getAppLogger().debug(fmt __VA_OPT__(,) __VA_ARGS__)

#else
      #define JTQ_APP_DEBUG(fmt, ...)
#endif

#if JTQ_APP_ACTIVE_LOG_LEVEL <= JTQ_LOG_LEVEL_INFO

   #define JTQ_APP_INFO(fmt, ...) \
      JtQ::LogManager::getAppLogger().info(fmt __VA_OPT__(,) __VA_ARGS__)

#else
   #define JTQ_APP_INFO(fmt, ...)
#endif

#if JTQ_APP_ACTIVE_LOG_LEVEL <= JTQ_LOG_LEVEL_WARN

   #define JTQ_APP_WARN(fmt, ...) \
      JtQ::LogManager::getAppLogger().warn(fmt __VA_OPT__(,) __VA_ARGS__)

#else
   #define JTQ_APP_WARN(fmt, ...)
#endif

#if JTQ_APP_ACTIVE_LOG_LEVEL <= JTQ_LOG_LEVEL_ERROR

   #define JTQ_APP_ERROR(fmt, ...) \
      JtQ::LogManager::getAppLogger().error(fmt __VA_OPT__(,) __VA_ARGS__)

#else
   #define JTQ_APP_ERROR(fmt, ...)
#endif

#if JTQ_APP_ACTIVE_LOG_LEVEL <= JTQ_LOG_LEVEL_CRITICAL

   #define JTQ_APP_CRITICAL(fmt, ...) \
      JtQ::LogManager::getAppLogger().critical(fmt __VA_OPT__(,) __VA_ARGS__)

#else
   #define JTQ_APP_CRITICAL(fmt, ...)
#endif

///////////////////////////////////////////////////////////////////////////////
// Engine logging macros //////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#if JTQ_ENG_ACTIVE_LOG_LEVEL == JTQ_LOG_LEVEL_TRACE

   #define JTQ_ENG_TRACE(fmt, ...) \
      JtQ::LogManager::getJtQLogger().trace(fmt __VA_OPT__(,) __VA_ARGS__)

#else
   #define JTQ_ENG_TRACE(fmt, ...)
#endif

#if JTQ_ENG_ACTIVE_LOG_LEVEL <= JTQ_LOG_LEVEL_DEBUG

   #define JTQ_ENG_DEBUG(fmt, ...) \
      JtQ::LogManager::getJtQLogger().debug(fmt __VA_OPT__(,) __VA_ARGS__)

#else
      #define JTQ_ENG_DEBUG(fmt, ...)
#endif

#if JTQ_ENG_ACTIVE_LOG_LEVEL <= JTQ_LOG_LEVEL_INFO

   #define JTQ_ENG_INFO(fmt, ...) \
      JtQ::LogManager::getJtQLogger().info(fmt __VA_OPT__(,) __VA_ARGS__)

#else
   #define JTQ_ENG_INFO(fmt, ...)
#endif

#if JTQ_ENG_ACTIVE_LOG_LEVEL <= JTQ_LOG_LEVEL_WARN

   #define JTQ_ENG_WARN(fmt, ...) \
      JtQ::LogManager::getJtQLogger().warn(fmt __VA_OPT__(,) __VA_ARGS__)

#else
   #define JTQ_ENG_WARN(fmt, ...)
#endif

#if JTQ_ENG_ACTIVE_LOG_LEVEL <= JTQ_LOG_LEVEL_ERROR

   #define JTQ_ENG_ERROR(fmt, ...) \
      JtQ::LogManager::getJtQLogger().error(fmt __VA_OPT__(,) __VA_ARGS__)

#else
   #define JTQ_ENG_ERROR(fmt, ...)
#endif

#if JTQ_ENG_ACTIVE_LOG_LEVEL <= JTQ_LOG_LEVEL_CRITICAL

   #define JTQ_ENG_CRITICAL(fmt, ...) \
      JtQ::LogManager::getJtQLogger().critical(fmt __VA_OPT__(,) __VA_ARGS__)

#else
   #define JTQ_ENG_CRITICAL(fmt, ...)
#endif
