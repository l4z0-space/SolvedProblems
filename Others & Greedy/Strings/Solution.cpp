#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<char>vch;
map<string,int>counter;


int main(){			// the idea is to keep track of the strings in a map and then print it if reaches the target
    vector<string>all;
    while(true){
        string input;
        cin>>input;
        int sz=(int)input.length();
        int target=sz/8;
        for(int i=0;i<sz-3;i++){
            string next="";
            for(int j=i;j<i+4;j++)next+=input[j];
            counter[next]++;
            if(counter[next]>target){
		all.push_back(next);
                cout<<next<<endl;
                break;
            }
        }
	sort(all.begin(),all.end());
	cout<<all[0]<<endl  // print smallest 
        counter.clear();
    }
}
