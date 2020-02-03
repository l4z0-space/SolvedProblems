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
typedef pair<double,double> pii;
typedef vector<pii> vii;
int INF = 1e6;




int main(){



    vi nums;
    ll n;
    while(cin>>n && n!=0){
        nums.pb((n));
        while(cin>>n&&n!=0){
            nums.pb((n));
        }

        sorted(nums);
        for(int i=1;i<(int)nums.size();i++){
            nums[i]-=nums[0];
        }
        nums[0]=nums[1];
        ll gcd = nums[0];
        for(auto x:nums){
            gcd=__gcd(gcd,x);
        }
        cout<<gcd<<endl;

        nums.clear();
    }


}








