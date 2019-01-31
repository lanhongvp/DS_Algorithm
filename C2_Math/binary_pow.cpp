#include<iostream>

using namespace std;
typedef long long LL;

LL binary_pow_recursion(LL a,LL b,LL m)
{
    if(b==0)
        return 1;
    else if(b%2==0)
    {
        LL mul = binary_pow_recursion(a,b/2,m);
        return mul*mul%m;
    }
    if(b%2==1)
    {
        return (a*binary_pow_recursion(a,b-1,m))%m;
    }
}


LL binary_pow_iteration(LL a,LL b,LL m)
{
    LL ans=1;

    while(b>0)
    {
        cout <<b<<" ";
        if(b&1)
        {
            ans = ans*a%m;
        }
        a = a*a%m;
        b >>=1;
    }
    return ans;
}


int main()
{
    LL a,b,m;

    cin >>a>>b>>m;
    LL result = binary_pow_recursion(a,b,m);
    cout <<result<<endl;
    LL result_1 = binary_pow_iteration(a,b,m);
    cout <<result_1<<endl;
}

/*
2 5 3
*/