/*
MIDDLE NODE
youre given a linked list with at least one node. write a function that returns the middle node of the linked list . if there are two middle nodes
(i.e. and even lenght list ), your function should return the second of these nodes.
Each linked list node has an integer value as well as a next node pointing to the next node in the list or to none/null if its the tail of the list
*/

// sample input = 2 -> 7 -> 3 ->5
// sample output // the middle could be 7 or 3
// 3 -> 5 // we return the second middle node 

// solution 
using namespace std;

// This is an input struct. Do not edit.
// the algoritm takes O(N) time and 0(1) space
class LinkedList 
{
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) 
  :value{value} {}
//{ this->value = value; }
};

LinkedList* middleNode(LinkedList* linkedList) 
{
  // Write your code here.
  //initialise count to be equal to 0
  int count = 0;
  LinkedList* current = linkedList;
  while(current != nullptr)
    {
      count += 1;
      current = current->next;
      continue;
    }
  LinkedList* midNode= linkedList;
  for(int i = 0; i < count/2; i++)
    {
      midNode = midNode->next;
    }
  return midNode;
}

// since their are two loops you may think that the time complexity would be 0(N`2) but this is not the case 
// this is because even though we are iterating through the linked list twice the loops are not nested within each other  
// henceforth the time complexity basically remains to be 0(N)


// solution 2
using namespace std;
// slow and fast pointer solution

// This is an input struct. Do not edit.
class LinkedList 
{
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) 
  :value{value} {}
//{ this->value = value; }
};

LinkedList* middleNode(LinkedList* linkedList) 
{
  // Write your code here.
  if(linkedList->next == nullptr)
  {
    return linkedList;
  }

  // initialising two pointers one to be fast and the other to be slow
  // essentially when the slow pointer moves by one step the fast pointer moves by two steps
  LinkedList* fast{linkedList};
  LinkedList* slow{linkedList};

  while(fast != nullptr && fast->next != nullptr)
    {
      fast = fast->next->next;
      slow = slow->next;
    }
  return slow;
}
// the concept here is that lets say given a linked list with even numbers and a linked list with odd number of elements 
// what will happen is that 

/*
lets say the even linked list is as follows
2->5->6->9->5->2->7->10 
the above linked list has an even number 8 of elements 
when the slow pointer moves one step onto the node with value of 5 , then the fast pointer moves faster to the node with value of 
6 in this case since it moves two steps per iteration so the fast will point to 6 and slow to 5
step : fast , slow 
1        6     5
2        5     6
3        7     9
4       null   5

in this case the value of fast will be equal to null and therefore the loop will terminate and slow will be assigned value of 5 as expected from 
the promt definition that is when we have two values that signify the middle node , the second of the two will be the one that is selected 
that is having 9 and 5 , 5 will be the value that is expected as the returned result from this run

2->5->6->9->5->2->7

if the number of nodes would be even then the above would happen 
step : fast , slow 
1        6     5
2        5     6
3        7     9

since in the next iteration the value of fast->next would be null in this case the value that would be returned as the middle would be 9 
as slow would be assigned the value of 9

*/