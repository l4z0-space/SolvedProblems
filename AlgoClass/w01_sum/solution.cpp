#include <iostream>
#include <algorithm> 
using namespace std;


int main() {
  int a,b;
  cin>>a>>b;
  int total=0;
  if(a>b)swap(a,b);
  for(int i=a;i<=b;i++){
    total+=i;
  }cout<<total;
}