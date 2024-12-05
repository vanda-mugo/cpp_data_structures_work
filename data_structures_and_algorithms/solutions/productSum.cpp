/*
Product sum 
write a function that takes in a "special" array and returns its product sum.
a "special" array is a non empty array that contiains either integers or other special arrays.The product sum of a special array is the sum 
of its elements, where special arrays inside it are summed themeselves then multiplied byt their levels of depth

the depth of a special array is how far nested it is. for instance the depth of [] is 1; the depth of the inner array [[]] is 2; the depth of the 
innermost array is [[[]]] is 3.
therefore the product sum of [x,y] is x + y; the product sum of [x,[y,z]] is x+2 * (y + z); the product sum of [x, [y, [z]]] is x + 2 * (y + 3z)*/

// sample input = [5, 2, [7, -1], 3, [6, [-13, 8],4]]
// sample output = 12

/*
any is one of the newest features that provides a safe container to store single values of any type . it allows storing of any
value in it without worrying about the type safety 

for checking the type of a varaible we have the typeid(x).name() which returns the data type of x. eg it returns i for integers,
d for doubles , f for float c for char Pi for pointer to integer Pd for pointer to double Pf for pointer to float Pc for
pointer to char, PPI for pointer to pointer to integer. single pointer results in prefix P double pointers results in the prefix PP

the other way is by using the decltype keyword : this one inspects the declared type of an entity or the type of an expression 


// C++ program to demonstrate use of decltype
#include <bits/stdc++.h>
using namespace std;
 
// Driver Code
int main()
{
    int x = 5;
 
    // j will be of type int : data type of x
    decltype(x) j = x + 5;
 
    cout << typeid(j).name();
 
    return 0;
}

decltype vs typeid
* decltype gives the type information at compile time while typeid gives this information at runtime
*/


//solution 1
#include <any>
#include <vector>

//using namespace std;

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
// If you know an element of the array is vector<any> you can cast it using:
//     any_cast<vector<any>>(element)
// If you know an element of the array is an int you can cast it using:
//     any_cast<int>(element)

// the time complexity is 0(N) where N is not the number of elements in the original array
// but rather N is the total number of elements in the original array including the elements 
// in the sub arrays and also elements in each of the nested as well subarrays 

// space complexity since we are making up recursive calls since at any particular the max
// values of multipliers at any time is equal to the depth of the sub arrays 
// so 0(D) will be the space complexity where D is the depth of the sub arrays or special arrays 
// in the given array

/*
any is somewhat similar to variant as any can be used to store any kind of data and variant only stores a limited 
number of data
any uses dynamic storage while variant uses stack based storage 
variant is more efficient storage memory management 

check out the example above 
inorder to print out the value of y in this case what has to happen 

std::any y;
y = 'z';
std::cout << y << std::endl;

note by that this will not compile as the left shift operator is not overloaded for objects of type any

to print 

std::cout << std::any_cast<char>(y) <<std::endl;
whereby the function any_cast will return a copy of y's data which is 'z'
the any_cast function is similar to the variants get function where the difference is any_cast returns a copy of the object 
where by the get function in variant returns a reference of the object 

unlike variant which cannot be empty , any can be an empty type
the data type for any can only be checked at run time unlike variant that can be checked at compile time using visitor


so inorder to check the data type stored in any you can only use run time type identification 
where 
nameOfAnyVariable.type() == typeid(dataTypeToCompareWith)
 */
int productSum(std::vector<std::any> array, int multiplier = 1 ) 
{
  // Write your code here.
  int sum{0};
  for(auto currElement : array)
    {
      // we need to check if the element is an array or not 
      if(currElement.type() == typeid(std::vector<std::any>))
      {
        // so in this case if an element is a vector what happens is that it is passed to the std::any_cast which in this case
        // returns the contained object
        sum += multiplier * productSum(std::any_cast<std::vector<std::any>>(currElement), multiplier + 1);
      }
      else if(currElement.type() == typeid(int))
      {
        sum += std::any_cast<int>(currElement) * multiplier;
      }
    }
  return sum;
}


/*
brief explanation of any_cast

operand : target any object 
the any_cast is used to extract a value of a given type from an any
any is one of the newest features of C++17 that provides a type-safe 
container to store single value of any type. In layman’s terms,
 it is a container which allows one to store any value in it without worrying about the type safety.
  It acts as an extension to C++ by mimicking behaviour similar to an object type in 

std::any_cast is a function provided by the C++ Standard Library in C++17 and later versions. 
It is part of the <any> header and is used for extracting a value from a std::any object
, which is a type-safe container for single values of any type. Here's how you can use std::any_cast:


#include <iostream>
#include <any>

int main() {
    // Create a std::any object holding an integer
    std::any myAny = 42;

    // Attempt to cast the value inside std::any to an integer
    try {
        int value = std::any_cast<int>(myAny);
        std::cout << "The value inside myAny is: " << value << std::endl;
    } catch (const std::bad_any_cast& e) {
        std::cerr << "Failed to cast the value: " << e.what() << std::endl;
    }

    return 0;
}

In this example, the code successfully extracts and prints the integer value stored in myAny. 
If you were to change the type in the std::any_cast, such as std::any_cast<double>(myAny),
it would throw a std::bad_any_cast exception because the stored value is an integer, not a double.
*/


//solution 2
#include <any>
#include <vector>

using namespace std;

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
// If you know an element of the array is vector<any> you can cast it using:
//     any_cast<vector<any>>(element)
// If you know an element of the array is an int you can cast it using:
//     any_cast<int>(element)
int productSum(vector<any> array, int multiplier = 1)
{
  // Write your code here.

  // this solution will utilise a for loop for the same operation 
  int sum = 0;
  for(int i = 0; i < array.size(); i++)
    {
      if(array[i].type() == typeid(std::vector<any>))
      {
        sum += multiplier * productSum(std::any_cast<std::vector<std::any>>(array[i]), multiplier + 1);
      }
      else if(array[i].type() == typeid(int))
      {
        sum += std::any_cast<int>(array[i]) * multiplier;
      }
    }
  return sum;
}
