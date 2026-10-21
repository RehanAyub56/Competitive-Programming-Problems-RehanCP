class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        long long int ans=0;
        int idx=0;
        while(l<=r){
            if(idx&1){
                ans-=(nums[l]*nums[l]);
                l++;
            }
            else{
                ans+=(nums[r]*nums[r]);
                r--;
            }
            idx++;
        }

        return ans;
    }
};