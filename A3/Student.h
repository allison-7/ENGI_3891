/*!
 * @file      Student.h
 * @brief     Declaration of the Student class.
 *
 * @author    Jonathan Anderson <jonathan.anderson@mun.ca>
 * @copyright (c) 2016 Jonathan Anderson. All rights reserved.
 * @license   Apache License, Version 2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#if !defined(STUDENT_H)
#define STUDENT_H

#include <string>


/**
 * A university student.
 */
class Student
{
public:
	enum class Level
	{
		Undergraduate,
		Postgraduate,
	};

	/**
	 * Construct a new Student.
	 *
	 * @param   id          student ID
	 * @param   name        full name
	 * @param   level       the level of student
	 */
	Student(unsigned int id, std::string name, Level level);


	//! The student's ID.
	unsigned int id() const;

	//! The student's name.
	std::string name() const;

	//! The student's level.
	Level level() const;


private:
	int Sid;
	std::string Sname;
	Level Slevel;
};

#endif // !defined(STUDENT_H)

