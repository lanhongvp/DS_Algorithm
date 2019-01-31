#include <iostream>

using namespace std;
const int maxsize=100;

int n,k,length;
int stick[maxsize];

int max_length(int max_split)
{
    int left=1,right=max_split;
    int mid;
    int num_cnt=0;

    while(1)
    {
        mid = (left+right)/2;
        for(int i=0;i<n;i++)
        {
            num_cnt += stick[i]/(mid);
        }
        cout<<"num_cnt "<<num_cnt<<" ";
        if(num_cnt==k)
            return mid;
        else if(num_cnt>k)
        {
            left = mid+1;
            num_cnt = 0;
        }
    }
}

int main()
{
    cin>>n>>k;

    int sum_length=0;
    for(int i=0;i<n;i++)
    {
        cin>>length;
        stick[i] = length;
        sum_length += length;
    }
    int max_split = sum_length/k;
    cout <<"max split "<<max_split<<" ";
    int max_len = max_length(max_split);
    cout <<max_len;
}

/*
3 7
10 24 15
*/