// **Lazaron Shyta Uhunt: lazo99
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <queue>
#include <bitset>
#include <cstring>
#include <string>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long  ll;      // given a,b,c how many pairs of primes x,y exists such that y=x+c
int a,b,c;



vector<bool>is(50000000);


void isPrime(ll n){



    for(int i=2; i*i<=n;i++){
        if(is[i]!=1){
            for(int p=i*i; p<=n;p+=i){
                is[p]=1;
            }
        }
    }


}



int main()
{
    int result=0;

    cin>>a>>b>>c;
    int limit = b-c;
    isPrime(b);
    for(int i=a;i<=limit;i++){
        if(!is[i]&&!is[c+i]  ){
                result++;
     //   cout<< i<< " " << c+i<<endl;
        }
    }
    cout<<result<<endl;

}




