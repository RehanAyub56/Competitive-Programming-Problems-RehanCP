class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp;
        int n=triangle.size();
        for(int i=0;i<n;i++){
            vector<int>a;
            for(int j=0;j<triangle[i].size();j++) a.push_back(0);
            dp.push_back(a);
        }

        for(int i=0;i<triangle[n-1].size();i++) dp[n-1][i]=triangle[n-1][i];

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                int left=triangle[i][j]+dp[i+1][j];
                int right=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(left,right);
            }
        }

        
        return dp[0][0];
    }
};