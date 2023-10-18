/*
youre given the hrad of a singly linked list whose nodes are in sorted order with respect to their values.Write a function that returns a modified
version of the linked list that doesnt contain any nodes with duplicate values. the linked list should be modified in place(i.e you shouldnt create a 
brand new list ), and the modified linked list should still have its nodes sorted with respect to their values.
Each linkedList node has an integer value as well as a next node pointing to the next node in the list or none/null if its tail of the the list 
*/

// solution 1
// runs in 0(N) time complexity 
using namespace std;

// This is an input struct. Do not edit.
// solution takes 0(N) time 
// even though you see two while loops the solution runs in 0(N) 
// since there is never a time that the same value is iterated over twice

class LinkedList 
{
 public:
  int value;
  LinkedList* next = nullptr;// a pointer of type linked list , the linked list is a class , therefore a pointer to a class member of type linked list 
  

  LinkedList(int value) 
  : value{value}
  {}
// note by within the initialisation list you cannot use this because the whole idea of the initialisation list is to 
// initialise valued of the class attributes to the object that is being created and henceforth in this case the object is not created already as compared to the 
// constructor body assignment that is commented below here where the object is already created and in this case the this basically refers to
// the object that has already been created and therefore a pointer to this object 
  //{this->value = value;}
  // overloaded constructor with the int value as a parameter 
};

LinkedList* removeDuplicatesFromLinkedList(LinkedList* linkedList) 
// note by this function returns a pointer to a linked list object or member and the input parameter is a linked list pointer 
{
  // Write your code here.
  // initialising a pointer to the current linked list node 
  LinkedList* current = linkedList; // in this case the initialised value is equal to the 
  // the initialised value is equal to the passed argument that is of type linked list and is a pointer of the same 
  while(current->next != nullptr)
    {
      // note by that the class linked list has two attributes that are the value and the next 
      // the value is the value of the current  node in the linked list 
      // the next is a pointer that points to the next node in the linked list 
      // we check if the next value is a duplicate of the current node 
      if(current->value == current->next->value)
      {
        // in this case we have a duplicate occurence in the linked list 
        current->next = current->next->next;
        continue; //note that continue breaks one iteration of the loop 
      }
      // update the current node 
      //and in this case progress to the next node 
      current = current->next;
    }
  return linkedList;
}

// note by the above solution has some memory leak associated with  it 


// solution without memory leak 
using namespace std;
// solution without memory leak
// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value)
: value{value} {}
//{ this->value = value; }
};

LinkedList* removeDuplicatesFromLinkedList(LinkedList* linkedList) 
{
  // Write your code here.
  LinkedList* current = linkedList;
  while(current && current->next)
    {
      if(current->value == current->next->value)
      {
        LinkedList* toDel = current->next;
        current->next = current->next->next;
        delete toDel;
        continue;
      }
      current = current->next;
    }
  return linkedList;
}
