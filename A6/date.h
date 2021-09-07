/*!
 * @file      date.h
 * @brief     Declaration of the currentDate() function.
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

#if !defined(DATE_H)
#define DATE_H


/**
 * What is the current date, relative to some "zero day".
 *
 * This function (which should be implemented by test code, *not* your code)
 * returns a number to represent the current date, relative to some reference.
 * That reference day could be relative to any number of calendars, but its key
 * property is that every day it increases by one.
 */
int currentDate();


#endif  // !defined(DATE_H)
