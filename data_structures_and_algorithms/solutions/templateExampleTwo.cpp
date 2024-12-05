#include <iostream>

template <class T>
class Array
{
private:
    T* ptr; // pointer of type T
    int size;

public:
    Array(T arr[], int s);
    void print();

};

template<class T>
Array<T>::Array(T arr[], int s)
{
    ptr = new T[s]; // array of type T being created with the name being ptr
    size = s;
    for(int i = 0; i < size; i++)
    {
        ptr[i] = arr[i];
    }
}

template<class T>
void Array<T>::print()
{
    for(int i = 0; i < size; i++)
    {
        std::cout << " value: " << ptr[i] << std::endl;
    }
}

int main()
{
    int arrayInt[5]{1,2,3,4,5}; 
    Array<int> intArray(arrayInt, 5);
    intArray.print();

    double doubleArray[10]{1,2,3,4,5,6,7,8,9,10};
    std::cout << " size " << std::size(doubleArray) << " size 2 " << sizeof(doubleArray) << std::endl;
    //std::cout << " size 3: " << doubleArray.size() << std::endl;
    Array<double> doubleArraysize(doubleArray,10 );
    doubleArraysize.print();
    return 0;
}

/*
sizeof() gives the size in bytes of the passed data structure 

*/