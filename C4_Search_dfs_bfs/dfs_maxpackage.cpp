#include<iostream>
using namespace std;

const int maxsize = 20;
int n,V,max_value = 0;
int w[maxsize],c[maxsize];

// 递归，岔道口，死胡同

void dfs_package_v1(int index,int sum_w,int sum_c)
{
    //cout << "V"<<V<<" ";
    //cout <<"sum w "<<sum_w<<" ";
    if(index==n)
    {
        if(sum_w<=V && sum_c>max_value)
        {
            max_value = sum_c;
            //cout <<"xixi";
        }
        return;
    } 

    dfs_package_v1(index+1,sum_w,sum_c);
    //cout<<"hha";
    dfs_package_v1(index+1,sum_w+w[index],sum_c+c[index]);
    //cout<<"hehe";
}


void dfs_package_v2(int index,int sum_w,int sum_c)
{
    if(index == n)
        return;
    dfs_package_v2(index+1,sum_w,sum_c);
    if(sum_w+w[index]<=V)
    {
        if(sum_c+c[index]>max_value)
            max_value = sum_c+c[index];
        dfs_package_v2(index+1,sum_w+w[index],sum_c+c[index]);
    }
}


int main()
{
    cin >>n>>V;
    int weight,cnt;
    for(int i=0;i<n;i++)
    {
        cin>>weight;
        w[i] = weight;
    }
    for(int i=0;i<n;i++)
    {
        cin>>cnt;
        c[i] = cnt;
    }
    dfs_package_v2(0,0,0);
    cout<<"max value "<<max_value<<" ";
}

/*
5 8
3 5 1 2 2
4 5 2 1 3
*/