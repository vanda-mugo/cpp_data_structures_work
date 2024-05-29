/*
Hash table store values in key value pairs where the key is a unique integer that is used for indexing
the values where value is the data that is associated with the key

Hashing functions 
In a hash table, a new index is processed using the keys. and the elements corresponding to that key is
stored in the index. this process is called hashing 

Hashing is a technique of mapping a large set of arbitrary data to tabular indexes using a hash function.
its a method for representing dictionaries for large data sets.


insertion of key value pair,  deletion of a key value pair or searching are all functions that run in 
constant time on average 

time = 0(1) => search, delete and insert

 keys in hash tables dont have to be integers and they can be strings unlike in arrays where the indices are
 integers. what we mean by this is that in arrays when you want to access an element at a specified index
 you use 
 array_name[index]

 note by that hash tables are build onto arrays that why we have the constant time lookup 

 we use a hash function to transform a key into an index which will now be used to access the values. then once 
 having found the value that it maps to you can then look up that value from the array using the index



collision in a hash table 

to explain collision think of a situation in which two keys map to the same index of the array. What this means is that 
both of the values linked to the different keys map to the same index on the array

now we shall realize that a hash table isnt just an array but rather an array in which each index maps to a linked list of 
potential values. this is to take care of instances where we have two keys mapping to the same value 

now how would we know which value is related to which node of the linked list where collision occured in the array indices 

so what happens in the linked list is that we need every node in the linked list to point back to the original key in this case
1 in the linked list would point back to "abr" while 2 would point back to "bar"


given the above

keys indices    values

"abr"  2          1
"bar"  2          2

so in this array we have collision 


[_0_  _1_  _2_]
            1 - > "abr"
            |
            2 - > "bar"



in worst case you can end up in a scenario where every element ends up in the same linked list. this therefore will not be constant 
time operations as it was in the average case scenarios in the linked list 

in worst case each of the three functions 

insertion, deletion and searching would take 0(n)

when the underlying arrays does not have enough space that is when the underlying array has too many key value pairs to fit into the array 
thats when the concept of resizing comes to play. 


in summary a hash table under the hood is a dynamic array of linked lists to efficiently store key/value pairs. 
a hash function first maps the key which is typically a string(or any data that can be hashed depending on the implementation of the 
hash table ) to an integer value and by extention to an index in the underying dynamic array.
the value associated with the key is added to the linked list sorted at the index in the dynamic array and a reference to the key is also
stored with the value 


{
    0: (value1, key1) -> null 
    1: (value2, key2) -> (value3, key3) -> (value4, key4)
    2: (value5, key5) -> null
    3: (value6, key6) -> null
    4: null
    5: (value7, key7) -> (value8, key8)
    6: (value9, key9) -> null

}

in the hash table above, the keys key2, key3 and key4 collided by all being hashed to 1, and the keys key7 and key8 collided by all being 
hashed to 5

the following are hash tables standard operations and their corresponding time complexities.
inserting a key/value pair 0(1) average and 0(n) is the worst case 
removing a key/value 0(1) on average and 0(n) in the worst case scenario 
looking up a key 0(1) on average and 0(n) in worst case scenario 


the worst case linear time operation occurs when a hash table experiences a lot of collisions, leading to long linked lists internally 
which take 0(n) time on average 

Structure of an hash table 

An array (often called a hash array or a bucket array ): each element of this array is a bucket that can store multiple key value pairs .
each element of this array is the key word here 

hash function : a function that maps keys to indices in the array 

Buckets : each bucket can be implemented as a linked list, a dynamic array or another data structure 
*/

// example of hash functions 
size_t hashFunction(const std::string &key)
{
    size_t hash = 0;
    for(char ch : key)
    {
        hash = hash * 31 + ch; // simple polynomial accumulation
    }
    return hash;
}

/*

3. Handling Collisions with Chaining

Collisions occur when multiple keys hash to the same index. Chaining is a common method to handle collisions, 
where each bucket in the hash array contains a linked list of key-value pairs.
*/


// implementation of hash functions 
#include <iostream>
#include <vector>
#include <list>
#include <string>

// A structure to store a key-value pair
struct KeyValuePair 
{
    // member variables of the struct 
    std::string key;
    std::string value;
};

// Hash table class
class HashTable 
/*

*/
{
private:
/*
std::vector: This is a dynamic array that can change size. 
It provides random access to elements and efficient insertions and deletions at the end.*/

/*
std::list: This is a doubly linked list that allows efficient insertions and deletions at 
any position within the list. It doesn't support random access as efficiently as std::vector 
but is optimal for operations that frequently insert or remove elements.*/

/*
KeyValuePair: This is a user-defined structure that holds a key and a value. For a hash table,
 this typically means a key-value pair for storing data entries.*/


    std::vector<std::list<KeyValuePair>> table;
    size_t tableSize;

    // Hash function to compute the index for a key
    size_t hashFunction(const std::string& key) const 
    {
        size_t hash = 0;
        for (char ch : key) {
            hash = hash * 31 + ch;
        }
        return hash % tableSize;
    }

public:
// overloaded constructor 
    HashTable(size_t size) : tableSize(size) 
    {
        /*
        Resizes the container to contain count elements, does nothing if count == size().
        If the current size is greater than count, the container is reduced to its first count elements.
        If the current size is less than count, 
        */
        table.resize(size);
    }

    // Insert a key-value pair into the hash table
    void insert(const std::string& key, const std::string& value) 
    {
        size_t index = hashFunction(key);
        table[index].push_back({key, value});
    }

    // Retrieve a value by key
    // indicates the method is a const member function. this means that the method is not allowed to modify the state of the object
    std::string get(const std::string& key) const 
    {
        size_t index = hashFunction(key);
        for (const auto& pair : table[index]) 
        {
            if (pair.key == key) 
            {
                return pair.value;
            }
        }
        return "Key not found";
    }

    // Remove a key-value pair by key
    void remove(const std::string& key) 
    {
        size_t index = hashFunction(key);
        auto& pairs = table[index];
        for (auto it = pairs.begin(); it != pairs.end(); ++it) 
        {
            if (it->key == key) 
            {
                pairs.erase(it);
                return;
            }
        }
    }
};

int main() {
    HashTable ht(10); // Create a hash table with 10 buckets

    ht.insert("name", "Alice");
    ht.insert("age", "30");
    ht.insert("city", "New York");

    std::cout << "Name: " << ht.get("name") << std::endl;
    std::cout << "Age: " << ht.get("age") << std::endl;
    std::cout << "City: " << ht.get("city") << std::endl;

    ht.remove("age");
    std::cout << "Age after removal: " << ht.get("age") << std::endl;

    return 0;
}

/*
struct 
in c++ is user defined data type that allows you to group variables of different types together 
under a single name. it is similar to a class in many ways,but with some differences in terms of default
access control and usage. struct are usually used to represent simple data structures

*/


#include <iostream>
#include <string>

// Define a struct named Person
struct Person {
    std::string name;
    int age;
    double height;
};

int main() {
    // Declare a variable of type Person
    Person person;

    // Assign values to the members
    person.name = "Alice";
    person.age = 30;
    person.height = 5.5;

    // Access and print the members
    std::cout << "Name: " << person.name << std::endl;
    std::cout << "Age: " << person.age << std::endl;
    std::cout << "Height: " << person.height << std::endl;

    return 0;
}
