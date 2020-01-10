// **Lazaron Shyta Uhunt: lazo99
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <fstream>
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
typedef long long  ll;



int main(){


    string n;
    int k;
    cin>>n>>k;
    k--;

while(k--){
    string next="";
    int toNext=0;
    char curr=n[0];

        for(int i=0;i<(int)n.length();i++){
            if(n[i]==curr){
                toNext++;
            }
            else {
                next += to_string(toNext);
                next+=curr;
                curr= n[i];
                toNext=1;
            }
            if(i==(int)n.length()-1){
                next += to_string(toNext);
                next+=curr;
            }

        }

    n = next; }

    cout << n<<endl;


}




