#pragma once

#include <stdio.h>
#include <string.h>

/**
 * Represents a string. Strings inherit properties from objects.
 */
class String : public Object { 
public:
    /**
     * @brief Constructor.
     */
    String();

    /**
     * @brief Constructor
     * @param c character to initialize string with.
     */
    String(char c);

    /**
     * @brief Constructor
     * @param c list of characters to initialize string with.
     */
    String(char* c);
    
    /**
     * @brief Constructor
     * @param c list of characters to initialize string with.
     */
    String(const char* c);

    /**
     * @brief Deconstructor
     */
    ~String();

    /**
     * @brief Calculates the hash of the string.
     * @return the hash
     */
    size_t hash();

    /**
     * @brief Determines if this string and the given object are equal.
     * @param other object to compare to
     * @return equal or not
     */
    bool equals(Object* other);

    /**
     * @brief Creates a new string where the first part is this string and the second is the given 
     * string
     * @param s string to concat to this string
     * @return new string that made of both strings
     */
    String* concat(String* s);
    
    /**
     * @brief Adds the char to the end of this string
     * @param the character to append
     */
    void concat_char(char c);

    /**
     * @brief Calculates the length of this string.
     * @return length of this string
     */
    size_t length();

    /**
     * @brief Prints a representation of this string to the console
     */
    void print();
};
