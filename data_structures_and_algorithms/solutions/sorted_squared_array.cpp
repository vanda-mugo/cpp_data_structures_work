// sorted square array

/*write a function that takes in a non empty array of integers that are sorted in ascending order and returns an 
array of the same lengh with the squares of the original integers also sorted in ascending order */

#include <vector>
#include <algorithm>
//using namespace std;

// sometime you can do as : using std::vector so this case you wnt have to use std prefix for vector elements also just use this in cpp file and not in the header file .


vector<int> sortedSquaredArray(const vector<int>& array) 
{
  // Write your code here.
  vector<int> sort_array(array.size(),0);
  for(int i=0; i < array.size(); i++)
    {
      sort_array[i] = array[i] * array[i]; 
      
    }
  sort(sort_array.begin(), sort_array.end());
  return sort_array;
}

// this runs on a space complexity of 0{N} since you are creating another array to hold the values 
// time complexity of 0(NlogN)
// the time complexity actually is 0(N + NlogN ) which is  0(2NlogN)
// however since in big O we really dont consider the 2 then it becomes 0(NlogN)
// kindly note that the first N is because we actually already have to iterate through each element of the 
// array atleast one time 


//solution 2
// space complexity of 0(N)
// time complexity of 0(N)

// this solution uses reverse iterators 

// in both this solutions kindly appreciate the use of the else 

#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  // Write your code here.
  vector<int> sortedArray (array.size(), 0);
  int smallPtr = 0;
  int largePtr = array.size() - 1;// this may be risky if size of the array is 0

  for(vector<int>::reverse_iterator it= sortedArray.rbegin(); it != sortedArray.rend(); ++it)
    {
      if(abs(array[largePtr]) > abs(array[smallPtr]))
      {
        *it = array[largePtr] * array[largePtr];
        largePtr -=1;
      }    
      else
      {
        *it = array[smallPtr] * array[smallPtr];
        smallPtr +=1;
      }    
    }
  return sortedArray;
}


// solution 3
// space complexity of 0(N)
// time complexity of 0(N)

// this solution uses standard integers to represent the values in the vector

#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array)
{
  // Write your code here.
  int large_ptr = array.size() - 1;
  int small_ptr = 0;
  vector<int> sorted_array(array.size(), 0);
  for(int i= large_ptr; i >= 0; i--)
    {
      if(abs(array[large_ptr]) > abs(array[small_ptr]))
      {
        sorted_array[i] = array[large_ptr] * array[large_ptr];
        large_ptr -= 1;
      }
      else
      {
        sorted_array[i] = array[small_ptr] * array[small_ptr];
        small_ptr += 1;
      }
    }
  return sorted_array;
}


// kindly note the use of the else which in this case goes a long way to satisfy
// the condition in which the values of the absolute integers may be the same 
// in this case therefore the else will take place and in the next time step the other abs value 
// that was equal to previous will be the one that is tabulated 


// solution 4 
// this is a less optimal solution 
// there is also some code duplication 

#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array)
{
  // Write your code here.
  int large_ptr = array.size() - 1;
  int small_ptr = 0;
  vector<int> sorted_array(array.size(), 0);
  for(int i= large_ptr; i >= 0; i--)
    {
      if(abs(array[large_ptr]) > abs(array[small_ptr]))
      {
        sorted_array[i] = array[large_ptr] * array[large_ptr];
        large_ptr -= 1;
      }

      else if(abs(array[small_ptr]) > abs(array[large_ptr]))
      {
        sorted_array[i] = array[small_ptr] * array[small_ptr];
        small_ptr += 1;
      }
      else
      {
        sorted_array[i] = array[small_ptr] * array[small_ptr];
        small_ptr += 1;
      }
    }
  return sorted_array;
}


// kindly note the use of the else which in this case goes a long way to satisfy
// the condition in which the values of the absolute integers may be the same 
// in this case therefore the else will take place and in the next time step the other abs value 
// that was equal to previous will be the one that is tabulated 


//solution 5
// this solution has a constant space complexity 0(1)
// time complexity is 0(NlogN)

#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array)
{
  for(int i = 0; i <= array.size()-1; i++)
    {
      array[i] = pow(array[i],2);
    }
  sort(array.begin(), array.end());
  return {array};
}



// solution 6 
// using while loop
// time complexity 0(N)
// space complexity 0(N)
#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  // Write your code here.
  vector<int> sort_array(array.size(), 0);
  int start = 0;
  int end = array.size()-1;
  int i = array.size() - 1;
  while(start <= end)
    {
      if(abs(array[start]) > abs(array[end]))
      {
        sort_array[i] = array[start] * array[start];
        start ++;
      }
      else
      {
        sort_array[i] = array[end] * array[end];
        end --;
      }
      i--;
    }
  return sort_array;
}


// to learn about deques and go back to see implementation using the same 


// avoid using the use namespace  std in the header(never!)


// using std::merge() to find the position or iterator or the position of the first positive value .
