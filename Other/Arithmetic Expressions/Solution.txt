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
string expression,toSolve;
vi nums;
vch signs;


int toNum(string a){
    int res=0;
    int dec=1;
    for(int i=(int)a.length()-1;i>=0;i--){
        res+=(a[i]-'0') * dec;          // string to int
        dec*=10;
    }
    return res;
}

void takeNums(){

    for(int i=0;i<(int)expression.length();i++){
        if( (expression[i] =='-' || expression[i]=='+') && i!=(int)expression.length()-1 ){
            string toDo="";
            int start=i+1;
            while(true){

                if(expression[start]=='-'||expression[start]=='+'){         // stores the numbers in a vector
                        nums.push_back(toNum(toDo));
                        if(start<(int)expression.length())i=(start-1);
                        break;
                }
                toDo+=expression[start];
                start++;
            }
        }
    }
}

void takeSigns(){
    for(int i=0;i<(int)expression.length()-1;i++){
        if(expression[i]=='+'||expression[i]=='-'){     // stores the signs in a vector
            signs.push_back(expression[i]);
        }
    }
}

int main(){

    while(true){
        int total=0;
        cin>>toSolve;

        if(toSolve[0]=='+'|| toSolve[0]=='-'){
            expression=toSolve+"+";
            takeNums();
        }
        else{
            expression="+"+toSolve+"+";
            takeNums();
        }

        takeSigns();

        for(int i=0;i<(int)nums.size();i++){
            if(signs[i]=='+')total+=nums[i];        // calculate
            else if(signs[i]=='-')total-=nums[i];
        }

        cout<<toSolve<<"="<<total<<endl;

        signs.clear();
        nums.clear();
    }
}
