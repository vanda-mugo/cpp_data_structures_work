#include <iostream>

template <typename T, typename U, typename V>
class ClassName
{
private:

    T m_memberT;
    U m_memberU;
    V m_memberV;
public:
    ClassName(T t1, U u1, V v1)
    :m_memberT(t1), m_memberU(u1), m_memberV(v1)
    {
        // overloaded constructor 
    }

    void printVar()
    {
        std::cout << " var U1: " << m_memberU << std::endl;
        std::cout << " var T1: " << m_memberT << std::endl;
        std::cout << " var V1: " << m_memberV << std::endl;
    }

};

int main()
{
    ClassName<int, double , int> obj1(7, 6.7, 6);
    std::cout << " obj values " << std::endl;
    obj1.printVar();

    ClassName<double, char, bool> obj2(9.8, 'b', false);
    obj2.printVar();

    return 0;
}