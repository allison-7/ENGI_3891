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
#include <vector>


//
// This is a "forward declaration" of the Course class. It lets us declare
// values of type reference-to-Course without having to #include "Course.h"
// (since that header file includes this one; we don't want a cycle).
//
class Course;


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

	//! Representation of a Memorial student ID (e.g., 201600001).
	struct ID
	{
		//! The year the student matriculated (e.g., 2016).
		const unsigned int year;

		//! A unique serial number within the year (e.g., 00001).
		const unsigned int serial;
	};

	/**
	 * Construct a new Student.
	 *
	 * @param   id          student ID
	 * @param   name        full name
	 * @param   level       the level of student
	 */
	Student(ID id, std::string name, Level level);


	/**
	 * Does this object represent the same student as another object?
	 *
	 * @returns true if both students have the same student ID
	 */
	bool operator == (const Student&) const;

	//! This object is *not* the same student as another object.
	bool operator != (const Student&) const;


	//! The student's ID.
	ID id() const;

	//! The student's name.
	std::string name() const;

	//! The student's level.
	Level level() const;

private:
	ID Sid;
	std::string Sname;
	Level Slevel;
	// replace this comment with whatever fields you need
	// to fulfill the contracts of Student
	//
};

#endif // !defined(STUDENT_H)

