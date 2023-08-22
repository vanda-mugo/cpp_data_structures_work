/*
given an array of positive integers representing the values of coins in your possession, write a function that returns 
the minimum amount of change (the minimum sum of money ) that you cannot create. the given coins have any positive integer value
and arent necessarily unique( you can have multiple coins of the same value )

for example given coins = [1,2,5], the minimum change that you cant create us 4. if youre given no coins, the minimum 
amount of change that you cant create is 1
*/



// solution 1 has the explanation
#include <vector>
#include <algorithm>
//using namespace std;

int nonConstructibleChange(std::vector<int> coins) {
  
  // Write your code here.
  int change = 0;
  std::sort(coins.begin(), coins.end());
  for(int i = 0; i < coins.size(); i++)
    {
      if(coins[i] > change + 1)
      {
        return change + 1;
      }
      else
      {
        change += coins[i];
      }
      
    }
  return change +1 ;
}


//the optimal solution can be such that you can sort the input array
// so consider such that you can loop through the input array checking the change that you can
// the change that you can create 
// if lets say the input array does not have a 1, then that means that you cant make the 1
// always after iterating consider the previous change that could be made plus one and 
//if the current number where youre at is greater than this then that means you cant create 
// the previous change plus one

/*
consider the above example of input array 
[5,7,1,1,2,3,22]
  the sorted array becomes above 
[1,1,2,3,5,7,22]
  now lets go  through this solutuion together 
min change to begin at value of 0, so after iterating the first coin, minimum change 
becomes 1, then the second coin is 1 as well , 
min change becomes 2 , note that 1 is not greater than 1+ 1
then to index pointing 2 in array, change becomes 4 , 2 < 2+1 , in this case 2 is previous change
then to index pointing 3 in array, change becomes 7 , 3 < 4+1
then to index pointing 5 in array, change becomes 12 , 5 < 7+1
then to index pointing 7 in array, change becomes 19 ,7 < 12+1
then to index pointing 22 in array, change becomes 41, 22 > 19+1

note that the current number 22 is greater than the previous change plus one which means that 
it wont be possible to create the change that is 20


if we get to a value in the sorted array that is greater than the amount of change that you
can make with the previous change amount plus 1 then that means that you cannot create the previous 
change plus 1

to summarise the answer we know that if the current coin that we are on is less than or equal to the 
previous change plus one then that means that we can make all of the change previously and all of the 
change we could make previously plus this new coin 

consider the above input
[1,1,3] we start at change 0 then advance to 1, then the next 1 where 1 will be less than previous
change of 1 plus 1 then we go to 3 and 3 will be equal to the previous change of 2 + 1, in which 
in this case will be able to make the change of 2 and all the change of previous change plus new num

*/

// solution is going to take 0(NlogN)
// space 0(1)
// if not allowed to sort the array in place then the space complexity would be 0(N)
// this because you would need another data structure to store the new sorted array 

// solution 2
// just reorganised the loop differently
#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
  
  // Write your code here.
  int change = 0;
  int leastChange = 0;
  std::sort(coins.begin(), coins.end());
  for(int i = 0; i < coins.size(); i++)
    {
      if(coins[i] <= change + 1)
      {
        change += coins[i];    
      }
      else
      {
        leastChange = change +1;
        return leastChange;
      }
    }
  return change + 1;
}

//solution 3

#include <vector>
#include <algorithm>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
  
  // Write your code here.
  int change = 0;
  std::sort(coins.begin(), coins.end());
  for(int i = 0; i < coins.size(); i++)
    {
      if(coins[i] <= change + 1)
      {
       change += coins[i];
      }
      else
      {
        return change +1 ;
      }
      
    }
  return change +1 ;
}

//solution using iterators
#include <vector>
//using namespace std;

int nonConstructibleChange(std::vector<int> coins) {
  int change = 0;
  std::sort(coins.begin(), coins.end());
  for(auto itr = coins.begin(); itr < coins.end(); itr ++)
    {
      if((*itr) <= change +1)
      {
        change += *itr;
      }
      else
      {
        return change + 1;
      }
    }
  // Write your code here.
  return change + 1;
}


//solution using break 
#include <vector>
#include <algorithm>
//using namespace std;

int nonConstructibleChange(std::vector<int> coins) 
{
  int change = 0;
  std::sort(coins.begin(), coins.end());
  for(auto itr = coins.begin(); itr < coins.end(); itr ++)
    {
      if(*itr > change +1)break;      
      else
      {
        change += *itr;
      }
    }
  // Write your code here.
  return change + 1;
}


//simple shortest explanation 
#include <vector>
#include <algorithm>
using namespace std;

int nonConstructibleChange(std::vector<int> coins) 
{
  int change = 0;
  std::sort(coins.begin(), coins.end());
  for(auto itr = coins.begin(); itr < coins.end(); itr ++)
    {
      if(*itr > change +1)break;      
      change += *itr;
    }
  // Write your code here.
  return change + 1;
}