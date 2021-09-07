/*!
 * @file      Pumpkin.h
 * @brief     Declaration of the Pumpkin class.
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

#if !defined(PUMPKIN_H)
#define PUMPKIN_H

#include <string>
#include <vector>


//! There is a problem with a pumpkin.
class PumpkinException
{
public:
	//! Create a PumpkinException with an error message.
	PumpkinException(std::string message);

	//! What message was this exception created with?
	std::string message() const;

private:
	std::string message_;
};


//! A representation of a pumpkin.
class Pumpkin
{
friend class PumpkinPatch; //allows PumpkinPatch to access private members of Pumpkin 
public:
	//! Colours that a pumpkin can have.
	enum class Colour
	{
		Orange,
		White,
		Blue,
		Teal,
	};

	/**
	 * Create a pumpkin of a given colour.
	 *
	 * @returns a heap-allocated Pumpkin object
	 */
	static Pumpkin* Create(Colour);

	/**
	 * Create a set of pumpkins that all have the same colour and that
	 * have all been carved (or not) in the same way.
	 *
	 * @param   n        the number of pumpkins to create
	 * @param   c        the colour that all of the pumpkins should have
	 * @param   carved   whether or not the pumpkins have been carved
	 */
	static std::vector<Pumpkin>
		CreatePumpkins(unsigned int n, Colour c, bool carved = false);


	//! What colour is this pumpkin?
	Colour colour() const;


	//! Has this pumpkin been carved?
	bool carved() const;

	/**
	 * Carve this pumpkin into a jack-o-lantern.
	 *
	 * @throw PumpkinException if the pumpkin has already been carved
	 */
	void carve();

	//! Has this pumpkin been carved and lit?
	bool alight() const;

	/**
	 * Light this pumpkin, which should already be carved as a
	 * jack-o-lantern.
	 *
	 * @throw PumpkinException   if the pumpkin has not been carved yet
	 *                           or *has* already been lit
	 */
	void light();

private:
	Colour pumpkinColour_;
	bool carved_;
	bool alight_;
};

#endif  // !defined(PUMPKIN_H)
