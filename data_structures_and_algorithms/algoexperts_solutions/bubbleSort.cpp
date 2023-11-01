/*
write a function that takes in an array of integers and returns a sorted version of that array. Use the bubble sort algorithm to sort the array
*/

//solution 1
#include <vector>
using namespace std;

// space complexity is 0(1) since the sorting happened in constant time 
// time complexity 0(N`2) which is the worst case scenario 
// the best case scenario for bubble sort is 0(N) which occurs when we are given a 
// sorted array

vector<int> bubbleSort(vector<int> array) {
  // Write your code here.
  bool isSorted = false;
  while(! isSorted)
    {
      // tentatively consider a situation in which you consider the array is sorted
      isSorted = true ;
      for(int i = 0; i < array.size()-1; i++)
        {
          // you may be wondering why the i < array.size()-1 is used and the reason 
          // is that at every number we are comparing the number to the next number in the array 
          // because of this we dont need to go to the last number in  the array
          if(array[i] > array[i + 1])
          {
            std::swap(array[i], array[i + 1]);
            // so if this if statement is true then we shall know that even though tentatively we considered the array to be sorted this 
            // basically tells us that the array wasnt actually sorted and therefore we can set the isSorted variable to be false 
            isSorted = false ;
          }
        }
    }
  return array;
}

/*
point to note is that in the if loop where we have a swap , after each swap the control goes back to the beginning of the loop 
so in this case each iteration of the for loop solves one swap or one swap betweeen two digits then after this the control goes back to the beginning of 
the loop then when teh value of the i is equal the value of the array .size()-1 then what happens essentially is that the loop terminates and since a swap will 
have occured then what occurs is that the while loop takes control and now the value of i goes back to 0*/


// solution 2
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array) {
  // Write your code here.
  for(int i = array.size() - 1; i >= 0; i--)
    {
      for(int j = 0; j < i; j++)
        {
          if(array[j] > array[j + 1])
          {
            std::swap(array[j], array[j + 1]);
          }          
        }
    }
  return array;
}

// a property of bubble sort is that after each pass, the last i element becomes sorted 
// this can be optimised by adding a flag to determine if any swaps happened after each
// pass and ending early if no swaps occured 0(N`2)
// essentially what is hapenning is as follows 
//  {141, 1, 17, -7, -27, 18, 541, 8, 7, 7}
//
/*

  iteration                    i             array[i]          j           array[j]       before iteration array                     after first iteration array
  1st of i  1st of j           9                7              0              141        {141, 1, 17, -7, -27, 18, 541, 8, 7, 7}     {1, 141, 17, -7, -27, 18, 541, 8, 7, 7}
  1st of i  2nd of j           9                7              1              141        {1, 141, 17, -7, -27, 18, 541, 8, 7, 7}     {1, 17, 141, -7, -27, 18, 541, 8, 7, 7}
  1st of i  3rd of j           9                7              2              141        {1, 17, 141, -7, -27, 18, 541, 8, 7, 7}     {1, 17, -7, 141, -27, 18, 541, 8, 7, 7}
  1st of i  4th of j           9                7              3              141        {1, 17, -7, 141, -27, 18, 541, 8, 7, 7}     {1, 17, -7, -21, 141, 18, 541, 8, 7, 7}
  1st of i  5th of j           9                7              4              141        {1, 17, -7, -21, 141, 18, 541, 8, 7, 7}     {1, 17, -7, -21, 18, 141, 541, 8, 7, 7}
  1st of i  6th of j           9                7              5              141        {1, 17, -7, -21, 18, 141, 541, 8, 7, 7}     {1, 17, -7, -21, 18, 541, 141, 8, 7, 7}
  1st of i  7th of j           9                7              6              141        {1, 17, -7, -21, 18, 541, 141, 8, 7, 7}     {1, 17, -7, -21, 18, 541, 8, 141, 7, 7}
  1st of i  8th of j           9                7              7              141        {1, 17, -7, -21, 18, 541, 8, 141, 7, 7}     {1, 17, -7, -21, 18, 541, 8, 7, 141, 7}
  1st of i  9th of j           9                7              8              141        {1, 17, -7, -21, 18, 541, 8, 7, 141, 7}     {1, 17, -7, -21, 18, 541, 8, 7, 7, 141}

 note what happens here is that now the value of j in the next iteration will be 9 and this would not qualify the condition in the for loop and therefore the loop would terminate
in this case then the value of the last element of i in this case will be sorted such that after each complete iteration of j the last element of i becomes sorted 

*/