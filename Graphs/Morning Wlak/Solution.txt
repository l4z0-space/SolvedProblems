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

//        freopen("C:\\Users\\Lazaron Shyta\\Desktop\\input.txt","r",stdin);
//        freopen("C:\\Users\\Lazaron Shyta\\Desktop\\output.txt","w",stdout);


        int n,r;
        while(cin>>n>>r){
        int balance=0;
        map<int,bool>degree;
        int a,b;
        bool Euler=0;
        forn(i,r){

            cin>>a>>b;

            if(!degree[a])balance--,degree[a]=1;
            else balance++,degree[a]=0;

            if(!degree[b])balance--,degree[b]=1;
            else balance++,degree[b]=0;

            Graph[a].pb(make_pair(b,true));
            Graph[b].pb(make_pair(a,true));

        }
        Euler = r!=0;


        if(Euler)if(balance!=0){Euler=0;}



        if(Euler) {
            EulerTour(cyc.begin(),a);
            Euler = cyc.size() == r;
//            for(list<pii>::iterator it = cyc.begin();it!=cyc.end();it++){
//                cout<< (*it).first <<" "<<(*it).second<<"\n";
//            }
        }
        if(Euler)cout<<"Possible";
        else cout<<"Not Possible";


        cout<<"\n";
        Graph.clear();
        cyc.clear();

}}





