/*
write a function that takes in a non empty array of distinct integers and an integer representing a target sum. the function 
should find all quadruplets in the array that sum up to the target sum and return a two dimensional array of all these quadruplets
in no particular order */
//if no four numbers sum to the target sum, the function should return an empty array 

// four for loops will not be optimal that is 0(N^4) will not be optimally efficient , this will be the time complexity

// so a quadruplet can be thought of as two pairs of numbers , that is think of instance in which you have 
// x,y as one pair and z,k as the other pair of numbers in the quadruplet , you can basically sum up each pair and have one pair of numbers 
// lets say that this values that come from the values of the pairs are p and q, that is p = x+y , q = z+k
//
/*
be careful not to double count quadruplets : that is think of the above situation where the target value is 16 amd the array of numbers that we 
have is [7,6,4,-1,1,2]
if you think of this say p =13 and q is equal to 3, then we may have the above combinations 
{
    p = 13 : [[7,6]],
    q = 3 : [[4,-1]]

    then we can have the above 
    p = 10 : [[6,4]],
    q = 6 : [[7,-1]]

    in the above you notice that some values have been double counted in that the quadruplets are still the same 
    ..so there is need to ensure that there happens to be no double counting of the above


}*/

/*
solutions to ensure no double counting 
one for loop and two inner for loops to strategically avoid the double counting of arrays
this will be shown in the algorithm 

so solution explanation

the firt for loop you iterate and the current value of 7 is stored 
so the second for loop will sum all numbers after 7 in the array \
that will be like 

then we calculate the difference with the target sum and the current number anc check if that difference will be in the hash table 

p = 7 + 6 = 13,  diff = 16 - 13 = 3
p = 7 + 4 = 11,  diff = 16 - 11 = 5
p = 7 + -1 = 6,  diff = 16 - 6 = 10
p = 7 + 1 = 8,   diff = 16 - 8 = 8
p = 7 + 2 = 9,   diff = 16 - 9 = 7

if the difference is  in the hash table then we have found the quadruplets and we have our numbers 
if it isnt we shall not add that difference to the hash table yet what shall happen is that we shall iterate through that will a second for loop for all 
numbers before the current number that we are in 
in this iteration we shall generate some numbers which we shall call Q and this numbers shall in this case be stored in the hash table 
this will allow us not to repeat the quadruplets 

we only add a sum to the hash table when in our parent for loop (first for loop ) we are at the second number that generates that sum in the array,
that is when the second number is the main number in the main for loop 

get this 

[7,6,4,-1,1,2] target sum of 16
so when at 7 in main for loop 
we shall have 
p = 7 + 6 = 13,  diff = 16 - 13 = 3
p = 7 + 4 = 11,  diff = 16 - 11 = 5
p = 7 + -1 = 6,  diff = 16 - 6 = 10
p = 7 + 1 = 8,   diff = 16 - 8 = 8
p = 7 + 2 = 9,   diff = 16 - 9 = 7
now note that since 7 is the first number then we shall not have any number prior to it and there for  nothing would be in the hash table for this number 
but now when we get to 6 

we would have the above 
p = 6 + 4 = 10 , diff =  6, not in hash table 
p = 6 + -1 = 5, diff = 11, not in hash table 
p = 6 + 1 = 7, diff = 9, not in hash table 
p = 6 + 2 = 8, diff = 8, not in hash table 

therefore think about the above now to iterate with third loop for all values before 7
not that this iteration is only going to happen if we have no number in the hash table that completes the quadruplet 

q = 7 + 6 = 13, so we shall now add 13 to has table and itll be added as such 

13 : [[7,6]]

this being because there may exist other number combinations that will sum to 13 which in this case shall be added to the pairs contained within 13

now to 4 
p = 4 + -1 = 3, diff = 13,
 
in this case 13 is in hash table and therefore all combinations of the value that are in the has table shall be appended to the two value of 
p that gave rise to p being equal to 3

since only one pair exist in 13 then the quadruplet shall be equal to the above p,q which will be [ 4, -2, 7, 6]

then to :-
p = 4 + 1 = 5, diff of 11, nt in hash table 
p = 4 + 2 = 6, diff = 10, nt in hash table 

then third for loop to iterate through the values before the valuje that is 4 and in this case give rise to the above 
q = 7 + 4 = 11, add to hash as 11: [[7,4]]
q = 6 + 4 = 10, add to hash as 10: [[6,4]]

the time complexity for this is 0(n^2) on average 
since we have the main for loop that checks every value for the array and two other for loops that iterate one from current number to end and the 
other one from beginning to the current number which evaluate to the iteration through the array once


worst case scenario the time complexity would be 0(N^3) since imagine that the inner loop we have a pair that has very many pairs adding up to a certain 
value of q eg lets say the target sum is 10 and p = 10 so q is equal to 0 where the value 0 in hash table has [[-1,1], [-2,2], [-3,3], [-4,4]] and in this case 
the main array probably had the same number of elements, this will bring the worst case to somthing of the sort of 0(N^3)


as far as space complexity it shall be  0(N^2) average case ( this is cause of you are storing N^2 pairs)so N^2 sums that you are storing on the table 


*/

// find solution that finds sum of any numbers 

// algo to find the nearest path on graph

// solution 1

/*
time complexity is 0(N^2)
space complexity is 0(N^2)
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
//using namespace std;

std::vector<std::vector<int>> fourNumberSum(std::vector<int> array, int targetSum)
{
  // Write your code here.
  if(array.size() < 4)
    return {};
  std::vector<std::vector<int>> quadruplets;
  // note by that the quardeuplets is a 2 dimensional vector that contains 
  std::unordered_map<int , std::vector<std::pair<int, int>>> dict ;
  // the dict is a std::unordered_map that has a int key and a vector that contains pairs of int, int as value
  // note by that this vector basically stores elements in form of pairs
  for(int i = 1; i < array.size()-1; i++)
    {
      for(int j = i+1; j < array.size(); j++)
        {
          int sumDiff = targetSum -array[i] - array[j];
          if(dict.count(sumDiff))
          {
            for(auto pair: dict[sumDiff])
              {
                quadruplets.push_back({pair.first, pair.second, array[i], array[j]});
              }
          }
        }
      for(int k = 0; k < i; k++)
            {
              int currentSum = array[i] + array[k];
              dict[currentSum].push_back({array[i], array[k]});
            }
    }
    
  
  return quadruplets;


  // solution 2 using while loop 
  // time complexity 0(N^2)
  // space complexity 0(N^2)

#include <vector>
#include <unordered_map>


std::vector<std::vector<int>> fourNumberSum(std::vector<int> array, int targetSum) 
{
  // Write your code here.
  std::vector<std::vector<int>> quadruplets;
  // we create a container that stores the elements we want , a map container is a good solution 
  std::unordered_map<int, std::vector<std::pair<int,int>>> dict;
  int len = array.size();
  if(len < 4)
  {
    return {};
  }
  for(int i = 1; i < len - 1; i++)
    {
      int j = i + 1;
      while(j < array.size())
        {
        int diff = targetSum - array[i] - array[j];
          if(dict.find(diff) != dict.end())
          {
            for(auto pair : dict[diff])
            {
              quadruplets.push_back({pair.first , pair.second, array[i], array[j]});
            }
          }
          j++;
        } 
      int k = 0;
      while(k < i)
      {
        int currentSum = array[k] + array[i];
        dict[currentSum].push_back({array[k],array[i]});
        k++;
      } 
  }
  
return quadruplets;
}



// 
/*
solution 3
time 0(N^3)
space 0(N)*/

#include <vector>
using namespace std;
//in the coming function kindly note that the targetSum is basically the difference
std::vector<std::vector<int>> findPairSum(int idx0, int targetsum, const vector<int> &array)
{
  std::vector<std::vector<int>> result;
  std::unordered_set<int> unique;
  for(int i = idx0; i < array.size(); i++)
    {
      int y = targetsum - array[i];
      // in the statement above the difference between the diff and the array[currentIndex] is being sort 
      // if this difference is in the unique unordered_map then what happens is that the answer is returned 
      // if not then the unique inserts the value of the current array[i]
      if(unique.find(y) != unique.end())
      {
        result.push_back({array[i], y});
      }
      else
      {
        unique.insert(array[i]);
      }
    }
  return result;
}


std::vector<std::vector<int>> fourNumberSum(std::vector<int> array, int targetSum) {
  // Write your code here.
  std::vector<std::vector<int>> results;
  for(int i = 0; i < array.size(); i++)
    {
      const int x = array[i];
      for(int j = i+1; j<array.size();j++)
        {
          const int y = array[j];
          const auto r = findPairSum(j + 1, targetSum -(x+y),array);// he is passing j+1, the diff and the array 
          // in this case r represents a multidimensional vector that contains vectors of int, int
          for(auto &&p : r)// && represents an r value , value that is not addresable in memory
          // code can still work if this is not an r value 
            {
              results.push_back({x,y,p[0],p[1]});
            }
        }
    }
    
  return results;
}


