#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxsize = 3e4+5;
int N,M,K;

struct student
{
    string id;
    int score;
    int location;
    int local_rank;
}stu[maxsize];

bool cmp(student a,student b)
{
    if(a.score != b.score) 
        return a.score > b.score;
    else 
        return a.id<b.id;
}

int main()
{
    cin>>N;

    string stu_id;
    int stu_score;
    int num = 0;
    //student a;
    for(int i=0;i<N;i++)
    {
        cin>>K;
        for(int j=0;j<K;j++)
        {
            cin>>stu_id>>stu_score;
            stu[num].id = stu_id;
            stu[num].location = i+1;
            stu[num].score = stu_score;
            num++;
        }
        sort(stu+num-K,stu+num,cmp);
        stu[num-K].local_rank = 1;
        for(int j=num-K+1;j<num;j++)  //边界条件细节的把握
        {
            if(stu[j].score==stu[j-1].score)
                stu[j].local_rank = stu[j-1].local_rank;
            else
                stu[j].local_rank = j+1-(num-K);  //注意此时的local_rank的写法
        }
    }
    cout << num<<endl;
    sort(stu,stu+num,cmp);
    int g_rank=1;
    for(int i=0;i<num;i++)
    {
        cout << stu[i].id<<" "; //global rank输出时的同分，不同分的排名情况
        if(i>0 && stu[i].score!=stu[i-1].score)
        {
            g_rank = i+1;
            cout <<g_rank<<" ";
        }
        else
            cout << g_rank<<" ";
        cout <<stu[i].location<<" "<<stu[i].local_rank<<endl;
    }
}

/*
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
*/