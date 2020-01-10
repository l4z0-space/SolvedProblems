#include <iomanip>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <queue>
#include <math.h>
#include <cstdlib>
#include <bitset>
#include <map>
#include <string>
#include <list>
#include <cstring>
using namespace std;
#define forn(i,n)           for(int i=0;i<n;i++)
#define pb(b)               push_back(b)
#define sorted(a)           sort(a.begin(),a.end())
#define reversed(a)         reverse(a.begin(),a.end())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef pair<pii,int>ppi;
typedef vector<ppi>vpi;
int INF = 1e9;
double pi = acos(-1);

// 1 2 3 4 5 6 7 8
ll mod = 1e9+7;

// Eulerian Cycle

map<int,vector<pair<int,bool>>>Graph;

list<pii>cyc;
void EulerTour(list<pii>::iterator i, int u){
    for(auto &edge : Graph[u]){
        if(edge.second){
            int v = edge.first;
            edge.second = 0;
            for(auto &bi_edge : Graph[v]){
                if(bi_edge.first == u && bi_edge.second){
                    bi_edge.second=0;
                    break;
            }}
            EulerTour(cyc.insert(i,make_pair(v,u)),v);
}}}


int main() {

    int tc;cin>>tc;
    forn(cc,tc)
     {

        vii edges;
        int n;
        cin>>n;
        int balance=0;
        map<int,bool>degree;
        int a,b;
        forn(i,n){

            cin>>a>>b;

            if(!degree[a])balance--,degree[a]=1;
            else balance++,degree[a]=0;

            if(!degree[b])balance--,degree[b]=1;
            else balance++,degree[b]=0;

            Graph[a].pb(make_pair(b,true));
            Graph[b].pb(make_pair(a,true));

        }
        printf("Case #%d\n",cc+1);
        if(balance!=0){cout<<"some beads may be lost\n";}



        else {
            EulerTour(cyc.begin(),a);
            for(list<pii>::iterator it = cyc.begin();it!=cyc.end();it++){
                cout<< (*it).first <<" "<<(*it).second<<"\n";
            }
        }

        cout<<"\n";
        Graph.clear();
        cyc.clear();
        }
}





