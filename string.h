#pragma once

#include <stdio.h>
#include <string.h>

/**
 * Represents a string, usually characterized as characters in quotes, ex: "hello".
 * Strings inherit properties from objects.
 */
class String : public Object { 
public:
    /**
     * @brief Constructor.
     */
    String();

    /**
     * @brief Constructor
     * @param c list of characters to initialize string with.
     */
    String(char* c);
    
    /**
     * @brief Constructor
     * @param c list of characters to initialize string with.
     * 
     * NOTE: Mainly used for character arrays determined by the progammer, ex: new String("hello")
     */
    String(const char* c);

    /**
     * @brief Deconstructor
     */
    ~String();

    /**
     * @brief Calculates the hash of the string.
     * @return the hash value
     */
    size_t hash();

    /**
     * @brief Determines if this string and the given object are equal.
     * @param other object to compare to
     * @return equal or not
     */
    bool equals(Object* other);

    /**
     * @brief Creates a new string using this current string and another string, concatenates as
     * this_string + other_string = returned_string (order is important)
     * @param s string to concat to this string
     */
    String* concat(String* s);

    /**
     * @brief Calculates the length of this string.
     * @return length of this string
     */
    size_t size();

    /**
     * Returns 0 if strings equal, >0 if this string greater,
     * <0 if this string less
     */
    int compare(String* o);

    /**
     * @brief Prints a representation of this string to the console
     */
    void print();
};
