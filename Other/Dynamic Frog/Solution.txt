#include <iomanip>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <queue>
#include <math.h>
#include <cstdlib>
#include <bitset>
#include <map>
#include <string>
#include <cstring>
using namespace std;
#define forn(i,n)           for(int i=0;i<n;i++)
#define pb(b)               push_back(b)
#define sorted(a)           sort(a.begin(),a.end())
#define reversed(a)         reverse(a.begin(),a.end())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,char> pii;
typedef vector<pii> vii;
int INF = 1e9;
double pi = acos(-1);



int main() {


    int tcs;cin>>tcs;
    forn(tc,tcs){
        int n,d;
        cin>>n>>d;
        vii river;
        forn(i,n){
            char a,b;int place;
            cin>>a>>b>>place;
            river.pb(pii(place,a));
        }
        sorted(river);
        river.pb(pii(d,'B'));

        int result=0;
        map<int,bool>used;
        int lastPlace=0;
        bool jump=0;
        for(int pos=0;pos<=n;pos++){
            if(river[pos].second=='B'){
                    result=max(result,river[pos].first-lastPlace);
                    lastPlace=river[pos].first;
            }
            else{
                if(jump==0)jump=1;
                else{
                    result=max(result,river[pos].first-lastPlace);
                    lastPlace=river[pos].first;
                    jump=0;
                    used[pos]=1;
                }
            }
        }
        lastPlace=0;
        for(int pos=0;pos<=n;pos++){
            if(!used[pos]){
                result = max(result,river[pos].first-lastPlace);
                lastPlace=river[pos].first;
            }
        }
        printf("Case %d: %d\n", tc+1 ,result);

    }

}






