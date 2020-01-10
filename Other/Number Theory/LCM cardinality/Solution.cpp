#include <iomanip>
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
int INF = 1e6;


vi findDiviors(ll num){

    int limit = sqrt(num);
    map<int,bool>used;

    vi divisors;
    for(ll div1=1;div1<=limit;div1++){

        if(num%div1==0){

            ll div2=num/div1;
            if(!used[div1]){used[div1]=1;divisors.pb(div1);}
            if(!used[div2]){used[div2]=1;divisors.pb(div2);}

        }
    }

    return divisors;
}

int main(){
    //ifstream cinn("C:\\Users\\Lazaron Shyta\\Desktop\\input.txt");
    //ofstream coutt("C:\\Users\\Lazaron Shyta\\Desktop\\output.txt");
    int n;
    while(cin>>n && n!=0){
        vi divisors = findDiviors(n);

        int res=0;
        int sz = (int)divisors.size();
        for(int i=0;i<sz-1;i++){
            for(int j = i+1;j<sz;j++){
                ll a = divisors[i];
                ll b = divisors[j];
               // cout<<a <<" "<<b<<endl;
                if(  n == a*(b/__gcd(a,b))  )
                    res++;
            }
        }

        cout<<n<<" "<<res+1<<endl;
    }

}








