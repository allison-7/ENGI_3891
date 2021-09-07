/*!
 * @file      PumpkinPatch.h
 * @brief     Declaration of the PumpkinPatch class.
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

#if !defined(PUMPKIN_PATCH_H)
#define PUMPKIN_PATCH_H

#include "Carriage.h"
#include "Pumpkin.h"

#include <vector>


//! A pumpkin patch: a container for pumpkins.
class PumpkinPatch
{
public:
	//! Create a pumpkin patch containing `n` pumpkins of colour `c`.
	static PumpkinPatch Create(size_t n, Pumpkin::Colour c);

	/**
	 * Construct a pumpkin patch from an existing vector of pumpkins.
	 *
	 * This object should take ownership of these (heap-allocated)
	 * pumpkin objects.
	 */
	PumpkinPatch(std::vector<Pumpkin*>);

	//! Copy constructor.
	PumpkinPatch(const PumpkinPatch&);

	//! Destructor.
	~PumpkinPatch();

	//! Assignment operator.
	PumpkinPatch& operator = (const PumpkinPatch&);

	//! How many pumpkins are there in this pumpkin patch?
	size_t size() const;

	/**
	 * Index/subscript operator.
	 *
	 * This operator gives access (by reference) to a Pumpkin object
	 * that is part of this pumpkin patch.
	 *
	 * @pre   i is less than the total number of pumpkins in the patch
	 */
	Pumpkin& operator[] (size_t i);

	//! Beginning of the pumpkin data: supports range-based for loop.
	Pumpkin** begin();

	//! End+1 of the pumpkin data: supports range-based for loop.
	Pumpkin** end();


	/**
	 * Carve all of the pumpkins in the patch.
	 *
	 * Attempt to carve all of the pumpkins in the patch, dealing with
	 * any exceptions they may throw: this method should not allow any
	 * PumpkinExceptions to propagate.
	 *
	 * @returns  the number of pumpkins that were successfully carved
	 */
	size_t carve();

	/**
	 * Light all of the pumpkins in the patch.
	 *
	 * Attempt to light all of the pumpkins in the patch, dealing with
	 * any exceptions they may throw: this method should not allow any
	 * PumpkinExceptions to propagate.
	 *
	 * @returns  the number of pumpkins that were successfully lit
	 */
	size_t light();

	/**
	 * Convert all of the pumpkins in this patch into carriages.
	 *
	 * For each pumpkin in the patch, create a carriage of the same colour
	 * and deallocate the original pumpkin.
	 *
	 * @returns   the carriages created from the pumpkins
	 */
	std::vector<Carriage> makeCarriages();

private:
	std::vector<Pumpkin*> myPatch_;
	// add any fields and methods that you need
};

#endif  // !defined(PUMPKIN_PATCH_H)
