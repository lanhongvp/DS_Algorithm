#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<map>

using namespace std;

struct node{
    double num;
    char op;
    bool flag;
};

string str;
stack<node> s;   //操作符栈
queue<node> q;   //后缀表达式
map<char,int> op;

void mid2post(){
    //double num;
    node tmp;
    for(unsigned int i=0;i<str.length();){
        if(str[i]>='0' && str[i]<='9'){
            tmp.flag = true;
            tmp.num = str[i++] - '0';
        while(i<str.length() && str[i]>='0' && str[i]<='9'){
            tmp.num = tmp.num*10+(str[i]-'0');
        }
        q.push(tmp);
        }
        else{
            tmp.flag = false;
            while(!s.empty()&&op[str[i]]<=op[s.top().op]){
                q.push(s.top());
                s.pop();
            }
            tmp.op = str[i];
            s.push(tmp);
            i++;
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    }
}

//void calc_post(){}

int main(){
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;

    while(getline(cin,str),str!="0"){
        for(string::iterator it=str.end();it!=str.begin();it--){
            if(*it==' ') 
                str.erase(it);
        }
    }
    while(!s.empty())
        s.pop();
    
    mid2post();
    for(unsigned int i=0;i<q.size();i++){
        printf("%c\n",q.front().op);
        printf("%d",q.size());
        q.pop();
    }  
}