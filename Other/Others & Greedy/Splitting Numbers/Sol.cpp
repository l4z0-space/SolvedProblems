#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <map>
#include <string>
using namespace std;
#define forn(i,n)           for(int i=0;i<n;i++)
#define pb(b)               push_back(b)
#define sorted(a)           sort(a.begin(),a.end())
#define reversed(a)         reverse(a.begin(),a.end())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
//int INF =1e9;


int lastZERO(int x){

    int last=0;
    for(int i = 0 ;i <= log2(x); i++ ){
            if(! (x&(1<<i)) )last=i;
    }

    return last+1;
}

void show(int x){

    string binary="";
    for(int i = 0 ; i <= log2(x); i++){
        if(x&(1<<i))binary+="1";
        else binary+="0";
    }
    reversed(binary);
    cout <<  binary << endl;
}


void solve(int n){

    int a=0,b=0;
    bool aTurn=1;
    for(int i = 0 ; i <= log2(n) ; i ++ ){

        if(n&(1<<i)){

            if(aTurn)a+=(1<<i),aTurn=0;
            else b+=(1<<i),aTurn=1;

        }

    }
    cout<<a<<" "<<b<<endl;

}


int main(){

    int n;
    while(cin>>n && n!=0){

        solve(n);

    }


}



