/*
write a function that takes in a non empty string and that returns a boolean representing whether the string is a palindrome 
a palindrome is defined as a string that is written the same backwards and forwards. note by that single characters strings are palindromes */

//solution 1
using namespace std;
// time complexity 0(N) and space complexity 0(1)

bool isPalindrome(string str) 
{
  // Write your code here.
  int leftIndex = 0;
  int rightIndex = str.size() - 1;
  while(rightIndex > leftIndex)
    {
      if(str[leftIndex] != str[rightIndex])
      {
        return false;
      }
      rightIndex--;
      leftIndex++;
    }
  
  return true;
}


// solution 2
#include <cstring>
using namespace std;

bool isPalindrome(string str) {
  // Write your code here.
  // lets say we were to use the for loop
  int lastPointer = str.length() - 1;
  for(int i = 0; i < lastPointer; i++)
    {
      if(str[i] != str[lastPointer])
      {
        return false;
      }
      lastPointer -= 1;
    }
  return true;
}

// solution 3
using namespace std;
// 0(N/2) time | 0(N) space, where N = number of characters
bool isPalindrome(string str) {
  // Write your code here.
  std::string reversed = str;
  std::reverse(reversed.begin(), reversed.end());
  return str == reversed;
}


// solution 4

