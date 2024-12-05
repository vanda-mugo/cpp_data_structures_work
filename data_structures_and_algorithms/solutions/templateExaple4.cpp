#include <cassert>
#include <iostream>

template <typename T>
class Array
{
private:
    int m_length{};
    T* m_data;

public:
    Array(int length);
    Array(const Array&) = delete;
    Array &operator=(const Array&) = delete;
    ~Array();
    void erase();
    T& operator[] (int index);
    int getLength() const;

    
};

template <typename T>
Array<T>::Array(int length)
{
    assert(length > 0);
    m_data = new T[length];// allocated an array of objects of type T
    m_length = length;
}

template <typename T>
Array<T>::~Array()
{
    delete [] m_data;
}

template <typename T>
void Array<T>::erase()
{
    delete [] m_data;
    // we have to ensure we set the m_data to nullptr to ensure that its not pointing to a 
    // deallocated memory
    m_data = nullptr;
    m_length = 0;
}

template <typename T>
int Array<T>::getLength() const 
{
    return m_length;
}

template<typename T>
T& Array<T>::operator[](int index)
{
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

int main()
{
    const int length{12};
    Array<int> intArray{length};
    Array<double> doubleArray{length};

    for(int count{0}; count < length; ++count)
    {
        intArray[count] = count + 0.5;
    }

    for(int count{length - 1}; count >= 0; --count)
    {
        std::cout << intArray[count] << '\t' << doubleArray[count] << std::endl;
        
    }
    return 0;
}