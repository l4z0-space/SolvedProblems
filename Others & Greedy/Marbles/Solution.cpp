#include <bits/stdc++.h>
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
map<int,bool>used;


        /* Distributing m identical things amongst n identical people
           (m+n-1) choose (n-1) */

ll binomial_coefficient(int n, int m)
{
    ll res = 1;

    if (m > n - m)
        m = n - m;

    for (int i = 0; i < m; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    int tc;cin>>tc;
    while(tc--){

        ll a ,b;
        cin>>a>>b;

        if(a==b)cout<<1;


        else cout<<binomial_coefficient(a-1,b-1);
        cout<<"\n";
    }


}









