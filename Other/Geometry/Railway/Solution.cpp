#include <iomanip>
#include <sstream>
#include<unordered_map>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <bitset>
#include <map>
#include <string>
using namespace std;
#define forn(i,n)           for(int i=0;i<n;i++)
#define pb(b)               push_back(b)
#define sorted(a)           sort(a.begin(),a.end())
#define reversed(a)         reverse(a.begin(),a.end())
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pii;
typedef vector<pii> vii;
int INF = 5e5+1;

double EPS = 1e-9;

struct point{ double x,y;
    point(){x=y=0;}
    point(double _x,double _y){
        x=_x;
        y=_y;
    }
    bool operator < (point other) const{
        if(fabs(x-other.x)>EPS)
        return x<other.x;
        else return y<other.y;
    }
};

struct vec{ double x,y;
    vec(double _x,double _y):x(_x),y(_y){};
};

vec toVec(point a, point b){
    return vec(b.x-a.x,b.y-a.y);
}

vec scale(vec a, double s){
    return vec(a.x*s,a.y*s);
}

point translate(point p,vec v){
    return point(p.x+v.x,p.y+v.y);
}

double dot(vec a, vec b){
    return (a.x*b.x + a.y*b.y);
}

double square(vec v){
    return (v.x*v.x+v.y*v.y);
}

double eDistance(point a, point b){

    return sqrt( (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y)  );

}

double distToLine(point p, point a, point b, point &c){

    vec ap = toVec(a,p);
    vec ab = toVec(a,b);

    double u = dot(ap,ab)/square(ab);

    c = translate(a,scale(ab,u));
    return eDistance(p,c);

}

double distToLineSegment(point p, point a, point b, point &c){

    vec ap = toVec(a,p);
    vec ab = toVec(a,b);

    double u = dot(ap,ab) / square(ab);

    if(u<0.0) {
        c = point(a.x, a.y);
        return eDistance(p,a);
    }
    if(u>1.0){
        c = point(b.x, b.y);
        return eDistance(p,b);
    }
    return distToLine(p,a,b,c);
}

int main(){
  //  ifstream cinn("C:\\Users\\Lazaron Shyta\\Desktop\\input.txt");
  // ofstream coutt("C:\\Users\\Lazaron Shyta\\Desktop\\output.txt");

    double x,y;

    while(cin>>x>>y){
        point station(x,y);
        int n;cin>>n;
        vector<point>Points;
        for(int i=0;i<=n;i++){
            double nX,nY;
            cin>>nX>>nY;
            point mypoint(nX,nY);
            Points.pb(mypoint);
        }

            double minDist=1e9;
            point result(1e3,1e3);

           /* for(int i=0;i<=n;i++){
                cout<<"Point: "<<Points[i].x<<" "<<Points[i].y<<endl;
            }*/
            double currDist;
            point candidate;
            for(int i=0;i<n;i++){

                currDist= distToLineSegment(station,Points[i],Points[(i+1)],candidate);

                if(currDist<minDist){
                    result = candidate;
                    minDist = currDist;

                 //   cout<<currDist<<" -> "<<Points[i].x<<","<<Points[i].y<<" & "<<Points[i+1].x<<","<<Points[i+1].y<<" ("<< result.x<<","<<result.y<<")"<<endl;
                }
            }


            cout<<fixed << setprecision(4)<< result.x <<"\n"<<result.y<<endl;
    }

}
