#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef map<int,ll> mil;


int main(){						// key idea is to know that (a+b)%n == a%n + b%n

    ll n,a,b;cin>>n;
    mil aa,bb,results;

    for(ll i=1;i<=n;i++){cin>>a;aa[i%3]+=a;}
    for(ll i=1;i<=n;i++){cin>>b;bb[i%3]+=b;}

    for(ll i=0;i<3;i++)for(int j=0;j<3;j++)results[(i+j)%3]+= (aa[i]*bb[j]);	// sol in constant time O(6)=O(1)

    cout<<results[0]<<" "<<results[1]<<" "<<results[2]<<endl;
}
