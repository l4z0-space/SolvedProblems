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

  int num;cin>>num;

  string pizza = "MARGARITA";
  map<char, int>mother_map;

  for (char x:pizza){
    mother_map[x]++;
  }

  forn(i,num){

    string name;
    cin >> name;

    int result = 500000;
    map<char,int> hm;

    for (char c : name){
      hm[c]++;
    }

    // cout << hm['M'];

    for (char c : pizza){

      result = min(result,  hm[c]/mother_map[c] );
    }

    cout << result << "\n";
  }
  return 0;

}