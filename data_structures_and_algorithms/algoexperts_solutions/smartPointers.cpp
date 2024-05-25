/*
Smart pointers in C++ are objects that act like pointers but provide automatic memory management and ownership 
semantics. They help eliminate many of the pitfalls associated with raw pointers, such as memory leaks and 
dangling pointers. C++ provides three main types of smart pointers in its standard library: std::unique_ptr, 
std::shared_ptr, and std::weak_ptr.

1. std::unique_ptr:

    A std::unique_ptr is a smart pointer in C++ that represents sole ownership of a dynamically allocated object. 
    It is part of the C++ Standard Library's smart pointer family, introduced in C++11, and it provides automatic 
    memory management with strict ownership semantics.

    kindly note the aspect of dynamically allocated objects 

    Ownership: Unique ownership (one owner at a time).
    Memory Management: Automatically deallocates memory when the std::unique_ptr goes out of scope.

    Here are some key characteristics of std::unique_ptr:

    Unique Ownership:
        A std::unique_ptr cannot be shared or copied. It represents exclusive ownership of the managed object.
        When a std::unique_ptr goes out of scope or is explicitly reset, it automatically deallocates the memory 
        associated with the managed object.

    Automatic Memory Management:
        The memory allocated for the object is automatically released when the std::unique_ptr is destroyed.
        This automatic cleanup helps prevent memory leaks and simplifies resource management.

    Move Semantics:
        std::unique_ptr supports move semantics, allowing efficient transfer of ownership between unique pointers.
        This facilitates the transfer of ownership without the need for copying.

    Array and Custom Deleters:
        std::unique_ptr can manage arrays, and it can be customized to use a custom deleter for special resource
        management needs.

    Nullptr Initialization:
        A std::unique_ptr can be initialized with nullptr or can be default-initialized to represent an empty 
        (non-owning) state.
*/

#include <iostream>
#include <memory>

void uniquePtrExample() {
    // Creating a unique pointer
    std::unique_ptr<int> uniquePtr(new int(42));

    // Accessing the value
    std::cout << "Value: " << *uniquePtr << std::endl;

    // Automatically deallocates memory when it goes out of scope
} // Memory is automatically freed when uniquePtr goes out of scope

// expound on different ways of initialisation of smart poiters in c++

//direct initialisation
std::unique_ptr<int> uniquePtr1(new int(42));

/*
Key Features: of std::make_unique

    Exception Safety:
        std::make_unique provides better exception safety compared to directly using new. 
        If an exception occurs during object creation, std::make_unique ensures proper cleanup without leaking memory.


    Avoiding new and delete:
        You don't need to use new and delete explicitly, reducing the risk of memory leaks and making the code more 
        concise.

    Type Deduction:
        The template type (T) is deduced from the type of the arguments passed to the constructor. This eliminates 
        the need to specify the type explicitly.
*/

// using the std::make_unique
// for the initialisation using std::make_unique use the = sign 
// no use of new
std::unique_ptr<int> ptr1 = std::make_unique<int>(423);
// using std::make_unique is preffered because it is 
/*
i . is more concise 
ii. avoids potential memory leaks associated with exception handling ( exception safety )
iii. is more efficient in certain cases 
*/

// intialization with nullptr

std::unique_ptr<int> uniquePtr2(nullptr);

// initialization with standard move 

std::unique_ptr<int> uniquePtr3(new int(456));
std::unique_ptr<int> uniquePtr4 = std::move(uniquePtr3);

// initialisation with custom deleters 
#include <memory>

struct CustomDeleter {
    void operator()(int* ptr) const {
        // Custom deletion logic
        delete ptr;
    }
};

std::unique_ptr<int, CustomDeleter> uniquePtr5(new int(42));


// array initialisation 

std::unique_ptr<int[]> uniquePtr6(new int[5] { 7,4,6,3,5});

// iniitialisation with a lambda deleter 
#include <memory>

auto customDeleterLambda = [](int* ptr) {
    // Custom deletion logic
    delete ptr;
};

std::unique_ptr<int, decltype(customDeleterLambda)> uniquePtr6(new int(42), customDeleterLambda);


// initialisation of objects with custom constructors

class MyClass {
public:
    MyClass(int value, const std::string& name) : value_(value), name_(name) {}

    void display() const {
        std::cout << "Value: " << value_ << ", Name: " << name_ << std::endl;
    }

private:
    int value_;
    std::string name_;
};

int main() {
    // Creating a unique pointer for an object with custom constructor
    auto uniquePtrCustom = std::make_unique<MyClass>(42, "Custom Object");

    uniquePtrCustom->display();

    return 0;
}


// using std::make_unique with custom deleters 


struct CustomDeleter {
    void operator()(int* ptr) const {
        std::cout << "Custom deleter called." << std::endl;
        delete ptr;
    }
};

int main() {
    // Creating a unique pointer with a custom deleter
    auto uniquePtrCustomDeleter = std::make_unique<int, CustomDeleter>(new int(42));

    return 0;
}




/*
2. std::shared_ptr:

    Ownership: Shared ownership (multiple std::shared_ptr instances can share ownership of the same object).
    Reference Counting: Keeps track of the number of std::shared_ptr instances owning the object.
    Memory Management: Automatically deallocates memory when the last std::shared_ptr owning the object is destroyed.

    Additional Considerations:

    Prefer std::make_shared: Use std::make_shared instead of new for creating objects managed 
    by std::shared_ptr to avoid potential memory leaks.
*/


void sharedPtrExample() {
    // Creating a shared pointer
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(42);
    
    // Creating another shared pointer that shares ownership
    std::shared_ptr<int> sharedPtr2 = sharedPtr1;

    // Accessing the value
    std::cout << "Value: " << *sharedPtr1 << std::endl;

    // Memory is automatically freed when the last shared pointer is destroyed
} // Memory is automatically freed when sharedPtr1 and sharedPtr2 go out of scope]

//Avoid Circular References: Be cautious when using std::shared_ptr to avoid circular references 
//that could prevent objects from being deallocated.

// Circular reference example (can cause memory leaks)
class Node {
public:
    std::shared_ptr<Node> next;
};

std::shared_ptr<Node> node1 = std::make_shared<Node>();
std::shared_ptr<Node> node2 = std::make_shared<Node>();
node1->next = node2;
node2->next = node1;  // Circular reference



/*
3. std::weak_ptr:

    Ownership: Does not contribute to the reference count.
    Useful for Breaking Cycles: Can be used with std::shared_ptr to break reference cycles.
*/

#include <iostream>
#include <memory>

void weakPtrExample() {
    // Creating a shared pointer
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(42);

    // Creating a weak pointer
    std::weak_ptr<int> weakPtr = sharedPtr;

    // Using weak_ptr to create a shared_ptr
    if (auto sharedPtrFromWeak = weakPtr.lock()) {
        std::cout << "Value: " << *sharedPtrFromWeak << std::endl;
    } else {
        std::cout << "Object has been destroyed." << std::endl;
    }
} // Memory is automatically freed when sharedPtr goes out of scope
