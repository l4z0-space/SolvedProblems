class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz  = s.length();
        int result = 0;
        for(int i=0;i<sz;i++){
            int preRes=0;
            map<char,int> cnt;
            for(int j = i ; j <sz;j++){
                if(cnt[s[j]]==0){
                    preRes++;
                    result=max(result,preRes);
                    cnt[s[j]]++;
                    
                }else break;
            }
        }return result;
    }
};