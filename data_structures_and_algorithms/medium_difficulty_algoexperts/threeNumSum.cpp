/*
write a function that takes in a non_empty array for distict integers and an integer representing a target sum,
the functiion should find all triplets in the array that sum up to the target sum and return a two dimensional 
array of all these triplets . the numbers in each triplet should be ordered in ascending order, and the triplets themselves 
should be ordered in ascending order with respect to the numbers they hold*/

// if no three numbers sum up to the target sum, the function should return an empty array 


//note by the input array is of distinct type
// so the not so optimal approach has the use of three for loops which is not so efficient has a time complexity of 0(N*N*N)
 /*
 given the above input to solve this as above
 
 input vector =
 [12,3,1,2,-6,5,-8,6]
 target sum = 0


with this solution we shall be able to find the solution in 0(N*N)
1st step : sort the array in ascending order
[-8,-6,1,2,3,5,6,12]
2nd step : initialise a left iterator pointing to the first digit after the current value held by i in for loop

We then shall have a digit that will be the first digit in the array and a pointer to digit after this , digit at index 1
the time complexity is 0(N*N)
the space complexity is 0(N)

current_sum(target_sum) = current_num + left_pointer_num + right_pointer_num
 */

#include <vector>
#include <algorithm>
using namespace std;

std::vector<std::vector<int>> threeNumberSum(std::vector<int> &array, int targetSum) 
{
  // Write your code here.
  std::sort(array.begin(), array.end());
  std::vector<std::vector<int>> outputVector;
  
  for(int i = 0; i < array.size()-2; i++)
    {
      if(targetSum < array[i])
      {
        break;
      }
      int left = i+1;
      int last_num = array.size() - 1;
      int findingSum = array[i];
      while(last_num > left )
        {
          int currentSum = array[i] + array[left] + array[last_num];
          if(currentSum == targetSum)
          {
            std::vector<int> v = {array[i], array[left], array[last_num]};
            outputVector.push_back(v);
            last_num--;
            left++;
            
          }
          else if(currentSum < targetSum)
          {
            left++;
          }
          else if(currentSum > targetSum)
          {
            last_num--;
          }
        }
      
    }
  return outputVector;
}


//solution 2
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) 
{
  std::sort(array.begin(), array.end());
  std::vector<vector<int>> outputVector;
  // Write your code here.
  for(int i = 0; i < array.size() ; i++)
    {
      int left = i + 1;
      int right = array.size() - 1;

      while(left < right)
        {
          int currentSum = array[i] + array[left] + array[right];
          if(currentSum == targetSum)
          {
            outputVector.push_back({array[i],array[left], array[right]});
            right --;
            left ++;
          }
          else if(currentSum < targetSum)
          {
            left++;
          }
          else if(currentSum > targetSum)
          {
            right--;
          }
        }
    }
  
  return outputVector;
}
//0(N*N) time complexity 
//0(1) space complexity


