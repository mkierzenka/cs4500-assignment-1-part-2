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
     * NOTE: the string's value will mutate after using this function
     * @param s string to concat to this string
     */
    void concat(String* s);
    
    /**
     * @brief Adds the char to the end of this string
     * @param c the character to append
     * NOTE: the string's value will mutate after using this function
     */
    void concat_char(char c);

    /**
     * @brief Returns the character at the index position of the string
     * NOTE: If the index is larger than the string's actual index, the last value will be returned
     * @param index the substring to be replaced in the string
     */
    char get_char(size_t index);

      /**
     * @brief Sets the character value of the string at an index
     * NOTE: the string's value will mutate after using this function
     * NOTE: If the index is larger than the string's actual index, the last value will be mutated
     * @param index the index for the character to be replaced in the string
     * @param c the new value of the character in the string
     */  
    void set_char(size_t index, char c);

    /**
     * @brief Replaces the FIRST INSTANCE of the old_string with the new_string
     * NOTE: If no old_string is found in the string, then nothing will be replaced
     * NOTE: the string's value will mutate after using this function
     * @param old_string the substring to be replaced in the string
     * @param new_string the substring that will replace the old_string
     */
    void replace(String* old_string, String* new_string);

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
