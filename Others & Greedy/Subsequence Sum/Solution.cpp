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
map<int,bool>store;


int main(){

    vi nums;
    int n,t;
    cin>>n>>t;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        nums.push_back(a);
    }
    vi nn=nums;
    sort(nums.begin(),nums.end());
    for(int i=n-1;i>=n-t;i--){
        store[nums[i]]=1;
    }
    for(int i=0;i<n;i++){
        if(store[nn[i]])cout<<nn[i]<<" ";
    }
}
