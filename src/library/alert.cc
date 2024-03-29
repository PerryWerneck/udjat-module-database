/* SPDX-License-Identifier: LGPL-3.0-or-later */

/*
 * Copyright (C) 2024 Perry Werneck <perry.werneck@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

 /**
  * @brief Brief description of this source.
  */

 #include <config.h>
 #include <udjat/tools/sql/script.h>
 #include <udjat/tools/abstract/object.h>
 #include <udjat/alert/abstract.h>
 #include <udjat/alert/activation.h>
 #include <udjat/alert/sql.h>
 #include <udjat/tools/value.h>

 using namespace std;

 namespace Udjat {

	SQL::Alert::Alert(const XML::Node &node, const char *defaults) : Abstract::Alert(node,defaults), script{node} {
	}


 }

