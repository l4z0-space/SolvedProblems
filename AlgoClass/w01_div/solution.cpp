#include <iostream>
using namespace std;


int numOfDiv(int a){

  int toReturn=0;

  for(int i=2;i<a;i++){
    if(a%i==0)toReturn++;
  }
  return toReturn;
}


int main() {
  int n,m;
  cin>>n>>m;
  int res=0;
  int NXT;
  while(n--){
    cin>>NXT;
    if(numOfDiv(NXT)==m)res++;
  }cout<<res;

}