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
ll a,b,c;
ll memo[500][500];
ll solve(ll sum,ll low){
    if(sum==a)return 1;
    if(sum>a)return 0;
    if(memo[sum][low]!=-1)return memo[sum][low];
    ll sol = 0;
    for(ll i=low;i<=c;i++){
        sol += solve(sum+i,i);
    }
    return memo[sum][low]=sol;
}

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    forn(i,500)forn(j,500)memo[i][j]=-1;
    cin>>a>>b>>c;
    cout<<solve(0,b);

}


