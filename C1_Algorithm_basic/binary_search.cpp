#include<iostream>

using namespace std;
const int maxsize = 100;

int seq[maxsize] = {1,3,4,5,5,5,6,7,8};

void binary_search(int search_num,int search_len)
{
    int left=0;
    int right=search_len;
    int mid = (left+right)/2;

    if(seq[mid]==search_num)
        cout<<mid;
    else
    {
        while(seq[mid]!=search_num)
        {
            if(seq[mid]>search_num)
            {
                right = mid;
                mid = (left+right)/2;
            }
            else if(seq[mid]<search_num)
            {
                left = mid;
                mid = (left+right)/2;
            }
        }
        cout<<mid;
    }
}


void binary_search_1(int search_num,int search_len)
{
    int left=0;
    int right=search_len;
    int mid;

    while(left<=right)
    {
        mid = (left+right)/2;
        if(seq[mid]==search_num) 
        {
            cout<<mid;
            break;
        }
        else if(seq[mid]>search_num)
            right = mid - 1;
        else
            left = mid - 1; 
    }
}


int lower_bound(int search_num,int search_len)
{
    int left = 0;
    int right = search_len;
    int mid;

    while(left<right)
    {
        mid = (left+right)/2;
        if(seq[mid]>=search_num)
        {
            right = mid;
        }
        else
            left = mid+1;
    }
    return left;
}


int upper_bound(int search_num,int search_len)
{
    int left = 0;
    int right = search_len;
    int mid;

    while(left<right)
    {
        mid = (right+left)/2;
        //cout <<mid;
        if(seq[mid]<=search_num)
        {
            left = mid+1;
        }
        else
        {
            right = mid;
            return right;
        }
    }
   return right;
}

int main()
{
    int search_num = 5;
    int search_len = 9;

    //binary_search_1(search_num,search_len);
    //int lower = lower_bound(search_num,search_len);
    //cout<<lower;
    int upper = upper_bound(search_num,search_len);
    cout <<upper;
} 