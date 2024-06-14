/*
deque

sometimes you find yourself in a situation in which you need to add elements both in the beginning and end of a sequence 
a std::deque is the best to use in such a circumstance which means double-ended queue.

it allows fast insertion and deletion at both its beginning and its end. in addition, insertion  and deletion at either 
the end of a deque never invalidates pointers or references to the rest of the elements 

As opposed to std::vector, the elements of a deque are not stored contiguously: typical implementations use a sequence of individually allocated fixed-size arrays, with additional bookkeeping, which means indexed access to deque must perform two pointer dereferences, compared to vector's indexed access which performs only one.

The storage of a deque is automatically expanded and contracted as needed. Expansion of a deque is cheaper than the expansion of a std::vector 
because it does not involve copying of the existing elements to a new memory location. On the other hand, deques typically have large minimal 
memory cost; a deque holding just one element has to allocate its full internal array (e.g. 8 times the object size on 64-bit libstdc++; 
16 times the object size or 4096 bytes, whichever is larger, on 64-bit libc++). 

complexity of common operations on deques as follows 

random access 0(1)
insertion and removal of elements at the end or beginning of  0(1)
insertion or removal of elements - linear 0(n)

not by unlike vectors contiguous storage allocation may not be guaranteed

*/

// CPP Program to implement Deque in STL
#include <deque>
#include <iostream>

using namespace std;

void showdq(deque<int> g)
{
	deque<int>::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		cout << '\t' << *it;
	cout << '\n';
}

int main()
{
	deque<int> gquiz;
	gquiz.push_back(10);
	gquiz.push_front(20);
	gquiz.push_back(30);
	gquiz.push_front(15);
	cout << "The deque gquiz is : ";
	showdq(gquiz);

	cout << "\ngquiz.size() : " << gquiz.size();
	cout << "\ngquiz.max_size() : " << gquiz.max_size();

	cout << "\ngquiz.at(2) : " << gquiz.at(2);
	cout << "\ngquiz.front() : " << gquiz.front();
	cout << "\ngquiz.back() : " << gquiz.back();

	cout << "\ngquiz.pop_front() : ";
	gquiz.pop_front();
	showdq(gquiz);

	cout << "\ngquiz.pop_back() : ";
	gquiz.pop_back();
	showdq(gquiz);

	return 0;
}


/*
Methods
	Description


push_back()
	inserts element at the back


push_front()
	inserts element at the front


pop_back()
	removes element from the back


pop_front()
	removes element from the front


front()
	returns the element at the front


back()
	returns the element at the back


at()
	sets/returns the element at specified index


size()
	returns the number of elements


empty()
	returns true if the deque is empty
*/