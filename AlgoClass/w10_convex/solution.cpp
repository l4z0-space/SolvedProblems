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
typedef vector<pii> vii;      // area half of the determinant of the polygon

unordered_map<int,int> diff;

double area( vii P){
    double result =0.0,x1,x2,y1,y2;

    forn(i,(int)P.size()-1){
        x1 = P[i].first;
        x2 = P[i+1].first;
        y1 = P[i].second;
        y2 = P[i+1].second;
        result += (x1*y2 - x2*y1);
        //cout<<(x1*y2 - x2*y1)<<endl;
    }
    return fabs(result/2.0);

}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vii vec;

    int n;cin>>n;

    while(n--){
        double a,b;
        cin>>a>>b;
        vec.pb(make_pair(a,b));
    }

    vec.pb(vec[0]);
   // sorted(vec);

    cout<<fixed<< setprecision(1)<<area(vec);
}


