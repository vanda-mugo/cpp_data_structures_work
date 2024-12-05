/*
there are two candy shops both of which have N candies for sale.the first sells each candy 
for one golden coin the second shop sells each candy for one silver coin. You have N/2 golden coins
and N/2 silver ones.N is even

each candy of a particular type not necessarily unique represented by an integer. What is the 
max number of each different type of candy that you can buy 

write a function 
int solution(vector<int> &A, vector<int>&B);

That giveb two arrays A and B of N integers, representing types of candles in the first 
and second shop respectively, returns the maximum number of different types of candy that 
you can buy 

example 
A = [1,2,3,4]
B = [3,3,3,7]
the function should return 4. You can for example buy candles of type 1 ,2  or 3, 4 or 2, 3,from the 
first shop and 3, 7 in the second shop

write an efficient algorithm
*/

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <bits/stdc++.h>


int solution(std::vector<int> &A, std::vector<int> &B)
{
    /*
    in this I shall investigate the differences brought about by the different use of std::map and the 
    std::unordered_map 
    
    in std::set ordering is done in increasing order while in the std::unordered_set their is no ordering
    
    in the implementation the set is a self balancing BST while the unordered_set is a hash table
    
    set search time is log(n) while the unordered_set 0(1) average while 0(n) worst case 

    insertion of set is log(n) + rebalance while unordered_set(same as search)

    use unordered_set when we need to place a set of distinct elements and no ordering is required 

    
    */

   int AN_size = A.size()/2;
   int BN_size = B.size()/2;
   int n = A.size();

   std::unordered_set<int> A_diffElements;
   std::unordered_set<int> B_diffElements;

   for(int i = 0; i < n; i++)
   {
    if(!A_diffElements.find(A[i]))
    {
        A_diffElements.insert(A[i]);
    }
    if(!B_diffElements.find(B[i]))
    {
        B_diffElements.insert(B[i]);
    }
   }
   int Amax = 0;
   int Bmax = 0;

   if(A_diffElements.size() >= AN_size )
   {
        Amax = AN_size;
   }

   else
   {
        Amax = A_diffElements.size();
   }

   if(B_diffElements.size() >= BN_size)
   {
    Bmax = BN_size;
   }

   else
   {
    Bmax = B_diffElements.size();
   }
   return Amax + Bmax;


}

int main()
{
    std::vector<int> test1vec{2,4,5,6,6,76,23,12,2,2,2,2,2,5};
    std::vector<int> test2vect{6,4,6,2,5,3,6,3,6,3,24,5,6,34,};

    std::cout << solution(test1vec, test2vect);

    return 0;
}