/* rush->AC */
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

typedef long long ll;
typedef unsigned long long ull;
const int N=100007;


//前缀和标记法：
vector<vector<int> > mat;
char str[]="UDLR";
int go[4][2]={-1,0, 1,0, 0,-1, 0,1};
int n,m,k;
int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {

        scanf("%d%d%d",&n,&m,&k);
        mat=vector<vector<int> >(n+2,vector<int>(m+2,0));
        char op;int step;
        int r=1,c=1;
        for(int i=0;i<k;i++)
        {
            scanf(" %c%d",&op,&step);
            if(op=='D'){
                mat[r][c]++;
                mat[r+step][c]--;
            }
            if(op=='U'){
                mat[r][c]++;
                mat[r-step][c]--;
            }
            int f=strchr(str,op)-str;
            r+=step*go[f][0];
            c+=step*go[f][1];
        }
        ll  ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                mat[i][j]=mat[i][j]+mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
                ans+=(ll)mat[i][j]*mat[i][j];
            }
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}
