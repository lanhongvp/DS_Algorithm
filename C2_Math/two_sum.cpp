#include<iostream>

using namespace std;

const int maxsize = 100;

int seq[maxsize] = {1,2,3,4,5,6};
int m=8;
int length=6;

int main()
{
    int i=0;
    int j=length-1;

    while(i<j)
    {
        if(seq[i]+seq[j]<m)
            i++;
        else if(seq[i]+seq[j]>m)
            j--;
        else
        {
            cout<<seq[i]<<" "<<seq[j]<<endl;
            i++;
            j--;
        }
    }
}