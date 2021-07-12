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

#define JTQ_APP_ACTIVE_LOG_LEVEL JTQ_LOG_LEVEL_INFO

#include "JetQuark.hpp"

class SandboxApp : public JtQ::Application {
public:

   SandboxApp() = default;

   virtual ~SandboxApp() override
   {}

   virtual void run() override
   {
      Application::run();

      JTQ_APP_TRACE("Application trace");
      JTQ_APP_DEBUG("Application debug");
      JTQ_APP_INFO("Application info");
      JTQ_APP_WARN("Application warn");
      JTQ_APP_ERROR("Application error");
      JTQ_APP_CRITICAL("Application critical");
   }
};

JtQ::Application* JtQ::createApplication()
{
   return new SandboxApp();
}
