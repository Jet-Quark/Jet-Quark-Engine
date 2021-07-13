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

#define JTQ_ENG_ACTIVE_LOG_LEVEL JTQ_LOG_LEVEL_INFO

#include "Log.hpp"

namespace JtQ {

   void Application::run()
   {
      LogManager::init();

      JTQ_ENG_TRACE("Trace logging should be striped");
      JTQ_ENG_DEBUG("Debug logging should be striped");
      JTQ_ENG_INFO("play with positions: {0}{1}{2}{3}; {3}{2}{1}{0}",
         'i', 'n', 'f', 'o'
      );
      JTQ_ENG_WARN("{:>30}", "right aligned");
      JTQ_ENG_ERROR("Hex en uppercase: {0} -> {0:X}", 243653445);
      JTQ_ENG_CRITICAL("Engine critical");
   }
}
