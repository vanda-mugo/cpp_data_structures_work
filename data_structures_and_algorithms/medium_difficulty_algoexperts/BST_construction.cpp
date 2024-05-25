/*
write a BST class for a binary search tree. the class should support:

:inserting values with the insert method 
:removing values with the remove method; this method should only remove the first instance of a given value.
:searching for values with contains method.

Note that you cant remove values from a single-node tree. In other words, calling the remove method on a single node 
tree should simply not do anything.

Each BST node has an integer value, a left child node anmd a right child node. A node is said to be a valid BST node if and only
if it satisfies the BST property. its value is strictly greater than teh values of every node to its left, its value is less than
or equal to the value of every node to its right ; and its children nodes are either valid BST nodes themselves or None/null.

Assuming the following BST has already been created:
                            
                              tree =            10
                                              /    \
                                            5       15
                                           / \      /  \
                                          2   5    13   22
                                         /           \
                                        1             14


                             insert(12) =       10
                                              /    \
                                            5       15
                                           / \      /  \
                                          2   5    13   22
                                         /        /   \
                                        1       12     14   

                             remove(10) =       12
                                              /    \
                                            5       15
                                           / \      /  \
                                          2   5    13   22
                                         /        /   \
                                        1       12     14       

                                contains(15) : true  

a binary tree is basically a data structure that consists of nodes and each node has a value and has two or up to two children , left node and right node
each node in a bst has to satisfy the condition
: A nodes value should be stricly greater than the values of the nodes to its left and a value of node must be less than or equal to values on right
the left and right children nodes as well should also be bst nodes 


methods that the BST class construction should have 

Insertion 
Searching 
Deletion 

: this is for nodes

based on the definition then it would be true to say that for searching and insertion basically you consider the value of the number/node that 
you want to insert 

Deletion : 
this is the removal of a specific value 

its easy if the node to be removed has no children node in the case of our bst deletion of 1 is easy since this will mean that the 
node 2 in this case will have no children node 


                                5                           
                              /   \
                            2      5                
                           / 
                          1 
what happens when we want to delete 2 lets say
if we want to remove the 2 what will happen  is that since you shall remove the two then the child node for the five in this case will remain 1 
                                5
                              /   \
                            1      5
                           
                          
so what will happen is that the 2 shall be removed and in this case the child node to the left for the node that is 5 will be 1

however lets think of a situation where we want to remove the node that is 10

this is the root node 
so what will happen is that you shall grab the smallest value in the right subtree of 10, in other words you grab the left most value in the subtree of 
10 in this case 12

so note that the right sub tree of 10 starts at 15

so in this case we grab the 12 and replace the value of 10 with 12, but in this case since the value that we have taken we know that its greater than
all the values in the left subtree of 10 and being the left most value in the right subtree of 10 we know that its smaller than all the other values
of the subtree to the right 

note that in no circumstance would there be a value less than 10 in the right subtree of 10, this being because the principle of BST dictates that even in
insertion if a value is already greater than 10 then it will be on the right side of 10 however if the value is less than the root node that is 10, 
then automatically itll be on the left side of the root node

so we cannot easily remove 10 just like that because the value has child nodes in this case so we replace the value of 10 with 12, then call the remove 
method on the value that is 12 in the left most part of the right subtree


                              tree =            10
                                              /    \
                                            5       15
                                           / \      /  \
                                          2   5    13   22
                                         /        /   \
                                        1       12     14



after removal of 10 
                               new tree
                                
                                tree =          12
                                              /    \
                                            5       15
                                           / \      /  \
                                          2   5    13   22
                                         /           \
                                        1             14


time complexity : average case 0(log(N))      this complexity is the same for insertion, searching and deletion. its like this cause with each action that
we undertook we did not traverse the whole tree but rather at each point we eliminated half of the subtree/ half of remaining BST. this is why the 
complexity in average

the worst case time complexity is 0(N), in which cases the logic of being able to eliminate half the bst is impossible

eg :                        10
                            |
                            12
                            |
                            13
                            |
                            15
                            |
                            22
                            |
                            33
 this is because there are never any left nodes therefore no eliminations in the number of nodes

 for space this is tricky cause there are two different versions     


1:   if you implement the algoritm recursively it shall run on 0(log(N)) in average
and in worst case scenarios it shall run in 0(N) linear

why is this the case:   imagine the bst below    

                                     tree =     12
                                              /    \
                                            5       15
                                           / \      /  \
                                          2   5    13   22
                                         /           \
                                        1             14

if you are searching lets say the value of 14 the call stack for the algorithm recursively shall be as above whereby we shall have the 
call for the search at node 12
then the call at node 15
then at node 13 
then at 14


if you imagine the call stack to be like a bucket it shall be something like the above : searching for the number 14. which in this case you are
using up frames on the call stack 

                                                |        |
                                                |        |
                                                |        |
                                                | nd 14  |
                                                | nd 13  |
                                                | nd 15  |
                                                | nd 12  |
                                                |________|

so this can be the representation of the call stack and its only at the point that is node 14 that you shall be able to start deleting the used frames in 
the call stack 

this means that there is a point in which the memory usage in the call stack is the branch that was taken  12 - 15 - 13 - 14, in which in this case the 
value of this branch effectively is 0(log(N))
it can also be thought of as 0(logD)  where in this case D is the length of its longest branch/ depth.

in worst case basically is 0(N) because if you have a tree that consist of no left or right branches then the space complexity basically is 0(N) since no 
elimination of half nodes will take place 

however the above solutions only occur if you use the above algoritms recursively however if you do the algorithms iteratively the space complexity changes
to basically 0(1) for both the average case and the worst case scenario
this is because you are not storing frames in the call stack 



so conceptual overview of algoritm involved 

*/



#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST 
{
 public:
  int value;
  BST* left; // pointer to left child node
  BST* right; //pointer to right child node 

  // the above is a class constructor 
  // overloaded constructor that takes in one argument 
  BST(int val) : value{val}, left{nullptr},right{nullptr}
  {    
  }

  BST& insert(int val) 
{
    // Write your code here.
    // Do not edit the return statement of this method.
    if(val<value)
    {
      if(left == nullptr )
      {
        left = new BST(val);// allocate the space in memory for the left pointer
      }
      else
      {
        left->insert(val);// in this case you are calling the insert method on the left node child of current node that is this 
        // now in this case the left will be this or sort of considered the self in the method 
      }      
    }
    if(val >= value)
    {
      if(right == nullptr)
      {
        right = new BST(val);
      }
      else
      {
        right->insert(val);
        //calling the insert method on the right child node which will be the self in the insert.
      }
    }
    return *this;
  }

  bool contains(int val) 
{
    // Write your code here.
    BST* node = this; // in this case you initialise the a pointer of type BST 
    // you are initialising the BST object called node to be this 
    // recall that the this is a pointer 

    //notice that this while loop makes the solution iterative since the loop will continue for all the circumstances that the 
    //node will not be equal to none 
    while(node != nullptr)
      {
        if(node->value == val)
        {
          return true;
        }
        else if(node->value < val)
        {
          node = node->right;
        }
        else
        {
          node = node->left;
        }
      }
      //in the case that the loop has gone through all the child nodes to the last childnode and still no presence of the searched for value
      // in this case the current this node will be null and therefore false will be returned 
    return false;
  }

  BST* deleteNode(BST* root, int key)
  {
    // note by in this case this is the node in which the method has been called 
    // the root node is the this in this function 
    if(root == nullptr)
      return nullptr;
      //in this if case you are checking whether this is a null pointer 
    
    if(key > root->value)
    {
      root->right = deleteNode(root->right, key);
      //note how this function is called 
      // in this case the this pointer is the node *root.right
      // so when you call the  method you call it with the root node and the key you want to remove
      // you are now calling the method on the root->right 
    }
    else if(key < root->value)
    {
      root->left = deleteNode(root->left, key);
    }
    // now to cover the situation where the node has no children nodes

    // the else in this case covers scenarios when the key == root->value
    else
    {
      // the first if to cover the case where the required to be deleted value has no child nodes present
      // this therefore means that there will be no replacement and the value can just be set to null
      if(root->left == nullptr && root->right == nullptr)
      {
        root = nullptr;
        // in this case you have deleted the root node 
      }

      // in this case one of the child nodes is present, in this case has a right child node 
      else if( root->right != nullptr)
      {
        root->value = successor(root);
        // this method returns an int 
        // this method basically returns the left most child node in the right subtree
        root->right = deleteNode(root->right, root->value);
        // get the concept here, now since we have set the value of the root to be deleted as the left most node in the right subtree,
        // then we call the delete method on the right->subtree and the value to be deleted as the value of the root node which in this case 
        // was the left most node in the right subtree
      }

      // in this else the root->right is equal to the null pointer 
      else
      {
        if(root->left == nullptr && root->right == nullptr)
        {
          // now to cover the situation where the node has no children nodes
          root = nullptr;
        }
        else if( root->right != nullptr)
        {
          root->value = successor(root);
          root->right = deleteNode(root->right, root->value);
        }
        else
        {
          root->value = predecessor(root);
          root->left = deleteNode(root->left, root->value);
        }
      }
   }
    return root;
  }

// returns left most child of the right subtree
int successor(BST* root)
{
  root = root->right;
  while(root->left != nullptr)
    {
      root = root->left;
    }
  return root->value;
}

int predecessor(BST* root)
{
  root = root->left;
  while(root->right != nullptr)
    {
      root = root->right;
    }
  return root->value;
}
  

  BST& remove(int val) {
    // Write your code here.
    // Do not edit the return statement of this method.
    // note by that the this pointer in this case is the object of the class by which this method shall be called
    // in the deleteNode method the this pointer is considered the root pointer while the val is the val of the 
    // node to be deleted
    BST* node = this;
    return *deleteNode(node, val);
  }
};



//solution 2
#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val) {
    value = val;
    // so the left and right is initialised since when we initialise a node 
    // they are initialised to nullptr since we dont have values for them.
    left = nullptr;
    right = nullptr;
  }

  BST& insert(int val) 
{
    // Write your code here.
    // Do not edit the return statement of this method.
    BST * currentNode = this;

    //while current node is not none
    while(currentNode)
      {
        if(val >= currentNode->value && currentNode->right == nullptr)
        {
          currentNode->right = new BST(val);
          break;
        }       
        else if( val < currentNode->value && currentNode->left == nullptr)
        {
          currentNode->left = new BST(val);
          break;
        }
  
        if(val >= currentNode->value)
        {
          currentNode = currentNode->right;
        }
        else if(val < currentNode->value)
        {
          currentNode = currentNode->left;
        }
      }  
    return *this;
  }

  bool contains(int val) {
    // Write your code here.
    BST* currentNode = this;
    while(currentNode)
      {
        if(currentNode->value == val)
          return true;
        else if(val >= currentNode->value)
        {
          currentNode = currentNode->right;
        }
        else if(val < currentNode->value)
        {
          currentNode = currentNode->left;
        }
      }
    return false;
  }

  BST& remove(int val, BST* parent = nullptr) {
    // Write your code here.
    // Do not edit the return statement of this method.
    std::vector<BST*> nodeToRemoveData;
    std::vector<BST*> rightSubtreeMinData;

    //finding the data(node and parent) for the node to remove
    nodeToRemoveData = this->getNodeToRemoveData(val, parent);
    BST* nodeToRemoveParent = nodeToRemoveData[0];
    BST* nodeToRemove = nodeToRemoveData[1];

    //node to remove both left and right children
    if(nodeToRemove->left && nodeToRemove->right)
    {
      nodeToRemove->value = nodeToRemove->right->getMinValue();
      nodeToRemove->right->remove(nodeToRemove->value, nodeToRemove);
    }

    else if(!nodeToRemoveParent) this->reassignBindings();

    else if(nodeToRemoveParent->left == nodeToRemove)
      nodeToRemoveParent->left = nodeToRemove->left ? nodeToRemove->left : nodeToRemove->right;
    else if(nodeToRemoveParent->right == nodeToRemove) 
      nodeToRemoveParent->right = nodeToRemove->left ? nodeToRemove->left : nodeToRemove->right;
    return *this;
  }

void reassignBindings()
{
  if(this->left != nullptr)
  {
    this->value = this->left->value;
    this->right = this->left->right;
    this->left = this->left->left;
  }
  else if(this->right != nullptr)
  {
    this->value = this->right->value;
    this->left = this->right->left;
    this->right = this->right->right;
  }
}

int getMinValue()
{
  BST* currentNode = this;
  while(currentNode->left) currentNode = currentNode->left;
  return currentNode->value;
}

//method returns a vector
std::vector<BST*> getNodeToRemoveData(int val, BST* parent)
{
  BST* currentNode = this;

  while(currentNode)
    {
      if(currentNode->value == val)
      {
        break;
      }
      parent = currentNode;
      if(val >= currentNode->value)
        currentNode = currentNode->right;
      else if(val < currentNode->value)
          currentNode = currentNode->left;
    }
  return std::vector<BST*> {parent, currentNode};
}
};

