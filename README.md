# C++ Data Structures and Algorithms

Welcome to the C++ Data Structures and Algorithms repository! This repository contains implementations and explanations of various data structures and algorithms in C++.

## Table of Contents
1. [Data Structures](#data-structures)
   - [Node](#node)
   - [Linked Lists](#linked-lists)
   - [Stacks](#stacks)
   - [Queues](#queues)
   - [Heaps (Max and Min)](#heaps-max-and-min)
   - [Graphs](#graphs)
   - [Trees](#trees)
2. [Algorithms](#algorithms)
   - [Binary Search](#binary-search)
   - [Dijkstra's Algorithm](#dijkstras-algorithm)
   - [Depth-First Search (DFS)](#depth-first-search-dfs)
   - [Breadth-First Search (BFS)](#breadth-first-search-bfs)
   - [A* Search](#a-search)
   - [Sorting Algorithms](#sorting-algorithms)
   - [Greedy Algorithms](#greedy-algorithms)
   - [Naive Algorithms](#naive-algorithms)

---

## Data Structures

### Node
A Node is a fundamental part of data structures like linked lists and trees. It typically contains data and references to other nodes.

```cpp
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


The above are different implementations of same solutions that indicate different approaches and the resulting space and time complexity in each case. To investigate the use of different STL data structures in C++ and corresponding effect. 
