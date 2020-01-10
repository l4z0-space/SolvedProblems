#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<double,double> pii;
typedef vector<pii> vii;
#define forn(i,n)           for(int i=0;i<n;i++)
#define pb(b)               push_back(b)
#define sorted(a)           sort(a.begin(),a.end())
#define reversed(a)         reverse(a.begin(),a.end())

int INF =1e9;
int n,m;
vi colors;
map<int,vi>G;
map<int,bool>avail;
int findNext(){

    for(int i=0;i<n;i++){
        if(colors[i]==INF){
            colors[i]=0;
            return i;
        }
    }
    return -2;
}

int main(){
/*
    ifstream cinn("C:\\Users\\Lazaron Shyta\\Desktop\\input.txt");
    ofstream coutt("C:\\Users\\Lazaron Shyta\\Desktop\\output.txt");
*/

    while(cin>>n && n!=0){
        colors.assign(n+15,INF);
        G.clear();

        int a,b;
        colors[0]=0; // colors first node
        while(cin>>a>>b){
            if(a==0 && b==0)break;
            G[a].pb(b);
            G[b].pb(a);
        }
        queue<int>q;
        q.push(1);
        bool OK=1;
        while(!q.empty() && OK){

            int curr = q.front();q.pop();

            for(int x:G[curr]){
                if(colors[x]==INF){
                    colors[x]=1-colors[curr];
                    q.push(x);
                }
                else{
                    if(colors[x]==colors[curr]){
                        OK=false;
                        break;
                    }
                }
            }

        }

        if(OK)cout<<"YES\n";
        else cout<<"NO\n";

    }
}






