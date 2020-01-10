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
typedef vector<int> vi;
typedef pair<ll,ll> pii;
typedef vector<pii> vii;
int INF = 33000;

bitset<1000010>isPrime;
vi allPrimes;

void sieve(int limit){
    isPrime.set();
    isPrime[0]=0;
    isPrime[1]=0;
    //int LIM = sqrt(limit);
    for(int i=2;i<=limit+1;i++){

        if(isPrime[i]){
            for(int p=i*i;p<=limit;p+=i)
                isPrime[p]=0;

                allPrimes.pb(i);
        }
    }
}

map<int,int>counts;
vi primeFactors(ll N){

    vi factors;
    ll index=0, PF = allPrimes[index];
    while(PF*PF<=N){
        while(N%PF==0){
            N/=PF;
            factors.pb(PF);

            counts[PF]++;
        }
        PF=allPrimes[++index];
    }
    if(N!=1)factors.push_back(N),counts[N]++;
    return factors;
}
ll PP(ll a,ll b){

    int toReturn=1;
    forn(i,b)toReturn*=a;
    return toReturn;

}

int main(){
    //ifstream cinn("C:\\Users\\Lazaron Shyta\\Desktop\\input.txt");
    //ofstream coutt("C:\\Users\\Lazaron Shyta\\Desktop\\output.txt");

    sieve(INF);


    string line;
    while(getline(cin,line) && line!="0"){

        stringstream INPUT(line);
        int number,power;

        ll total=1;

        while(INPUT>>number>>power){
          //  cout<<number<<power<<endl;
       //   cout<<number << " "<<power<<endl;
            ll toM = PP(number,power);
           // cout<<total<< " * " << toM <<"= ";
            total*= toM;
           // cout<<total<<endl;
        }
        total--;
       // cout<<total<<endl;

      //  cout<<"Total: "<<total<<endl;

        vi sol;
        sol = primeFactors(total);

        map<int,bool>used;
        for(int i=(int)sol.size()-1;i>=0;i--){
            int x = sol[i];
            if(!used[x]){

                cout<<x<<" "<<counts[x];
                if(x!=sol[0])cout<<" ";
                used[x]=1;

            }
        }cout<<endl;counts.clear();
    }



}




