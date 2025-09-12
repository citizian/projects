#include <iostream>
#include <cstdlib>
double hmean(double,double);
int main()
{
    double x,y,z;
    std::cout << "enter two number.\n";
    while(std::cin >> x >> y)
    {
        z=hmean(x,y);
        std::cout << "Harmonic mean of "<< x << " and " << y << " is " << z << std::endl;

    }
    std::cout << "Bye!\n";
    return 0;

}

double hmean(double x, double y)
{
    if (x == -y)
    {
        std::cout << "untenable arguments to hmean()\n";
        std::abort();
    }
    return 2.0 * x*y/(x+y);
}