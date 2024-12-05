/*
First Non-Repeating character

write a function that takes in a string of lowercase english alphabet letters and returns the index of the string's first non repeating character

the first non repeating character is the first character in a string that occurs only once. if the input string doesnt have non repeating characters 
your function should return -1

sample input : "abcdcaf"
sample output .. the first non repeating character is 'b' and is found at index 1

*/
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int firstNonRepeatingCharacter(string string) 
{
  // Write your code here.
  std::unordered_map<char,int> characterCount ;
  for(std::string::iterator itr = string.begin(); itr != string.end(); itr++)
    {
      if(characterCount.find(*itr) == characterCount.end())
      {
        // in this case the *itr is not found within the characterCount 
        characterCount[*itr] = 1;
      }
      else 
      {
        characterCount[*itr]++;
      }
    }
  
 for(int i = 0; i < string.size(); i++)
   {
     if(characterCount[string[i]] == 1)
     {
       return i;
     }
   }
  return -1;
}


// not the best optimized solution 
/*
lets say the sample input is abcdcaf
when at index a when iterating we check the remaining bits of each element of the sting and if a occurs again then we know that that character is repeating 
in the case that now we go to be and check if the character b occurs again within the string then we find that this characters does not occur again within the string 
so in this case we know that this is the first non repeating character 
when it comes to time complexity 0(N`2) in the worst case scenario since we shall have a nested loop that checks if the characters occurs again 
in this case we shall have the main loop has index i and inner loop has j 
that is comparing if j and i are the same whereby for every i the j will go through every character in the string with the onlhy exception when i and j are on the same index
in this case we shall not check if the characters are the same since they are on the same index

space complexity is constant space complexity 0(1)

*/

// solution 2
// in this solution we use a hash table and it shall have constant space and even though this seems not to be the case , what actually happens is that 
// with this solution since we know that within the hash table we shall have the characters with the number of occurences and since we are only using lower case characters in this case 
// what shall happen is that our space complexity will be 0(26) since we have a maximum of 26 characters in the english alphabet and with this then what happens is that we have 
// constant space complexity since this value shall never be greater than this 
// basically the time complexity will be as follows where we have two for loops that are not nested within each other and in this case then what happens is that we have 
// 0(N + N)
// this will be 0(2N) whereby we shall not consider the constant variable leading to a linear time complexity 


// similar solution as the first but less code 
using namespace std;

int firstNonRepeatingCharacter(string string) 
{
  // Write your code here.
  std::unordered_map<char,int> characterCount ;
  for(std::string::iterator itr = string.begin(); itr != string.end(); itr++)
    {
        characterCount[*itr]++;
    }
  
 for(int i = 0; i < string.size(); i++)
   {
     if(characterCount[string[i]] == 1)
     {
       return i;
     }
   }
  return -1;
}



//least optimal solution of time complexity 0(N`2)
using namespace std;

int firstNonRepeatingCharacter(string string) {
  // Write your code here.
  
  for(int i = 0; i < string.size(); i++)
    {
      bool foundDuplicate = false;
      for(int j = 0; j < string.size(); j++)
        {
          if(string[i] == string[j] && j != i)
          {
            foundDuplicate = true;
            continue;
          }  
        }
      if(!foundDuplicate)
      {
        return i;
      }
    }
  return -1;
}


// hints as per algo experts 
