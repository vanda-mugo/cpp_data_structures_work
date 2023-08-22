// Validate subsequence
/*
given two non empty arrays of integers, write a function that determines whether the second array is a subsequence of the first onr.

what is a subsequence : a subsequence is a sequence that can be derived from another sequence by deleting some or no elements without 
changing the order of elements */

//solution 1
#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) 
{
  std::vector<int>::iterator seq = sequence.begin();// will return an iteragtor to the beginning.pointer to the first element in the vector sequence
  std::vector<int>::iterator arry = array.begin();// points to the first element in the subsequence 
  // Write your code here.
  for( auto i = arry; i != array.end(); i++)
    {
      if(*i == *seq  )
      {
        seq++;
        if(seq == sequence.end())
        {
          return true;
        }
      }
    }
  return false;
}

// in the subsequence we only move forward if the element is found within the main array
// in the main sequence even after finding out the existence of an object that was on the subsequence we can only move forward but not back since order
// now if iterator to the element in the subsequence is equal to the iterator the subsequence then we shall move the subsequence iterator forward as well as the main sequence pointer forward

// time and space complexity analysis 
// time 0(N)  where N is the length of the main array. this is the worst case scenario
// space 0(1) we are not storing anything that will increase in  size with the increase of the main array


// solution 2

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
  int arrIndx = 0;
  int seqIndx = 0;
  while (arrIndx < size(array) && seqIndx < size(sequence))
    {
      if(array[arrIndx] == sequence[seqIndx])
      {
        seqIndx += 1;
        if(seqIndx == sequence.size())
        {
          return true;
        }
      }
    arrIndx += 1;  
    }
  
  return false;
}

// basically the time complexity of this function is 0(N)

// to go through other solutions 

//solution 3
/*
Explanation
This is just a little bit leaner than the solution provided by algo expert that is using a raw index to iterate over the sequence array.
The method is the same:
Iterate over the input `array`. For every element, check if that is in the `sequence`. If it is in there, look for the next element in the `sequence` further in the `array`.
When you have fully stepped through the `sequence`, you know that all its elements are also found in the `array` (and are found in the same order).*/

using namespace std;

bool isValidSubsequence(vector<int> array , vector<int> sequence)
{
    auto sequence_itr = sequence.begin();
    for(auto it = array.begin(); it<array.end(); it++)
    {
        if(*sequence_itr == * it)
        {
            sequence_itr += 1;
        }
        if(sequence_itr == sequence.end() )
        {
            return true;
        }
    }
    return false;
}

//much easier solution 4

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence)
{
    int seq_ind = 0;
    for(int i=0; i < array.size(); i++)
    {
        if(sequence[seq_ind] == array[i])
        {
            seq_ind ++;
        }
    }
    return (seq_ind == sequence.size());      
}