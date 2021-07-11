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

namespace JtQ
{

class Logger {
public:

   friend class LogManager;

   Logger(const Logger&) = delete;

   template<typename FormatString, typename... Args>
   inline void trace(const FormatString& fmt, Args&&... args)
   {
      mSpdLogger_sptr->trace(fmt, std::forward<Args>(args)...);
   }

   template<typename FormatString, typename... Args>
   inline void debug(const FormatString& fmt, Args&&... args)
   {
      mSpdLogger_sptr->debug(fmt, std::forward<Args>(args)...);
   }

   template<typename FormatString, typename... Args>
   inline void info(const FormatString& fmt, Args&&... args)
   {
      mSpdLogger_sptr->info(fmt, std::forward<Args>(args)...);
   }

   template<typename FormatString, typename... Args>
   inline void warn(const FormatString& fmt, Args&&... args)
   {
      mSpdLogger_sptr->warn(fmt, std::forward<Args>(args)...);
   }

   template<typename FormatString, typename... Args>
   inline void error(const FormatString& fmt, Args&&... args)
   {
      mSpdLogger_sptr->error(fmt, std::forward<Args>(args)...);
   }

   template<typename FormatString, typename... Args>
   inline void critical(const FormatString& fmt, Args&&... args)
   {
      mSpdLogger_sptr->critical(fmt, std::forward<Args>(args)...);
   }

private:

   std::shared_ptr<spdlog::logger> mSpdLogger_sptr;

   Logger() = default;
   explicit Logger(const char* name);
   Logger(Logger&& temp) noexcept;

   Logger& operator=(Logger&&) noexcept;

   ~Logger() = default;
};


class LogManager {
public:

   static bool init(const char* logFile = nullptr);

   static inline LogManager& getSingleInstance()
   {
      assert(initialized);
      return singleInstance;
   }

   static inline Logger& getAppLogger()
   {
      assert(initialized);
      return singleInstance.appLogger;
   }

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

   LogManager() = default;
   ~LogManager() = default;

   LogManager(const LogManager&) = delete;
};

} // namespace JtQ
