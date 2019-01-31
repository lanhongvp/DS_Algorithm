#include<iostream>

using namespace std;

const int maxsize=11;
int n,p[maxsize];
int hashtable[maxsize]={0};

// 递归程序
void permutation(int index)
{
    //边界条件
    if(index==n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<p[i];
        }
        cout<<endl;
        return;
    }
    //递归部分
    for(int i=0;i<n;i++)
    {
        cout<<"out_i "<<i<<endl;
        if(hashtable[i]==0)
        {
            p[index] = i;
            hashtable[i] = 1;
            permutation(index+1);
            cout<<"i "<<i<<" "<<"in "<<index<<" ";
            hashtable[i] = 0; 
            //cout<<"xiix "<<i<<" ";
        }
    }

}

//main
int main()
{
    cin>>n;

    permutation(0);
}