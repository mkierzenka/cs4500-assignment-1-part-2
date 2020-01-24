# cs4500-assignment-1-part-2
By Kaylin Devchand & Cristian Stransky
```
Outline:
    Object:
        size_t hash()
        bool equals(Object* other)
        void print()

    String : Object:
        String* concat(String s)
        void concat_char(char c)
        size_t length()

    Map : Object:
        size_t size()

        MapStrObj : Map:
            void put(String* key, Object* val)
            Object* get(String* key)
            Object* remove(String* key)
            bool contains_key(String* key)
            String** get_keys()
            String** get_values()

        MapStrStr : Map:
            void put(String* key, String* val)
            String* get(String* key)
            String* remove(String* key)
            bool contains_key(String* key)
            String** get_keys()
            String** get_values()  
```
## Object

Each and every object will have a hash code of some kind to allow for all objects to be manipulated  
in a similiar fashion (sorting different objects for example). This hash value will also allow us to  
use the equals function to see if two objects are equivalent.  

The print function is mainly used for debugging, as it is quite useful to have a console line  
representation of an object.

## String

The string class has been made to allow for easier use of character arrays in CwC.   

We make use of two concatenate functions (concat, concat_char) that will mutate the string itself.  
We decided mutating the string in the function let's the user worry less about memory  
allocation/deallocation than if the concatenate functions were returning a new string without   
mutating the string.   

The functions get_char, set_char, and length are to be used for for loop manipulation. Being able to  
manipulate separate characters may be helpful.

The function replace is mainly used for a more robust method of being able to manipulate strings,  
instead of only using characters. Using the function replace multiple times can remove all spaces in  
a string for example:  
```
while(!has_no_spaces(string)) {  
    string->replace(" ", "")  
}  
```
Or it can be used if the user wishes to check for strings with relation to each other,   
like: ```string->replace("\r\n", "  ").  ```

## Map

A map needs its intended function of being able to store and retrieve data based off a unique key,  
which is why we have the basic functions of put and get. This operation needs to be completed at a  
time of O(1) by using the power of indexing on an array of "buckets".  

It also may be useful to completely remove a pairing (and not just the value) from a map, so the  
function remove will free up both the key and value, as not to interfere with the functions like  
contains_key or get_keys.  

Sometimes, it may be useful to iterate through a map like an unsorted array, which is why the  
function get_keys can be used to iterate through the keys, which allows for the values to be  
iterated through as well. We have also added the function get_values if the user wishes to abstract  
this process.  

Since our map uses indexing, it's important that we have a boolean function contains_key to make  
sure we know the key exists first before trying to get a value from it. This is a valuable way to   
avoid index out of bounds errors.
