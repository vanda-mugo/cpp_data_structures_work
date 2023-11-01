/*
Generate Document 
youre given a string of available characters and a string representing a document that you need to generate. Write a function that determines if you can 
generate the document using the available characters.if you can generate the document your function should return true otherwise it should return false.

youre only able to generate the document if the frequency of unique characterrs in the characters string is greater or equal to the frequency 
of unique characters in the document string . for example given characters = "a,b,c,a,b,c" and document = "aabbccc" then you cannot generate the document 
since you are missing one c.
the document that you need to create may contain any character, including special characters , capital letters, numbers and spaces
note : you can always generate the empty string ("")

sample input 

characters = "Bste!hetsi ogEAxpert x "

document = "AlgoExpert is the Best!"

sample output = true
*/

// solution with best time complexity 
/*
// solution 3 
// best time complexity 

/*
we shall use a hash map , dictionary etc where we shall have a char and the number of times that this charatcter has occured in the string 

characters = "BSte!hetsi_ogEAxpelrt_x_"
document = "AlgoExpert_is_the_Best!"

lets say that we are at index B in characters all we have to do is check if this character already is in the unsorted_map and in this case 
if its present we add the count with the +1 or if not present just introduce this character with int value of 1 in the document 

so in the case of now the documents string what shall hapen is that lets say we are at index A we shall check if the character occurs in the map and if so reduce the 
integer count in this case by 1

the time complexity of this solution is 0(N + M)
this is because in each case we are only iterating through each element only once 

space complexity is 0(C) where C is the number of unique occurences of a certain characters in our characters string which was used to count the characters string */

using namespace std;

bool generateDocument(string characters, string document) {
  // Write your code here.
  std::unordered_map<char, int> charCountFreq;
  for(auto ch : characters)
    {
      if(charCountFreq.count(ch))
      {
        charCountFreq[ch] += 1;
      }
      else
      {
        charCountFreq[ch] = 1;
      }
    }
  // now we have the unordered map that contains the characters and number of occurences 
  for(auto ch : document)
    {
      if(charCountFreq.count(ch))
      {
        if(charCountFreq[ch] <= 0)
        {
          // means that the count has gone below 
          return false;
        }
        charCountFreq[ch] -= 1;
      }
      else
      {
        return false;
      }
    }
  
  return true;
}
//

// so to check the non optimal solution and then we shall check the most optimal solution 
// the least optimal solutions is as follows 

// iterate through all the characters in the document string, count how many times a said character occurs in the characters list and see if the occurences are valid 
// if the number of times the character occurs in the characters list is greater or equal to the number of times the character occurs in the document list , then in this case 
// we shall know that we can actually reproduce the characters
// so loop over each of the chars in the documnet string and then loop the character occurence in the character list 
// so note that in this solution checks over each and every character in the 
// this solution shall run in 0(M * (N + M))  and this is because we shall loop over the document and in this case its 0(M) and then why we have N + M is because with each 
// character that we are checking within the document we shall then look for it again within the document to see how many times it occurs in the document while also checking 
// how many times the same character will occur within the characters list which in this case will be 0(M * 0(M + N))
// space is 0(1)
// so this is very inefficient algorithm 

/*
so lets say that you have the above characters 
characters = "BSte!hetsi_ogEAxpelrt_x_"
document = "AlgoExpert_is_the_Best!"

so in this case when in the first for loop of document and notice teh A , so when the iterator is at A or index , then we loop through the rest of the chars in the doc 
in this case we are finding how many times the character occurs again 
then we check for the same character and the same occurence within the characters list and check if they occur the same number of times 
this solution shall run in 0(M * (N + M)) time and constant space 
*/
//
// solution 2
// at the beginning of our algorithm we shall create the set counted
// this is an optimization of solution 1 where everything already said in solution 1 holds but in this case now we shall keep record of all the characters that have already been noted 
// after we count one of the characters we shall add it to the set 
/*
so lets say that you have the above characters 
characters = "BSte!hetsi_ogEAxpelrt_x_"
document = "AlgoExpert_is_the_Best!"

so in this case when the index is at A and we count the number of occurences of A within the documet list and count this occuerence within the characters list 
then in this case afterwards we shall then add this character to the set of that containst the characters we counted and therefore when within the docunments list of chars
when going over the index and you find lets say another A then you shall pass it as you already counted and concluded on this character

// so this solution has improved the time complexity 
0(C * (N + M)) so in this case we are still counting the number of character occurences within the document and within the character list the only difference is that in this case we are 
doing it only C times in this case C being the count of characters in the document whereby duplicate occurences are only counted once 
C in this case stands for the number of unique characters that have occured in the document 

C < M where M is the character count in the document and C is only the number of unique occurences in the document list 
*/


// solution 3 
// best time complexity 

/*
we shall use a hash map , dictionary etc where we shall have a char and the number of times that this charatcter has occured in the string 

characters = "BSte!hetsi_ogEAxpelrt_x_"
document = "AlgoExpert_is_the_Best!"

lets say that we are at index B in characters all we have to do is check if this character already is in the unsorted_map and in this case 
if its present we add the count with the +1 or if not present just introduce this character with int value of 1 in the document 

so in the case of now the documents string what shall hapen is that lets say we are at index A we shall check if the character occurs in the map and if so reduce the 
integer count in this case by 1

the time complexity of this solution is 0(N + M)
this is because in each case we are only iterating through each element only once 

space complexity is 0(C) where C is the number of unique occurences of a certain characters in our characters string which was used to count the characters string 
*/




// solution B using iterators 
using namespace std;

bool generateDocument(string characters, string document) {
  // Write your code here.
  // lets see if this can be implemented using iterators 
  std::unordered_map<char, int> charCount;
  std::string::iterator charIter;
  for(charIter = characters.begin(); charIter != characters.end(); charIter ++)
    {
      charCount[*charIter]++;
    }

  for(std::string::iterator docIter = document.begin(); docIter != document.end(); docIter ++)
    {
      if(charCount.find(*docIter) != charCount.end())
      {
        charCount[*docIter] --;
        if(charCount[*docIter] < 0)
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
  return true;
}
