/*!
 * @file      Course.h
 * @brief     Declaration of the Course class.
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

#if !defined(COURSE_H)
#define COURSE_H

#include "Student.h"
#include <vector>


/**
 * A university course that can be taken by students.
 */
class Course
{
public:
	enum class Level
	{
		Undergraduate,
		Postgraduate,
	};

	/**
	 * Construct a new Course.
	 *
	 * @param   number      the course number, e.g., 3891
	 * @param   level       the level of student the course is primarily
	 *                      targeted at
	 * @param   capacity    how many students can enrol in the course
	 */
	Course(unsigned int number, Level level, unsigned int capacity = 100);

	//! What course number is this?
	unsigned int number() const;

	//! What level is this course targeted at?
	Level level() const;

	//! How many students can enrol in this course?
	unsigned int capacity() const;

	//! How many students have enrolled in this course?
	unsigned int enrolment() const;


	/**
	 * Register a new student in the course.
	 *
	 * This method, in the normal case, will only register a student if
	 * there is room, i.e., capacity has not been reached, and also
	 * <b>if the student is not already registered</b>. It is possible to
	 * override the capacity limit, but not the uniqueness requirement.
	 *
	 * @param   s                 the student to register
	 * @param   overrideLimits    force registration of the student, even
	 *                            if capacity has already been reached
	 *
	 * @returns whether or not the student was registered
	 */
	bool registerStudent(Student s, bool overrideLimits = false);

	/**
	 * Register a new student in the course.
	 *
	 * This operator registers a student if there is room and if they have
	 * not already registered. Otherwise, it throws an exception of type
	 * `std::string` containing an error message.
	 *
	 * @param   s                 the student to register
	 */
	Course& operator << (Student s);


	/**
	 * How many seats remain in this course?
	 *
	 * @returns    the number of seats remaining in the course
	 *             (negative if enrolment exceeds capacity)
	 */
	int seatsRemaining() const;

	/**
	 * Create a class list containing the names of all registered students.
	 */
	std::vector<std::string> classList() const;

private:
	int v_course;
	Level v_level;
	int v_capacity;
	int v_seatsRemaining;
	int  enrolled; 
	std::vector<std::string> ClassList;
	// replace this comment with whatever fields you need
	// to fulfill the contracts of Course
	//
};

#endif // !defined(COURSE_H)
