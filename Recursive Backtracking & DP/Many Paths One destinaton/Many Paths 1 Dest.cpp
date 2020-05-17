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
int memoize[10000]={0};
map<int,vi> graph;
map<int,bool>used;
int res=0;
int memo[1000];


int TS(int curr){
  //  cout<<curr<<endl;
    if(graph[curr].size()==0) {memo[curr]=1;}

    if(memo[curr]==0)
    {
        for(int child : graph[curr] ){
                 (memo[curr]+=TS(child));
        }
        return memo[curr];

    }
    else {

        return memo[curr];
    }


 //  cout<<curr<<"\n";
}

int main(){
  //  ifstream cinn("C:\\Users\\Lazaron Shyta\\Desktop\\input.txt");
  //  ofstream coutt("C:\\Users\\Lazaron Shyta\\Desktop\\output.txt");
    int n;
    int cnt=0;
    while(cin>>n){
        if(cnt!=0)cout<<endl;
        forn(i,n)memo[i]=0;
        forn(i,n){
            int a;cin>>a;
            forn(j,a){
                int nxt;cin>>nxt;

                graph[i].pb(nxt);

            }
        }
        TS(0);
        cout<<memo[0]<<endl;
        graph.clear();
        cnt++;


    }
}




