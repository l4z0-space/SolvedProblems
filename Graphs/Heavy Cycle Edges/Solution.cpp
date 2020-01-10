#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<char>vch;
typedef vector<bool>vb;					//(MST) Kruskal's
typedef map<int,vi>alist;
typedef map<string,int>msi;
typedef map<string,string>mss;

vi parent(1000000);
vi ranks(1000000);


int findSet(int start){
    if(parent[start]==start)return start;
    else return parent[start]=findSet(parent[start]);
}

bool sameSet(int a,int b){
    return findSet(a)==findSet(b);
}

void unionSet(int a, int b){
    if(!sameSet(a,b)){
        int pa=findSet(a);
        int pb=findSet(b);
        if(ranks[pa]>ranks[pb])parent[pb]=pa;
        else{
            parent[pa]=pb;
                if(ranks[pa]==ranks[pb])ranks[pb]++;
        }
    }
}

void initUF(int n){
    for(int i=0;i<=n;i++){
        parent[i]=i;
        ranks[i]=0;
    }
}

void printResult(vi s){
    for(int i=0;i<(int)s.size();i++){
        cout<<s[i];
        if(i!=(int)s.size()-1)cout<<" ";
    }cout<<endl;
}

int main(){
    int E,V;
    while(cin>>V>>E){
        vi sols;
        bool hasCycle=0;
        if(V==0 && E==0)break;
        int total=0;
        vector<pair<int,pii>>EdgeList;
        int u,v,w; // w is weight
        for(int i=0;i<E;i++){
            cin>>u>>v>>w;
            total+=w;
            EdgeList.push_back(make_pair(w,pii(v,u)));
        }
        sort(EdgeList.begin(),EdgeList.end());
        int mst_cost=0;
        initUF(V);
        for(int i=0;i<E;i++){
            pair<int,pii>fronts=EdgeList[i];
            int x=fronts.second.first;  //first vertex
            int y=fronts.second.second; //second vertex
            if(!sameSet(x,y)){      // check for a cycle
                mst_cost+=fronts.first; // add the weight
                unionSet(x,y); // unions the vertex(s)
            }
            else{hasCycle=1;sols.push_back(fronts.first);}
        }

        if(hasCycle)printResult(sols);
        else cout<<"forest\n";
    }



}







