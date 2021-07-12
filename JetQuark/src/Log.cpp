
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

#include "Log.hpp"

namespace JtQ
{

Logger::Logger(const char* name):
   mSpdLogger_sptr(spdlog::stdout_color_mt(name))
{}

Logger::Logger(Logger&& temp) noexcept:
   mSpdLogger_sptr(temp.mSpdLogger_sptr)
{}

Logger& Logger::operator=(Logger&& temp) noexcept
{
   this->mSpdLogger_sptr = temp.mSpdLogger_sptr;
   return *this;
}

LogManager LogManager::singleInstance;
bool LogManager::initialized = false;

bool LogManager::init(const char* logFile)
{
   // TODO: implement file logging
   assert(logFile == nullptr);

   spdlog::set_level(spdlog::level::trace);
   spdlog::set_pattern("%^%H:%M:%S:%e [%n::%L]%$ %v");

   singleInstance.JtQLogger = std::move(Logger("JtQ"));
   singleInstance.appLogger = std::move(Logger("App"));

   initialized = true;

   return true;
}

} // namespace JtQ
