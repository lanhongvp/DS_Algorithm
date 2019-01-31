#include<iostream>
#include<string>

using namespace std;

const int maxsize = 105;
string pre,in;

int main(){
    int n;
    cin>>n;
    
    cin>>pre>>in;

    for(int i=0;i<n;i++){
        if(pre[i]==in[i])
            cout<<"haha"<<endl;
        else
            cout<<"xixi"<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<pre[i]<<endl;
        cout<<in[i]<<endl;
    }
}