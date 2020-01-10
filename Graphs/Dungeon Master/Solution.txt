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
map<pii,int>DimLvl;


int d,x,y;

int d1[6]={1,-1,0,0,0,0};
int d2[6]={0,0,1,-1,0,0};
int d3[6]={0,0,0,0,1,-1};

char Dimension3[100][100][100];

bool isSafe(int a, int b, int lvl){
    if(a<0 || a>=x || b<0 || b>= y || lvl<0 || lvl>=d)return false;
    return true;
}



int main(){
    int LL;
    while(cin>>d>>x>>y){
        if(d==0 && x==0 && y==0)break;
        pii start,ends;
        for(int i=0;i<d;i++){

            for(int a=0;a<x;a++){
                for(int b=0;b<y;b++){
                    char s;cin>>s;
                    Dimension3[i][a][b]=s;

                    if(s=='S'){start=pii(a,b);DimLvl[start]=i;LL=i;Dimension3[i][a][b]='.';}
                    if(s=='E'){ends=pii(a,b);DimLvl[ends]=i;Dimension3[i][a][b]='.';}
                }
            }
        }

        pair<pii,pii>a = make_pair(start,pii(0,LL)); // mins and lvl
        queue<pair<pii,pii>>q;
        q.push(a);
        bool found =0;
        while(!q.empty()){
            a =q.front();q.pop();
            int currX=a.first.first;
            int currY=a.first.second;
            int meters =a.second.first;
            int lvl = a.second.second;
            if(currX == ends.first && currY==ends.second && lvl==DimLvl[ends] ){
                cout<<"Escaped in "<<meters<<" minute(s).\n";
                found=1;
                break;
            }

            for(int i=0;i<6;i++){
                int nextX=currX+d1[i];
                int nextY=currY+d2[i];
                int nextLvl=lvl+d3[i];
                if(Dimension3[nextLvl][nextX][nextY]=='.'){
                    Dimension3[nextLvl][nextX][nextY]='#'; // mark as visited
                    q.push(make_pair(pii(nextX,nextY),pii(meters+1,nextLvl)));
                }
            }

        }

        if(!found)cout<<"Trapped!\n";
        DimLvl.clear();


    }


}


