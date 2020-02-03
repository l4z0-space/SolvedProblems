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
#include <bitset>					// uHunt: lazo99
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
        return x>other.x;
        else return y>other.y;
    }
};

vector<point>Points;    // all points


double findSlope(point p1,point p2){
    return (( p1.y-p2.y  )/(p1.x-p2.x)); // find the slope of the current mountain segment
}

double findX(point p1, double slope, double y0){    // find x to from the slope
    double x1=p1.x,y1=p1.y;
    return ( (y1-y0)/slope - x1 )*-1;
}

double hypot(double dx, double dy){ // Pythagorean theorem
    return sqrt(dx*dx+dy*dy);
}

double dist(point p1, point p2){    // distance
    return hypot(p1.x-p2.x,p1.y-p2.y);
}

int main(){
    int cases;cin>>cases;
    while(cases--){
        int n;
        cin>>n;
        forn(i,n){
            double x,y;cin>>x>>y;
            point mypoint(x,y);
            Points.pb(mypoint);
        }
        sorted(Points);
        double distance=dist(Points[0],Points[1]);
        double limit = Points[1].y;
        for(double idx=1;idx<n;idx++){
            double currY =Points[idx].y;
            if(currY > limit ){             // find next mountain with sun
                double slope = findSlope(Points[idx-1],Points[idx]); // find the slope of the line where the new point lies
                double otherX = findX(Points[idx],slope,limit); // find the x of the new point
                point newPoint(otherX,limit); // create the new point
                distance+= dist(newPoint,Points[idx]);
                limit=currY;
            }
        }
        cout<<fixed << setprecision(2)<<distance<<endl;
        Points.clear();
    }


}
