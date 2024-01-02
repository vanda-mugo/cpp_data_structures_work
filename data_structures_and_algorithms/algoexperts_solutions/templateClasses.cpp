
#include<iostream>


/*
this is a powerful feature that allows you to write generic code. Template classes are used to create a classs
that can work with different data types without having to rewrite the code for each type 
*/

// Declaration of a template class with a generic type 'T'
template<class T>

// name of the class 
class MyTemplateClass
{

private:
    T m_myVariable; // declare a variable of type 'T'

public:
    MyTemplateClass(T intialValue)// constructor and member function to work with generic type 'T'
    :m_myVariable(intialValue)
    {}

    T getValue()
    {
        return m_myVariable;
    }

    void setValue(T newValue)
    {
        m_myVariable = newValue;
    }


};


// class templates declaration 
/*
A class template starts with keyword Template followed by the template parameters inside <> which is followed 
by the class declaration


*/

template <class M>
class ClassName
{
private:
    M tVarType;

public:
    M  functionName(M arg);
};

/*
in this example M is the template argument which is a placeholder for the data type used and class is a keyword

Inside the class body a member variable tVarType and member function functionName() are both of type M
*/


// creating a class template object 
/*
className<dataType> classObject 

for example 

className<int> classObject
className<float> classObject
className<string> classObject 
*/

int main()
{
    // instantiate MyTemplateClass with int 

    MyTemplateClass<int> intobject(34);
    std::cout << " Integer value: " << intobject.getValue() << std::endl;

    MyTemplateClass<double> doubleObject(3.15);
    std::cout << " Double value: " << doubleObject.getValue() << std::endl;
}