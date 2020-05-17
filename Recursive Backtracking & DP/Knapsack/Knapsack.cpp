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

int n,tW;
int w[105],v[105];
int memo[1000][1000];
int res = 0;

int solve(int currW,int lvl){
    if(lvl==n || currW==tW){
        return 0;
    }

    if(memo[currW][lvl]!=-1)return memo[currW][lvl];

    if(currW+w[lvl]<=tW) return memo[currW][lvl] = max(
                                  v[lvl] + solve(currW + w[lvl],lvl+1),// consider element
                                  solve(currW,lvl+1)); //  ignore element
    else return solve(currW,lvl+1);
}



int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>tW;
    forn(i,1000)forn(j,1000)memo[i][j]=-1;
    forn(i,n){
        int a,b;
        cin >> a >> b;
        w[i]=a;
        v[i]=b;
    }
    cout<<solve(0,0);

}


