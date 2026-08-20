class Solution {
public:
int dp[100];

    int Robed(vector<int>& nums,int i){
        int n=nums.size();
        
        if(i>=n){
            return 0;
        }
        


        if(dp[i]==-1){
            int left=0,right=0;
            left=nums[i]+Robed(nums,i+2);
            right=Robed(nums,i+1);
            dp[i]=max(left,right);
        }

        return dp[i];
    }


    int rob(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        Robed(nums,0);
        int ans=INT_MIN;
        for(int i=0;i<100;i++){
            ans=max(ans,dp[i]);
            cout<<dp[i]<<endl;
        }

        return ans;

    }
};