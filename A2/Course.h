/*      Course.h
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

// The following lines are "header guards": they prevent us from redefining the
// Course class if we include this header file more than once. They effectively
// tell the pre-processor, "only pay attention to the contents of this file if
// you haven't seen them before".
#if !defined(COURSE_H)
#define COURSE_H

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


	/**
	 * Register a new student in the course.
	 *
	 * This method, in the normal case, will only register a student if
	 * there is room, i.e., capacity has not been reached. However, it is
	 * possible to explicitly override the capacity limit if needs must.
	 *
	 * **Note:** for this assignment, we do not have or use any details
	 *           about the students, we only track the total number of them
	 *
	 * @param   overrideLimits    force registration of the student, even
	 *                            if capacity has already been reached
	 *
	 * @returns whether or not the student was registered
	 */
	bool registerStudent(bool overrideLimits = false);


	//! How many students can enrol in this course?
	unsigned int capacity() const;

	//! How many students have enrolled in this course?
	unsigned int enrolment() const;

	//! How many seats remain in this course?
	int seatsRemaining() const;

private:
	int v_course;
	Level v_level;
	int v_capacity;
	int enrolled;
	int v_seatsRemaining;
	// replace this comment with whatever fields you need
	// to fulfill the contracts of Course
	//
};

#endif // the end of the COURSE_H header guard

