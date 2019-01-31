#include <cstdio>
#include <algorithm>

using namespace std;
const int maxsize = 1e5+5;

struct node{
    int address,key,next;
    int flag;
    node(){}
    node(int _flag){
        flag = _flag;
    }
    node(int _address,int _key,int _next){
        address = _address;
        key = _key;
        next = _next;
    }
}link_list[maxsize];

bool cmp(node a,node b){
    if(a.flag==0 || b.flag==0){
        return a.flag>b.flag;
    }
    else{
        return a.key<b.key;
    }
}

int main(){
    int n,head_address;
    scanf("%d %d",&n,&head_address);

    //flag初始化
    for(int i=0;i<maxsize;i++){
        link_list[i] = node(0);
    }

    int address,key,next;
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&address,&key,&next);
        link_list[i] = node(address,key,next);
        link_list[i].flag = 1;
    }
    sort(link_list,link_list+n,cmp);
    int tmp0 = link_list[0].address;
    printf("%d %05d\n",n,tmp0);
    //while(tmp0!=-1)
    for(int i=0;i<n;i++){
        link_list[i].next = link_list[i+1].address;
        if(i==n-1){
            link_list[i].next = -1;
            break;
        }
    }

    for(int i=0;i<n;i++){
        if(i!=n-1){
            printf("%05d %d %05d\n",link_list[i].address,link_list[i].key,link_list[i].next);
        }
        else{
            //link_list[i].next = -1;
            printf("%05d %d %d\n",link_list[i].address,link_list[i].key,link_list[i].next);
        }
    }
}

