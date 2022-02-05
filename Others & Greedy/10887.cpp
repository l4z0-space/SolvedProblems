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

  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  
  int tc;
  scanf("%d",&tc);  
  string nxt;
  map<string, int> mp;
  int a,b, result = 0;
  string first[1501], second[1501];

  forn(casenum, tc){
    

    scanf("%d %d",&a,&b);
    getchar();
  
    forn(i,a){
      getline(cin, first[i]);
    }

    forn(i,b){
      getline(cin, second[i]);
    }

    mp.clear();
    forn(i,a){
        forn(j,b){
          string cont = first[i] + second[j];
          if (!mp[cont]){
              mp[cont]=1;
              result++;
          }
      }
    }

    printf("Case %d: %d\n",casenum+1,result);
    result=0;

  }
  


  return 0;
}
