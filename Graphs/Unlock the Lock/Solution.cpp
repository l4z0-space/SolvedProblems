#include <iostream>
#include <string>
#include <queue>
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
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,int> pii;
typedef vector<pii> vii;


int main(){


        int cnt=1;
        ll start,ends,n;
        while(cin>>start>>ends>>n){
            if(start==0 && ends==0 && n==0)break;
            vi all;
            while(n--){
                ll w;cin>>w;
                all.push_back(w);
            }
            int result=0;
            queue<pii>q;
            q.push(pii(start,0));
            bool found=0;
            printf("Case %d: ",cnt++);
            map<ll,bool>used;
            while(!q.empty()){

                pii curr = q.front();
                ll sum=curr.first;
                int steps=curr.second;
                q.pop();
                if(sum==ends){found=1;result=steps;break;}

                for(int i=0;i<(int)all.size();i++){
                    ll nextSum = (sum+all[i])%10000;
                    if(!used[nextSum]){
                        q.push(pii(nextSum,steps+1));
                        used[nextSum]=1;
                    }
                }

            }
            if(!found)cout<<"Permanently Locked\n";
            else cout<<result<<endl;
        }
}
