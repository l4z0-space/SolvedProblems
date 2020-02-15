class Solution {
public:
    
    vector<vector<int>> gridd;
    int x ;
    int y ;
    
    int d1[4]={1,-1,0,0};
    int d2[4]={0,0,1,-1};
    int result=0;
    int toAdd;
    void color(int i, int j){
        
        if(i>=0 && i<x && j>=0 && j<y){
            if(gridd[i][j]==0){
                if( i==0 || j==0 || i==x-1 || j==y-1)toAdd=0;
                gridd[i][j]=1;
            }
            else return;
        }
        else return;
        for(int s=0;s<4;s++){
            
            color(i+d1[s],j+d2[s]);
        }
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        x = grid.size();
        y = grid[0].size();
        gridd = grid;
        for (int i=0;i<gridd.size()-1;i++){
            for(int j=0;j<gridd[0].size()-1;j++){
                if(gridd[i][j]==0){
                    toAdd=1;
                    color(i,j);
                    result += toAdd;
                    
                }
            }
        }return result;
    }
};