#include <iomanip>
#include <sstream>
#include<unordered_map>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <bitset>
#include <map>
#include <string>
using namespace std;
#define forn(i,n)           for(int i=0;i<n;i++)
#define pb(b)               push_back(b)
#define sorted(a)           sort(a.begin(),a.end())
#define reversed(a)         reverse(a.begin(),a.end())
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef vector<pii> vii;
int INF = 5e5+1;
int Price[25][210];
int limit,total;

int memo[1000][1000];


int CS(int pos, int sum){
    if(sum>limit)return -1e5;

    if(pos==total+1)return sum;
    
    if(memo[pos][sum]!=-1)return memo[pos][sum];

    int sol=-1;
    for(int i=1;i<=(int)Price[pos][0];i++)
        sol = max(sol,CS(pos+1,sum+Price[pos][i]));

    return memo[pos][sum]=sol;

}


int main(){
//ifstream cinn("C:\\Users\\Lazaron Shyta\\Desktop\\input.txt");
       int tc;cin>> tc;
       while(tc--){
          cin>>limit>>total;
          forn(i,500)forn(j,500)memo[i][j]=-1;

          forn(i,total){
            int n;cin>>n;
            Price[i+1][0]=n;
            forn(j,n){
                int nxt;cin>>nxt;
                Price[i+1][j+1]=nxt;
            }
          }

          for(int i=1;i<total;i++){
          //  for(auto x: Price[i])cout<<x<<" ";
          }
            int res = CS(1,0);
            if(res<0)cout<<"no solution\n";
            else cout<<res<<endl;
       }

}
