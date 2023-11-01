/*
write a function that takes in a non empty string and returns its runLength encoding. from wikipedia "run length encoding is a form of lossless data
compression in which runs of data are stored as a single data value and count, rather than as the original run." for this problem a run of data is any 
sequence of consecutive , identical characters, so when the run "AAA" would be run length encoded as "3A"
to make things more complicated, however, the input string can contain all sorts of special characters, including numbers. And since encoded data must be 
decodable, this means that we cant naively run lenght encode long runs, for example the run "AAAAAAAAAAAA" ( 12 As), cant naively be encoded as "12A" since
this string can be decoded as either "AAAAAAAAAAAA" or "1AA" . thus long runs( runs of more than 10 characters) should be encoded in a split fashion;
the aforementionaed run should be encoded as "9A3A"
*/

// the time complexity is 0(N)
// the space complexity is 0(N)
// basically the space complexity is 0(2N) this is because at most or at worst case scenario we shall add the amount of letters in the string multiplied 
// by 2
// lets say that the ABCD the character list will be [1A1B1C1D], Therefore we would have to add two times the number of all the elements in the list 

// the time complexity will be creating a list and setting the length to 1 then we shall have for loop to loop over all characters of the string
// then within the for loop we shall be having constant time operations so therefore we shall have 0(N) time complexity for the for loop 

// then after the for loop we shall have to change the characters list to a string , to convert a list of characters to a string will take 0(N) time
// in the case that we have 2N characters eg ABCD then you would say that the it will take 0(2N) time to convert the above to a string 

// so as far as time is concerned lets say that conclusively it shall take 0(N) + 0(N) = 20(N) which in this case is basically 0(N)


// solution 1
// time complexity 0(N)
// space complexity 0(N)

using namespace std;

string runLengthEncoding(string str) {
  // Write your code here.
  std::vector<char> encodedStringCharacter;
  int currentRunLength = 1;// we can set this to one since we know that the current 
  // passed string cannot be empty
  for(int i = 1; i < str.length(); i++)
    {
      char currentChar = str[i];
      char previousChar = str[i - 1];
      if(currentChar != previousChar || currentRunLength == 9)
      {
        // in this case the if will be true if the char variables are not the same
        // or if the currentRunLength == 9 , so in this case the counter shall be reset
        // if one of the conditions is true then we shall add the run to the list 
        // otherwise we shall increment the currentRunLength
        encodedStringCharacter.push_back(std::to_string(currentRunLength)[0]);
        // the reason we have [0] is because the string value returned is a string and therefore this is the 
        // first element of the string
        encodedStringCharacter.push_back(previousChar);// the reason we are taking the
        // previous character is because the previous charcter would have been the end 
        // of the longest run that we had just found
        currentRunLength = 0;
        // this is because we have just added the longest run or the previous run that we had just found. 
        // in the case that the run length is 9 then even if the next char is similar to the previous char then 
        // the current run will be added 
      }
      // in the case that the currentChar is equal to previousChar and counter not equal to 9 then the currentRunLength should increase by 1
      // so because if we found any run or if the if was true then currentRunLength would be zero and in this case it shall be set to 1
      currentRunLength += 1;  
    }
    // to handle the last run the above shall take place
    encodedStringCharacter.push_back(std::to_string(currentRunLength)[0]);
    encodedStringCharacter.push_back(str[str.size() - 1]);
    // this is cause of teh last element in the string 
    // check the above examples ABCD  OF ABCCC
    // With ABCD the last element will not be equal to the previous and therefore the if will be true.
    // in this case the currentRunLength is reset to zero and the C in this case will be added 
    // in the next run the for loop wont run since the index will be greater than the size therefore the last element should be added to the vector of char
  
  return std::string(encodedStringCharacter.begin(), encodedStringCharacter.end());
}


// solution 2
using namespace std;
// time complexity 0(N)
// space complexity 0(N)


string runLengthEncoding(string str) {
  // Write your code here.
  std::vector<char> encodedString;

  for(int i = 0; i < str.size(); i++)
    {
      int currentRunLength = 1;
      while(str[i] == str[i + 1] && currentRunLength < 9)
      {
        currentRunLength ++;
        i++;
      }
      encodedString.push_back(std::to_string(currentRunLength)[0]);
      encodedString.push_back(str[i]);
    }
  //here is a method that converts the vector char to std::string in c++
  // this is one method of converting which uses the containers begin iterator 
  // this also utilises the containers end iterator 
  return std::string(encodedString.begin(), encodedString.end());
}


