#include<cstdio>
#include<cstring>

//using namespace std;
const int maxsize = 90;

int main()
{
  char str[maxsize];
  gets(str);
  
  int str_len = strlen(str);
  int r,h=0;
  
  char ans[maxsize][maxsize];
  
  for(int i=0;i<str_len;i++)
  {
    if(str[i]!=' ')
      ans[r][h++] = str[i];
    else
    {
      ans[r][h] = '\0';
      r++;
      h = 0;
    }  
  }
  
  for(int i=r;i>=0;i--)
  {
    printf("%s",ans[i]);
    if(i>0) printf(" ");
  }
}