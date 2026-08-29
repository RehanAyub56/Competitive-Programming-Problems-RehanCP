class Solution {
public:
    vector<int>dp;
    int Robed(vector<int>& nums,int i){
        int n=nums.size();
        if(i>=n){
            return 0;
        }
        
        if(dp[i]==-1){
            int left=nums[i]+Robed(nums,i+2);
            int right=Robed(nums,i+1);
            dp[i]=max(left,right);
        }

        return dp[i];

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,-1);
        int val=nums[n-1];
        nums.pop_back();
        Robed(nums,0);
        int first=*max_element(dp.begin(),dp.end());
        nums.push_back(val);
        dp.assign(n,-1);
        nums.erase(nums.begin());
        Robed(nums,0);
        int second=*max_element(dp.begin(),dp.end());
        

        
        return max({first,second,nums[0]});

    }
};