class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=INT_MIN;
        int sum=0;
        int l=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            if(r-l+1==k){
                if(sum>ans){
                    ans=sum;
                }
                sum-=nums[l];
                l++;
            }

        }
        return ans/k;
    }
};