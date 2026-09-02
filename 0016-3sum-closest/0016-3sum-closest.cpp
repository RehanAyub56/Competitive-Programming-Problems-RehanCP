class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        int m=0;
        int distance=INT_MAX;
        int ans=0;
        while(l<nums.size()-2){
            m=l+1;
            while(m<r){
            int sum=nums[l]+nums[r]+nums[m];
            if(distance>abs(sum-target)){
                distance=abs(sum-target);
                ans=sum;
            }

            if(sum<target){
                m++;
            }
            else if(sum>target){
                r--;
            }
            else{
                return sum;
            }


            }

            l++;
            r=nums.size()-1;

        }

        return ans;
    }
};