/* 
*    Algorithm: dp n^2+单调栈+线段树优化-->nlogn
*         Date: 2015-08-26
*      Contest: WUST2015暑假训练赛14（2015-8-25）
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#define ls rt<<1
#define rs rt<<1|1
using namespace std;
const int N=1000007;
typedef long long ll;
int n;
int pre[N],pos[N],type[N],energy[N];
ll dp[N];
struct Seg{
	ll minn;
	ll delta;
}s[N<<2];

void build(int l,int r,int rt)
{
	s[rt].minn=s[rt].delta=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
}
void push_down(int rt)
{
	if(s[rt].delta)
	{
		ll &de=s[rt].delta;
		s[ls].minn+=de;s[ls].delta+=de;
		s[rs].minn+=de;s[rs].delta+=de;
		de=0;
	}
}
void modify(int l,int r,int rt,int L,int R,ll v)
{
//	cout<<"==="<<rt<<endl;
	if(L<=l&&r<=R)
	{
		s[rt].minn+=v;
		s[rt].delta+=v;
		return;
	}
	push_down(rt);
	int mid=(l+r)>>1;
	if(L<=mid) modify(l,mid,ls,L,R,v);
	if(R>mid) modify(mid+1,r,rs,L,R,v);
	s[rt].minn=min(s[ls].minn,s[rs].minn);
}
ll query(int l,int r,int rt,int L,int R)
{
	if(L<=l&&r<=R) return s[rt].minn;
	push_down(rt);
	int mid=(l+r)>>1;
	ll ret=1ll*N*N;
	if(L<=mid) ret=min(ret,query(l,mid,ls,L,R));
	if(R>mid) ret=min(ret,query(mid+1,r,rs,L,R));
	s[rt].minn=min(s[ls].minn,s[rs].minn);
	return ret;

}
int sta[N],top_;
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		memset(pos,0,sizeof pos);
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",type+i);
		for(int i=1;i<=n;i++) scanf("%d",energy+i);
		for(int i=1;i<=n;i++)
		{
			pre[i]=pos[type[i]];
			pos[type[i]]=i;
		}
		build(1,n,1);
		energy[0]=N;
		top_=0;
		sta[top_++]=0;
		for(int i=1;i<=n;i++)
		{
			while(top_&&energy[sta[top_-1]]<=energy[i])
			{
				modify(1,n,1,sta[top_-2]+1,sta[top_-1],-energy[sta[top_-1]]);
				top_--;
			}
			//cout<<"++++="<<i<<endl;
			sta[top_++]=i;
			modify(1,n,1,sta[top_-2]+1,i,energy[sta[top_-1]]);
			dp[i]=query(1,n,1,pre[i]+1,i);
			modify(1,n,1,i+1,i+1,dp[i]);
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}


