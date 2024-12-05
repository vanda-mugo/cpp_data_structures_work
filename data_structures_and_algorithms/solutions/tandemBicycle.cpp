/*
A tandem bicycle is a bicycle that is operated by two people: a person A and a person B. both people pedal the bike, but the person that pedals 
faster dictates the speed of the bike. So if person A pedals at a speed of 5 and person B pedals at a speed of 4, then the bike moves at a speed
of 5, that is tandemSpeed = max(speedA, speedB)

youre given two lists of positive integers: one that contains teh speeds of riders wearing red shirts and one that contains the speed of riders wearing 
blue shirts.Each rider is represented by a single positive integer, which is the speed that they pedal a tandem bike at. Both lists have the same length
, meaning that there are as many red shirt riders as they are blue shirts riders. your goal is to pair every rider wearing red shirt to operate a tandem
bike

write a function that returns the maximum possible total speed or the minimum possible total speed of all the tandem bikes being ridden based on an input 
parameter, fastest. if fastest = true, your function should return the maximum possible total speed; otherwise it should return the minimum total speed.

'total speed' is defined as the sum of the speeds of all the tandems bikes being ridden. for example,if there are 4 riders (2 red shirt riders and 2 blue
shirt riders ) who have speeds of 1,3,4,5, and if theyre paired on tandem bikes as follows : [1,4], [5,3], then the total speed of the tandem bikes is 
4+5 = 9
 */

// solution 1 

#include <vector>
#include <algorithm>
//using namespace std;
// the algorithm runs in 0(NlogN)


int tandemBicycle(
  std::vector<int> redShirtSpeeds, std::vector<int> blueShirtSpeeds, bool fastest
) {
  // Write your code here.
  std::sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
  std::sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());

  int totalSpeed = 0;
  if(fastest)
  {
    // finding the maximum possible speed 
    // complexity of the reverse function for a vector is o(N)
    std::reverse(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
    // in this case we have reversed the vector. one of the vectors  
  }
  
  for(int i = 0; i < blueShirtSpeeds.size(); i++)
    {
      totalSpeed += std::max(blueShirtSpeeds[i], redShirtSpeeds[i]);   
    }
  return totalSpeed;
}
// since you have to revese one of the vectors if youre looking for the maximum speed 
