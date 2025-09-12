#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stcktp1.h"

const int Num = 10;

int main()
{
    std::srand(std::time(0));
    std::cout << "Please enter stack size: ";
    int stackSize;
    std::cin >> stackSize;

    Stack<const char *> st(stackSize);

    const char * in[Num] = {
        "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "ten"
    };
    const char * out[Num];
    int processed = 0;
    int nextin = 0;
    while (processed < Num)
    {
        if (st.isEmpty())
            st.push(in[nextin++]);
        else if (st.isFull())
            st.pop(out[processed++]);
        else if (std::rand() % 2 && nextin < Num)
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
    }
    for ( int i = 0; i < Num; i++)
        std::cout << out[i] << std::endl;
    std::cout << "Done!\n";
    return 0;
}