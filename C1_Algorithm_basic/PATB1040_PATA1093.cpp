#include<iostream>
#include<cstring>

using namespace std;
const int maxsize=1e5+5;

char raw_str[maxsize];
int left_num_p[maxsize]={0};
int right_num_t=0;

int main()
{
  gets(raw_str);
  int length = strlen(raw_str);
  
  for(int i=0;i<length;i++)
  {
    if(i>0)
      left_num_p[i] = left_num_p[i-1];
    if(raw_str[i]=='P')
      left_num_p[i]++;
  }
  
  int ans=0;
  for(int i=length-1;i>=0;i--)
  {
    if(raw_str[i]=='T')
    {
      right_num_t++;
    }
    if(raw_str[i]=='A')
    {
      ans +=left_num_p[i]*right_num_t;
    }
  }
  cout <<ans;
}