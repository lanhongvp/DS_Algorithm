#include<cstdio>
#include<cstring>

const int maxsize=1e5+5;

struct node{
    //int s;
    char a;
    int next;
    int flag;
    node(){}
    node(int _flag){
        flag = _flag;
    }
    node(char _a,int _next){
        a = _a;
        next = _next;
    }  // flag用以判断是否出现在第二个单词中
}word[maxsize];

int main(){
    int s1,s2,n;
    scanf("%d%d%d",&s1,&s2,&n);
    for(int i=0;i<maxsize;i++){
        word[i] = node(0);
    }

    int first,next;
    char a;
    for(int i=0;i<n;i++){
        scanf("%d %c %d",&first,&a,&next);
        word[first] = node(a,next);
    }

    //第一个单词遍历
    int tmp1 = s1;
    while(tmp1!=-1){
        //printf("%d",tmp1);
        word[tmp1].flag = 1;
        tmp1 = word[tmp1].next;
    }

    //第二个单词遍历
    int tmp2 = s2;
    while(tmp2!=-1){
        if(word[tmp2].flag==1){
            printf("05%d",tmp2);
            return 0;
        }
        else
            tmp2 = word[tmp2].next;
    }
    printf("-1");
}