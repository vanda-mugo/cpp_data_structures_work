/*
Nth fibonacci
the fibonacci sequence is defined as follows: the first number of the sequence is 0, the second number is 1, the nth number is the sum of the (n-1)th
numbers. write a function that takes in an integer n and returns the nth fibonacci number .

important note: the fibonacci sequence is often defined with its first two numbers as f0 = 0 and f1 = 1. for the purpose of this question , the first 
fibonacci number is F0; therefore getNthFib(1) is equal f0, getNthFib(2) is equal to f1 etc
*/

// sample input #1
// n =2

// solution 1
#include <map>
using namespace std;

// so its important to note the following 
// for a fibonacci sequence its defined with the first number being 0 and the second being 1 and the concept is as follows
// to get the value of  a fibonacci number is to add the sum of the two fibonacci numbers before the said nth fibonacci and in this case applies to numbers above the second number
/*
eg get the following :
0, 1, 1, 2, 3, 5, 8, 13, 21, 34
as you can see from the sequence above index 1 that has value 1 , that the number following operate in such a way that 
if you add the two preceding numbers you get the value of the fibonacci number 
fib(n) = fib(n-1) + fib(n-2) for n > 2 , when the n index starts at 1 in this case

you can think of a solution 

if(n == 1)
{
return 0;
}
else if(n == 2)
{
return 1;
}
else{
return fib(n-1) + fib(n-2);
} 
time complexity : 2`n
this is not the best solution and can be explained as follows

lets say you are finding the fib(6)

                                                              fib(6)
                                                            /        \
                                                        fib(5)        fib(4)
                                                       /     \         /     \
                                                    fib(4)  fib(3)   fib(3)  fib(2)
so as you can tell the list will go on and on and to some extent you can even notice the use and occurence of the repeated values with which 
the fibonacci is supposed to be calculated for 
in this case this fails to be a good solution 

so why is it 2`n 
when we start at fib(6) note that with each fib we call two more fibs, each of the two fibs call two fibs and so on and so forth 
so each fib calls 2 fibs and therefore this basically converges to n times 

space complexity will be o(n)
since its a recursive function we shall end up using alot in the function call stack and this is because of all the recursive fibs that are being called 
during the entire lifetime in the call stack we shall have at most n calls , beyond that we hit base cases and start deleting frames on the call stack 
at any given time we are storing at most n calls 

the smarter solution whereby we store some of the values of certain fibs that is in memoize, so in this case what happens is that we use a form of hash table 
that is if n is in memoize, return the memoize(n) that is if we have a certain solution to a certain fibonacci we wont need to calculate this values again 

if(n in memoize)
 return memoize[n]
else
 memoize[n] = fib(n-1) + fib(n-2)
 return memoize[n]

this will now run in 
0(n) Time, and you may ask why is this the case :-
this is because we shall have to calculate each fibonacci once 
space complexity will remain to be 0(n) since we have the call stack recursive operartion and also we have the memoize function that stores n solutions 
therefore having the space complexity of 0(n)


best method is the iterative solution that will be explained above 
step one 

have an array of the two fibonacci numbers 
[0, 1] which are the first two fibonacci numbers 

so then we start calculating any fib number thereafter
so eg fib(6)
while the counter is less that or equal to n then just keep calculating the next fibonacci number

the next fibonacci number will be equal to 0 + 1 = 1, at first 
when we calcualate next we take the first element of the array and remove it and replace it with the second number in the array 
[1, ] in this case we take the next fib number and insert it as the next element in the array so in this case the next will be 1
[1, 1]
the next nuumber in this iteration will be 1 + 1 = 2
next array [1, 2]
next number 3
next array [2, 3]
next number 5
next array
[3,5]
next number 8 
at any time we are just storing two number and doing the next calculation with constant time
time = 0(n) since we have to calculate n fibonacci numbers therefore have to calculate for n fibonacci numbers
but space wise itll be 
0(n) since we are not using any space recursively and only two values which in this case is constant space 


  */

int getNthFib(int n) 
{
  // Write your code here.

  // this is the naive solution
  // runs in 0(2`n) and 0(n) space
  if(n == 2)
    return 1;
  else if(n == 1)
      return 0;
  else
    return getNthFib(n-1) + getNthFib(n-2);
  return -1;
}


// solution 2
// using the memoize function 
//using namespace std;

// will run in 0(n) time and 0(n) space
int getNthFib(int n, std::map<int, int> memoize = {{1,0}, {2,1}})
// note by the use of the has table in the memoize one
// note also that we have gave this variable a default value which is the initialised map that is {{1,0}, {2,1}}

{
  // Write your code here.
  // using memoization 

  if(memoize.find(n) != memoize.end())
  {
    return memoize[n];
  }
  else
  {
    // lets say that they call the function as follows 
    /*
      getNthFib(6)
      6 is not in memoize so memoize[6] = getNthFib(5, memoize(default)) + getNthFib(4, memoize(default))
      since 5 is not in memoize
      getNthFib(5) = 
      memoize[5] = getNthFib(4) + getNthFib(3)
      since memoize[4] not in memoize
      memoize[4] = getNthFib(3) + getNthFib(2)
      in this case 
      3 is not in memoize
      memoize[3] = getNthFib(2) + getNthFib(1)
      since 1 and two are in memoize then this will be equal to 
      memoize[3] = getNthFib(2) (== 1) + getNthFib(1) (== 0) hence memoize[3] = 1

      so in this case memoize[3] will be in the map
      calling function of memoize[3] was 
      memoize[4] = getNthFib(3) + getNthFib(2)
      in this case we have both the getNthFib(3) = 1 and memoize(2) 1

      memoize[4] == 2
      the calling function for memoize[4] was memoize[5] = getNthFib(4) + getNthFib(3)
      memoize(5) = 2 + getNthFib(3) which is memoize[3] == 1
      memoize[5] = 3
      calling function of memoiz[5] was
      memoize[6] = getNthFib(5, memoize(default)) + getNthFib(4, memoize(default))
      which in this case will be 
      memoize[6] = 3 + 2
      return will be 5
      the above is a simple explanation of how the function operates

      
*/
    memoize[n] = getNthFib(n-1, memoize) + getNthFib(n-2, memoize);
    return memoize[n];
  }
  return -1;
}


//solution 3
// will run with best complexity of time 0(N) and space complexity of 0(1)
using namespace std;

int getNthFib(int n) {
  // iterative solution 
  // Write your code here.
  int lastTwo[] = {0, 1};
  // the counter is 3 because we already have two values in the array for the first two values of the fibonacci sequence 
  int counter{3};
  while(counter <= n)
    {
      int nextFib = lastTwo[0] + lastTwo[1];
      lastTwo[0] = lastTwo[1];
      lastTwo[1] = nextFib;
      counter += 1;
    }
  if(n > 1)
  {
    return lastTwo[1];
    // if n = 0, then that is an edge case since the n will signify the first element in the fibonacci sequence
  }
  else
  {
    return lastTwo[0];
  }
}
/*
lets say you are given the above 
fib(6) then note the above 
6 > 3
when counter is 3, nextFib = 1
when counter is 4, next fib = 2
when counter is 5, next fib = 3
when counter is 6, next fib = 5
*/
