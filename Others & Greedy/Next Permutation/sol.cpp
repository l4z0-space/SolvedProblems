#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define forn(i,n)           for(int i=0;i<n;i++)
#define pb(b)               push_back(b)
#define sorted(a)           sort(a.begin(),a.end())
#define reversed(a)         reverse(a.begin(),a.end())


int main(){
    int n;cin>>n;
    while(n--)
        {string a,suff;
        cin>>a;
        int sz=(int)a.length()-1;
        suff=a[sz];
        for(a;sz>0;sz--)
            if(a[sz-1]>=a[sz])suff+=a[sz-1];
            else break;
        reversed(suff);
        if(suff==a){cout<<"no answer\n";continue;}
        sorted(suff);
        sz--;
        for(int i=0;i<(int)suff.length();i++){
            if(suff[i]>a[sz]){
                swap(suff[i],a[sz]);
                break;
            }
        }
        sorted(suff);

        for(int i=0;i<=sz;i++){
            cout<<a[i];
        }
        cout<<suff<<endl;}
}

