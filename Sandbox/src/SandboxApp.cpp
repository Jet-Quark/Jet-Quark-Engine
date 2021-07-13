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

#define JTQ_APP_ACTIVE_LOG_LEVEL JTQ_LOG_LEVEL_TRACE

#include "JetQuark.hpp"

class LoggableType {
public:

   LoggableType(int id, std::string name):
      id(id), name(name)
   {}

   ~LoggableType() = default;

   template<typename OStream>
   friend OStream& operator<<(OStream& os, const LoggableType& lt)
   {
      return os << "[LoggableType: id=" << lt.id << " name=" << lt.name << "]";
   }

private:
   int id;
   std::string name;
};

class SandboxApp : public JtQ::Application {
public:

   SandboxApp() = default;

   virtual ~SandboxApp() override
   {}

   virtual void run() override
   {
      Application::run();

      JTQ_APP_TRACE("Application logs: {}", "trace");

      LoggableType loggable(4, "Loggable");
      JTQ_APP_DEBUG("Logging a user defined type: {}", loggable);

      JTQ_APP_INFO(
         "Support for int: {0:d}; hex: {0:x}; oct: {0:o}; bin: {0:b}",
         42
      );
      JTQ_APP_WARN("Support for floats: {:03.2f}", 1.23456);
      JTQ_APP_ERROR("Positional args are {1} {0}..", "too", "supported");
      JTQ_APP_CRITICAL("App critical");
   }
};

JtQ::Application* JtQ::createApplication()
{
   return new SandboxApp();
}
