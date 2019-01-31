#include <iostream>

using namespace std;

const int maxsize = 10;
int raw_seq[maxsize] = {3,4,1,2,8,9,10,7,11,5};
int sorted_seq[maxsize];

void bubble_sort()
{
    for(int i=0;i<maxsize;i++)
    {
        for(int j=i+1;j<maxsize;j++)
        {
            if(raw_seq[j]<raw_seq[i])
            {
                int tmp = raw_seq[i];
                raw_seq[i] = raw_seq[j];
                raw_seq[j] = tmp;
            }
        }
    }
}


void select_sort()
{
    for(int i=0;i<maxsize;i++)
    {
        int k = i;
        for(int j=i;j<maxsize;j++)
        {
            //注意比较时的细节，小于号右边为K
            if(raw_seq[j]<raw_seq[k])
            {
                k = j;
                //cout <<"k1 "<<k<<" ";
            }
        }
        //cout <<"k2 "<<k<<" ";
        int tmp = raw_seq[i];
        raw_seq[i] = raw_seq[k];
        raw_seq[k] = tmp;
    }
}


void insert_sort()
{
    for(int i=1;i<maxsize;i++)
    {
        int j = i;
        int tmp = raw_seq[i];
        while(j>0 && tmp<raw_seq[j-1])
        {
            raw_seq[j] = raw_seq[j-1];
            j--;
        }
        raw_seq[j] = tmp;
    }
}


int main()
{
    //bubble_sort();
    //select_sort();
    insert_sort();
    for(int i=0;i<maxsize;i++)
        cout << raw_seq[i]<<" ";
}