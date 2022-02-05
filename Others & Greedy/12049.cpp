#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define forn(i,n)           for(int i=0;i<n;i++)
#define pb(b)               push_back(b)
#define sorted(a)           sort(a.begin(),a.end())
#define reversed(a)         reverse(a.begin(),a.end())



int main() {
  // freopen("files/input.txt","r",stdin);
  // freopen("files/myOutput.txt","w",stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc;
  cin >> tc;

  while(tc--){

    int a,b,nxt;
    cin >> a >> b;

    vi first, second;

    map<int,int> map_a, map_b;

    forn(i,a){
      cin >> nxt;
      first.pb(nxt);
      map_a[nxt]++;
    }

    forn(i,b){
      cin >> nxt;
      second.pb(nxt);
      map_b[nxt]++;
    }

    int result = 0;
    // Remove extra elements from the first
    for(int x:first){
      if (map_a[x]>map_b[x]){
        result += map_a[x] - map_b[x];
        map_a[x] -= map_a[x] - map_b[x];
        // cerr << "extra " << x << endl;
      }
    }


    // Remove extra elements from the second
    for(int x:second){
      if (map_a[x]<map_b[x]){
        result += map_b[x] - map_a[x];
        map_b[x] -= map_b[x] - map_a[x];
        // cerr << "extra " << x << endl;
      }
    }

    cout << result << endl;

  }

  

  return 0;
}
