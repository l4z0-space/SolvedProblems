// 8

int main(){

    ifstream input("numbers.txt");  //input file
    ofstream output("sorted.txt");  //output file

    vector<int>nums;
    int next;
    while(input>>next){     // read nums
        nums.push_back(next);
    }
    input.close();

    sort(nums.begin(),nums.end());      //sort increasing order

    for(int i=0;i<(int)nums.size();i++){
        output<<nums[i]<<endl;      // file output created with sorted nums
    }

}