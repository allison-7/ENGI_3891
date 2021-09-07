/*!
 * @file      Carriage.h
 * @brief     Declaration of the Carriage class.
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

#if !defined(CARRIAGE_H)
#define CARRIAGE_H

#include "date.h"
#include "Pumpkin.h"


//! A horse-and-carriage, as in the Cinderella story.
class Carriage
{
public:
	/**
	 * Create a carriage of a given colour (pumpkin-coloured for reasons
	 * of circumstance).
	 */
	Carriage(Pumpkin::Colour);


	//! What colour is this carriage?
	Pumpkin::Colour colour() const;


	/**
	 * Change this carriage into a pumpkin, if the day has changed since
	 * the carriage was created.
	 *
	 * @returns  a Pumpkin if the date has changed, nullptr otherwise
	 */
	Pumpkin* change() const;


private:
	Pumpkin::Colour carriageColour_;
	int day_;
};

#endif  // !defined(CARRIAGE_H)
