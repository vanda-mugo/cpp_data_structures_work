/*
write a function that takes in an array of at least three integers and, without sorting the input array returns a sorted array of the three largest 
integers in the input array.
the function should return duplicate integers if necessary ; for example it should return [10, 10, 12] for an input array of [10, 5, 9, 10, 12]
*/

// solution 1
#include <vector>
//using namespace std;
// TIME complexity 0{n}
//space complexity 0(1)
// incase you use the std::map, note the above on inserting elements in the map
// std::map<int, int> mp;
// mp.insert(std::pair<int, int>(1,15));
std::vector<int> findThreeLargestNumbers(std::vector<int> array) 
{
  // Write your code here.
  std::vector<int> nums(3,INT_MIN);
  // note by that you cannot initialise the vector to be equal to value of 0 
  // this is because there may be negative values within the inserted array in the input 
  // INT_MIN is a macro that rep the minimum value of type int that can exist 
  for(int i = 0; i < array.size(); i++)
    {
        if(array[i] > nums[2])
        {
          nums[0] = nums[1];
          nums[1] = nums[2];
          nums[2] = array[i];
        }
        else if(array[i] > nums[1])
        {
          nums[0] = nums[1];
          nums[1] = array[i];
        }
        else if(array[i] > nums[0])
        {
          nums[0] = array[i];
        }
      
    }
  return nums;
}


// solution 2
#include <vector>
#include <limits>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array)
{
  // note by that std::numeric_limits<T>::min returns the minimum finite value represented by the type T in this case 
  int smallest = std::numeric_limits<int>::min();
  std::vector<int> nums(3, smallest);
  for(auto n: array)
    {
      if(n > nums[2]) std::swap(nums[2], n);
      if(n > nums[1]) std::swap(nums[1], n);
      if(n > nums[0]) std::swap(nums[0], n);
    }
  // Write your code here.
  return nums;
}
//The function std::swap() is a built-in function in the C++ Standard Template Library (STL) which swaps the value of two variables.
// in this case within each iteration the value of the n is swapped with the value of the nums[i] this is because n being an arbitrary value it can be switched from within the 
// loop , the for loop 



int main()
{
    std::vector<int> array {141, 1, 17, -7, -27, 18, 541, 8, 7, 7};
    findThreeLargestNumbers(array);
    std::cout << "the array is " << std::endl;
}
