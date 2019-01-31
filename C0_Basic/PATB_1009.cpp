//#include<iostream>
#include<cstdio>
#include<cstring>

//using namespace std;

int main()
{
    char str[90];
    gets(str);

    char ans[90][90];
    int r=0,h=0;
    for(unsigned int i=0;i<strlen(str);i++)
    {
        if(str[i]==' ')
        {
            ans[r][h] = '\0';
            r++;
            h = 0;
        }
        else if(str[i]!=' ')
        {
            ans[r][h++] = str[i];
        }
    }

    for(int i=r;i>=0;i--)
    {
        printf("%s",ans[i]);
        if(i>0) printf(" ");
    }
}
