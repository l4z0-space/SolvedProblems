class Solution {
public:
    int numTrees(int n) {
        if(n==1)return 1;
        vector<int>dp(2*n+1);
        dp[0]=1;dp[1]=1;dp[2]=2;dp[3]=5;
        
        for(int i=4;i<=n;i++){
            dp[i]=0;
            for(int j=0;j<i;j++){
                dp[i]+= dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};


