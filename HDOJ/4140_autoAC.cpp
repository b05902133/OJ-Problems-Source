#include <stdio.h>
#include <string.h>
#define N 1000000
char str[N];
int x;
int pow(int a,int b)
{
    int res =  1;
    while(b--)
        res *= a;
    return res;
}
int solve()
{
    int res = 0,add = 0,flag = 1,c,e;
    int i = 0,j = 0;
    int len = strlen(str);
    for(--len; str[len]!='+' && str[len] != '-' && len >= 0; --len);
    if(str[0] == '-')
    {
        flag = -1;
        i = 1;
    }
    for(;i < len; ++i)
    {
        c = 0;
        for(j = i; str[j] != 'X'; ++j)
            c = c*10 + str[j] - '0';
        if(i == j)
            c = 1;
        ++j;
        if(str[j] == '^')
        {
            e = 0;
            for(++j;str[j] != '+' && str[j] !='-';++j)
                e = e * 10 + str[j] - '0';
        }
        else
            e = 1;
        res += c* flag*pow(x,e);
        if(str[j] == '+')
            flag = 1;
        else
            flag = -1;
        i = j;
    }
    c = 0;
    for(j = i;str[j] && str[j] != 'X'; ++j)
        c = c * 10 + str[j] - '0';
    if(!str[j])
        res += c * flag;
    else
    {
        if(i == j)
            c = 1;
        ++j;
        if(!str[j])
            res += c * x * flag;
        else
        {
            ++ j;
            e = 0;
            for(;str[j];++j)
                e = e * 10 + str[j] - '0';
            res += c * flag * pow(x,e);
        }
    }
    return res;
}
int main()
{
    int t,sp = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&x,str);
        printf("Case #%d: %d\n",++sp, solve());
    }
    return 0;
}
