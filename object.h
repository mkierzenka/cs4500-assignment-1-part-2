#pragma once
// lang::CwC

#include <stdlib.h>

/**
 * Represents an object. 
 */ 
class Object {
public:
	/**
	 * @brief Constructor
	 */
	Object();

	/**
	 * @brief Deconstructor
	 */
	virtual ~Object();

	/**
	 * @brief Calculates the hash of the object.
	 * @return hash
	 */
	virtual size_t hash();

	/**
	 * @brief Determines if the objects are equal.
	 * @param other object to compare to
	 * @return equal or not
	 */
	virtual bool equals(Object* other);

	/**
	 * @brief Prints a representation of the object to console.
	 */
	virtual void print();
};
