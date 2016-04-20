#include<bits/stdc++.h>

using namespace std;

int data[100010];
map<int,int> pos;
int main(){
//freopen("in","r",stdin);
    int n;
    while(cin>>n){
        pos.clear();
        for(int i=0;i<n;i++) scanf("%d",data+i);
        int ans=1,maxx=0,minn=0;
        pos[data[0]]=0;
        for(int i=1;i<n;i++){
            pos[data[i]]=i;
            if(data[i]>data[maxx]){
                maxx=i;
                if(data[minn]+1<data[maxx])
                    minn=pos[data[minn]]+1;
            }
            if(data[i]<data[minn]){
                minn=i;
                if(data[minn]+1<data[maxx])
                    maxx=pos[data[maxx]]+1;
            }
            ans=max(ans,max(i-minn,i-maxx)+1);
        }
        cout<<ans<<endl;
    }

    return 0;
}
