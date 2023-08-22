/*
theres an algorithm tournament taking place in which teams of programmers compete against each other to solve an 
algorithmic problem as fast as possible. teams compete in a round robin where each team faces off against all other teams, 
only two teams compete against each other at a time, and for each competition, one team is designated the home team, while 
the other team is the away team, in each competiotion theres always one winner and one loser; there are no ties. A team receives 
3 points if it wins and o points if it loose, the winner of the tournament is the team that receives the most amount of points.

Given an array of pairs representing the teams that have competed against each other and an array containing the results of each
competition, write a function that returns the winner of the tournament, the input arrays are named [competition] and [results], 
respectively. the [competition] array has elements in the form of [homeTeam, awayTeam], where each team is a string of at most 30 
characters representing the name of the team, the [results] array containing the information about the winner of each corresponding
competition in the [competiotions] array, specifically, [results[i]] denotes the winner of the competitions[i], where a 1 in the [results]
array means that the home team in the corresponding competition won and -0 means the away team won.

it is guaranteed that exactly one team will win the tournament and that each team will compete against all the other teams exactly once.
its also guaranteed that the tournament will always have atleast two teams*/



#include <vector>
#include <utility>
#include <string>
#include <map>

// if its an array it would be as so 
// recall array initialisation 
// type array_name[num_of_elements]

//solution 1 
// this solution has a bad time complexity cause it features 
#include <vector>
//using namespace std;

  std::string tournamentWinner(
  std::vector<std::vector<std::string>> competitions, std::vector<int> results
) {
  // create a map object 
    std::map<std::string, int> resultsMap;
  // Write your code here.
  for(int i = 0; i <results.size(); i++)
    {
      if(results[i] == 1)
      {
        // this means that the home team won
        // to first check if its in the map object is in the map
        if(resultsMap.count(competitions[i][0]))
        {
          resultsMap[competitions[i][0]] += 3;
        }
        else
        {
          // this is the circumstance by which this value is not in the map
          // we now just insert it into the map 
          resultsMap[competitions[i][0]] = 3;
        }
      }
      else if(results[i] == 0)
      {
        // in this case the away team has won the competiotion 
        if(resultsMap.count(competitions[i][1]))
        {
          // in this case the value exists in the map
          resultsMap[competitions[i][1]] += 3;
        }
        else
        {
          // value exists not in the map
          resultsMap[competitions[i][1]] = 3;
        }
      }

    }
    std::string winnerName = "";
    int winnerMarks = 0;
    for( std::map<std::string, int>::iterator itr = resultsMap.begin(); itr != resultsMap.end();
      itr ++)
      {
        if(itr->second > winnerMarks )
        {
          winnerName = itr->first;
          winnerMarks += itr->second;
        }
      }
  return winnerName;
}

// an array of pairs representing teams that have competed against each other 
// array of the results of each competition
// note by that the input is a vector that contains vectors . a vector of vectors with each nested vector 
// being of type string 

// to tabulate the exact time complexity of the above solution 



// solution 2

// we can be able to have one for loop

#include <vector>
#include <unordered_map>
//using namespace std;

std::string tournamentWinner(
  std::vector<std::vector<std::string>> competitions, std::vector<int> results
) {
  // Write your code here.
  std::unordered_map<std::string, int> points;
  int i = 0;
  int maxPoints = 0;
  std::string bestWinner = "";
  
  while(i < competitions.size())
    {
      std::string winner = competitions[i][!results[i]];//this has to be explained 
      //lets say for competitions[i] the results is 1, this means that home team has won 
      //so  !results[i] wuill mean that the home team which is the first one will be the one since its at index 0 of the 
      // nested vector input of competition
      // if the results were 0 means that away team won and therefore the negation will mean 1 which in this case is
      // the position of the away team on nested vector 
      if(std::unordered_map<std::string, int>::iterator search = points.find(winner) ; search != points.end())
      {
        points[winner] += 3;// this will mean that the key is not found
      }
      else
      {
        points[winner] = 3; 
      }

      if(points[winner]>maxPoints)
      {
        maxPoints = points[winner];
        bestWinner = winner;
      }
      i++;
    }
  
  
  return bestWinner;
}


// std::find is used to search for specific key in an unordered map
// unordered_map.find(key)

// example of sample input
/*
competitions =[
  ["HTML", "C#"],
  ["C#", "PYTHON"],
  ["PYTHON","HTML"]
]
results = [0,0,1]

*/

//solution 3
#include <vector>
#include <iostream>
#include <unordered_map>
//using namespace std;

std::string tournamentWinner
(std::vector<std::vector<std::string>> competitions, std::vector<int> results) 
{
  // Write your code here.
  std::unordered_map<std::string, int> scores;
  
  int winnerMarks = 0;
  std::string bestTeam = "";
  
  // in theory we shall be looping across the results array as well as the competitions array
  for(int i = 0; i < competitions.size(); i++)
    {
      std::string winnerTeam = competitions[i][!results[i]];
      //to get winner in each team
      if(auto search = scores.find(winnerTeam); search != scores.end())
      {
        scores[winnerTeam] += 3;
      }
      else
      {
        scores[winnerTeam] = 3;
      }
      
      if(scores[winnerTeam] > winnerMarks)
          {
            winnerMarks = scores[winnerTeam];
            bestTeam = winnerTeam;          
          }
    }
  return bestTeam;
}

// solution to run in 0(N) time and 0(K) space 
// n is the number of competitions that shall be there, number of results 
//
//k is the number  of teams 


// solution 4
#include <vector>
#include <iostream>
#include <unordered_map>
//using namespace std;

std::string tournamentWinner
(std::vector<std::vector<std::string>> competitions, std::vector<int> results) 
{
  // Write your code here.
  std::unordered_map<std::string, int> scores;
  
  int winnerMarks = 0;
  std::string bestTeam = "";
  
  // in theory we shall be looping across the results array as well as the competitions array
  for(int i = 0; i < competitions.size(); i++)
    {
      std::string winnerTeam = "";
      //to get winner in each team
      if(results[i] == 1)
      {
        winnerTeam = competitions[i][0];
        if(scores.count(winnerTeam))
        {
          scores[winnerTeam] += 3;
        }
        else
        {
          scores[winnerTeam] = 3;
        }
      }

      else if(results[i] == 0)
      {
        winnerTeam = competitions[i][1];
        if(scores.count(winnerTeam))
        {
          scores[winnerTeam] += 3;
        }
        else
        {
          scores[winnerTeam] = 3;
        }
      }
      
      if(scores[winnerTeam] > winnerMarks)
          {
            winnerMarks = scores[winnerTeam];
            bestTeam = winnerTeam;          
          }
    }
  return bestTeam;
}

// solution to run in 0(N) time and 0(K) space 
// n is the number of competitions that shall be there, number of results 
//
//k is the number  of teams 
