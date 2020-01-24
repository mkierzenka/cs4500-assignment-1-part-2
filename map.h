#pragma once

#include "object.h"
#include "string.h"

/**
 * Represents a map where elements are mapped from key to value. Map inherits properties from Object 
 */
class Map : public Object {
    public:
    /**
     * @brief Determines if this map equals the given object.
     * @param other object to compare to
     * @return equals or not
     */
    virtual bool equals(Object* other);

    /**
     * @brief Calculates the hash of the map.
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
};

/** 
 * Represents a map where the key is a string and the value is a object. Inherits from map.
 */
class MapStrObj : public Map {
    public:

    /**
     * Constructor
     */
    MapStrObj();

    /**
     * Deconstructor
     */
    ~MapStrObj();

    /**
     * Adds a mapping from key to val to the map.
     * @param key key
     * @param val value
     */
    void put(String* key, Object* val);
    
    /**
     * Returns the object that the key maps to.
     * @param key key
     * @return value key maps to
     */
    Object* get(String* key);

    /**
     * Removes the mapping from the map.
     * @param key key of mapping to remove
     * @return value that was removed
     */
    Object* remove(String* key);

    /**
     * Replace the value at the key with the given value.
     * @param key key of value to replace
     * @param val new value
     */
    void replace(String* key, Object* val);

    /**
     * Determines if the map contains the given key.
     * @param key key
     * @return if the key is in the map
     */
    bool contains_key(String* key);

    /**
     * Returns a list of keys in the map.
     * @return list of keys
     */
    String* get_keys();
};

/** 
 * Represents a map where the key is a string and the value is a string. Inherits from map.
 */
class MapStrStr : public Map {
    public:
    
    /**
     * Constructor
     */
    MapStrStr();

    /**
     * Deconstructor
     */
    ~MapStrStr();

    /**
     * Adds a mapping from key to val to the map.
     * @param key key
     * @param val value
     */
    void put(String* key, String* val);

     /**
     * Returns the object that the key maps to.
     * @param key key
     * @return value key maps to
     */   
    String* get(String* key);

    /**
     * Removes the mapping from the map.
     * @param key key of mapping to remove
     * @return value that was removed
     */
    String* remove(String* key);

    /**
     * Replace the value at the key with the given value.
     * @param key key of value to replace
     * @param val new value
     */
    void replace(String* key, String* val);

    /**
     * Determines if the map contains the given key.
     * @param key key
     * @return if the key is in the map
     */
    bool contains_key(String* key);

    /**
     * Returns a list of keys in the map.
     * @return list of keys
     */
    String* get_keys();
};