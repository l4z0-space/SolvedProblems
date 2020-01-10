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
int INF = 1e9;
vi nums;
int total=0,n;

vi memo[100];

int divide(int pos,int sum){

    int temp = total - sum;
    int minD = abs(temp-sum);

    if(pos==n)return minD;

    if(memo[pos][sum]!=-1)return memo[pos][sum];

    return memo[pos][sum]=min(minD,min(divide(pos+1,sum+nums[pos]),
                        divide(pos+1,sum)));
}






int main(){
//ifstream cinn("C:\\Users\\Lazaron Shyta\\Desktop\\input.txt");

    int tc;cin>>tc;
    while(tc--){
        cin>>n;
        forn(i,n){int a;cin>>a;nums.pb(a);total+=a;}
        forn(i, n)memo[i].resize(total);
        forn(i,n)forn(j,total)memo[i][j]=-1;

        cout<<divide(0,0)<<endl;
        nums.clear();
        total=0;
    }
}
