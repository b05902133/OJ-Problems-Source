#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[10001],lib[100][10001],*arr[20000],ans[20000],*t;
int cas,n,len[20000],a,b;
int main()
{
    while(scanf("%s",s)&&strcmp(s,"0"))
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i) 
        {
            scanf(" %s",lib[i]);
            arr[i]=lib[i];
            len[i]=strlen(lib[i]);
        }
        t=ans;
        a=strlen(s);
        for(int i=0;i<a;)
        {
            b=s[i++]-'0';
            for(int j=10;n>j;j*=10) b=b*10+s[i++]-'0';
            arr[n]=t;
            len[n++]=len[b]+1;
            for(int j=0;j<len[b];++j)
            {
                *t=arr[b][j];
                t++;
            }
        }
        *t='\0';
        printf("Case %d: %s\n",++cas,ans);
    }
}
