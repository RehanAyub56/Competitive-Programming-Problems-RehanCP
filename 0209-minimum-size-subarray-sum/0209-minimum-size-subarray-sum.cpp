class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0;
        int sum=nums[r];
        int ans=INT_MAX;
        int n=nums.size();
        while(l<=r){
            if(sum>=target){
                ans=min(ans,r-l+1);
                sum-=nums[l];
                l++;
            }
            else{
                if(r<n-1){
                    r++;
                    sum+=nums[r];
                }
                else{
                    sum-=nums[l];
                    l++;
                }
            }
        }

        if(ans==INT_MAX)return 0;
        return ans;
    }
};