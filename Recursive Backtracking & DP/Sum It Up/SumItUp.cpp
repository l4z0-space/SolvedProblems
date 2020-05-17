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
#include <string>
#include <climits>
#include <iomanip>
using namespace std;
vector<int>nums;
vector<int>sol;
map<vector<int>,bool>check;
bool found =0;

int target,n;

void print(){
    for(int i=0;i<(int)sol.size();i++){
        if(i!=(int)sol.size()-1)cout<<sol[i]<<"+";
        else cout<<sol[i];
    }cout<<endl;
}

void dfs(int sum,int pos){

    if(sum==target){
            if(check[sol]==0){
                    print();
                    found=1;
                    check[sol]=1;}
            else return;}
{
    for(int i=pos+1;i<n;i++){
        if(sum+nums[i]<=target){
            sol.push_back(nums[i]);


            dfs(sum+nums[i],i);
            sol.pop_back();}
    } }

    return;


}

int main()
{

    while(cin>>target>>n && n!=0){
        for(int i=0;i<n;i++){
            int q;cin>>q;
            nums.push_back(q);
        }
        sort(nums.begin(),nums.end(),greater<int>());
        cout<<"Sums of "<<target<<":\n";

        for(int i=0;i<n;i++){
            if(nums[i]<=target){
              //  cout<<nums[i]<<endl;dfs(nums[i],i);
                sol.push_back(nums[i]);
                dfs(nums[i],i);
                sol.clear();

            }
        }
        if(!found)cout<<"NONE\n";
        check.clear();
        found=0;
        sol.clear();
        nums.clear();
    }

}





