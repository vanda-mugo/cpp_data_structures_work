/*
takes a year as input 
checks to see if the yearis a four digit number 
displays whether or not the year falls in a leap year 

critria for leap year 
evenly divisible by 4 

*/

#include <iostream>


int main()
{
    std::cout << " Enter  Year " << std::endl;
    int x;
    std::cin >> x;
    int size;

    std::cout << " enter size of array " << std::endl;
    std::cin >> size;
    int arrayInt[];

    for(int i = 0 ; i < size ; i++)
    {
        std::cout << "enter value of year " << std::endl;
        std::cin >> arrayInt[i] ;
    }
    
    if(x > 999 && x < 10000)
    {
        std::cout << " valid " << std::endl;
        if(x%4 == x%100 && x%4 == x%400 )
        {
            std::cout << " The year: " << x << " Is a leap year " << std::endl;
        }
        if(x%4 == x%100 && x%100 != x%400)
        {
            std::cout << " the year: " << x << " is not a leap " << std::endl;
        }


        if(x%4 == 0)
        {
            if(x%100 == 0 && x%400 == 0)
            {
                std::cout << " year  " << x  << " is leap " << std::endl;
            }
            if(x%100 == 0 && x%400 != 0)
            {
                std::cout << " year " << x << " is not leap " << std::endl;
            }
        }

    }
    else 
    {
        std::cout << " Invalid year " << std::endl;
    }


    return 0;
}