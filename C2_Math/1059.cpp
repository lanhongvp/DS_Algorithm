#include<cstdio>
#include<math.h>

//using namespace std;
const int maxsize=1e4+5;
int prime[maxsize];
int is_prime[maxsize]={0};

struct factor
{
    int x,cnt;
}fac[10];

void prime_table()
{
    int num=0;
    for(int i=2;i<maxsize;i++)
    {
        if(is_prime[i]==0)
        {
            prime[num++] = i;
            for(int j=i+i;j<maxsize;j+=i)
                is_prime[j] = 1;
        }
    }
}

int main()
{
    long long n,tmp;
    scanf("%lld",&n);
    tmp = n;
    if(n==1) 
    {
        //printf("haha");        
        printf("1=1");
        return 0;
    }
    
    prime_table();
    int num=0;
    int sqr_num = (int)sqrt(n);
    //printf("sqr_num %d",sqr_num);
    for(int i=0;i<sqr_num && prime[i]<=sqr_num;i++)
    {
        //printf("haha");
        if(n%prime[i]==0)
        {
            fac[num].x = prime[i];
            fac[num].cnt = 0;
            while(n%prime[i]==0)
            {
                fac[num].cnt++;
                n /= prime[i];
            }
            num++;
            if(n==1) break;
        }
    }
    //质数本身的情况
    if(n!=1 && num==0)
    {
        fac[num].x = n;
        fac[num].cnt = 1;
        //printf("xixi");
        printf("%lld=%d",n,fac[num].x);
        return 0;
    }
    //按要求输出
    printf("%lld=",tmp);
    for(int i=0;i<num;i++)
    {
        if(i>0) printf("*");
        printf("%d",fac[i].x);
        if(fac[i].cnt>1)
        {
            printf("^%d",fac[i].cnt);
        }
    }
}