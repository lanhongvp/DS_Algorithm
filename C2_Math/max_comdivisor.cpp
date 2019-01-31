#include<iostream>

using namespace std;

int gcd(int a,int b)
{
    if(b==0) 
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
    int a,b;
    cin>>a>>b;

    int max_comdivisor = gcd(a,b);
    cout<<max_comdivisor<<endl;

    int min_lcm = a/max_comdivisor*b;
    cout<<min_lcm;
}