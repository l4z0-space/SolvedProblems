class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n,m;
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        
        long long dp[n+10][m+10]={0};
        
        dp[0][0]=1-obstacleGrid[0][0];
        
        
        for(int i =1;i<n;i++)dp[i][0]=min(dp[i-1][0],(long long)1-obstacleGrid[i][0]);
        for(int i =1;i<m;i++)dp[0][i]=min(dp[0][i-1],(long long)1-obstacleGrid[0][i]);
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j]==0)dp[i][j]+= dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};