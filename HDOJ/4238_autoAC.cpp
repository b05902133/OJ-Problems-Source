#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#define ll long long
#define oo 1<<29
#define pi acos(-1.0)
#define esp 1e-30
using namespace std;
char s[45]={"PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV"},c,Q[30];
int A[30],C[30];
int main()
{
       int cases,id,t,x,i,len; 
       scanf("%d",&cases);
       while (cases--)
       {
               scanf("%d%s",&id,Q),len=strlen(Q);
               if (Q[0]=='-') x=Q[1]-'0';
                        else  x=Q[0]-'0';
               if (x)
               {
                     if (x>1) { printf("%d INVALID VALUE\n",id); continue; }
                     for (i=3;i<=19;i++)
                        if (Q[i]>='1' && Q[i]<='9') break;
                     if (i<=19) { printf("%d INVALID VALUE\n",id); continue; }
               }
               if (Q[0]=='-') 
               {
                     A[1]=1;
                     C[x=1]=1;
                     for (i=2;i<len;i++)
                       if (Q[i]>='0' && Q[i]<='9') 
                          C[++x]=0-(Q[i]-'0');
                     len=x;
                     for (i=len;i>=1;i--)
                        if (C[i]<0) C[i-1]--,C[i]+=10;
                     C[1]=0;
               }
               else 
               {
                     A[1]=0;
                     x=0;
                     for (i=0;i<len;i++)
                       if (Q[i]>='0' && Q[i]<='9') 
                          C[++x]=Q[i]-'0';
                     len=x;
               }
               for (i=2;i<=17;i++)
               {
                       for (x=2;x<=len;x++) C[x]*=2;
                       for (x=1;x<=len;x++) C[x-1]+=C[x]/10,C[x]%=10;
                       if (C[1]) A[i]=1;
                            else A[i]=0;
                       C[1]=0;
                       while (len && !C[len]) len--;
               }
              if (len && A[1]) A[17]++;
               for (x=20;x>=1;x--) A[x-1]+=A[x]/2,A[x]%=2;  
               x=0;
               for (i=1;i<=5;i++)
                 if (A[i]) x+=1<<(5-i);
               printf("%d %c",id,s[x]);
               x=0,t=10;
               for (i=6;i<=16;i++)
               {
                     if (A[i]) x+=1<<t;
                     t--;
               }
               printf(" %d",x);
               if (!A[17]) printf(" F\n");
                     else  printf(" D\n");
       }
       return 0;
}
