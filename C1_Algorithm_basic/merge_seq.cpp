#include<iostream>

using namespace std;
const int maxsize=100;

int A[maxsize] = {1,4,5,6,7};
int B[maxsize] = {2,3,8,9,10};
int C[maxsize];
int n=5;
int m=5;

int main()
{
    int i=0,j=0,index=0;

    while(i<n && j<m)
    {
        //cout<<A[i]<<" "<<B[i];
        if(A[i]<B[j])
        {
            C[index++] = A[i];
            i++;
        }
        else if(A[i]>B[j])
        {
            C[index++] = B[j];
            j++;
        }
        else if(A[i]==B[j])
        {
            C[index++] = A[i++];
            C[index++] = B[j++];
        }
    }
    //cout<<"i "<<i;
    //cout<<"j "<<j;
    while(i<n)
        C[index++] = A[i++];
    while(j<m)
        C[index++] = B[j++];
    //cout<<"index"<<index<<" ";
    for(int i=0;i<index;i++)
        cout<<C[i]<<" ";
}
