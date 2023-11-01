/*
write a function that takes in an array of integers and returns a sorted version of that array. use the selection sort algorithm to sort the array 
*/

// solution 1
#include <vector>
using namespace std;
//space complexity is 0(1)
// time complexity is 0(N`2)

vector<int> selectionSort(vector<int> array) 
{
  // Write your code here.
  // in the very beginning we have a list of unsorted numbers 
  // we have no list of sorted numbers 
  // note by based on the selection sort what is happening is that 
  // we iterate throught the loop and with this iteration what occurs is that we find the smallest number in the unsorted list 
  // this number is appended to the beginnning of the unsorted list and the pointer to the beginning of this list is pushed forward one step
  int currentIndex = 0; // this is the index of the first number in the unsorted sublist 
  while(currentIndex < array.size() - 1)
    {
      // NOTICE THAT WE ARE TAKING THE CURRENT INDEX FROM VALUE OF 0 ALL THE WAY TO THE LENGHT OF THE INDEX
      // this is because when our current index which represents the index of the first number in the unsorted list gets all the end of the sublist 
      // this means that our unsorted sublist is only going to have one number which means that we are done because that number is going to be at its final position 
      int smallestIndx = currentIndex;
      for(int i = currentIndex + 1; i < array.size(); i++)
        {
          if(array[smallestIndx] > array[i])
          {
            smallestIndx = i;
            // basically what is happening is that we are updating the index to now the index that contains the smallest number.
            // note that the for loop will continue until the end of the array index and in this case i will contain the index of the smalles number in the array 
          }
        }
      std::swap(array[currentIndex], array[smallestIndx]);
      currentIndex += 1;
    }
  
  return array;
}


// solution 2
#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
  // Write your code here.
  for(int i = 0; i < array.size(); i++)
    {
      int minIndex = i;
      for(int j = i + 1; j < array.size(); j++)
        {
          if(array[j] < array[minIndex])
          {
            minIndex = j;
          }
        }
      std::swap(array[i], array[minIndex]);
    }
  return array;
}


