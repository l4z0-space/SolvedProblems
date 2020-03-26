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

unordered_map<int,int> diff;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sol=0;
    diff[0]=-1;

    string s;
    cin>>s;

    int z=0,o=0;
    int sz = (int)s.length();

    for(int i=0;i<sz;i++){
        char curr = s[i];
        if(curr=='0')z++;
        else o++;
        if(diff[o-z]) sol = max(sol, i - diff[o-z]);
        else diff[o-z] = i;
    }
    cout <<sol;
}