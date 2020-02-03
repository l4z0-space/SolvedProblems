#include <iomanip>
#include <sstream>
#include<unordered_map>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <bitset>
#include <map>
#include <string>
using namespace std;
#define forn(i,n)           for(int i=0;i<n;i++)
#define pb(b)               push_back(b)
#define sorted(a)           sort(a.begin(),a.end())
#define reversed(a)         reverse(a.begin(),a.end())
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef vector<pii> vii;
int INF = 5e5+1;

void factorize(long long n)
{   ll res=0;
    ll ss=0;
    ll counts = 0;

    // count the number of times 2 divides
    while (!(n % 2)) {
        n >>= 1; // equivalent to n=n/2;
        counts++;
    }

    // if 2 divides it
    if (counts){
     //   cout << 2 << "  " << counts << endl;
        ss++;
        res=2;
    }
    // check for all the possible numbers that can
    // divide it
    for (long long i = 3; i <= sqrt(n); i += 2) {
        counts = 0;
        while (n % i == 0) {
            counts++;
            n = n / i;
        }
        if (counts){
           // cout << i << "  " << counts << endl;
            ss++;
            res=i;
        }
    }

    // if n at the end is a prime number.
    if (n > 2){
      //  cout << n << " -- " << 1 << endl;
        ss++;
        res=n;
    }
    if(ss>1)cout<<res<<endl;
    else cout<<-1<<endl;
}
int main(){
   // ifstream cinn("C:\\Users\\Lazaron Shyta\\Desktop\\input.txt");

    ll n;
    while(cin>>n && n){
        if(n<0)n*=-1;
        factorize(n);

    }

}
