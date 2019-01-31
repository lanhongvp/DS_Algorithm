#include<cstdio>
#include<cstring>

const int maxsize=256;

int is_palindrome(char str[],int length)
{
    for(int i=0;i<length/2;i++)
    {
        if(str[i]!=str[length-i-1])
            return 0;
    }
    return 1;
}

int main()
{
    char str[maxsize];
    scanf("%s",str);
    int length = strlen(str);
    int ans = is_palindrome(str,length);

    if(ans)
        printf("YES");
    else
        printf("NO");
}