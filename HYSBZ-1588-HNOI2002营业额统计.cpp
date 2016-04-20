/* 
*    Algorithm: Splay
*         Date: 2015-08-26
*      Contest: 练习
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define INF 1<<29
#define mod 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef long long LL;
const int N=100007;

struct SplayTree
{
    int son[N][2],pre[N],val[N];
    int rt,sz;
    inline void Rotate(int x,int c)//旋转
    {
        int y=pre[x];
        son[y][!c]=son[x][c];
        pre[son[x][c]]=y;
        pre[x]=pre[y];
        if(pre[y])
            son[pre[y]][son[pre[y]][1]==y]=x;
        son[x][c]=y;
        pre[y]=x;
    }
    inline void Splay(int x,int goal)
    {
        while(pre[x]!=goal)
        {
            if(pre[pre[x]]==goal)
            {
                if(son[pre[x]][0]==x) Rotate(x,1);
                else Rotate(x,0);
            }
            else
            {
                int y=pre[x],z=pre[y];
                if(son[z][0]==y)
                {
                    if(son[y][0]==x)
                        Rotate(x,1),Rotate(x,1);
                    else
                        Rotate(x,0),Rotate(x,1);
                }
                else
                {
                    if(son[y][0]==x)
                        Rotate(x,1),Rotate(x,0);
                    else
                        Rotate(x,0),Rotate(x,0);
                }
            }
        }
        if(goal==0) rt=x;
    }
    inline void NewNode(int y,int &x,int a)
    {
        x=++sz;
        pre[x]=y;
        val[x]=a;
        son[x][0]=son[x][1]=0;
    }
    inline void init()
    {
        sz=0;
        NewNode(0,rt,-INF);
        NewNode(rt,son[rt][1],INF);
    }

    inline void Insert(int a)
    {
        int x=rt;
        while(son[x][val[x]<a]) x=son[x][val[x]<a];
        NewNode(x,son[x][val[x]<a],a);
        Splay(sz,0);
    }
    inline int fx_min(int a)
    {
        int x=rt,minn=INF;
        while(x)
        {
            if(val[x]==a) return a;
            if(val[x]>a) minn=min(minn,val[x]),x=son[x][0];
            else x=son[x][1];
        }
        return minn;
    }
    inline int fx_max(int a)
    {
        int x=rt,maxx=-INF;
        while(x)
        {
            if(val[x]==a) return a;
            if(val[x]<a) maxx=max(maxx,val[x]),x=son[x][1];
            else
                x=son[x][0];
        }
        return maxx;
    }
}spt;

int main()
{
    int n;
    scanf("%d",&n);
    int v,ans;
    scanf("%d",&v);
    ans=v;
    spt.init();
    spt.Insert(v);
    for(int i=1;i<n;i++)
    {
        if(scanf("%d",&v)==-1) v=0;
        //scanf("%d",&v);
        ans+=min(fabs(v-spt.fx_min(v)),fabs(spt.fx_max(v)-v));
        spt.Insert(v);
    }
    cout<<ans<<endl;

    return 0;
}
