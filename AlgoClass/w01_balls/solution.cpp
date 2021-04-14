#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long int ,bool> used;


int main() {

ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 long long int n;
 int k;
long long int nxt;
 cin>>n>>k;

 while(k--){
   
   cin>>nxt;

   if(!used[nxt]){
     used[nxt]=1;
     n--;
   }

 }cout<<n;


}