#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 1111
#define MAXM 88888888
struct Edge{
    int v,cap,next;
}edge[MAXM];
int head[MAXN];
int pre[MAXN];
int cur[MAXN];
int level[MAXN];
int gap[MAXN];
int NE,NV,vs,vt,n,f,d;
int Food[MAXN];
int Drink[MAXN];
void Insert(int u,int v,int cap,int cc=0){
    edge[NE].v=v;edge[NE].cap=cap;
    edge[NE].next=head[u];head[u]=NE++;
    edge[NE].v=u;edge[NE].cap=cc;
    edge[NE].next=head[v];head[v]=NE++;
}
int SAP(int vs,int vt){
    memset(pre,-1,sizeof(pre));
    memset(level,0,sizeof(level));
    memset(gap,0,sizeof(gap));
    for(int i=0;i<NV;i++)cur[i]=head[i];
    int u=pre[vs]=vs,maxflow=0,aug=-1;
    gap[0]=NV;
    while(level[vs]<NV){
loop:
        for(int &i=cur[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(edge[i].cap&&level[u]==level[v]+1){
                aug==-1?aug=edge[i].cap:aug=min(aug,edge[i].cap);
                pre[v]=u;
                u=v;
                if(v==vt){
                    maxflow+=aug;
                    for(u=pre[u];v!=vs;v=u,u=pre[u]){
                        edge[cur[u]].cap-=aug;
                        edge[cur[u]^1].cap+=aug;
                    }
                    aug=-1;
                }
                goto loop;
            }
        }
        int minlevel=NV;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(edge[i].cap&&minlevel>level[v]){
                cur[u]=i;
                minlevel=level[v];
            }
        }
        gap[level[u]]--;
        if(gap[level[u]]==0)break;
        level[u]=minlevel+1;
        gap[level[u]]++;
        u=pre[u];
    }
    return maxflow;
}
int main(){
    char str[MAXN];
    while(~scanf("%d%d%d",&n,&f,&d)){
        vs=0,vt=f+2*n+d+1,NV=vt+1,NE=0;
        memset(head,-1,sizeof(head));
        for(int i=1;i<=f;i++){
            scanf("%d",&Food[i]);
            Insert(vs,i,Food[i]);
        }
        for(int i=1;i<=d;i++){
            scanf("%d",&Drink[i]);
            Insert(i+2*n+f,vt,Drink[i]);
        }
        for(int i=1;i<=n;i++){
            Insert(i+f,i+f+n,1);
        }
        for(int i=1;i<=n;i++){
            scanf("%s",str+1);
            for(int j=1;j<=f;j++){
                if(str[j]=='Y'){
                    Insert(j,i+f,1);
                }
            }
        }
        for(int i=1;i<=n;i++){
            scanf("%s",str+1);
            for(int j=1;j<=d;j++){
                if(str[j]=='Y'){
                    Insert(i+f+n,f+2*n+j,1);
                }
            }
        }
        printf("%d\n",SAP(vs,vt));
    }
    return 0;
}
