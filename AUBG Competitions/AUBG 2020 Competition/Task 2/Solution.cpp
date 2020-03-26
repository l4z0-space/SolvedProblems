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

ll memo[40][40][40];
ll X,Y;

ll counts(int rem,int x,int y){

    if(x<0 || y<0 || y>=Y || x>=X )return 0;
 
    if(rem==1)return 1;

    if(memo[rem][x][y] !=-1) return memo[rem][x][y];
    else return memo[rem][x][y] = counts(rem-1,x+1,y)+
                                  counts(rem-1,x,y+1)+
                                  counts(rem-1,x-1,y)+
                                  counts(rem-1,x,y-1);
}

int main() {

    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll sol = 0;
    ll c;
    cin>>X>>Y>>c;
    forn(i,40)forn(j,40)forn(z,40)memo[i][j][z] = -1;
    forn(i,X)forn(j,Y) sol+=counts(c,i,j);
    cout<<sol;
}