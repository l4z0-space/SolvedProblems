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



int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   int n;cin>>n;

   ll a[50];
   a[0]=1;
   a[1]=2;
   a[2]=4;
   for(int i=3;i<=n;i++){
    a[i] = a[i-1]+a[i-2]+a[i-3];
   }
   cout << a[n];


}


