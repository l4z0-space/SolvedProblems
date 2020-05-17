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

ll n,m;
ll used[100][100];
ll ress=0;
ll solve(ll i, ll lvl){
    //cout<<i<<" "<<lvl<<endl;
    if(lvl==1){return 1;}
    if(used[i][lvl]!=-1){return used[i][lvl];}

    ll sol = 0;
    for(int ii=i+1;ii<=n;ii++){
        sol += solve(ii,lvl-1);
    }
    return used[i][lvl]=sol;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    forn(i,100)forn(j,100)used[i][j]=-1;
    cin >> n >> m;

    for(int i=1;i<=n;i++)ress+=solve(i,m);
    cout<<ress;

}


