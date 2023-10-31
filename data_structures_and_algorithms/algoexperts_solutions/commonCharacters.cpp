/*
    COMMON CHARACTER
    write a function that takes in a non empty list of non empty string and return a list of characters that are common to all strings
    in the list ignoring multiplicity 
    note that the string are not guaranteed to only contain alphanumeric characters . the list you return can be in any order 
    
*/


// solution 1
using namespace std;

// the time complexity will be 0(N*M) where N is the size of strings and M is the size of the longest string within the strings vector
// since within each element that is each string in the strings vector we are creating a set therefore we are going to store a max of all the characters within a said string 
// the other space is for the character counts which is going to be larger space and it will be 0(C) which is the total number of entries in the character counts
// or total number of unique entries in the character counts map
vector<string> commonCharacters(vector<string> strings) {
  // Write your code here.
  std::unordered_map<char, int> characterCount;
  for(auto str : strings)
    // this for loop has 0(N * M) since the inner loop loops over each element of the string element str
    // inserting element to an std::unordered_set is a constant time operation which can become linear based on the hash function used 
    {
      std::unordered_set<char> charKeySet(str.begin(), str.end());
      for(auto n : charKeySet)
        {
          if(characterCount.count(n))
          {
            characterCount[n]  += 1;
          }
          else
          {
            characterCount[n] = 1;
          }
        }
    }
  std::vector<string> vecOut;
  for(auto n : characterCount)
    {
      if(n.second == strings.size())
      {
        std::string str(1, n.first);
        vecOut.push_back(str);
      }
    }
  return vecOut;
}


// solution 2
using namespace std;

//for space complexity first we iterate through all the strings
//for each of the string we generate the set and then we shall go through the set to find the character counts which shall be added to the unordered_set

// we are generating sets for each of the strings 
// note by the qualities of set is that each key element can only be stored once 
std::vector<string> commonCharacters(std::vector<string> strings) 
{
  // Write your code here.
  std::unordered_map<char, int> characterCount ;
  // note by that strings is a vector that contains list of character elements 
  for(auto n : strings)
    {
      // the use of the for loop is one of the ways of creating a set from a string. 
      // the other means is by using of a set constructor 
      // set < char> set_obj(begin(string_name), end(string_name))
      // in our case this would be as follows 
      /*
        std::unordered_set<char> charKeySet(n.begin(), n.end())
        in this case this will copy the content of the string n and insert them into the set 
        */
      std::unordered_set<char> charKeySet;
      for(int i = 0; i < n.size(); i++)
        {
          charKeySet.insert(n[i]);
        }
      // now since the set only stores the values as singular and allows no duplicates then we get to iterate over the set and add it onto the map
      std::unordered_set<char>::iterator i;
      for(i = charKeySet.begin(); i != charKeySet.end(); i++)
        {
          characterCount[*i] += 1;
        }
    }
  //the above for loop was tasked with adding the count to the std::unordered_map()
  std::vector<string> vecOutput;
  for(std::unordered_map<char, int>::iterator itr = characterCount.begin(); itr != characterCount.end(); itr++)
    {
      if(itr->second == strings.size())
      {
        // the method observed here is of string class whereby you specify the size of the string
        // eg create a string of size n and fill the string with character x
        // string s(size_t n, char x)
        // using a string literal is another way to convert a single character to a string in c++.
        // the syntax is as follows string str = string(1,c) where c is the character
        string s(1,itr->first);
        vecOutput.push_back(s);
      }
    }
  
  return vecOutput;
}


// solution 2