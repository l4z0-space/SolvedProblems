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
   long long a[40][40]={0};

   for(int i=0;i<n;i++)a[i][0]=1,a[0][i]=1;

   for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
        a[i][j]=a[i-1][j]+a[i][j-1];
    }
   }
   cout<<a[n-1][n-1];
}


