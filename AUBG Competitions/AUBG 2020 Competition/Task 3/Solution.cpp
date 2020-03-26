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

    int n,m;
    cin>>n>>m;
    vii first,second;
    forn(i,n){
        int a,b;
        cin>>a>>b;
        first.pb(make_pair(a,b));
        second.pb(make_pair(b,a));
    }
    sorted(first);
    sorted(second);
    int sol=0;
    forn(i,n){
        pii curr1 = first[i];
        swap(curr1.first,curr1.second);
        vii :: iterator low;
        low = lower_bound(second.begin(),second.end(),curr1);
        int pos = low - second.begin();
        pos--;
        for(;pos>=0;pos--)
            if(second[pos].second>curr1.second){sol++;}
    }

    cout<<sol;
}


