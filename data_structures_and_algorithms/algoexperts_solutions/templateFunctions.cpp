//Function templates 

/*
we write a generic function that can be used for different data types. eg sort(), max(), min() and printArray()
*/

#include <iostream>

// one function works for all data types 
template<typename T>
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

template<class M>
M minMax(M x, M y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << myMax<int>(3,5) << std::endl;
    std::cout << myMax<double>(5.6, 7.7) << std::endl;

    std::cout << minMax<int>(7, 5) << std::endl;
    std::cout << minMax<double>(9.9, 6.5) << std::endl;
    return 0;
}

// compiler internally generates the code below for both int and double 

