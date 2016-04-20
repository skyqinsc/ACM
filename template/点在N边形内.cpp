#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

const double eps = 1e-6;
double dcmp(double x) {
  if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}

struct Point {
  double x, y;
  Point(double x=0, double y=0):x(x),y(y) { }
};

typedef Point Vector;

Vector operator - (const Point& A, const Point& B) {
  return Vector(A.x-B.x, A.y-B.y);
}

double Cross(const Vector& A, const Vector& B) {
  return A.x*B.y - A.y*B.x;
}

double Dot(const Vector& A, const Vector& B) {
  return A.x*B.x + A.y*B.y;
}

bool operator < (const Point& p1, const Point& p2) {
  return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

bool operator == (const Point& p1, const Point& p2) {
  return p1.x == p2.x && p1.y == p2.y;
}


bool OnSegment(const Point& p, const Point& a1, const Point& a2) {
  return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}

int IsPointInPolygon(const Point &p,const vector<Point> &poly){
  int wn = 0;
  int n = poly.size();
  for(int i = 0; i < n; i++){
    const Point& p1 = poly[i];
    const Point& p2 = poly[(i+1)%n];
    if(p1 == p || p2 == p || OnSegment(p, p1, p2)) return -1; // 在边界上
    int k = dcmp(Cross(p2-p1, p-p1));
    int d1 = dcmp(p1.y - p.y);
    int d2 = dcmp(p2.y - p.y);
    if(k > 0 && d1 <= 0 && d2 > 0) wn++;
    if(k < 0 && d2 <= 0 && d1 > 0) wn--;
  }
  if (wn != 0) return 1; // 内部
  return 0; // 外部
}


vector<Point> po;
int main()
{
    double p0,q0,p1,q1;
    int n,a,b;
    while(scanf("%lf%lf%lf%lf",&p0,&q0,&p1,&q1)==4)
    {

        scanf("%d%d%d",&n,&a,&b);
        int x,y;
        double ans=0.0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            po.push_back(Point(x,y));
        }
        for(int i=ceil(p0);i<=floor(p1);i++)
        {
            for(int j=ceil(q0);j<=floor(q1);j++)
            {
                int cc=IsPointInPolygon(Point(i,j),po);
                if(cc==1||cc==-1)
                {
                    double up,down,left,right;
                    up=min(j+0.5,q1);
                    down=max(j-0.5,q0);

                    left=max(i-0.5,p0);
                    right=min(i+0.5,p1);
                    ans+=(up-down)*(right-left)*(a*i+b*j);

                }
            }
        }

        printf("%.3lf\n",ans/((p1-p0)*(q1-q0)));
    }
    return 0;
}
