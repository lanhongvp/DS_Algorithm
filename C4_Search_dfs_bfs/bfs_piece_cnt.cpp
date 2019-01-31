#include<iostream>
#include<vector>
#include<queue>

using namespace std;
const int maxsize = 100;

int n,m;
int inque[maxsize][maxsize]={0};
int matrix[maxsize][maxsize];
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};

struct node
{
    int x;
    int y;
};



bool boundery(int x,int y)
{
    if(x>m||y>n||x<0||y<0) 
        return false;
    else 
        return true;
}


void bfs(int x,int y)
{
    node start_node;
    queue<node> q;
    start_node.x = x;
    start_node.y = y;
    inque[start_node.x][start_node.y] = 1;
    q.push(start_node);

    while(!q.empty())
    {
        node top_node = q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            node new_node;
            new_node.x = top_node.x+X[i];
            new_node.y = top_node.y+Y[i];

            if(boundery(new_node.x,new_node.y))
            {
                if(matrix[new_node.x][new_node.y]==1 && inque[new_node.x][new_node.y]==0)
                {
                    inque[new_node.x][new_node.y] = 1;
                    q.push(new_node);
                }
            }
        }
    }
    
}


int main()
{
   cin >>n>>m;

   int value;
   // matrix input
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           cin >>value;
           matrix[i][j] = value;
       }
   } 

   int cnt = 0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(matrix[i][j]==1 && inque[i][j]==0)
           {
                cnt++;
                bfs(i,j);
           }
       }
   }
   cout << "cnt "<<cnt;
}

/*
6 7
0 1 1 1 0 0 1
0 0 1 0 0 0 0
0 0 0 0 1 0 0
0 0 0 1 1 1 0
1 1 1 0 1 0 0
1 1 1 1 0 0 0
*/