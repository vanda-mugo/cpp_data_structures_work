/*
OPTIMAL FREELANCING
you recently started a freelance software development and have been offered a variety of job opportunities.Each job has a deadline, meaning there
is no value in completing the work after the deadline. Additionally, each job has an associated payment representing the profits for completing the job
Given this information write a function that returns the max profit write a function that returns the max profits that can be obtained in a 7 day period

each job will take 1 full day to complete and the deadline will be given as the number of the days left to complete the job. for example if a job
has a deadline of 1, it can only be completed if its the first job worked on . if  a job has a deadline of 2 then it could be started on the first 
or second day

note : there is no requirement to complete all the jobs, Only one job can be worked on at a time.Meaning that in some scenarios it will be impossible to 
complete them all
*/

/*
jobs = [
    {"deadline" : 1, "payment":1},
    {"deadline" : 2, "payment":1},
    {"deadline" : 2, "payment" :2}
]*/


// solution 1
//using namespace std;
#include <vector>
#include <algorithm>

int optimalFreelancing(std::vector<unordered_map<string, int>> jobs)
{
  // the parameter input is a std::unordered_map that contains the string and int values 
  // Write your code here.
  // we shall sort based on the payment 
  // sorting will be O(NlogN) and iterating O(N)
  // so time complexity will be O(NlogN)
  // space complexity O(1) constant space operation 
  int profits = 0;
  std::vector<std::pair<int,int>> sortedJobs;// creating a vector that contains pairs 
  for(const auto job : jobs)// the const so as to not be able to change the values for the job being iterated over
    {
      // note by that in this case the job variable is a single element of type pair , since each element in the input vector is a unordered_map element 
      // recall the methods of std::unordered_map the at() method in which the used value/key in the parameter equates to the key element 
      // the return is the reference to the mapped value of the element with a key value equivalent 
      sortedJobs.push_back(std::make_pair(-job.at("payment"), job.at("deadline")));
      // the sortedJobs will basically be a vector that contains pairs that in this case contains payments and deadlines of the different jobs
    }

  std::sort(sortedJobs.begin(), sortedJobs.end());
  // in this case the sort function will sort based on the first element of the pair 
  // the negative on the jobs.at("payment") will ensure that since its sorting in ascending order that the highest payment in this case will have the 
  // smallest negative number and henceforth will be the first element 
  std::unordered_set<int> deadlines;
  for(const auto job : sortedJobs)
    {
      // note that job in this case refers to  one element of the sorted pair which in this case happens to be a pair
      // so pair.second will in this case be the deadline

      if(deadlines.size() == 7) break;
      for(int i = job.second; i >= 1; i--)
        {
          //so in this case note that the for loop basically iterates over the values of deadline and each step what happens is that the 
          // deadline of each job is checked if it is equal to the deadline.end(), in this case the .end() returns the iterator to the 
          // end which in this case is not an element of the set 
          //lets say the work has a deadline of 3
          //itll check for the element 3 in the , in this case if the value 3 is not found that will mean that it will return deadlines.end()
          // in this case the deadlines will have the value of 3 shall be inserted in the unordered_set
          // if the value is found within the deadlines this will mean that said day has already been taken and therefore cannot be assigned 
          if(deadlines.find(i) == deadlines.end())
          {
            deadlines.insert(i);
            profits -= job.first;
            // since payments were in negative this will essentially mean that the values will be added

            break;
          }
        }
    }
  
  
  return profits;
}
