class Solution {
public:

    map<int,string>nun;

    vector<string>result;

    void init(){
    
    nun[2]="abc";

        nun[3]="def";

        nun[4]="ghi";

        nun[5]="jkl";

        nun[6]="mno";

        nun[7]="pqrs";

        nun[8]="tuv";

        nun[9]="wxyz";

    }
   

 
    
	void dfs(string seq, string cur,int lvl,int limit){

        	if(lvl==limit){
			if(cur!="")result.push_back(cur);
			return;
	}
        
        
		for(char x:bnun[seq[lvl]-'0'])dfs(seq,cur+x,lvl+1,limit);
       
  	}



 	vector<string> letterCombinations(string digits) {

        	init();
        
		dfs(digits,"",0,digits.size());

       		return result;

    }
};