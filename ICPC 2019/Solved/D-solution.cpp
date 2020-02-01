#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
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
#define print(a)            cout<<a;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,char> pii;
typedef vector<pii> vii;
typedef pair<pii,int>ppi;
typedef vector<pii>vp;

double pi = acos(-1);


void Yes(){
    cout<<"YES\n";
}
void No(){
    cout<<"NO\n";
}


int main(){

   // freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);

   string a;
   cin>>a;

   string x="";
   string remains="";
   string result="";

   map<char,int>cnt;
   int maxC=0;
   char mostC;
   for(char c:a){
        cnt[c]++;
        if(cnt[c]>maxC){
            maxC=cnt[c];
            mostC=c;
        }
    }

    for(char ss:a){if(ss!=mostC)remains+=ss;}
    int n = (int)a.length()/2;
    sorted(a);

    if(maxC<=n){Yes();print(a);return 0;} // maxC <= n YES
    if(maxC==2*n || maxC==2*n-1){No();return 0;}    // all chars the same NO

    if(maxC==2*n-2 && n>=3){
        string temp="";
        string rest="";
        map<char,bool>used;
        for(char i:a){
            if(!used[i]){used[i]=1;temp+=i;if(i!=mostC)rest+=i;}
        }
        if(rest.length()==1){No();return 0;} //if other chars the same NO
        result=rest[0];
        for(int i=0;i<n-1;i++)result+=mostC;
        result+=rest[1];
        for(int i=0;i<n-1;i++)result+=mostC;
        Yes();print(result);return 0;       //if other chars different YES
    }

    if(maxC>=n && maxC<=2*n-3){
        result="";
        result+=remains[0];
        int totalLen=2*n;
        totalLen--;
        forn(i,n)result+=mostC,totalLen--;
        for(int i=1;i<(int)remains.length();i++){
            result+=remains[i];
            totalLen--;
        }
        forn(i,totalLen)result+=mostC;
        Yes();print(result);return 0;

    }

 //   No();return 0;

}



