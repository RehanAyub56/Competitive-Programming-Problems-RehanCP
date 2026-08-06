class Solution {
public:
    int dp[100][100];
    int Paths(vector<vector<int>>&grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();

        if(i>=n || j>=m){
            return 0;
        }
        if(i==n-1 && j==m-1 && grid[i][j]!=1){
            return 1;
        }
        if(grid[i][j]==1){
            return 0;
        }

        


        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int left=Paths(grid,i+1,j);
        int right=Paths(grid,i,j+1);

        dp[i][j]=left+right;

        return dp[i][j];


    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                dp[i][j]=-1;
            }
        }


        return Paths(obstacleGrid,0,0);

    }
};