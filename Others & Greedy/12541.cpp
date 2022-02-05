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

  vector< pair< pii, pair<int, string> >> persons;

  forn(i,num){

    string name;
    int dd, mm, yyyy;

    cin >> name >> dd >> mm >> yyyy;

    auto person = make_pair( make_pair(yyyy,mm) ,  make_pair(dd,name) );

    persons.push_back(person);

  }

  sorted(persons);
  cout << persons[persons.size()-1].second.second << "\n";
  cout << persons[0].second.second << "\n";
  


  return 0;

}