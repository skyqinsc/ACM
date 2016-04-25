#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define EPS 1e-8
#define x first
#define y second
using namespace std;

typedef pair<double,double> Point;

Point p[4],cir;

double dis_p_s(Point a,Point b,Point c){
    double dot=(a.x-b.x)*(c.x-b.x)+(a.y-b.y)*(c.y-b.y);
    if(dot<=EPS) return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    double seg=(c.x-b.x)*(c.x-b.x)+(c.y-b.y)*(c.y-b.y);
    if(dot>=seg) return sqrt((a.x-c.x)*(a.x-c.x)+(a.y-c.y)*(a.y-c.y));
    double tx=b.x+(c.x-b.x)*(dot/seg);
    double ty=b.y+(c.y-b.y)*(dot/seg);
    return sqrt((a.x-tx)*(a.x-tx)+(a.y-ty)*(a.y-ty));
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        double r;
        scanf("%lf%lf%lf%lf%lf%lf%lf",&cir.x,&cir.y,&r,&p[0].x,&p[0].y,&p[2].x,&p[2].y);
        p[1].x=p[2].x,p[1].y=p[0].y;
        p[3].x=p[0].x,p[3].y=p[2].y;
        int in=1,out=1;
        for(int i=0;i<4;i++){
            if((p[i].x-cir.x)*(p[i].x-cir.x)+(p[i].y-cir.y)*(p[i].y-cir.y)>=r*r){
                in=0;
                break;
            }
        }
        if(in) cout<<"NO"<<endl;
        else{
            for(int i=0;i<4;i++){
                if(dis_p_s(cir,p[i],p[(i+1)%4])<=r){
                    out=0;
                    break;
                }
            }
            if(out) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}

