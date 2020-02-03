#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;


long long pisano(long long m){

    long long a=0,b=1,c=a+b;
    for(long long i=0;i<m*m;i++){       // pisano period return position when a==0 and b==1 because of pattern
        c= (a+b)%m;
        a=b;
        b=c;
        if(a==0 && b==1)return i+1;

    }
}


long long solve(long  n,long m){

    long long iters =n % pisano(m);     // until reaches first cycle
    long long a=0,b=1,c=iters;
    for(long long i=1;i<iters;i++){
        c=(a+b)%m;
        a=b;
        b=c;
    }
    return c%m;         //result
}


main(){

	long long n,m;
	cin>>n>>m;
	cout<<solve(n,m);
	}
