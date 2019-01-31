#include<iostream>
#include<algorithm>

using namespace std;
const int maxsize=100;

struct line
{
    int x,y;
}line_seq[maxsize];

bool cmp(line a,line b)
{
    if(a.x!=b.x)
        return a.x>b.x;
    else
        return a.y<b.y;
}

int main()
{
    int n;
    cin>>n;

    int x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        line_seq[i].x = x;
        line_seq[i].y = y;
    }

    sort(line_seq,line_seq+n,cmp);
    int last_x = line_seq[0].x;
    cout <<last_x<<line_seq[0].y;
    for(int i=1;i<n;i++)
    {
        if(last_x>=line_seq[i].y)
        {
            cout<<line_seq[i].x<<line_seq[i].y;
            last_x = line_seq[i].x;
        }
        else
            continue;
    }
}

/*
4
1 3
2 4
3 5
6 7
*/