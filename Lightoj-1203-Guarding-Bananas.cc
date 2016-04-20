#include<bits/stdc++.h>

using namespace std;

const double eps=1e-8;
const double pi=acos(-1.0);
const int maxn=100010;

int dcmp(double x){
    if(fabs(x)<eps) return 0;
    if(x<0) return -1;
    else return 1;
}

struct Point {
    double x,y;
    Point(){}
    Point(double _x,double _y){
        x=_x;
        y=_y;
    }
}p[maxn],ch[maxn];
typedef Point Vector;

bool operator < (const Point &a,const Point &b){
    return dcmp(a.x-b.x)==0?dcmp(a.y-b.y)<0:a.x<b.x;
}

bool operator == (Vector a,Vector b){
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}

Vector operator + (Vector a,Vector b){
    return Vector(a.x+b.x,a.y+b.y);
}

Vector operator - (Point a,Point b){
    return Vector(a.x-b.x,a.y-b.y);
}

Vector operator * (Vector a,double b){
    return Vector(a.x*b,a.y* b);
}

Vector operator / (Vector a,double b){
    return Vector(a.x/b,a.y/b);
}

double dot(Vector a,Vector b){
    return a.x*b.x+a.y*b.y;
}

double cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}

double len(Vector a){
    return sqrt(dot(a,a));
}

double angle(Vector a,Vector b){
    return acos(dot(a,b)/len(a)/len(b));
}

int get_convex(Point *p,int n,Point *ch){
    sort(p,p+n);
    int m=0;
    for(int i=0;i<n;i++){
        while(m>1&&dcmp(cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--){
        while(m>k&&dcmp(cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) m--;
        ch[m++]=p[i];
    }
    if(n>1) m--;
    return m;
}

int main(){
//freopen("in","r",stdin);
    int T,n,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        sort(p,p+n);
        n=unique(p,p+n)-p;
        int m=get_convex(p,n,ch);
        double ans=1e20;
        if(m==1) ans=0;
        else{
            for(int i=0;i<m;i++){
                //cout<<ch[i].x<<","<<ch[i].y<<endl;
                //cout<<angle(ch[(i-1+m)%m]-ch[i],ch[(i+1)%m]-ch[i])/pi*180.0<<endl;
                ans=min(angle(ch[(i-1+m)%m]-ch[i],ch[(i+1)%m]-ch[i])/pi*180.0,ans);
            }
        }
        printf("Case %d: %.10lf\n",++cas,ans);
    }
    return 0;
}
