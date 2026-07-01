class Solution {
public:
    int findMin(vector<int>& nums) {
        int idx1=0;
        int idx2=nums.size()-1;
        int ans=0;
        int middle;
        while(idx1<idx2){
            if(abs(idx1-idx2)==1){
                if(idx1-1>=0 && idx2+1<=nums.size()-1 && (nums[idx1-1]<nums[idx1] || nums[idx2]>nums[idx2+1])){
                    if(nums[idx1-1]<nums[idx1]){
                        idx1--;
                    }
                    else{
                      idx2++;  
                    }

                }
                else
                return min(nums[idx1],nums[idx2]);
            }
            middle=(idx1+idx2)/2;
            if(nums[idx1]>nums[idx2]){
                idx1=middle;
            }
            else if(nums[idx1]<nums[idx2]){
                idx2=middle;
            }
            else{
                return nums[middle];
            }
        }

        return nums[middle];
    }
};