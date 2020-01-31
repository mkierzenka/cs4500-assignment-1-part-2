#pragma once

#include "object.h"
#include "string.h"

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
     * @brief Calculates the hash of the map. The hash will only be dependent on the key value pairs
     * of the map, and NOT the location of them in the buckets.
     * Example:
     * Map* map1 = new Map(10000);
     * Map* map2 = new Map();
     * Object* key = new Object();
     * Object* value = new Object();
     * map1->put(key, value);
     * map2->put(key, value);
     * // This should return true even though the key value pairs are in different bucket locations
     * map1->hash() == map2->hash(); 
     * 
     * @return hash representation of each key value pair in the map
     */
    virtual size_t hash();

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
     * Returns a new Object array of keys. This array will need to be freed in memory after use.
     * NOTE: If a map has no keys, it will return an empty Object**
     * @return new Object array of keys
     */
    virtual Object** get_keys();

    /**
     * Returns a new Object array of values. This array will need to be freed in memory after use.
     * NOTE: If a map has no values, it will return an empty Object**
     * @return new Object array of values
     */
    virtual Object** get_values();  
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