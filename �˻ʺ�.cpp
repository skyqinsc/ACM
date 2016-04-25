#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

int n,ans;

void solve(LL row,LL lc,LL rc){
    if(row<(1L<<n)-1){
        LL pos=((1L<<n)-1)&(~(row|lc|rc));
        while(pos){
            LL p=pos&(-pos);
            pos-=p;
            solve(row+p,(lc+p)<<1,(rc+p)>>1);
        }
    }
    else
        ans++;
}

int main(){
    while(cin>>n){
        ans=0;
        solve(0,0,0);
        cout<<ans<<endl;
    }
}
