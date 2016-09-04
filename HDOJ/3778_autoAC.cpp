#include <algorithm>
#include <cstring>
#include <cstdio>
using std::sort;
struct dat
{
    int socer;
    int top;
    int low;
    int number;
    bool operator<(const dat p)const
    {
        return p.socer<socer;
    }
} a[33],b[33];
char name[33][33];
struct odat
{
    int as;
    int bs;
} vs[20];
int n,m;
int aa,bb,q;
int fins(char *s)
{
    for(int i=0; i<n; i++)
        if(!strcmp(name[i],s))
            return i;
    return 0;
}
bool cmp(dat p, dat q)
{
    return p.socer>q.socer;
}
int ans[33];
void dfs(int x)
{
    if(x==q)
    {
        for(int i=0; i<n; i++)
            b[i]=a[i];
        for(int i=0; i<q; i++)
        {
            int nx=vs[i].as;
            int ny=vs[i].bs;
            if(ans[i]==-1)
            {
                b[nx].socer+=3;
            }
            else if(ans[i]==0)
            {
                b[nx].socer++;
                b[ny].socer++;
            }
            else
            {
                b[ny].socer+=3;
            }
        }
        sort(b, b+n);
        int pp=1,dd=0;
        for(int i=0; i<n; i++)
        {
            dd++;
            if(b[i-1].socer!=b[i].socer && i)
                pp=dd;
            if(b[i].top>pp)
                b[i].top=pp;
            if(b[i].low<pp)
                b[i].low=pp;
        }
        for(int i=0; i<n; i++)
        {
            int nx=b[i].number;
            a[nx].low=b[i].low;
            a[nx].top=b[i].top;
        }
    }
    else
        for(int i=-1; i<2; i++)
            ans[x]=i,dfs(x+1);
}
int main()
{
    int count=0;
    while(scanf("%d %d",&n,&m)==2 && (n+m))
    {
        if(count)puts("");
        count=1;
        for(int i=0; i<n; i++)
        {
            scanf("%s",name[i]);
            a[i].socer=0;
            a[i].number=i;
            a[i].top=n+1;
            a[i].low=0;
        }
        char s[33],s2[33];
        q=0;
        for(int i=0; i<m; i++)
        {
            scanf("%s vs %s%d %d",s,s2,&aa,&bb);
            s2[strlen(s2)-1]='\0';
            int x=fins(s);
            int y=fins(s2);
            if(aa==-1 && bb==-1)
            {
                vs[q].as=x;
                vs[q++].bs=y;
            }
            else
            {
                if(aa>bb)
                    a[x].socer+=3;
                else if(bb>aa)
                    a[y].socer+=3;
                else if(aa==bb)
                    a[y].socer++,a[x].socer++;
            }
        }
        dfs(0);
        for(int i=0; i<n; i++)
        {
            printf("Team %s can finish as high as ",name[i]);
            if(a[i].top==1)
                printf("1st");
            else if(a[i].top==2)
                printf("2nd");
            else if(a[i].top==3)
                printf("3rd");
            else
                printf("%dth",a[i].top);
            printf(" place and as low as ");
            if(a[i].low==1)
                printf("1st");
            else if(a[i].low==2)
                printf("2nd");
            else if(a[i].low==3)
                printf("3rd");
            else
                printf("%dth",a[i].low);
            printf(" place.\n");
        }
    }
    return 0;
}
