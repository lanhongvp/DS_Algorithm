#include<cstdio>
#include<cstring>

const int maxsize=1005;
struct big_num
{
    int d[maxsize];
    int length;
    big_num()
    {
        memset(d,0,sizeof(d));
        length = 0;
    }
};

big_num change(char a_char[])
{
    big_num a;
    int length = strlen(a_char);
    for(int i=0;i<length;i++)
    {
        a.d[i] = a_char[length-i-1]-'0';
        a.length++;
    }
    return a;
}


big_num add(big_num a,big_num b)
{
    big_num result;
    //int carry;
    for(int i=0;i<a.length||i<b.length;i++){
        result.d[i] += (a.d[i]+b.d[i])%10;
        printf("first %d",result.d[i]);
        result.d[i+1] = (a.d[i]+b.d[i])/10;
        //carry = (a.d[i]+b.d[i])/10;
        printf("second %d\n",result.d[i+1]);
        result.length++;
    }
    return result;
}


big_num sub(big_num a,big_num b){
    big_num c;
    for(int i=0;i<a.length||i<b.length;i++){
        if(a.d[i]<b.d[i]){
            c.d[i] = a.d[i]+10-b.d[i];
            a.d[i+1] -= 1;
            c.length++;
        }
        else{
            c.d[i] = a.d[i] - b.d[i];
            c.length++;
        }
    }
    //细节：根据题目输出要求，此处是保证至少保留一位最低位
    while(c.length-1>=1 && c.d[c.length-1]==0){
        c.length--;
    }
    return c;
}


int main()
{
    char a[maxsize],b[maxsize];
    scanf("%s%s",a,b);

    big_num a_int,b_int;
    a_int = change(a);
    b_int = change(b);

    big_num result_int;
    //result_int = add(a_int,b_int);
    result_int = sub(a_int,b_int);
    
    for(int i=result_int.length-1;i>=0;i--)
    {
        printf("%d",result_int.d[i]);
    }

}