#include<iostream>

using namespace std;
const int maxsize=105;
int heap_seq[maxsize];
int n;                //heap_seq size

void down_adjust(int low,int high){
    int i=low,j=2*i;   //i代表欲调整结点，j代表左子树
    while(j<=high){
        if(j+1<=high && heap_seq[j+1]>heap_seq[j])
            j = j+1;        //左右子树比较
        if(heap_seq[j]>heap_seq[i]){
            swap(heap_seq[j],heap_seq[i]);
            i = j;
            j = 2*i;
        }
        else
            break;
    }
}

void up_adjust(int low,int high){
    int i=high,j=i/2;
    while(j>=low){
        if(heap_seq[i]>heap_seq[j]){
            swap(heap_seq[i],heap_seq[j]);
            i = j;
            j = i/2;
        }
        else
            break;
    }
}

void create_heap(){
    for(int i=n/2;i>=1;i--)
        down_adjust(i,n);
}

void insert(){
    heap_seq[++n] = 9;
    up_adjust(1,n);
}
void dis_heap(int i){
    cout<<"i "<<i<<" ";
    if(i>n)
        return;
    cout<<heap_seq[i]<<" ";
    dis_heap(i*2);
    //cout<<"xi"<<" ";
    dis_heap(i*2+1);
}

int main(){
    cin>>n;
    int value;
    for(int i=1;i<=n;i++){
        cin>>value;
        heap_seq[i] = value;
    }
    create_heap();
    insert();
    dis_heap(1);
}

/*
7
3 4 5 2 6 7 8
*/