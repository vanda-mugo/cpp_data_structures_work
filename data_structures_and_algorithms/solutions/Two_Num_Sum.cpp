// the following are two solutions to the two number sum in algoexperts.io
/*the prompt is as above 
write a function that takes in a non-empty array of distinct integers and a target sum. if any two numbers in the input
array sum up to the target sum, the function should return them in an array in any order , if no two numbers sum up to the 
target sum the funciton should return an empty array 
note that the target sum has to be obtained by summing two different integers in the array; you cant add a single integer
to obtain the target sum */

// note by three solutions will be provided each with there own time and space complexity 

//solution 1

#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) 
{
  int n = array.size();
  for(int i =0; i<n ; i++)
    {
      int firstNum = array[i];
      int y1 = targetSum - firstNum;
      
      for(int j = 0; j<n; j++)
        {
          if(array[j]== y1 && array[j] != firstNum)
          {
            return {y1,firstNum};
          }
        }
    } 
  // Write your code here.
  return {};
}

//bad time complexity



// time complexity 0(N*N)
// space complexity 0(1)


// // solution 2
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) 
{
  unordered_set<int> lookup;
  int n = array.size();
  for(int i = 0; i<n ; i++)
    {
      int num = array[i];
      int y1 = targetSum - num;
      lookup.insert(array[i]);
      if(lookup.count(y1) && y1 != num)
      {
        return{num, y1};
      }
    }
  
  // Write your code here.
  return {};
}

// time complexity of 0(N)
// space complexity of 0(N)

// solution 3

#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  int n = array.size();
  //to sort
  std::sort(array.begin(), array.end());// O(nlogn)
  int firstNum = 0;
  int lastNum = n-1;
  while(firstNum < lastNum)
    {
      int sum = array[firstNum] + array[lastNum];
      if(sum == targetSum)
      {
        return {array[firstNum], array[lastNum]};
      }
      else if (sum > targetSum )
      {
        lastNum -= 1;
      }
      else if( sum < targetSum)
        firstNum += 1;
    }
  return {};
}

// sort has a time complexity of 0(NlogN)
// overall space complexity 0(1)
// overall time complexity 0(NlogN)


int main()
{
    std::vector<int> array {3, 5, -4, 8, 11, 1, -1, 6};
    int target_sum = 10;
    twoNumberSum(array, target_sum);
}