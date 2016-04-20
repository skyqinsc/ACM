/* 
*    Algorithm: 逆向并查集
*         Date: 2015-08-26
*      Contest: 练习
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;

const int N=10010;

int power[N];
set<pair<int,int> > edge;
struct Query{
	int op;
	int a,b;
	int ans;
	void set_(int opp,int aa,int bb)
	{
		op=opp;
		a=aa;
		b=bb;
	}
}query[50010];

int uset[N],mx[N];
int find_set(int x)
{
	if(uset[x]!=x)
	{
		int f=uset[x];
		uset[x]=find_set(uset[x]);
		mx[x]=max(mx[x],mx[f]);
	}
	return uset[x];
}

void union_set(int x,int y)
{
	int fx=find_set(x);
	int fy=find_set(y);
	if(fx==fy) return;
	if(mx[fy]>mx[fx]||(mx[fx]==mx[fy]&&fx>fy)) uset[fx]=fy;
	else uset[fy]=fx;

}

int main()
{
	int n,m,q,cas=0;
	while(scanf("%d",&n)==1)
	{
		if(cas++) puts("");
		char op[10];
		int a,b;
		edge.clear();
		for(int i=0;i<n;i++) scanf("%d",power+i);
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			if(a>b) swap(a,b);
			edge.insert(mp(a,b));
		}
		scanf("%d",&q);
		for(int i=0;i<q;i++)
		{
			scanf("%s",op);
			if(op[0]=='q')
			{
				scanf("%d",&a);
				query[i].set_(1,a,0);
			}
			else
			{
				scanf("%d%d",&a,&b);
				if(a>b) swap(a,b);
				edge.erase(mp(a,b));
				query[i].set_(2,a,b);
			}
		}
		for(int i=0;i<n;i++)
		{
			uset[i]=i;
			mx[i]=power[i];
		}
		set<pair<int,int> >::iterator it;
		for(it=edge.begin();it!=edge.end();it++)
		{
			a=(*it).first;b=(*it).second;
			union_set(a,b);
		}
		for(int i=q-1;i>=0;i--)
		{
			if(query[i].op==1)
			{
				if(mx[find_set(query[i].a)]>power[query[i].a])
					query[i].ans=uset[query[i].a];
				else
					query[i].ans=-1;
			}
			else
			{
				union_set(query[i].a,query[i].b);
			}
		}
		for(int i=0;i<q;i++)
			if(query[i].op==1) 
				printf("%d\n",query[i].ans);
	}	
	return 0;
}
