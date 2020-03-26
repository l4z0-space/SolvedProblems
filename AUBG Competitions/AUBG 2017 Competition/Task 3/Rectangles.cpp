#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;

struct Rect{

    int area;
    int X,Y,Xd,Yd;

    bool operator < (Rect other){
        return area<other.area;
    }

};


int main(){
    vi depths(100000);
    map<int,bool>visited;
    int n;cin>>n;
    Rect all[n];
    for(int i=0;i<n;i++){
        int x,y,xd,yd;
        cin>>x>>y>>xd>>yd;
        Rect newRec;
        newRec.X=x;newRec.Y=y;
        newRec.Xd=xd;newRec.Yd=yd;
        newRec.area=xd*yd;
        all[i]=newRec;
        visited[i]=0;
    }


    int maxdepth=0;
    sort(all,all+n);
    int W=0;
   
    while(W<n){
        int cP=W;
        int currDepth=1;
        for(int i=W+1;i<n;i++){
            if(all[cP].X > all[i].X)
            if(all[cP].Y > all[i].Y)
            if(all[cP].Xd+all[cP].X<all[i].Xd+all[i].X)
            if(all[cP].Yd+all[cP].Y<all[i].Yd+all[i].Y)

            {
                cP=i;
                currDepth++;
            }

        }
       maxdepth=max(maxdepth,currDepth);
       depths[W]=currDepth;
       W++;


    }
    int count=0;
    for(int i=0;i<n;i++){
      if(depths[i]==maxdepth)count++;
    }
    cout<<maxdepth<<" "<<count<<endl;

}
