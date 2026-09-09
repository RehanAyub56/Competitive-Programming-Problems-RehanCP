class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,medium=0,high=n-1;

        while(medium<=high){
            if(nums[medium]==0){
                swap(nums[medium],nums[low]);
                low++;
                medium++;
            }
            else if(nums[medium]==2){
                swap(nums[medium],nums[high]);
                high--;
            }
            else{           
                medium++;
            }
        }

    }
};