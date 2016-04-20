#include<bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;
int n,m;
int dist[2][500][500];

void floyd(int c){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[c][i][j]=min(dist[c][i][j],dist[c][i][k]+dist[c][k][j]);
            }
        }
    }
}

int main(){
//freopen("D.in","r",stdin);
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) dist[0][i][j]=dist[1][i][j]=0;
                else{
                    dist[0][i][j]=1;
                    dist[1][i][j]=INF;
                }
            }
        }
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            dist[1][u][v]=dist[1][v][u]=1;
            dist[0][u][v]=dist[0][v][u]=INF;
        }
        floyd(0);
        floyd(1);
        if(dist[0][1][n]<INF&&dist[1][1][n]<INF)
            cout<<max(dist[0][1][n],dist[1][1][n])<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;

}
