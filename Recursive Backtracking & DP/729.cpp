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


string text;
unordered_map<string,bool> done;
vector<string> all;

void solve(int pos, string res, unordered_map<int,bool>used){

  if (!done[res]){
      done[res] = 1;
  }
  else{
    return;
  }

  if (res.length() == text.length()){
    all.pb(res);
    return;
  }


  for (int i=0;i<text.length();i++){
    if(!used[i]){
      unordered_map<int, bool> temp;
      temp = used;
      temp[i]=1;
      solve(pos, res+text[i], temp);
    }
  }
  return;

}


int main() {
  // freopen("files/input.txt","r",stdin);
  // freopen("files/myOutput.txt","w",stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  
  int tc;
  
  cin>>tc;
  
  while(tc--){
    int a,b;
    cin>>a>>b;
    text = "";
    all.clear();
    done.clear();



    forn(i,b)text+="1";
    forn(i,a-b)text+="0";

    unordered_map<int,bool> used;
    solve(0, "", used);

    sorted(all);
    for(string c:all){
      cout << c << endl;
    }
    if (tc!=0)cout << "\n";
  }


  return 0;
}
