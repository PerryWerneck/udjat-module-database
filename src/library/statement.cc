/* SPDX-License-Identifier: LGPL-3.0-or-later */

/*
 * Copyright (C) 2023 Perry Werneck <perry.werneck@gmail.com>
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
  * @brief Implements SQL statement.
  */

 #include <config.h>
 #include <udjat/defs.h>
 #include <udjat/version.h>
 #include <udjat/tools/xml.h>
 #include <udjat/tools/object.h>
 #include <cppdb/frontend.h>
 #include <vector>
 #include <stdexcept>
 #include <udjat/tools/string.h>
 #include <udjat/tools/logger.h>

 #include <udjat/sql/statement.h>
 #include <private/session.h>

 using namespace std;

 namespace Udjat {

 	static const char * find_next_ctrl_char(const char *ptr) {

		while(*ptr && ((unsigned char) *ptr) >= ' ') {
			ptr++;
		}

		return ptr;

 	}

	SQL::Statement::Statement(const char *sql, bool cached) {

		String sqltext;

		// Remove line breaks.
		while(sql && *sql) {

			sqltext += " ";

			const char *next = find_next_ctrl_char(sql);
			if(next && *next) {
				sqltext += String{sql,(size_t) (next-sql)}.strip();
				sql = next+1;
			} else {
				sqltext += String{sql}.strip();
				sql = next;
			}

			sqltext.strip();

		}

		debug("Processing SQL '",sqltext.c_str(),"'");



	}

	SQL::Statement::Statement(const XML::Node &node) : Statement{String{node.child_value()}.expand(node).strip().c_str(),node.attribute("sql-keep-prepared").as_bool(true)} {
	}

	SQL::Statement::~Statement() {
	}

	/// @brief Execute SQL query
	/// @param request The object with the parameter values.
	void SQL::Statement::exec(const Udjat::Object &request) {
	}

 }