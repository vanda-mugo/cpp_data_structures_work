/*
Binary search

Write a function that takes in a sorted array of integers as well as a target integer. the function should use the binary seach
algorithm to determine if the target integer is contained in the array and should return its index if it is otherwise return -1



write a function that takes in a sorted array of integers as well as the target integer.The function should use binary search 
algorithm to determine if the target integer is contained in the array and should return its index if it is, otherwise -1

sample input
array = [0, 1, 21, 33, 45, 45, 61, 71, 72, 72]
target = 33

sample output 3*/


/*
a sorted array tends to point to the use of the binary search

time complexity 0(logN) where n is the length of the input array . the reason is with
using the pointer method where one pointer is pointing to the last element and the other 
pointer is pointing to the beginning of a pointer , then we add the index of this pointers to 
then divide by two and floor, this action is to get the middle pointer and compare this middle 
pointer to the number that we are searching for . if you recall this will in each time step 
reduce the number of elements n by half with each time step and henceforth thats why the time 
complexity happens to be 0(logN)
this is the concept of the binary search 

space complexity : if you implement this iteratively then the space complexity is 0(1) space
if you implement recursively then the complexity is 0(log(N))

  */

//solution 1 that uses recursion 
// time complexity 0(log(N)) and space 0(log(N)) space because you are adding frames to the call stack because of the 
// recursive calls 
#include <vector>
//using namespace std;

int binarySearchHelper(std::vector<int>array, int target,int leftPointer ,int rightPointer)
{
    if(leftPointer > rightPointer)
    {
      return -1;
    }
    int middlePointer = std::floor((rightPointer + leftPointer)/2);
    int potentialNum = array[middlePointer];
    if(target == potentialNum)
    {
      return middlePointer;
    }
    else if(target < potentialNum)
    {
      return binarySearchHelper(array, target, leftPointer, middlePointer-1);
      // in this case since the middle pointer value happens to be greater than the 
      // value of the target that means that we delete everything to the right of
      // the middle node since they are greater than the potentialNum which is 
      //established to be greater than the target value we currently are looking for 
    }
    else if(target > potentialNum)
    {
      return binarySearchHelper(array, target, middlePointer+1, rightPointer);
    }
}

int binarySearch(std::vector<int> array, int target)
{
  // Write your code here.
  // implementation recursively
  int rightPointerVal = array.size() -1;
  return binarySearchHelper(array, target, 0,rightPointerVal );
}


// solution 2
// iterative solution 
// time complexity 0(logN) and constant space 0
#include <vector>
using namespace std;

int binarySearchHelper(std::vector<int>array, int target,int leftPointer ,int rightPointer)
{
    while(leftPointer <= rightPointer)
      {
        int middlePointer = std::floor((rightPointer + leftPointer)/2);
        int potentialNum = array[middlePointer];
        if(target == potentialNum)
        {
          return middlePointer;
        }
        else if(target < potentialNum)
        {
          rightPointer = middlePointer -1; 
        }
        else if(target > potentialNum)
        {
          leftPointer = middlePointer + 1;
        }
      }
  return -1;
    
}

int binarySearch(std::vector<int> array, int target)
{
  // Write your code here.
  // implementation recursively
  int rightPointerVal = array.size() -1;
  return binarySearchHelper(array, target, 0,rightPointerVal );
}



