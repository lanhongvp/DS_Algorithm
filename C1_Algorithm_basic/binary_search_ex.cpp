#include<iostream>

using namespace std;
double eps=1e-5;

double sqrt(double x)
{
    return x*x;
}

double binary_sqrt(double left,double right,double result)
{
    double mid;
    while(right-left>=eps)
    {
        mid = (left+right)/2;
        if(sqrt(mid)>=result)
        {
            right = mid;
        }      
        else
        {
            left = mid;
        }        
    }
    return mid;
}

int main()
{
    double sqrt_result = binary_sqrt(1,2,2);
    cout << sqrt_result;
}