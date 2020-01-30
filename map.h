#pragma once

#include "object.h"
#include "string.h"
#include "array.h" // This file will have to be provided yourself

/**
 * Represents a map where elements are mapped from key to value. A map can return its value by key
 * at O(1) time because each key is unique and grabbed by index, there are no duplicate keys.
 * 
 * NOTE: This parent Map class will deal strictly with key-value pairs of (Object, Object). 
 * 
 * If you wish to type-check specifically, use the SOMap and SSMap accordingly. If you wish to add 
 * more specific maps that you think will be useful, make a pull request here: 
 * https://github.com/csstransky/cs4500-assignment-1-part-2
 */
class Map : public Object {
    public:
    /**
     * @brief Construct a new Map object
     * 
     */
    Map();

    /**
     * Constructor to optimize performance of map.
     * @param capacity number of buckets available to store different values.
     */
    Map(size_t capacity);

    /**
     * @brief Destroy the Map object
     * 
     */
    ~Map();

    /**
     * @brief Determines if this map equals the given object. For two maps to be equal, they must
     * contain the exact same key-value pairs, BUT do not need to share the same locations inside
     * of the buckets.
     * 
     * @param other object to compare to
     * @return equals or not
     */
    virtual bool equals(Object* other);

    /**
     * @brief Calculates the hash of the map. 
     * 
     * @return hash
     */
    virtual size_t hash();

    /**
     * @brief Prints a representation of map to the console.
     */
    virtual void print();

    /**
     * @brief Determines the number of mappings in this map.
     * @return size of map
     */
    virtual size_t size();

    /**
     * Adds a mapping from key to val to the map. A key must be unique, if there is already a key
     * of the same value in the map, the value will be overwritten by the new value.
     * 
     * NOTE: This function will mutate the Map
     * 
     * @param key Object key
     * @param val Object value
     * @return the old value from the given key, a nullptr is returned if no old value exists
     */
    Object* put(Object* key, Object* val);

    /**
     * Returns the object that the key maps to.
     * 
     * @param key Object unique key
     * @return Object value for the key, a nullptr is returned if no value exists
     */
    Object* get(Object* key);

    /**
     * Removes the key value mapping from the map.
     * 
     * @param key Object key of mapping to remove
     * @return value that was removed, a nullptr is returned if no value exists
     */
    Object* remove(Object* key);

    /**
     * Determines if the map contains the given key.
     * @param key Object key
     * @return if the key is in the map
     */
    bool contains_key(Object* key);

    /**
     * Returns an Array object of keys
     * @return Array of keys
     */
    virtual Array* get_keys();

    /**
     * Returns an Array object of values
     * @return Array of values
     */
    virtual Array* get_values();  
};

/** 
 * Represents a map where the key is a string and the value is a object. Inherits from map.
 * Example: { "string_list: new StrList("hi", "bye"), "string": new String("hello") }
 * 
 * These functions are restricted to only allowing String->Object pairs, meaning that a MapStrObj
 * will only allow String->Object pairs.
 */
class MapStrObj : public Map {
    public:
    /**
     * Adds a mapping from key to val to the map. A key must be unique, if there is already a key
     * of the same value in the map, the value will be overwritten by the new value.
     * 
     * NOTE: This function will mutate the Map
     * 
     * @param key String key
     * @param val Object value
     * @return the old value from the given key, a nullptr is returned if no old value exists
     */
    Object* put(String* key, Object* val);
    
    /**
     * Returns the object that the key maps to.
     * 
     * @param key String unique key
     * @return Object value for the key, a nullptr is returned if no value exists
     */
    Object* get(String* key);

    /**
     * Removes the key value mapping from the map.
     * 
     * @param key String key of mapping to remove
     * @return Object value that was removed, a nullptr is returned if no value exists
     */
    Object* remove(String* key);

    /**
     * Determines if the map contains the given key.
     * @param key String key
     * @return if the key is in the map
     */
    bool contains_key(String* key);
};

/** 
 * Represents a map where the key is a string and the value is a string. Inherits from map.
 * 
 * These functions are restricted to only allowing String->String pairs, meaning that a MapStrStr
 * will only allow String->String pairs.
 */
class MapStrStr : public Map {
    public:
    /**
     * Adds a mapping from key to val to the map. A key must be unique, if there is already a key
     * of the same value in the map, the value will be overwritten by the new value.
     * 
     * NOTE: This function will mutate the Map
     * 
     * @param key String key
     * @param val String value
     * @return the old value from the given key, a nullptr is returned if no old value exists
     */
    String* put(String* key, String* val);
    
   /**
     * Returns the String that the key maps to.
     * 
     * @param key String unique key
     * @return String value for the key, a nullptr is returned if no value exists
     */
    String* get(String* key);

    /**
     * Removes the key value mapping from the map.
     * 
     * @param key String key of mapping to remove
     * @return String value that was removed, a nullptr is returned if no value exists
     */
    String* remove(String* key);

    /**
     * Determines if the map contains the given key.
     * @param key String key
     * @return if the key is in the map
     */
    bool contains_key(String* key);
};