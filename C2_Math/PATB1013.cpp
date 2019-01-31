#include<cstdio>

const int maxsize=1e4+5;

int prime[maxsize];
int is_prime[maxsize]={0};

void prime_table(int n)
{
  int prime_num=0;
  for(int i=2;i<maxsize;i++)
  {
    if(is_prime[i]==0)
    {
      prime[prime_num++] = i;
      if(prime_num>=n) break;
      for(int j=i+i;j<maxsize;j+=i)
      is_prime[j] = 1;
    }
  }
}


int main()
{
  int m,n;
  scanf("%d%d",&m,&n);
  
  int cnt=0;
  prime_table(n);
  
  for(int i=m;i<=n;i++)
  {
    printf("%d",prime[i-1]);
    cnt++;
    if(i<n && cnt%10!=0)
      printf(" ");
    else
      printf("\n");
  }
}