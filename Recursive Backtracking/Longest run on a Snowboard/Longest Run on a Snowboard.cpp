#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <map>
#include <string>
using namespace std;
#define forn(i,n)           for(int i=0;i<n;i++)
#define pb(b)               push_back(b)
#define sorted(a)           sort(a.begin(),a.end())
#define reversed(a)         reverse(a.begin(),a.end())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
int INF =1e9;
int res;
map<int,vi> Graph;

int X,Y;
int d1[4]={1,-1,0,0};
int d2[4]={0,0,1,-1};

int graph[250][250];

void bTrack(int x,int y, int depth){

    res = max(res,depth);

    forn(i,4){
        int nX = x+d1[i];
        int nY = y+d2[i];
        if(nX>=0 && nX<X && nY>=0 && nY<Y){
            if(graph[nX][nY]<graph[x][y]){
                bTrack(nX,nY,depth+1);
            }
        }
    }

}

int main(){
   // ifstream cinn("C:\\Users\\Lazaron Shyta\\Desktop\\input.txt");
    //ofstream coutt("C:\\Users\\Lazaron Shyta\\Desktop\\output.txt");

     int cases;cin>>cases;
     forn(it,cases){

        string name;

        cin>>name>>X>>Y;

        forn(i,X)forn(j,Y)cin>>graph[i][j];

        forn(i,X)forn(j,Y)bTrack(i,j,1);

        cout<<name<<": "<<res<<endl;
        res = 0;
     }
}




