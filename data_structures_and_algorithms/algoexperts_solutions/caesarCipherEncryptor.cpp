/*
Caesar Cipher Encryptor
Given a non-empty string of lowercase letters and non negative integer representing a key, write a function that returns a new string 
obtained by shifting every letter in the input string by k position in the alphebet where k is the key.

note that letters should "wrap" around the alphabet; in other words, the letter z shifted by one returns the letter a.
*/

#include <string>
#include <iostream>

// solution 1
using namespace std;
// constant space complexity 
// checking wheter the ascii after adding the key is greater than 122 then removing k = k - 26
// checking wheter the ascii after adding the key is greater than 97 then removing k = k + 26
// return the str which has been changed in real time 
string caesarCypherEncryptor(string str, int key) {
  // Write your code here.
  int newKey = key % 26;
  for(int i = 0; i < str.size(); i++)
    {
      int code = str[i];
      if( code + newKey > 122) newKey = newKey - 26; 
      if( code + newKey < 97) newKey = newKey + 26;
      str[i] = str[i] + newKey;
    }
  return str;
}


// solution 2
using namespace std;
// time complexity 0(n)
// space complexity 0(1) since we are just modyfying the input string

string caesarCypherEncryptor(string str, int key) {
  // Write your code here.
  // time complexity0(N)
  // space complexity is 0(N) because you are creating an array of length N
  for(int i = 0; i < str.size(); i++)
  {
    str[i] = char((str[i] - 'a' + key) % 26 + 'a');
  }
  return str;
}


// solution 3
