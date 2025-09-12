#include <iostream>
#include <cfloat>
bool hmean(double,double,double*);
int main()
{
    double x,y,z;
    std::cout << "enter two number.\n";
    while(std::cin >> x >> y)
    {
        if(hmean(x,y,&z))
            std::cout << "Harmonic mean of "<< x << " and " << y << " is " << z << std::endl;
        else
            std::cout << "One value should not be the negative of the other -try again.\n";
        std::cout << "Enter next set of numbers <q to quit>.\n";
    }
    std::cout << "Bye!\n";
    return 0;

}

bool hmean(double x, double y,double* z)
{
    if (x == -y)
    {
        *z = DBL_MAX;
        return false;
    }else
    {
        *z = 2.0 * x*y/(x+y);
        return true;
    }
    
}