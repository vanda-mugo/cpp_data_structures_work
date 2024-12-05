/*
Minimum Waiting Time 
youre given a non empty array of positive integers representing the amounts of time that specific queries take to execute.only one query can be executed 
at a time, but the queries can be executed in any order.
A querys waiting time is defined as the amount of time that it must wait before its execution starts. In other words, if a query is executed  second,
then its waiting time is the duration of the first query; if a query is executed third then its waiting time is the sum of the first two queries.
write a function that returns the minimum amount of total waiting time for all the queries . eg if youre given the queries of durations [1, 4, 5], then 
the total waiting time if the queries were executed in the order of duration of [5, 1, 4] would be (0) + (5) + (5 + 1) = 11
the first query of 5 would be executed immediately, so its waiting time would be 0, the second query of duration 1 would have to wait 5 seconds( the 
duration of the first query) to be executed , and the last and the last query would have to wait the duration of the first two queries being executed 

note: youre allowed to mutate teh input array 

sample input 
queries = [ 3, 2, 1, 2, 6]
sample output 17

the shortest waiting time is as follows if the queries are worked on at the order in which they occur 
[3, 2, 1, 2, 6]

 |  |  |  |  |
 0  3  5  6  8

 this will give a total waiting time of 22 seconds 
 it is identified that by starting with the queries taking the least time then we shall have the shortest waiting time 

 [1, 2, 2, 3, 6]

  |  |  |  |  |
  0  1  3  5  8

in this case we get the shortest waiting time which is 17

can also be thought of as when at index 0 all the remaining queries will wait a total of 1 * 4 where 4 is the remaining number of queries 

in index 1 the remaining 3 will wait 2 * 3 = 6
when index 2 the remaining 2 will be 2 * 2 = 4
when index 3 the remaining 1 will wait 3 * 1 = 3
in total 4 + 6 + 4 + 3 = 17

*/

using namespace std;
#include <algorithm>
#include <vector>
// this is the greedy algorithm where we decided to check the queries  that take the least time and with this you get to have the least waiting time 
// the reason this is called a greedy algorithm is because we make a greedy choice at each step when we picking an order to select the query to pick, we always pick a query with 
// the least time and this is a greedy choice so hence its called a greedy algorithm 

int minimumWaitingTime(vector<int> queries) 
{
  // Write your code here.
  // the first step should be sort
  std::sort(queries.begin(), queries.end()); // 0(nlogn) time complexity and 0(1) space complexity 
  int total = 0;
  int n = queries.size();
  for(int i = 0; i < n; i++)
    {
      total += queries[i] * (n - i - 1);
    }
  
  return total;
}

// the sort takes 0(n log n) 
// the for loop takes 0(n)
// n log n + n  which can be reduced to 0(n log n)
// space complexity is 0(1) constant space complexity 

