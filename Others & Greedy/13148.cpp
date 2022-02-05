#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
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

  
  set<int> all = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,
    1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224,
    47045881, 64000000, 85766121};



  int nxt;
  while(cin>>nxt){
    if (nxt ==0)break;
    string res = all.count(nxt) ? "Special" : "Ordinary";
    cout << res << "\n";
  }
  
  

  return 0;
}
