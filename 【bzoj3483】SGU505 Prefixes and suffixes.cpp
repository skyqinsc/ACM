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
const int N=2000007;
const ull seed=131;
int n,m;
char ch[2000005];
string s[2005],a,b;
vector<ull> L[2005],R[2005];


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",ch);
        int len=strlen(ch);
        for(int j=0;j<len;j++)
            s[i]+=ch[j];
        ull hash_=0;
        for(int j=0;j<len;j++)
        {
            hash_=hash_*seed+(s[i][j]-'a');
            L[i].push_back(hash_);
        }
        hash_=0;
        for(int j=len-1;j>=0;j--)
        {
            hash_=hash_*seed+(s[i][j]-'a');
            R[i].push_back(hash_);
        }
    }
    scanf("%d",&m);
    int ans=0;
    for(int i=0;i<m;i++)
    {
        //scanf("%s",ch);
        cin>>ch;
        ull hash_a,hash_b;
        int len_a,len_b;
        len_a=strlen(ch);
        hash_a=0;
        for(int j=0;j<len_a;j++)
        {
            hash_a=hash_a*seed+(ch[j]-'a'+ans)%26;
        }
        //scanf("%s",ch);
        cin>>ch;
        hash_b=0;
        len_b=strlen(ch);
        for(int j=len_b-1;j>=0;j--)
        {
            hash_b=hash_b*seed+(ch[j]-'a'+ans)%26;
        }
        ans=0;
        for(int j=0;j<n;j++)
        {
            if(L[j][len_a-1]==hash_a&&R[j][len_b-1]==hash_b)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

/*
3
aaaaa
abacabaa
avtobus
6
a a
y yy
yy y
zzzzz zzzz
zazb bzaz
abac a
*/
