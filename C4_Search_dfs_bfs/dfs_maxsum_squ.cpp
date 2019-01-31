#include <iostream>
#include <vector>

using namespace std;

const int maxsize = 100;

int N,K,X;
int A[maxsize] = {0};
int maxsum_squ = -1;
vector<int> ans;
vector<int> tmp;

void dfs_maxsum_squ(int index,int nowk,int sumx,int sumsqu)
{
    //cout << "sumsqu "<<sumsqu<<" ";
    //cout << "sumx "<<sumx<<" ";
    cout << "nowk "<<nowk<<" ";
    cout << "K "<<K<<" ";
    if(nowk==K&&sumx==X)
    {
        cout<<"jaja";
        if(sumsqu>maxsum_squ)
        {
            cout<<"xixi";
            maxsum_squ = sumsqu;
            //ans = tmp;
        }
        return;
    }
    if(index==N||nowk>K||sumx>X)  //死胡同
        return;

    dfs_maxsum_squ(index+1,nowk,sumx,sumsqu);    
    dfs_maxsum_squ(index+1,nowk+1,sumx+A[index],sumsqu+A[index]*A[index]);
    //tmp.push_back(A[index]);     //岔道口
    //tmp.pop_back();
}


int main()
{
    cin>>N>>K>>X;
    
    int num;
    for(int i=0;i<N;i++)
    {
        cin>>num;
        A[i] = num;
    } 
    dfs_maxsum_squ(0,0,0,0);
    cout<<"maxsum squ "<<maxsum_squ;
}

/*
4 2 6
2 3 3 4
*/