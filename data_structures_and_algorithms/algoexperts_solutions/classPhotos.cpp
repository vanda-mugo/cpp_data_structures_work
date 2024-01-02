/*
its photo day at the local school, and youre the photographer assigned to take class photos. the class that you will be photographying has an even number 
of students , and all this students are wearing red or blue shirts. In fact, exactly half of the class is wearing red and the other half is wearing blue,
you are responsible for arranging the students in two rows before taking the photo.Each row should contain the same number of students and should adhere
to the following guidelines.
    *ALL STUDENTS WEARING RED SHIRTS MUST BE IN THE SAME ROW
    *ALL STUDENTS WEARING BLUE SHIRTS MUST BE IN THE SAME ROW
    *EACH STUDENT IN THE BACK ROW SHOULD BE STRICTLY TALLER THAN THE STUDENT DIRECTLY IN FRONT OF THEM IN THE FRONT ROW
    
youre given two input arrays; one containing the heights of all the students with red shirts and another containing the heights of all the students 
with blue shirts, there arrays will have the same lengths, and each height will be a positive integer. write a function that returns whether or not a
class photo that follows the stated guidelines can be followed 
assume that each class has at least 2 students 
*/

// solution 1 
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
//using namespace std;
// this is called a greedy algorithm
// time complexity 0(NlogN)
// space 0(1)

/*
THE TIME COMPLEXITY IS SUCH THAT WE NEED TO SORT BOTH THE BLUE AND THE RED SHIRTS AND THIS 
WILL BASICALLY TAKE 2[Nlog(N)]
this will equate to Nlog(N)
since we need to loop through this arrays then 
2[Nlog(N)] + N
since N < NlogN
we can say :-
N = NlogN
which equates to 3[Nlog(N)]

*/
bool classPhotos(std::vector<int> redShirtHeights, std::vector<int> blueShirtHeights) 
{
  // Write your code here.
  std::sort(redShirtHeights.begin(), redShirtHeights.end(), greater<int>());
  std::sort(blueShirtHeights.begin(), blueShirtHeights.end(), greater<int>());

  std::string backRowColor; 
  if(redShirtHeights[0] > blueShirtHeights[0] )
  {
    backRowColor = "redShirt";
  }
  else
  {
    backRowColor = "blueShirt";
  }

  for(int i = 0; i < redShirtHeights.size(); i++)
    {
      int redShirtHeightsvalue = redShirtHeights[i];
      int blueShirtHeightsvalue = blueShirtHeights[i];
      if(backRowColor == "redShirt")
      {
        if(redShirtHeightsvalue <= blueShirtHeightsvalue)
        {
          return false;
        }
      }
      else if(backRowColor == "blueShirt")
      {
        if(blueShirtHeightsvalue <= redShirtHeightsvalue)
        {
          return false;
        }
      }    
    } 
  return true;
}


// solution 2
// explanation 
// firstly sort the array then compare teh array, check an array is strictly greater or lower all elements than another  
#include <vector>
using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) 
{
  sort(redShirtHeights.begin(), redShirtHeights.end());
  sort(blueShirtHeights.begin(), blueShirtHeights.end());
  int greater = 0, lower = 0, n = blueShirtHeights.size();

  for(int i=0; i < n; i++)
    {
      if(redShirtHeights[i]>blueShirtHeights[i])greater++;

      else if(redShirtHeights[i] < blueShirtHeights[i])lower++;
    }
    
  // Write your code here.
  return greater == n || lower == n;
}


//solution 3

// the above solution basically checks for consistency in the heights of the students 
// with this now it becomes clear that if one of the rows should be at the back and the other at the front there should exist consistency in the differences
// of heights between sorted students in each of the categories 
// that is if the differences are ++ they should be ++ throughout or if the differences are -- then it should be the same 
// if one of the values are not consistent then that means that the students cannot be taken a photo as the required conditions 
#include <vector>
#include <algorithm>

bool classPhotos(std::vector<int> redShirtHeights, std::vector<int> blueShirtHeights)
{
  std::sort(redShirtHeights.begin(), redShirtHeights.end());
  std::sort(blueShirtHeights.begin(), blueShirtHeights.end());
  for(int i = 0; i < redShirtHeights.size(); i++)
    {
      if((blueShirtHeights[i] - redShirtHeights[i]) * (blueShirtHeights[0] - redShirtHeights[0]) <= 0)
      {
        return false;
      }
    }
  return true;
}




