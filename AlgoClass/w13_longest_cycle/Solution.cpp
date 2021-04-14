#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define forn(i,n)           for(int i=0;i<n;i++)
#define pb(b)               push_back(b)
#define sorted(a)           sort(a.begin(),a.end())
#define reversed(a)         reverse(a.begin(),a.end())
#define print(a)            cout<<a;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;

map<int,vi>Graph;

bool v[1000];
int maxL=0;

void dfs(int i,int beg, int L){

    v[i]=1;

    for(int x: Graph[i]){

        if(!v[x])
            dfs(x,beg,L+1);

        else if (x==beg)
            maxL=max(maxL,L);
    }
}


int main() {

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    forn(i,m){
        int a,b;
        cin>>a>>b;
        Graph[a].pb(b);
        Graph[b].pb(a);
    }

    forn(i,n){

        forn(i,n)v[i+1]=0;
        dfs(i+1,i+1,1);
    }

    cout << maxL;
}
