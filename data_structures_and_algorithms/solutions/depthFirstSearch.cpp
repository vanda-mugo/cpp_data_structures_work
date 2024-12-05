/*
Depth First Search
youre given a node class that has a name and an array of optional children nodes. when put together , the nodes form an acyclic tree like structure.
implement the depthFirstSearch method on the node class, which takes in an empty array traverses the tree using depth first seach approach 
( specifically navigating the tree from the left to the right ), stores all of the nodes names in the input array and returns it 

if youre unfamiliar with depth first seach watch the overview section of this questions explanation before starting to code 


Sample input 
graph   =   A
          / | \
         B  C  D
        / \   / \
       E   F G   H
          / \  \
         I   J  K

Sample output 
["A", "B", "E", "F", "I", "J", "C", "D", "G", "K", "H"]


HINT 1
 the depth first search algorithm works by traversing a graph branch by branch. In  other words, before traversing any node's sibling nodes, its children
 nodes must be traversed. How can you simply and effectively keep track of nodes' sibling nodes as you traverse them, all the while retaining the order 
 in which you must traverse them?


 HINT 2
 start at the root node and try simply calling the depth first search method on all of its children nodes. then call the depthfirstSearch method on all 
 children nodes of each child node. keep applying this logic until the entire graph has been traversed. dont forget to add the current nodes name to the 
 input array at every call of depthFirstSearch


 optimal space and time complexity 
 0(v + e) time | 0(v) space where v is the number of vertices of the input graph and e is the number of edges of the input graph
*/

//solution 
#include <vector>
#include <string>
using namespace std;

// Do not edit the class below except
// for the depthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node 
{
 public:
  string name;
  std::vector<Node*> children;// this is a vector that will contain pointers to the members of class Node

  // overloaded contructor that passes in the argument that is str
  // was assigned within the constructor but will change this to be an initialization list 
  Node(string str) 
  :name{str} // constructor initialization list 
  {}
  //{ name = str; }

  std::vector<string> depthFirstSearch(std::vector<string>* array) 
 {
   // this shall run in 0(v + e) time and 0(v) space
   // method that takes parameter that is a pointer of type std::vector<string>
   // the method returns a vector of type string 
    // Write your code here.
   // first step is to add the name of the node to the array 
   // so we shall call push back on the array given which in this case is a pointer 
   array->push_back(this->name);

   // for every child that the current node has we run the DFS on it 
   for(Node* child : this->children)
     {
       child->depthFirstSearch(array); // note that the argument expects a pointer as the parameter passed 
     }
   //return the dereferenced pointer 
    return *array;
  }

   Node* addChild(string name) 
 {
   // a method that returns a pointer to the member of type Node class and has a name string argument parameter 
    Node* child = nullptr;
    child = new Node(name);// dynamic memory allocation in the heap 
    children.push_back(child);
    return this;
  }
};

// so how does the depth first search work, in this case for every node we shall add that nodes name to the final array
// then for every child node that this node has we shall call the depth first function and then pass the final array 
// for every vertex we iterate throught the children nodes of those vertex and call the depthFirstSearch function 
// when iterating through the children nodes when using a for loop , what is the length of the for loop , this will be however many
// children nodes that we may be having or how many edges are coming out of the current node eg when at A we had 3 edges because we had 3 children nodes coming out of A
// time complexity 0(V + E) where v is the number of vertices in the graph or rather the number of nodes in the given graph
// the space complexity would be 0(v) where this is the worst case complexity think of the fact that if we had a node that scaled down and each child node only had one node 
// then in this case we would have frames for the call of each of the child nodes and the parent node wouldnt be resolved until the last element has been resolves in the branch 
// in this case at a worst scenario we would have call frames for all the vertex of the graph at a given point 
// then E is the number of edges that is like the connection from one node to another 


/*

some notes and to revisit the depth first search algorithm
What is Depth First Search?

Depth First Search (DFS) is a graph traversal algorithm that starts at the root node and explores as far as possible along each branch before backtracking.
 It is an algorithm for traversing or searching tree or graph data structures. The DFS algorithm traverses a graph in a depth-ward motion and uses a stack to
  remember to get the next vertex to start a search, when a dead end occurs in any iteration.*/


