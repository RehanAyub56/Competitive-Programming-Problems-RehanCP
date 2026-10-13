class Solution {
public:
int Sum(vector<vector<int>>&grid,vector<vector<int>>&dp,int sum,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i==n-1){
            for(;j<m;j++){
                sum+=grid[i][j];
            }
            return sum;
        }

        if(j==m-1){
            for(;i<n;i++){
                sum+=grid[i][j];
            }
            return sum;
        }

        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int left=grid[i][j]+Sum(grid,dp,sum,i+1,j);
        int right=grid[i][j]+Sum(grid,dp,sum,i,j+1);

        return dp[i][j]=min(left,right);
}
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        return Sum(grid,dp,0,0,0);
    }
};