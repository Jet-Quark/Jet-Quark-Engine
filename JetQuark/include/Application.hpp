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

namespace JtQ {

   class Application {
   public:

      /**
       * Default constructor for Application.
       */
      Application() = default;

      /**
       * Default destructor for Application.
       * it must be overriden by client application.
       */
      virtual ~Application() = default;

      /**
       * Runs applicaton's code.
       * TODO: (It's temporary)
       */
      virtual void run();
   };

   /**
    * Creates an Application and returns a pointer to it.
    * It must be implemented by the client application.
    * @return A pointer to the created Application.
    */
   Application* createApplication();
}
