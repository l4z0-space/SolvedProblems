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

  
  string next;

  unordered_map<char,int> m;

  m['B']=1;
  m['F']=1;
  m['P']=1;
  m['V']=1;

  m['C']=2;
  m['G']=2;
  m['J']=2;
  m['K']=2;
  m['Q']=2;
  m['S']=2;
  m['X']=2;
  m['Z']=2;

  m['D']=3;
  m['T']=3;

  m['L']=4;
  m['M']=5;
  m['N']=5;
  m['R']=6;



  while(cin>>next){
    string res = "";
    string a = "0";
    for (char c: next){
      if ( m[a[a.length()-1]] != m[c]){
        a += c;
      }
    }


    for (char c: a){
      if(m[c])res += to_string(m[c]);
    }

    cout << res << endl;;  
    }

  return 0;
  }
