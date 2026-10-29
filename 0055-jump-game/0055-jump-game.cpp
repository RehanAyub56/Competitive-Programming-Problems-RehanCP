class Solution {
public:
    bool Jump(vector<int>&nums,vector<int>&dp,int i){
        int n=nums.size();
        if(i==n-1 || i+nums[i]>=n-1){
            return 1;
        }

        if(i>=n || nums[i]==0){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        dp[i]=0;

        for(int j=i;j<i+nums[i] && j<n-1;j++){
            dp[i]|=Jump(nums,dp,j+1);
        }  

        return dp[i];

    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return Jump(nums,dp,0);
    }
};