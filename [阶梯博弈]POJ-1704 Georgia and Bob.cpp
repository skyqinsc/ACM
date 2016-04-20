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

typedef long long LL;
const int N=100007;

int stone[N];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",stone+i);
        }
        sort(stone+1,stone+1+n);
        int sum=0;
        if(n&1)
        {
            for(int i=1;i<=n;i+=2)
                sum=sum^(stone[i]-stone[i-1]-1);
        }
        else{
            for(int i=2;i<=n;i+=2)
            {
                sum=sum^(stone[i]-stone[i-1]-1);
            }
        }
        if(sum) printf("Georgia will win\n");
        else printf("Bob will win\n");
    }
    return 0;
}
