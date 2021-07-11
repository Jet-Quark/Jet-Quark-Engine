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

#include <iostream>


#include "Application.hpp"
#include "Log.hpp"

namespace JtQ {

   Application::Application()
   {}

   Application::~Application()
   {}

   void Application::run()
   {
      LogManager::init();
      Logger& JtQLogger = LogManager::getJtQLogger();
      Logger& appLogger = LogManager::getAppLogger();

      JtQLogger.info("Hello, JtQLogger!");
      appLogger.warn("Hello, AppLogger!");
   }
}
