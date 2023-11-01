/*
Semordnilap

write a function that takes in a list of unique strings and returns a list of semordnilap pairs

a semordnilap pair is defined as a set of different strigs where the reverse of one word is the same as the forward version of the other . 
eg the word "diaper" and "repaid" are semordnilap pair as the words "palindromes" and "semordnilap"
the order of the returned pairs and teh order of the strings within each pair does not matter.

sample input 
words = ["diaper", "abc", "test", "cba", "repaid"]
sample output :
[["diaper", "repaid"], ["abc", "cba"]]
*/

// solution 1
using namespace std;
#include <unordered_set>
// time 0(n * m) where n is the size of words and m is the size of the longest word in the string
// space 0(n * m)
vector<vector<string>> semordnilap(vector<string> words) {
  // Write your code here.
  std::unordered_set<string> wordsSet(words.begin(), words.end());
  std::vector<std::vector<string>> semordnilapPairs ;
  for(auto word: words)
    {
      // the reverse function has a complexity of 0(N) and constant space complexity 
      string reverseWord = string(word.rbegin(), word.rend());
      if(wordsSet.count(reverseWord)  && reverseWord != word)
      {
        std::vector<string> pair{word, reverseWord};
        semordnilapPairs.push_back(pair);
        wordsSet.erase(word);
        wordsSet.erase(reverseWord);
      }
    }
  return semordnilapPairs;
}

// hints

/*
it can be helpful to convert the input array into a set, so that you can check if a word exists in the list in constant time 

hint 2
after creating the set of words, try iterating through the original array. for each word, can you check if its semordnilap pair is in the word list 

optimal space and time complexity 
0(n * m) time | 0(n * m) space where n is the number of words and m is the length of the longest word
*/

// explanation 
/*
 we shall use a set because we shall get constant lookup time with a set . set to contain all the words 
*/


// solution 2
using namespace std;
#include <unordered_set>
// time 0(n * m) where n is the size of words and m is the size of the longest word in the string
// space 0(n * m)
vector<vector<string>> semordnilap(vector<string> words) {
  // Write your code here.
  std::unordered_set<string> wordsSet(words.begin(), words.end());
  std::vector<std::vector<string>> semordnilapPairs ;
  for(auto word: words)
    {
      // the reverse function has a complexity of 0(N) and constant space complexity 
      string reverseWord = string(word.rbegin(), word.rend());
      if(wordsSet.find(reverseWord) != wordsSet.end() && reverseWord != word)
      {
        std::vector<string> pair{word, reverseWord};
        semordnilapPairs.push_back(pair);
        wordsSet.erase(word);
        wordsSet.erase(reverseWord);
      }
    }
  return semordnilapPairs;
}

