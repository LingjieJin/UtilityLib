#include <stdio.h>
#include <iostream>


int main()
{
    std::string a = "用地名称";
    char c;

    for (int  i = 0; i < a.size(); i++)
    {
        c = a.at(0);
        std::cout << c <<std::endl; 
    }
    
   


    return 0;

}