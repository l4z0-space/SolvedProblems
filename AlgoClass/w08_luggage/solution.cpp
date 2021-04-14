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

int minCoins(int coins[], int m, int V)
{

    int table[V+1];

    table[0] = 0;

    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;

    for (int i=1; i<=V; i++)
    {
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
              int sub_res = table[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
    return table[V];
}
int main()
{
    int V,m;
  //freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    cin>>V>>m;
  int coins[m];
  forn(i,m)cin>>coins[i];


cout <<  minCoins(coins, m, V);



}



