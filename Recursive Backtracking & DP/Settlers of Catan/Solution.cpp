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
#include <cstring>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
int res=0;
map<int,vi>graph;
map<pii,bool>used;
int n,m;

void btrack(int depth,int pos){
  
    res=max(res,depth);

    for(int i=0;i<(int)graph[pos].size();i++){

        int next=graph[pos][i];

        if( used[pii(pos,next)] ){

            used[pii(pos,next)]=0;
            used[pii(next,pos)]=0;

            btrack(depth+1,next);

            used[pii(pos,next)]=1;
            used[pii(next,pos)]=1;
        }
       
    }
}


int main(){


    while(cin>>n>>m && n!=0 && m!=0){

        while(m--){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            used[pii(a,b)]=1;
            used[pii(b,a)]=1;
        }
        for(int i=0;i<n;i++){
         
            btrack(0,i);
        }
        used.clear();
        graph.clear();
        cout<<res<<endl;
        res=0;
    }
}