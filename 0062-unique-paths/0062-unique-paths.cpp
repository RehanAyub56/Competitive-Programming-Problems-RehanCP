class Solution {
public:
    int dp[100][100];

    
    int count(int n,int m,int i,int j){
       
        if(i==n-1 || j==m-1){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int left=count(n,m,i+1,j);
        int right=count(n,m,i,j+1);
        dp[i][j]=left+right;
        return dp[i][j];

    }
    int uniquePaths(int m, int n) {
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dp[i][j]=-1;
        }
    }
        return count(m,n,0,0);
    }
};