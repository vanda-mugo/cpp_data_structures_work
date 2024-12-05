/*
INSERTION SORT
write a function that takes in an array of integers and returns a sorted version of that array. use insertion sort algorithm to 
sort the array 
*/

// solution 1
#include <vector>
using namespace std;

// space complexity 0(1)
// time complexity 0(N`2)
vector<int> insertionSort(vector<int> array)
{
  // Write your code here.
  for(int i = 1; i < array.size(); i++ )
    {
      // Why is the for loop starting at 1, this is because we have this sort of tentatively sorted list of numbers and we want to 
      //keep inserting numbers 
      // to this list . so in the beginning our sorted list of numbers consist of only the first number in the array 
      int j = i;
      while(j > 0 && array[j] < array[j - 1])
        {
          // note that this while loop is a nested loop within the for loop so lets say the the index i is at the end of said array, then 
          // what will happen is that the value of j will decrease until j = 1 where itll be compared with the value at the beginning of 
          //the said array 
          // we are checking that J is greater than 0 which in this case will mean that we havent reached the beginning of the tentatively 
          //sorted list 
          // recall that in the insertion sort we are swapping between the value at index i until it gets to its required location in the 
          //already tentatively sorted list 
          // what essentially has happened is that in this scenario we are checking whether 
          //the value at index i is less than the value at [j - 1]
          // this will basically necessitate a swap in the values concerned 
          std::swap(array[j], array[j - 1]);
          j -= 1;
          // in this case we are subtracting one so as to ensure that the value of j will decrease up to j = 1 to ensure whatever value at 
          //index i of the array was 
          // was swapped continuously until its expected location in the array 
        }
    }

  //insertion sort
  return array;
}


//solution 2
// using two for loops 
#include <vector>
using namespace std;
// space 0(1) time 0(N`2)
vector<int> insertionSort(vector<int> array) {
  // Write your code here.
  for(int i = 1; i < array.size(); i++)
    {
      for(int j = i; j > 0; j--)
        {
          if(array[j] < array[j - 1])
          {
            std::swap(array[j], array[j - 1]);
          }
          else
          {
            break;// continue as well can work or even the lack of the whole else loop
          }
        }
    }
  return array;
}
