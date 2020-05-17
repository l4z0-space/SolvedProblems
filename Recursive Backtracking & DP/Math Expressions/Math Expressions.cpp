#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <iomanip>
#include <istream>
#include <unordered_set>
#include <stdio.h>
#include <string.h>
#include <list>
#include <unordered_map>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <math.h>
typedef long long ll;
using namespace std;


int tupl[100];
bool possible=0;

void searchs(int a, long t,long target,int n) {
    if(a == n)
       { if(t == target) possible =1 ;
        return;}

    searchs(a + 1, t + tupl[a],target,n);
    searchs(a + 1, t - tupl[a],target,n);
}

int main() {
     {
        int n,target;cin>>n>>target;
        for ( int i = 0 ; i <n ; i++){cin>>tupl[i]; }
        (searchs(1, tupl[0],target,n)) ;
         if(possible)cout<<"Yes\n";
         else cout<<"No\n";
    }
}
