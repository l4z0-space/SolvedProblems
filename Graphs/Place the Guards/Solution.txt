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
    int cs;cin>>cs;
    while(cs--){
        colors.assign(10000+15,INF);
        G.clear();

        cin>>n>>m;
        colors[0]=0; // colors first node
        forn(i,m){
            int a,b;
            cin>>a>>b;
            avail[a]=1;avail[b]=1;
            G[a].pb(b);
            G[b].pb(a);
        }
        queue<int>q;
        q.push(0);
        bool OK=1;
        int res=0;
        int z=0,o=0;
        while(!q.empty() && OK){

            int curr = q.front();q.pop();
            if(colors[curr]==0)z++;
            else o++;

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
            if(q.empty()){
                int nxt=findNext();
                if(min(z,o)==0)res+=max(z,o);
                else res+=min(z,o);
                z=0;o=0;
                if(nxt==-2)break;
                else q.push(nxt);
            }
        }


        if(OK)cout<<res;
        else cout<<-1;
        cout<<endl;

    }
}






